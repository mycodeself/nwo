#include "character.h"

const TFrame allFrames[12] = {
   {s_character_down0, 4, 8},
   {s_character_down1, 4, 8},
   {s_character_right0, 4, 8},
   {s_character_right1, 4, 8},
   {s_character_left0, 4, 8},
   {s_character_left1, 4, 8},
   {s_character_up0, 4, 8},
   {s_character_up1, 4, 8},
   {s_character_right_attack, 6, 8},
   {s_character_left_attack, 6, 8},
   {s_character_down_attack, 4, 12},
   {s_character_up_attack, 4, 12}
};

TFrame* const walkDown_frames[3]    = {&allFrames[0], &allFrames[1], 0};
TFrame* const walkRight_frames[3]   = {&allFrames[2], &allFrames[3], 0};
TFrame* const walkLeft_frames[3]    = {&allFrames[4], &allFrames[5], 0};
TFrame* const walkUp_frames[3]      = {&allFrames[6], &allFrames[7], 0};
TFrame* const attackRight_frames[2] = {&allFrames[8], 0};
TFrame* const attackLeft_frames[2]  = {&allFrames[9], 0};
TFrame* const attackDown_frames[2]  = {&allFrames[10], 0};
TFrame* const attackUp_frames[2]    = {&allFrames[11], 0};

const TAnimation character_animation = {walkRight_frames, 0};
/*
* Personaje principal 
*/
const TCharacter character = {
   {{0,0}, {0,0},0,0,0},
   {&character_animation},
   (u8*)0xC0A4
};


/////////// private functions

void updateCharacterAnimation(TAnimation* anim);
void moveCharacter(TCharacter* c);
void drawCharacter(TCharacter* c);
void doAttack(TCharacter* c);

/////////////////////


void initCharacter(){
   TCharacter* c = getCharacter();
   c->entity.pos.i = 1;
   c->entity.pos.j = 1;
   c->entity.npos.i = 1;
   c->entity.npos.j = 1;
   c->entity.status = walk;
   c->animation = &character_animation;
   c->pvmem = (u8*)0xC0A4;
   changeMapPosition(c->entity.pos.i, c->entity.pos.j, _character);
}

void clearAttackFrames(TCharacter* c){
   u8* pvmem;
   switch(character.entity.side){
      case left:
         cpct_drawTileAligned4x8_f(block, character.pvmem);
         cpct_drawTileAligned2x8_f(block, character.pvmem+4);
         c->pvmem = getScrPtrFromMapIndex(character.entity.pos.i, character.entity.pos.j);
         break;
      case right: 
         cpct_drawTileAligned4x8_f(block, character.pvmem); 
         if(map[character.entity.pos.i][character.entity.pos.j+1]==9){
            cpct_drawTileAligned4x8_f(border, character.pvmem+4);
         }else if(map[character.entity.pos.i][character.entity.pos.j+1]==_solidblock){
            cpct_drawTileAligned4x8_f(solidblock, character.pvmem+4);
         }else{
            cpct_drawTileAligned2x8_f(block, character.pvmem+4);            
         }
         break;
      case up:
         pvmem = cpct_getScreenPtr(SCR_VMEM, c->entity.pos.j*4, (c->entity.pos.i+1)*8);
         cpct_drawTileAligned4x4_f(block, character.pvmem);
         cpct_drawTileAligned4x8_f(block, pvmem);
         c->pvmem = getScrPtrFromMapIndex(c->entity.pos.i, c->entity.pos.j);
         break;
      case down:
         cpct_drawTileAligned4x8_f(block, character.pvmem);
         pvmem = cpct_getScreenPtr(SCR_VMEM, c->entity.pos.j*4, ((c->entity.pos.i+2)*8));
         if(map[character.entity.pos.i+1][character.entity.pos.j]==9){
            cpct_drawTileAligned4x8_f(border, pvmem);
         }else if(map[character.entity.pos.i+1][character.entity.pos.j]==_solidblock){
            cpct_drawTileAligned4x8_f(solidblock, pvmem);
         }else{
            cpct_drawTileAligned4x4_f(block, pvmem);            
         }
         break;
   }
}

void clearFrames(TCharacter* c){
   switch(character.entity.status){
      case walk:  cpct_drawTileAligned4x8_f(block, character.pvmem); break;
      case attack: clearAttackFrames(c);
   }
}

void updateCharacter(TCharacter* c)
{
   TGame *g = getGame();
   clearFrames(c);
   if(c->entity.status == attack){
      updateCharacterAnimation(c->animation);
      c->entity.status = walk;
   }
   if(map[c->entity.pos.i][c->entity.pos.j]==_enemy){
      g->state = gameover;
   }else{
      moveCharacter(c);
   }
   drawCharacter(c);
}

/*
* Devuelve el puntero al personaje principal
*/
TCharacter* getCharacter(){
	return &character;
}

/*
* Mueve el personaje según la tecla pulsada
*/
void moveCharacter(TCharacter* c)
{
   TPosition* alliePosition;
   TAnimation* anim = c->animation;
   TAllie* a;
   TGame* g = getGame();

   if(cpct_isKeyPressed(Key_D)){
	   
	  if(c->entity.side == right)
		c->entity.npos.j = c->entity.pos.j + 1;
	  else
	  {
		c->entity.nside = right;
		updateCharacterAnimation(anim);
		c->entity.side = right;
	  }
   }else 
   if(cpct_isKeyPressed(Key_A)){
	  if(c->entity.side == left)
		c->entity.npos.j = c->entity.pos.j - 1;
	  else
	  {
		c->entity.nside = left;
		updateCharacterAnimation(anim);
		c->entity.side = left;
	  }
   }   
   else 
   if(cpct_isKeyPressed(Key_S)){
	  if(c->entity.side == down)
		c->entity.npos.i = c->entity.pos.i + 1;
	  else
	  {
		c->entity.nside = down;
		updateCharacterAnimation(anim);
		c->entity.side = down;
	  }
   }  
   else 
   if(cpct_isKeyPressed(Key_W)){
	  if(c->entity.side == up)
		c->entity.npos.i = c->entity.pos.i - 1;
	  else
	  {
		c->entity.nside = up;
		updateCharacterAnimation(anim);
		c->entity.side = up;
	  }
   }
   if(cpct_isKeyPressed(Key_P)){
      doAttack(c);
   }
   if(c->entity.pos.j != c->entity.npos.j || c->entity.pos.i != c->entity.npos.i){
      if(!detectCollisionEntity(&c->entity)){
         changeMapPosition(c->entity.pos.i, c->entity.pos.j, _empty);
         updateCharacterAnimation(anim);
         doNextMovement(&c->entity);
         changeMapPosition(c->entity.pos.i, c->entity.pos.j, _character);
         c->pvmem = getScrPtrFromMapIndex(c->entity.pos.i, c->entity.pos.j);
      }
      else if (detectCollisionEntity(&c->entity)==2) //Hay un aliadoo en la siguiente posicion
      {
         increaseScore((u8)100);
         changeMapPosition(c->entity.pos.i, c->entity.pos.j, _empty);
         updateCharacterAnimation(anim);
         alliePosition = &c->entity.npos;
         a = getAllieByPosition(alliePosition);
         a->status=_dead;
         doNextMovement(&c->entity);
         changeMapPosition(c->entity.pos.i, c->entity.pos.j, _character);       
         c->pvmem = getScrPtrFromMapIndex(c->entity.pos.i, c->entity.pos.j);
      }
      else{
         cancelNextMovement(&c->entity);
      }
   }
   if(map[c->entity.pos.i][c->entity.pos.j] == _enemy){
      g->state = gameover;
   } 
}


void doAttack(TCharacter* c){
   TPosition attackpos;
   TGame* g;
   TEnemy* e;
   u8* pvmem;
   u8 kill;
   kill = 0;
   g = &game;
   
   switch(c->entity.side){
      case left:  
         if(!isWallOrBorder(c->entity.pos.i, c->entity.pos.j-1)){
            attackpos.i = c->entity.pos.i;
            attackpos.j = c->entity.pos.j-1;
			e = getEnemyByPosition(&attackpos);
			if(e->entity.side != right)
			{
				c->animation->frames = attackLeft_frames;
				c->pvmem = cpct_getScreenPtr(SCR_VMEM, (c->entity.pos.j*4)-2, (c->entity.pos.i+1)*8); 
				c->entity.status = attack;
				c->animation->frame_idx = 0;
				kill = 1;
			}
         }
         break;
      case right: 
         if(!isWallOrBorder(c->entity.pos.i, c->entity.pos.j+1)){
            attackpos.i = c->entity.pos.i;
            attackpos.j = c->entity.pos.j+1;
			e = getEnemyByPosition(&attackpos);
			if(e->entity.side != left)
			{
				c->animation->frames = attackRight_frames;
				c->pvmem = getScrPtrFromMapIndex(c->entity.pos.i, c->entity.pos.j); 
				c->entity.status = attack;
				c->animation->frame_idx = 0;
				kill = 1;
			}
         }
         break;
      case up: 
         if(!isWallOrBorder(c->entity.pos.i-1, c->entity.pos.j)){ 
			attackpos.i = c->entity.pos.i-1;
			attackpos.j = c->entity.pos.j;
			e = getEnemyByPosition(&attackpos);
			if(e->entity.side != down)
			{
				c->animation->frames = attackUp_frames;
				c->pvmem = cpct_getScreenPtr(SCR_VMEM, c->entity.pos.j*4, ((c->entity.pos.i+1)*8)-4);       
				c->entity.status = attack;
				c->animation->frame_idx = 0; 
				kill = 1;
			}
         }
         break;
      case down:
         if(!isWallOrBorder(c->entity.pos.i+1, c->entity.pos.j)){
			 
			attackpos.i = c->entity.pos.i+1;
			attackpos.j = c->entity.pos.j; 
			e = getEnemyByPosition(&attackpos);
			if(e->entity.side != up)
			{
				c->animation->frames = attackDown_frames;
				c->pvmem = getScrPtrFromMapIndex(c->entity.pos.i, c->entity.pos.j);
				c->entity.status = attack;
				c->animation->frame_idx = 0;  
				kill = 1;
			}
         }
         break;
   }
   if(attackpos && kill == 1){
      switch(map[attackpos.i][attackpos.j]){
         case _enemy: // atacar enemigo
            e = getEnemyByPosition(&attackpos);
			e->entity.status = dead;
			g->numberEnemiesAlive -= 1;
			changeMapPosition(attackpos.i, attackpos.j, _empty);
			pvmem = getScrPtrFromMapIndex(e->entity.pos.i, e->entity.pos.j);
			cpct_drawTileAligned4x8_f(block, pvmem);
			increaseScore(200);
			if(g->numberEnemiesAlive == 0)
				reliveMoreEnemies();
            break;
         case _allie:
            resetScore();
            pvmem = getScrPtrFromMapIndex(attackpos.i, attackpos.j);
            cpct_drawTileAligned4x8_f(block, pvmem);
            break; // atacar aliado
      }
   }
}

void updateCharacterAnimation(TAnimation* anim){
   TFrame* nframe;

   if(character.entity.side != character.entity.nside  || character.entity.status == attack){
      switch(character.entity.nside){
         case right: anim->frames = walkRight_frames; break;
         case left: anim->frames = walkLeft_frames; break;
         case down: anim->frames = walkDown_frames; break;
         case up: anim->frames = walkUp_frames; break;
      }
      anim->frame_idx = 0;
   }else{
      nframe = anim->frames[++anim->frame_idx];
      if(!nframe){
         anim->frame_idx = 0;
      }
   }
}


/*
* Pinta el personaje en la posición actual
*/
void drawCharacter(TCharacter* c){
   TAnimation* anim = c->animation;
   TFrame* frame = anim->frames[anim->frame_idx];
   cpct_drawSpriteMasked(frame->sprite, c->pvmem, frame->width, frame->height);
}
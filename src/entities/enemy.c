#include "enemy.h"
#include "../utils/A.h"
///////// ANIMATIONS /////////////
const TFrame enemiesFrames[20] = {
	// enemy1 frames
	{s_enemy1_down0, 4, 8}, {s_enemy1_down1, 4, 8}, {s_enemy1_down2, 4, 8},
	{s_enemy1_up0, 4, 8}, {s_enemy1_up1, 4, 8}, {s_enemy1_up2, 4, 8},
	{s_enemy1_left0, 4, 8},	{s_enemy1_left1, 4, 8},
	{s_enemy1_right0, 4, 8}, {s_enemy1_right1, 4, 8},
	// enemy2 frames
	{s_enemy2_down0, 4, 8},	{s_enemy2_down1, 4, 8},
	{s_enemy2_up0, 4, 8}, {s_enemy2_up1, 4, 8},
	{s_enemy2_left0, 4, 8},	{s_enemy2_left1, 4, 8},
	{s_enemy2_right0, 4, 8}, {s_enemy2_right1, 4, 8}
};

TFrame* const e1_walkDown_frames[4] = {&enemiesFrames[0], &enemiesFrames[1], &enemiesFrames[2], 0};
TFrame* const e1_walkUp_frames[4] = {&enemiesFrames[3], &enemiesFrames[4], &enemiesFrames[5], 0};
TFrame* const e1_walkLeft_frames[3] = {&enemiesFrames[6], &enemiesFrames[7], 0};
TFrame* const e1_walkRight_frames[3] = {&enemiesFrames[8], &enemiesFrames[9], 0};
TFrame* const e2_walkDown_frames[3] = {&enemiesFrames[10], &enemiesFrames[11], 0};
TFrame* const e2_walkUp_frames[3] = {&enemiesFrames[12], &enemiesFrames[13], 0};
TFrame* const e2_walkLeft_frames[3] = {&enemiesFrames[14], &enemiesFrames[15], 0};
TFrame* const e2_walkRight_frames[3] = {&enemiesFrames[16], &enemiesFrames[17], 0};

const TAnimation enemy1_animation = {0, 0};
const TAnimation enemy2_animation = {0, 0};
const TAnimation enemy3_animation = {0, 0};
const TAnimation enemy4_animation = {0, 0};
const TAnimation enemy5_animation = {0, 0};
const TAnimation enemy6_animation = {0, 0};
const TAnimation enemy7_animation = {0, 0};
const TAnimation enemy8_animation = {0, 0};
const TAnimation enemy9_animation = {0, 0};
const TAnimation enemy10_animation = {0, 0};
const TAnimation enemy11_animation = {0, 0};
const TAnimation enemy12_animation = {0, 0};
////////////////// END ANIMATIONS

//

const TEnemy enemy1 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy1_animation},
    0 // enemy type
};
const TEnemy enemy2 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy2_animation},
    0 // enemy type
};

const TEnemy enemy3 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy3_animation},
    0 // enemy type
};
const TEnemy enemy4 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy4_animation},
    0 // enemy type
};
const TEnemy enemy5 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy5_animation},
    0 // enemy type
};
const TEnemy enemy6 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy6_animation},
    0 // enemy type
};
const TEnemy enemy7 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy7_animation},
    0 // enemy type
};
const TEnemy enemy8 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy8_animation},
    0 // enemy type
};
const TEnemy enemy9 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy9_animation},
    0 // enemy type
};
const TEnemy enemy10 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy10_animation},
    0 // enemy type
};
const TEnemy enemy11 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99},
    {&enemy11_animation},
    0 // enemy type
};
const TEnemy enemy12 = {
	{{0 ,0}, {0, 0}, 0,0, dead},
    {0, 0, 0, 0}, // sensor
    3, 6, // rango
    {99, 99, 99, 99}, // nextMoves
    {&enemy12_animation},
    0 // enemy type
};

TEnemy* const enemies[MAX_ENEMIES] = {
	&enemy1, &enemy2, &enemy3, &enemy4, &enemy5, &enemy6,
	&enemy7, &enemy8, &enemy9, &enemy10, &enemy11, &enemy12
};

void initEnemies(){

	u8 i;
	TEnemy* e;
	for(i = 0; i < MAX_ENEMIES; i++)
	{
		e = enemies[i];
		e->entity.status = dead;
		
	}
	for(i=0;i<game.numberEnemies;i++){
		e = enemies[i];
		e->entity.pos.i = (mixedRandomGenerator() % 22) + 1;
		e->entity.pos.j = (mixedRandomGenerator() % 18) + 1;
		while(map[e->entity.pos.i][e->entity.pos.j]!=0){
			e->entity.pos.i = (mixedRandomGenerator() % 22) + 1;
			e->entity.pos.j = (mixedRandomGenerator() % 18) + 1;
		}
		e->entity.npos.i = e->entity.pos.i;
		e->entity.npos.j = e->entity.pos.j;
		e->entity.side = (mixedRandomGenerator() % 4);
		e->entity.nside = e->entity.side;
		e->entity.status = walk;
		e->nextMoves[0] = 99;
		e->nextMoves[1] = 99;
		e->nextMoves[2] = 99;
		e->nextMoves[3] = 99;
		e->type = (mixedRandomGenerator() % 2);
		changeMapPosition(e->entity.pos.i, e->entity.pos.j, _enemy);
		initEnemyAnimation(e);
	} 
}

void initEnemyAnimation(TEnemy* e){
	TAnimation* anim;
	anim = e->animation;
	switch(e->type){
		case one:
			switch(e->entity.nside){
				case down: anim->frames = e1_walkDown_frames; anim->frame_idx = 0;
					break;
				case up: anim->frames = e1_walkUp_frames; anim->frame_idx = 0;
					break;
				case right: anim->frames = e1_walkRight_frames; anim->frame_idx = 0;
					break;
				case left: anim->frames = e1_walkLeft_frames; anim->frame_idx = 0;
					break;
			}
			break;
		case two:
			switch(e->entity.nside){
				case down: anim->frames = e2_walkDown_frames; anim->frame_idx = 0;
					break;
				case up: anim->frames = e2_walkUp_frames; anim->frame_idx = 0;
					break;
				case right: anim->frames = e2_walkRight_frames; anim->frame_idx = 0;
					break;
				case left: anim->frames = e2_walkLeft_frames; anim->frame_idx = 0;
					break;
			}
			break;
	}
}

// Incrementa el nº de enemigos y los inicializa^M
void reliveMoreEnemies()
{
       TGame *g = getGame();
       if(g->numberEnemies < 6)
       {
               g->numberEnemies += 2;  
       }
       else if(g->numberEnemies <= g->maxEnemies)
       {
               g->numberEnemies++;
       }
       g->numberEnemiesAlive = g->numberEnemies;
		initEnemies();
}

TEnemy* getEnemyByPosition(TPosition* p){
	u8 i;
	for(i=0;i<MAX_ENEMIES;i++){
		if(enemies[i]->entity.pos.i == p->i && enemies[i]->entity.pos.j == p->j){
			return enemies[i];
		}
	}
	return 0;
}

void updateEnemyByIndex(u8 i){
	if(enemies[i]->entity.status != dead)
		updateEnemy(enemies[i]);
}

void updateEnemies(){
	u8 i;
	for(i=0;i<MAX_ENEMIES;i++){
		if(enemies[i]->entity.status != dead)
				updateEnemy(enemies[i]);	
	}
}

void updateEnemyAnimation(TEnemy* e){
	TFrame* nframe;
	TAnimation* anim = e->animation;

	if(e->entity.side != e->entity.nside){
		initEnemyAnimation(e);
	}else{
		nframe = anim->frames[++anim->frame_idx];
		if(!nframe){
			anim->frame_idx = 0;
		}
	}

}

void updateEnemy(TEnemy* e){	
	TPosition* alliePosition;
	TAllie* a;
	u8 *pvmem;
	u8 aux;
	TGame* g;
	TPosition pos;
	g = getGame();
	//clearSensor(&e->range);
	getRange(e);
	
	switch(e->type)
	{
		case one:
			if (inRange(&e->range, &character.entity.pos))
				A(e, &character.entity.pos);		
			else
			{
				for(aux = 0; aux <4; aux++)
				{
					// Si tiene algun movimiento en la lista entrara en algun switch, sino sale del bucle con aux=5 y calculamos movimiento basico
					switch(e->nextMoves[aux])
					{
						case up: 	
							e->entity.npos.i=e->entity.pos.i-1;	
							e->entity.npos.j=e->entity.pos.j; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 
							aux = 99; 
							break;
						case down:	
							e->entity.npos.i=e->entity.pos.i+1; 
							e->entity.npos.j=e->entity.pos.j; 
							e->entity.nside = e->nextMoves[aux]; 
							e->nextMoves[aux] = 99; 
							aux = 99;  
							break;
						case right:	
							e->entity.npos.i=e->entity.pos.i; 
							e->entity.npos.j=e->entity.pos.j+1; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 	
							aux = 99;  
							break;
						case left:	
							e->entity.npos.i=e->entity.pos.i; 
							e->entity.npos.j=e->entity.pos.j-1; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 	
							aux = 99;  
							break;
					}
				}
				// Si no hay movimiento siguiente, calculamos el basico
				if(aux == 4)
				{
					
					allieInRange(&e->range, &pos);
					if(pos.i != 99)
						A(e, &pos);
					else
						basicEnemyMovement(e);
				}				
			}
			break;
		case two:
			allieInRange(&e->range, &pos);
			if(pos.i != 99)
				A(e, &pos);
			else
			{
				for(aux = 0; aux <4; aux++)
				{
					// Si tiene algun movimiento en la lista entrara en algun switch, sino sale del bucle con aux=5 y calculamos movimiento basico
					switch(e->nextMoves[aux])
					{
						case up: 	
							e->entity.npos.i=e->entity.pos.i-1;	
							e->entity.npos.j=e->entity.pos.j; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 
							aux = 99; 
							break;
						case down:	
							e->entity.npos.i=e->entity.pos.i+1; 
							e->entity.npos.j=e->entity.pos.j; 
							e->entity.nside = e->nextMoves[aux]; 
							e->nextMoves[aux] = 99; 
							aux = 99;  
							break;
						case right:	
							e->entity.npos.i=e->entity.pos.i; 
							e->entity.npos.j=e->entity.pos.j+1; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 	
							aux = 99;  
							break;
						case left:	
							e->entity.npos.i=e->entity.pos.i; 
							e->entity.npos.j=e->entity.pos.j-1; 
							e->entity.nside = e->nextMoves[aux];
							e->nextMoves[aux] = 99; 	
							aux = 99;  
							break;
					}
				}
				// Si no hay movimiento siguiente, calculamos el basico
				if(aux == 4)
				{					
					if (inRange(&e->range, &character.entity.pos))
						A(e, &character.entity.pos);
					else
						basicEnemyMovement(e);
				}
						
			}
	}
	
	pvmem = getScrPtrFromMapIndex(e->entity.pos.i, e->entity.pos.j);
    cpct_drawTileAligned4x8_f(block, pvmem);
	updateEnemyAnimation(e);
	changeMapPosition(e->entity.pos.i, e->entity.pos.j, _empty);
	if(map[e->entity.npos.i][e->entity.npos.j] == 2){
		g->state = gameover;
	}
	// Si la npos == _allie, decremento score
	else if(map[e->entity.npos.i][e->entity.npos.j] == _allie)
	{
		alliePosition = &e->entity.npos;
      	a = getAllieByPosition(alliePosition);
      	a->status=_dead;
		changeMapPosition(e->entity.npos.i, e->entity.npos.j, _enemy);
		doNextMovement(&e->entity);		
		decreaseScore(20);
	}
	else
	{
		changeMapPosition(e->entity.npos.i, e->entity.npos.j, _enemy);
		doNextMovement(&e->entity);			
	}
	// drawSensor(&e->range);
	drawEnemy(e);
}

void drawEnemy(TEnemy* e){
	u8* pvmem;
	TAnimation* anim = e->animation;
   	TFrame* frame = anim->frames[anim->frame_idx];
	pvmem = getScrPtrFromMapIndex(e->entity.pos.i, e->entity.pos.j);
	cpct_drawSpriteMasked(frame->sprite, pvmem, 4, 8);
}

void allieInRange(TSensor* range, TPosition *pos)
{
	u8 i,j;
	
	pos->i = 99;
	pos->j = 99;
	
	// pvmem = getScrPtrFromMapIndex(e->entity.pos.i, e->entity.pos.j);
    // cpct_drawTileAligned4x8_f(block, pvmem);
	// doNextMovement(&e->entity);
	for(i = range->i_min; i<= range->i_max; i++)
	{
		for(j = range->j_min; j<= range->j_max; j++)
		{
			if(map[i][j] == _allie)
			{
				pos->i = i;
				pos->j = j;
				i = 99;
				j = 99;
			}
		}

	}
}

void basicEnemyMovement(TEnemy* enemy)
{
	TPosition pos;
	u8 i,j;
	/* ZONAS
		1  5  9   13  17  21
		2  6  10  14  18  22
		3  7  11  15  19  23
		4  8  12  16  20  24
	*/
	// Calculamos la j de la zona
	if(enemy->entity.pos.j <=6)
	{
		if(enemy->entity.pos.j <= 3)
		{
			// Zona 1
			if(enemy->entity.pos.i <= 6)
			{
				//Zona 6
				i = 7;
				j = 4;
			}
			// Zona 2
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 5
				i = 1;
				j = 4;
			}
			// Zona 3
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 8
				i = 18;
				j = 4;
			}
			// Zona 4
			else
			{
				// Zona 7
				i = 12;
				j = 4;
			}
		}
		else
		{
			// Zona 5
			if(enemy->entity.pos.i <= 6)
			{
				// Zona 9
				i = 1;
				j = 7;
			}
			// Zona 6
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 3
				i = 12;
				j = 1;
			}
			// Zona 7
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 2
				i = 7;
				j = 1;
			}
			// Zona 8
			else
			{
				// Zona 4
				i = 18;
				j = 1;
			}
		}
	}
	else if(enemy->entity.pos.j <= 12)
	{
		if(enemy->entity.pos.j <= 9)
		{
			// Zona 9
			if(enemy->entity.pos.i <= 6)
			{
				// Zona 14
				i = 7;
				j = 10;
			}
			// Zona 10
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 13
				i = 1;
				j = 10;
			}
			// Zona 11
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 16
				i = 18;
				j = 10;
			}
			// Zona 12
			else
			{
				// Zona 15
				i = 12;
				j = 10;
			}
		}
		else
		{
			// Zona 13
			if(enemy->entity.pos.i <= 6)
			{
				// Zona 17
				i = 1;
				j = 13;
			}
			// Zona 14
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 11
				i = 12;
				j = 7;
			}
			// Zona 15
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 10
				i = 7;
				j = 7;
			}
			// Zona 16
			else
			{
				// Zona 12
				i = 18;
				j = 7;
			}
		}
	}
	else
	{
		if(enemy->entity.pos.j <= 15)
		{
			// Zona 17
			if(enemy->entity.pos.i <= 6)
			{
				// Zona 22
				i = 7;
				j = 16;
			}
			// Zona 18
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 21
				i = 1;
				j = 16;
			}
			// Zona 19
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 24
				i = 18;
				j = 16;
			}
			// Zona 20
			else
			{
				// Zona 23
				i = 12;
				j = 16;
			}
		}
		else
		{
			// Zona 21
			if(enemy->entity.pos.i <= 6)
			{
				// Zona 17
				i = 1;
				j = 13;
			}
			// Zona 22
			else if(enemy->entity.pos.i <= 11)
			{
				// Zona 19
				i = 12;
				j = 13;
			}
			// Zona 23
			else if(enemy->entity.pos.i <= 17)
			{
				// Zona 18
				i = 7;
				j = 13;
			}
			// Zona 24
			else
			{
				// Zona 20
				i = 18;
				j = 13;
			}
		}
	}
	do
	{
		pos.i = i;
		pos.j = j;
		pos.i += (mixedRandomGenerator() % 5);
		pos.j += (mixedRandomGenerator() % 3);
	}while(map[pos.i][pos.j]!=0 && manhattanDistance(&enemy->entity.pos, &pos) < 10);
	
	A(enemy, &pos);
}
/*
* Obtiene el rango de visión de un enemigo 
*/
void getRange(TEnemy *enemy)
{
	// Estos valores permaneceran si el enemigo esta mirando hacia el borde del mapa

	enemy->range.j_min = enemy->entity.pos.j;
	enemy->range.j_max = enemy->entity.pos.j;
	enemy->range.i_min = enemy->entity.pos.i;
	enemy->range.i_max = enemy->entity.pos.i;

   // Según hacia donde esté mirando, tiene un campo de range diferente
	switch(enemy->entity.side)
	{
		case up:
			// if(enemy->entity.pos.i != MIN_MAP_INDEX_I)		// Si no esta mirando hacia el borde
			// {
				enemy->range.i_min = enemy->entity.pos.i - enemy->range_front;
				enemy->range.i_max = enemy->entity.pos.i;
				enemy->range.j_min = enemy->entity.pos.j -enemy->range_sides;
				enemy->range.j_max = enemy->entity.pos.j +enemy->range_sides;
			// }
		break;
		case down:
			// if (enemy->entity.pos.i != MAX_MAP_INDEX_I)		// Si no esta mirando hacia el borde
			// {
				enemy->range.i_min = enemy->entity.pos.i ;
				enemy->range.i_max = enemy->entity.pos.i +enemy->range_front;
				enemy->range.j_min = enemy->entity.pos.j -enemy->range_sides;
				enemy->range.j_max = enemy->entity.pos.j +enemy->range_sides;
			// }
		break;
		case left:
			// if (enemy->entity.pos.j != MIN_MAP_INDEX_J)		// Si no esta mirando hacia el borde
			// {
				enemy->range.i_min = enemy->entity.pos.i -enemy->range_sides;
				enemy->range.i_max = enemy->entity.pos.i +enemy->range_sides;
				enemy->range.j_min = enemy->entity.pos.j -enemy->range_front;
				enemy->range.j_max = enemy->entity.pos.j ;
			// }
		break;		
		case right:
			// if (enemy->entity.pos.j != MAX_MAP_INDEX_J)		// Si no esta mirando hacia el borde
			// {
				enemy->range.i_min = enemy->entity.pos.i -enemy->range_sides;
				enemy->range.i_max = enemy->entity.pos.i +enemy->range_sides;
				enemy->range.j_min = enemy->entity.pos.j ;
				enemy->range.j_max = enemy->entity.pos.j +enemy->range_front;
			// }
		break;		
	}
   
	// Si se sale del tablero, adaptamos coordenadas de range
	if (enemy->range.i_min < MIN_MAP_INDEX_I || enemy->range.i_min > MAX_MAP_INDEX_I)	// Si el y minimo se sale de rango por abajo
	   enemy->range.i_min = MIN_MAP_INDEX_I;
	if (enemy->range.i_max > MAX_MAP_INDEX_I)				// Si el y maximo se sale de rango por arriba
		enemy->range.i_max = MAX_MAP_INDEX_I;
	if (enemy->range.j_min < MIN_MAP_INDEX_J || enemy->range.j_min > MAX_MAP_INDEX_J)	// Si el x minimo se sale de rango por abajo
		enemy->range.j_min = MIN_MAP_INDEX_J;
	if (enemy->range.j_max > MAX_MAP_INDEX_J)				// Si el x maximo se sale de rango por arriba
		enemy->range.j_max = MAX_MAP_INDEX_J;
}

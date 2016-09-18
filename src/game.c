#include "game.h"
#define ENEMIES_ON_MAP 3

const TGame game = {
  playing, ENEMIES_ON_MAP, 12, ENEMIES_ON_MAP, 2, 8
};

TGame* getGame(){
  return &game;
}

/*
* Pinta el marcador en pantalla
*/
void drawScore()
{
   u8* pvmem;
   u8  str[6];
   pvmem = cpct_getScreenPtr(SCR_VMEM, 36, 0);
   sprintf(str, "%5u", game.score);
   cpct_drawStringM0("SCORE", pvmem, 6, 1);
   pvmem = cpct_getScreenPtr(SCR_VMEM, 56, 0);
   cpct_drawStringM0(str, pvmem, 6, 1);
   pvmem = cpct_getScreenPtr(SCR_VMEM, 76, 0);
   cpct_drawSpriteMasked(Aliado, pvmem, 4, 8);  
}
/*
* Incrementa el marcador en n
*/
void increaseScore(u8 n)
{
  TGame* g = &game;
  g->score = game.score + n;
}
/*
* Decrementa el marcador en n
*/
void decreaseScore(u8 n)
{
  TGame* g = &game;
  if(game.score > 0)
    g->score = game.score - n;
}
/*
* Pone el marcador a 0
*/
void resetScore(){
  TGame *g = &game;
  g->score = 0;
}

void drawStartScreen(){
  u8* pvmem;
  pvmem = cpct_getScreenPtr(SCR_VMEM, 28, 0);
  cpct_drawSprite(logo_eye, pvmem, 25, 50);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 17, 60);
  cpct_drawSprite(logo_text, pvmem, LOGO_TEXT_W, LOGO_TEXT_H);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 33, 125);
  cpct_drawStringM0("Play", pvmem, 14, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 145);
  cpct_drawStringM0("Controls", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 28, 165);
  cpct_drawStringM0("Credits", pvmem, 6, 1);
}
/*void drawBorder(){
  u8* pvmem;
  u8 i;
  //cpct_clearScreen_f64(0x3030);
  for(i=0;i<80;i+=4){
    pvmem = cpct_getScreenPtr(SCR_VMEM, i, 0);
    cpct_drawTileAligned4x8(border, pvmem);
    pvmem = cpct_getScreenPtr(SCR_VMEM, i, 192);
    cpct_drawTileAligned4x8(border, pvmem);
  }
  for(i=8;i<192;i+=8){
    pvmem = cpct_getScreenPtr(SCR_VMEM, 0, i);
    cpct_drawTileAligned4x8(border, pvmem);
    pvmem = cpct_getScreenPtr(SCR_VMEM, 76, i);
    cpct_drawTileAligned4x8(border, pvmem);
  }
}*/
void creditsScreen(){
  u8* pvmem;
  //drawBorder();
  pvmem = cpct_getScreenPtr(SCR_VMEM, 17, 0);
  cpct_drawSprite(logo_text, pvmem, LOGO_TEXT_W, LOGO_TEXT_H);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 15, 85);
  cpct_drawStringM0("Gacel Ivorra", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 15, 95);
  cpct_drawStringM0("Josep Perez", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 15, 105);
  cpct_drawStringM0("Isma P.Ramos", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 12, 135);
  cpct_drawStringM0("With CPCtelera", pvmem, 6, 1);
  /*pvmem = cpct_getScreenPtr(SCR_VMEM, 6, 165);
  cpct_drawStringM0("Any key to return", pvmem, 4, 1);*/
  pvmem = cpct_getScreenPtr(SCR_VMEM, 32, 184);
  cpct_drawSpriteMasked(s_character_down0, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 36, 184);
  cpct_drawSpriteMasked(Aliado, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 40, 184);
  cpct_drawSpriteMasked(s_enemy1_down0, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 44, 184);
  cpct_drawSpriteMasked(s_enemy2_down0, pvmem, 4, 8);
  waitNVSYNCs(4);
  cpct_scanKeyboard();
  while(!cpct_isAnyKeyPressed()){
    cpct_scanKeyboard();
  };
  waitNVSYNCs(4);
  if(cpct_isAnyKeyPressed())
    startGame();
}
void controlsScreen(){
  u8* pvmem;
  //drawBorder();
  pvmem = cpct_getScreenPtr(SCR_VMEM, 17, 0);
  cpct_drawSprite(logo_text, pvmem, LOGO_TEXT_W, LOGO_TEXT_H);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 10, 70);
  cpct_drawStringM0("W \xf0 A \xf2 S \xf1 D \xf3", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 20, 90);
  cpct_drawSpriteMasked(s_character_right_attack, pvmem, 6, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 26, 90);
  cpct_drawStringM0("P Attack", pvmem, 6, 1);

  pvmem = cpct_getScreenPtr(SCR_VMEM, 20, 110);
  cpct_drawSpriteMasked(s_enemy1_down0, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 110);
  cpct_drawSpriteMasked(s_enemy2_down0, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 30, 110);
  cpct_drawStringM0("Enemies", pvmem, 6, 1);

  pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 130);
  cpct_drawSpriteMasked(Aliado, pvmem, 4, 8);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 30, 130);
  cpct_drawStringM0("Allie", pvmem, 6, 1);
  pvmem = cpct_getScreenPtr(SCR_VMEM, 6, 160);
  cpct_drawStringM0("NO FRONT ATTACK!!", pvmem, 6, 1);
  /*pvmem = cpct_getScreenPtr(SCR_VMEM, 6, 165);
  cpct_drawStringM0("Any key to return", pvmem, 4, 1);*/
  waitNVSYNCs(4);
  cpct_scanKeyboard();
  while(!cpct_isAnyKeyPressed()){
    cpct_scanKeyboard();
  };
  waitNVSYNCs(4);
  if(cpct_isAnyKeyPressed())
    startGame();
}

void startScreen()
{
  u8 num = 0;
  u8* pvmem;
  TMenuOption optselected;
  optselected = play;
  cpct_clearScreen_f64(0xC0C0); 
  cpct_scanKeyboard();
  drawStartScreen(); 
  while(!cpct_isKeyPressed(Key_Return) && !cpct_isKeyPressed(Key_Space)){
    if(cpct_isKeyPressed(Key_CursorDown) || cpct_isKeyPressed(Key_S)){
      if(optselected == play){
        pvmem = cpct_getScreenPtr(SCR_VMEM, 33, 125);
        cpct_drawStringM0("Play", pvmem, 6, 1);
        pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 145);
        cpct_drawStringM0("Controls", pvmem, 14, 1);
        optselected = controls;
      }else if(optselected == controls){
        pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 145);
        cpct_drawStringM0("Controls", pvmem, 6, 1);
        pvmem = cpct_getScreenPtr(SCR_VMEM, 28, 165);
        cpct_drawStringM0("Credits", pvmem, 14, 1);
        optselected = credits;
      }
    }else if(cpct_isKeyPressed(Key_CursorUp) || cpct_isKeyPressed(Key_W)){
      if(optselected == controls){
        pvmem = cpct_getScreenPtr(SCR_VMEM, 33, 125);
        cpct_drawStringM0("Play", pvmem, 14, 1);
        pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 145);
        cpct_drawStringM0("Controls", pvmem, 6, 1);
        optselected = play;
      }else if(optselected == credits){
        pvmem = cpct_getScreenPtr(SCR_VMEM, 25, 145);
        cpct_drawStringM0("Controls", pvmem, 14, 1);
        pvmem = cpct_getScreenPtr(SCR_VMEM, 28, 165);
        cpct_drawStringM0("Credits", pvmem, 6, 1);
        optselected = controls;
      }
    }  
    num++;
    waitNVSYNCs(5);
    cpct_scanKeyboard_f();
  }

  cpct_clearScreen_f64(0xC0C0);
  
  switch(optselected){
    case play:
      initializeRandomGenerators(num);
      gameLoop();
      break;
    case controls: controlsScreen(); break;
    case credits: creditsScreen(); break;
  }
}

void gameLoop(){
  TCharacter* c;
  u8 i, indexEnemy, auxOp1, auxOp2;
  TGame* g = getGame();
  c = getCharacter();
  
  clearFrames(c);
  initMap();
  initCharacter();
  initEnemies();
  drawMap();
  
  i = 0;
  indexEnemy = 0;
  
  while(game.state == playing && !cpct_isKeyPressed(Key_Esc)){

    cpct_scanKeyboard_f();
    drawScore();
	auxOp1 = (game.maxEnemies/(game.numberEnemiesAlive+2));
	auxOp2 = (game.maxEnemies/(game.numberEnemiesAlive+1));
	
	if(auxOp1 == 0)
		auxOp1 = 1;
	if(auxOp2 == 0)
		auxOp2 = 1;
	
	if(i % auxOp1 == 0)		
	{
		updateCharacter(c);
		if(game.state == gameover)
		  break;		
	}
    if(i % auxOp2 == 0)		
	{	  
		++indexEnemy;
		if(indexEnemy >= game.numberEnemies)
			indexEnemy = 0;
		while(enemies[indexEnemy]->entity.status == dead)
		{
			if(indexEnemy >= game.numberEnemies)
				indexEnemy = 0;
			else
				++indexEnemy;
				
		}
		updateEnemyByIndex(indexEnemy);
	}
    if(game.state == gameover)
      break;
    mostrarAliados();
      
	if(i >= 12)
		i=0;
	else
		++i;
    cpct_waitVSYNC();
  };
  resetAllies();
  startGame();
}

void startGame(){

  TGame* g = getGame();
  g->state = playing;
  resetScore();
  g->numberEnemies = ENEMIES_ON_MAP;	
  g->numberEnemiesAlive = ENEMIES_ON_MAP;
  startScreen();
}
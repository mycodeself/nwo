#ifndef _GAME_H_
#define _GAME_H_

#include <cpctelera.h>
#include <stdio.h>
#include "sprites/sprites.h"
#include "entities/entities.h"
#include "entities/character.h"
#include "entities/enemy.h"
#include "entities/allies.h"
#include "map/map.h"
#include "utils/utils.h"
#define SCR_VMEM (u8*)0xC000
#define LOGO_TEXT_W 45 // bytes
#define LOGO_TEXT_H 45 // bytes

typedef enum MenuOption{play, controls, credits}TMenuOption;
typedef enum GameState{playing, gameover}TGameState;

typedef struct Game {
  TGameState state;
  u8 numberEnemies;
  u8 maxEnemies;
  u8 numberEnemiesAlive;
  u8 numberAllies;
  u8 maxAllies;
  u16 score;
}TGame;

extern const TGame game;


// Public functions
TGame* getGame();
void startGame();
void gameLoop();
void drawScore();
void increaseScore(u8 n);
void decreaseScore(u8 n);
void resetScore();
///////////////////
#endif
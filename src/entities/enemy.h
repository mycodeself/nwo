#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <cpctelera.h>
#include "entities.h"
#include "character.h"
#include "../sprites/sprites.h"
#include "../utils/utils.h"
#include "../map/map.h"
#include "../game.h"
#define MAX_ENEMIES 12


typedef enum {one, two} TEnemyType;

typedef struct Enemy {
     TEntity entity;
     TSensor range;
     u8 range_sides, range_front;
     TEntitySide nextMoves[4];
     TAnimation* animation;
     TEnemyType type;
}TEnemy;

extern TEnemy* const enemies[MAX_ENEMIES];
//PUBLIC
void getRange(TEnemy* enemy);
void updateEnemy(TEnemy* e);
void drawEnemy(TEnemy* e);
void basicEnemyMovement(TEnemy* e);
void enemyMovement(TEnemy* e);
void updateEnemies();
void updateEnemyByIndex(u8 i);
TEnemy* getEnemyByPosition(TPosition* p);
void initEnemyAnimation(TEnemy* e);
void initEnemies();
void allieInRange(TSensor* range, TPosition *pos);
void reliveMoreEnemies();
#endif
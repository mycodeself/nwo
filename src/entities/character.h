#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <cpctelera.h>
#include "entities.h"
#include "../sprites/sprites.h"
#include "../utils/utils.h"
#include "enemy.h"
#include "../game.h"

#define SCR_VMEM (u8*)0xC000

/*
* Struct que representa el personaje principal basado en una entidad
*/
typedef struct Character {
   TEntity entity;
   TAnimation* animation;
   u8* pvmem;
}TCharacter;

/*
* Personaje principal 
*/
extern const TCharacter character;

// public functions
TCharacter* getCharacter();
void updateCharacter(TCharacter* c);
void initCharacter();
void clearFrames(TCharacter* c);
#endif
#ifndef _ALLIES_H_
#define _ALLIES_H_


#include <cpctelera.h>
#include <stdio.h>
#include "entities.h"
#include "../map/map.h"
#include "../sprites/sprites.h"
#include "../utils/utils.h"
#define MAX_ALLIES 10

typedef enum {_alive, _dead} TAllieStatus;

typedef struct Allie {
   TPosition pos;
   TAllieStatus status;
}TAllie;

extern TAllie* const allies[MAX_ALLIES];

void pintaAliado(TAllie* allie);
void  mostrarAliados();
u8 alliesOnMap();
TAllie* getAllieByPosition(TPosition* p);
void resetAllies();

#endif
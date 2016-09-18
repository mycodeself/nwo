#ifndef _ENTITIES_H_
#define _ENTITIES_H_

#include <cpctelera.h>
#include "../utils/utils.h"
#include "../map/map.h"

/*
* Definición de los tipos de lugares hacia los cuales puede mirar una entidad
*/
typedef enum {left, right, up, down} TEntitySide;
typedef enum {dead, walk, attack} TEntityStatus;

typedef struct Position {
	u8 i;
	u8 j;
}TPosition;

typedef struct Frame {
	u8* sprite;
	u8	width, height;
}TFrame;

typedef struct Animation {
	TFrame** frames;
	u8 frame_idx;
}TAnimation;

/*
* Struct que representa cualquier entidad de juego
* Coordenadas x e y, además de las siguiente coordenadas en caso de movimiento
*/
typedef struct Entity {
   TPosition pos; // Coordenada actual de la entidad en posicion del array (i = y, j = x)
   TPosition npos; // Próxima coordenada de la entidad
   TEntitySide side; // Lugar hacia el cual esta mirando el entidad
   TEntitySide nside; // Lugar hacia el cual mirará la entidad
   TEntityStatus status;
}TEntity;

typedef struct Sensor {
	u8 i_min, i_max, j_min, j_max;
}TSensor;

// public functions
u8 detectCollisionAllie(TPosition* p);
u8 detectCollisionEntity(TEntity* e);
u8 inRange(TSensor* range, TPosition *position);
void drawSensor(TSensor* sensor);
void clearSensor(TSensor* sensor);
u8 entityInRange(TEntity* e, TSensor* sensor);
u8 getPositionsManhattanDistance(TPosition* p1, TPosition* p2);
void doNextMovement(TEntity* e);
void cancelNextMovement(TEntity* e);

#endif

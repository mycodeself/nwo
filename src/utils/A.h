#ifndef _A_H_
#define _A_H_

#include "../entities/entities.h"
#include "../entities/enemy.h"
#include <cpctelera.h>
#include "../utils/utils.h"
#include "../map/map.h"

typedef struct Nodo {
	TPosition position;
	u8 f,g,h;
	struct Nodo *padre;
	TEntitySide side;
}TNodo;

void quicksort(TNodo *nodos, i8 first, i8 last);
u8 manhattanDistance(TPosition* init, TPosition* finish);
void A(TEnemy *enemy, TPosition *finish);
void getChildrens(TNodo* hijos, i8 *n_nodos, TPosition *finish);

extern const TNodo temp;
extern const TPosition p1;
extern const TNodo colaFrontera[30];

#endif
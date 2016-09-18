#include "entities.h"

/*
* Copia los valores del siguiente movimiento a realizar en el movimiento actual
* Lo que es equivalente a realizar un movimiento
*/
void doNextMovement(TEntity* e){
	e->pos.i = e->npos.i;
	e->pos.j = e->npos.j;
	e->side = e->nside;
}
/*
* Copia los valores del movimiento actual en el siguiente movimiento
* Lo que es equivalente a cancelar un movimiento y quedarse stanby en la posición
* actual
*/
void cancelNextMovement(TEntity* e){
	e->npos.i = e->pos.i;
	e->npos.j = e->pos.j;
	e->nside = e->side;
}	



/*
* Funcion que detecta si en la posicion donde va a
* colocarse el aliado, hay una caja o no
*/
u8 detectCollisionAllie(TPosition* p){
   	if(map[p->i][p->j]==0){
      	return 0;
   	}
   	else{
   		return 1;
   	}
}


/*
* Función para detectar colisiones de entidades
* Si no se produce colisión devuelve 0
* Si se produce colisión devuelve 1
*/
u8 detectCollisionEntity(TEntity* e){
   	if(map[e->npos.i][e->npos.j]==0){
      	return 0;
   	}
   	if(map[e->npos.i][e->npos.j]==_allie){
   		return 2;
   	}
   	else{
   		return 1;
   	}
}
/*
* Dibuja el sensor pasado como parámetros
* Para testing
*/
void drawSensor(TSensor* sensor){
	u8* pvmem;
	u8 i, j;
	for(i=sensor->i_min;i<=sensor->i_max;i++){
		for(j=sensor->j_min;j<=sensor->j_max;j++){
			if(checkMapPosition(i,j)==0){
				pvmem = getScrPtrFromMapIndex(i, j);
				cpct_drawSolidBox(pvmem, palette[0], 4, 8);
			}
		}
	}
}

void clearSensor(TSensor* sensor){
	u8* pvmem;
	u8 i, j;
	for(i=sensor->i_min;i<=sensor->i_max;i++){
		for(j=sensor->j_min;j<=sensor->j_max;j++){
			if(checkMapPosition(i,j)==0){
				pvmem = getScrPtrFromMapIndex(i, j);
				cpct_drawTileAligned4x8_f(block, pvmem);
			}
		}
	}	
}

/*
* Comprueba si una entidad se encuentar en el rango de un sensor
* ambos pasados como parámetro, 1 si se encuentra en rango
* 0 en caso contarrio
*/
u8 entityInRange(TEntity* e, TSensor* sensor)
{
	if(sensor->j_min <= e->pos.j && e->pos.j <= sensor->j_max && sensor->i_min <= e->pos.i && e->pos.i <= sensor->i_max)
		return 1;
	else
		return 0;
}
/*
* Obtiene la distancia de manhattan a través de dos entidades
*/
/*u8 getPositionsManhattanDistance(TPosition* p1, TPosition* p2){
	i8 x, y;
	x = p1->i - p2->i;
	if(x<0) x*-1;
	y = p1->j - p2->j;
	if(y<0) y*-1;
	return x+y;
}*/

/*
* Comprueba si una posición esta en el rango de un sensor
* Devuelve 1 si esta en el rango 0 en caso contrario
*/
u8 inRange(TSensor *range, TPosition *position)
{
	if(range->j_min <= position->j && position->j <= range->j_max && range->i_min <= position->i && position->i <= range->i_max)
		return 1;
	else
		return 0;
}



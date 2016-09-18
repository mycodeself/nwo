#include "allies.h"

const TAllie allie0 = {{0 ,0}, _dead};
const TAllie allie1 = {{0 ,0}, _dead};
const TAllie allie2 = {{0 ,0}, _dead};
const TAllie allie3 = {{0 ,0}, _dead};
const TAllie allie4 = {{0 ,0}, _dead};
const TAllie allie5 = {{0 ,0}, _dead};
const TAllie allie6 = {{0 ,0}, _dead};
const TAllie allie7 = {{0 ,0}, _dead};
const TAllie allie8 = {{0 ,0}, _dead};
const TAllie allie9 = {{0 ,0}, _dead};


TAllie* const allies[10] = {
	&allie0, &allie1, &allie2, &allie3, &allie4, &allie5, &allie6, &allie7, &allie8, &allie9
};

/*
* Muestra los aliados y las armas de fomra random por el mapa
*/
void mostrarAliados()
{
	u8 i, alliesAppearOnMap;
	TAllie* alliesAux = allies[0];

	if(alliesOnMap()==0)	//Si los aliados que hay en el mapa son menor de los que deberian haber.
	{	
		alliesAppearOnMap=(mixedRandomGenerator()%5)+5;	//Numero aleatorio de aliados que aparecen en el mapa cuando los recogemos todos
		for (i=0; i < alliesAppearOnMap;i++)	//Cambiamos el estado de los aliados a _alive y los pintamos
		{
			alliesAux[i].status=_alive;
			pintaAliado(&alliesAux[i]);
		}
	}
}


/*
* Pinta el aliado en una posicion random
*/
void pintaAliado(TAllie* allie)
{
	u8* pvmem;
	allie->pos.i=(mixedRandomGenerator() % 22) + 1;
	allie->pos.j=(mixedRandomGenerator() % 18) + 1;

	while(detectCollisionAllie(&allie->pos)!=0)
	{
		allie->pos.i=(mixedRandomGenerator() % 22) + 1;
		allie->pos.j=(mixedRandomGenerator() % 18) + 1;
	};

	pvmem = getScrPtrFromMapIndex(allie->pos.i, allie->pos.j);
	changeMapPosition(allie->pos.i, allie->pos.j, _allie);
	cpct_drawSpriteMasked(Aliado, pvmem, 4, 8);	
}


/*
* Devuelve el numero de aliados que quedan en el mapa
*/
u8 alliesOnMap()
{
	u8 i;
	u8 cont=0;
	for(i=0;i<MAX_ALLIES;i++){
		if(allies[i]->status == _alive)
		{
			cont++;
		}
 	}
 	return cont;
}


/*
* Devuelve un aliado a partir de su posicion
*/
TAllie* getAllieByPosition(TPosition* p){
	u8 i;
	for(i=0;i<MAX_ALLIES;i++){
		if(allies[i]->pos.i == p->i && allies[i]->pos.j == p->j){
			return allies[i];
		}
	}
	return 0;
}


/*
* Resetea el status de todos los aliados a _dead
*/
void resetAllies()
{
	u8 i;
	for(i=0;i<MAX_ALLIES;i++)
	{
		allies[i]->status=_dead;
	}
}


#include "A.h"
const TNodo temp;
const TPosition p1;
const TNodo colaFrontera[30];

// rellena el array de nodos con los hijos del nodo actual, 
void getChildrens(TNodo* hijos, i8 *n_nodos, TPosition *finish)
{
	TPosition *p = &p1;
	// u8 *mvp;
	// Si las coordenadas i,j estan libres en el mapa y dentro del rango...
	// NO HACE FALTA HACER UN ARRAY DEL SENSOR COMPLETO PORQUE NUNCA SE VA A LLENAR

	
	p->i = hijos[0].position.i -1;
	p->j = hijos[0].position.j;
	if(map[p->i][p->j] != 9 && map[p->i][p->j] != _solidblock)
	{
		if(map[p->i][p->j] == _allie)
			changeMapPosition(p->i, p->j, 9);
		else
			changeMapPosition(p->i, p->j, _solidblock);
		
		hijos[(*n_nodos)].side = up;
		
		hijos[(*n_nodos)].position.i = p->i;
		hijos[(*n_nodos)].position.j = p->j;
		hijos[(*n_nodos)].g = hijos[0].g +1;
		hijos[(*n_nodos)].h = manhattanDistance(&hijos[(*n_nodos)].position, finish);
		hijos[(*n_nodos)].f = hijos[(*n_nodos)].g + hijos[(*n_nodos)].h;
		hijos[(*n_nodos)].padre = &hijos[0];
		
		(*n_nodos)++;
	}
	p->i = hijos[0].position.i +1;
	p->j = hijos[0].position.j;

	if(map[p->i][p->j] != 9 && map[p->i][p->j] != _solidblock)
	{
		if(map[p->i][p->j] == _allie)
			changeMapPosition(p->i, p->j, 9);
		else
			changeMapPosition(p->i, p->j, _solidblock);
		
		hijos[(*n_nodos)].side = down;
		
		hijos[(*n_nodos)].position.i = p->i;
		hijos[(*n_nodos)].position.j = p->j;
		hijos[(*n_nodos)].g = hijos[0].g +1;
		hijos[(*n_nodos)].h = manhattanDistance(&hijos[(*n_nodos)].position, finish);
		hijos[(*n_nodos)].f = hijos[(*n_nodos)].g + hijos[(*n_nodos)].h;
		hijos[(*n_nodos)].padre = &hijos[0];

			// mvp= getScrPtrFromMapIndex(p->i, p->j);
			// cpct_drawSolidBox(mvp, palette[1], 4, 8);
			
		(*n_nodos)++;
	}
	p->i = hijos[0].position.i;
	p->j = hijos[0].position.j-1;

	if(map[p->i][p->j] != 9 && map[p->i][p->j] != _solidblock)
	{
		if(map[p->i][p->j] == _allie)
			changeMapPosition(p->i, p->j, 9);
		else
			changeMapPosition(p->i, p->j, _solidblock);
		
		hijos[(*n_nodos)].side = left;
		
		hijos[(*n_nodos)].position.i = p->i;
		hijos[(*n_nodos)].position.j = p->j;
		hijos[(*n_nodos)].g = hijos[0].g +1;
		hijos[(*n_nodos)].h = manhattanDistance(&hijos[(*n_nodos)].position, finish);
		hijos[(*n_nodos)].f = hijos[(*n_nodos)].g + hijos[(*n_nodos)].h;
		hijos[(*n_nodos)].padre = &hijos[0];
			// mvp= getScrPtrFromMapIndex(p->i, p->j);
			// cpct_drawSolidBox(mvp, palette[1], 4, 8);

		(*n_nodos)++;
	}
	p->i = hijos[0].position.i;
	p->j = hijos[0].position.j+1;

	if(map[p->i][p->j] != 9 && map[p->i][p->j] != _solidblock)
	{
		if(map[p->i][p->j] == _allie)
			changeMapPosition(p->i, p->j, 9);
		else
			changeMapPosition(p->i, p->j, _solidblock);
		
		hijos[(*n_nodos)].side = right;
		
		hijos[(*n_nodos)].position.i = p->i;
		hijos[(*n_nodos)].position.j = p->j;
		hijos[(*n_nodos)].g = hijos[0].g +1;
		hijos[(*n_nodos)].h = manhattanDistance(&hijos[(*n_nodos)].position, finish);
		hijos[(*n_nodos)].f = hijos[(*n_nodos)].g + hijos[(*n_nodos)].h;
		hijos[(*n_nodos)].padre = &hijos[0];
			// mvp= getScrPtrFromMapIndex(p->i, p->j);
			// cpct_drawSolidBox(mvp, palette[1], 4, 8);

		(*n_nodos)++;
	}
}

u8 manhattanDistance(TPosition* init, TPosition* finish)
{
	i8 distanceJ, distanceI;
	distanceJ = init->j - finish->j;
	distanceI = init->i - finish->i;
	if(distanceJ < 0)
		distanceJ = distanceJ * -1;
	if(distanceI < 0)
		distanceI = distanceI * -1;
	return distanceJ + distanceI;
}

void quicksort(TNodo *nodos, i8 first, i8 last){
    u8 pivot,j,i;
    TNodo *p_temp = &temp;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(nodos[i].f <= nodos[pivot].f && i<last)
                 ++i;
             while(nodos[j].f > nodos[pivot].f)
                 --j;
             if(i<j){
                 //temp=nodos[i];
				 p_temp->position.i = nodos[i].position.i;
				 p_temp->position.j = nodos[i].position.j;
				 p_temp->f = nodos[i].f;
				 p_temp->g = nodos[i].g;
				 p_temp->h = nodos[i].h;
				 p_temp->padre = nodos[i].padre;
				 p_temp->side = nodos[i].side;
				 
                //nodos[i]=nodos[j];
				 nodos[i].position.i = nodos[j].position.i;
				 nodos[i].position.j = nodos[j].position.j;
				 nodos[i].f = nodos[j].f;
				 nodos[i].g = nodos[j].g;
				 nodos[i].h = nodos[j].h;
				 nodos[i].padre = nodos[j].padre;
				 nodos[i].side = nodos[j].side;
				 
				// nodos[j]=temp;
				 nodos[j].position.i = p_temp->position.i;
				 nodos[j].position.j = p_temp->position.j;
				 nodos[j].f = p_temp->f;
				 nodos[j].g = p_temp->g;
				 nodos[j].h = p_temp->h;
				 nodos[j].padre = p_temp->padre;
				 nodos[j].side = p_temp->side;
             }
         }

         // temp=nodos[pivot];
		 p_temp->position.i = nodos[pivot].position.i;
		 p_temp->position.j = nodos[pivot].position.j;
		 p_temp->f = nodos[pivot].f;
		 p_temp->g = nodos[pivot].g;
		 p_temp->h = nodos[pivot].h;
		 p_temp->padre = nodos[pivot].padre;
		 p_temp->side = nodos[pivot].side;
		 
         //nodos[pivot]=nodos[j];
		 nodos[pivot].position.i = nodos[j].position.i;
		 nodos[pivot].position.j = nodos[j].position.j;
		 nodos[pivot].f = nodos[j].f;
		 nodos[pivot].g = nodos[j].g;
		 nodos[pivot].h = nodos[j].h;
		 nodos[pivot].padre = nodos[j].padre;
		 nodos[pivot].side = nodos[j].side;
		 
         // nodos[j]=temp;
		 nodos[j].position.i = p_temp->position.i;
		 nodos[j].position.j = p_temp->position.j;
		 nodos[j].f = p_temp->f;
		 nodos[j].g = p_temp->g;
		 nodos[j].h = p_temp->h;
		 nodos[j].padre = p_temp->padre;
		 nodos[j].side = p_temp->side;
		 
         quicksort(nodos,first,j-1);
         quicksort(nodos,j+1,last);

    }
}

void A(TEnemy *enemy, TPosition *finish)
{
	TNodo *n;
	u8 cuentaNodos, cuentaNodosAux;
	//	u8* mvp;
	u8 x;
	i8 n_nodosFrontera, cont;
	TNodo *nodoAux;
	n = &colaFrontera[0];

	// n = &colaFrontera[0];
	n->position.i = enemy->entity.pos.i;
	n->position.j = enemy->entity.pos.j;
	n->h = manhattanDistance(&n->position, finish);
	n->g = 0;
	n->f = n->g + n->h;
	
	
	n_nodosFrontera = 1;
	//n_nodosInterior = 0;
	cont = 1;
	cuentaNodos = 1;
	
	// Reseteamos los movimientos pendientes
	enemy->nextMoves[0] = 99;
	enemy->nextMoves[1] = 99;
	enemy->nextMoves[2] = 99;
	enemy->nextMoves[3] = 99;

	// mvp= getScrPtrFromMapIndex(finish->i, finish->j);
	// cpct_drawSolidBox(mvp, palette[1], 4, 8);
	
	while(n_nodosFrontera > 0 && cont<10)
	{
			// mvp= getScrPtrFromMapIndex(n->position.i, n->position.j);
			// cpct_drawSolidBox(mvp, palette[1], 4, 8);
		
		cont+=1;
			
		if(n->position.i == finish->i && n->position.j == finish->j)
		{
			n_nodosFrontera = 0;	
		}
		else
		{
			cuentaNodosAux = n_nodosFrontera;
			getChildrens(n, &n_nodosFrontera, finish);
			cuentaNodos += n_nodosFrontera - cuentaNodosAux;
			if(n_nodosFrontera > 1)
				n++;
			
			n_nodosFrontera--;
			quicksort(n, 0, n_nodosFrontera-1);
			// Si el array de nodos esta llenandose salimos del bucle
			if(cuentaNodos >= 28)
				n_nodosFrontera=0;
		}
	}
	
	nodoAux = n;
	// Inicializo a -1 para el bucle de memorizacion funcione correctamente
	cont = -1;
	while(!(nodoAux->padre->position.i == enemy->entity.pos.i && nodoAux->padre->position.j == enemy->entity.pos.j))
	{
		nodoAux = nodoAux->padre;
		cont++;
	}
	// Asignamos movimiento segun el camino
	enemy->entity.npos.i = nodoAux->position.i;
	enemy->entity.npos.j = nodoAux->position.j;
	// Asignamos orientacion del personaje al realizar el movimiento
	enemy->entity.nside = nodoAux->side;
	
	// Bucle para memorizar 4 posicionas adicionales del camino
	nodoAux = n;
	while(!(nodoAux->position.i == enemy->entity.npos.i && nodoAux->position.j == enemy->entity.npos.j))
	{
		if(cont < 4)
		{
			enemy->nextMoves[cont] = nodoAux->side;
		}
		--cont;
		nodoAux = nodoAux->padre;
	}
	
	n = &colaFrontera[0];
	for(x=0; x<cuentaNodos; x++)
	{
		if(map[n[x].position.i][n[x].position.j] == 9)
			changeMapPosition(n[x].position.i, n[x].position.j, _allie);
		else
			changeMapPosition(n[x].position.i, n[x].position.j, _empty);
	}
}
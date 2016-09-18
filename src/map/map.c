#include "map.h"

const u8 map[MAP_SIZE_H][MAP_SIZE_W] = {
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9},
	{9,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,9},
	{9,0,1,1,0,1,1,0,1,1,1,1,0,1,1,0,1,1,0,9},
	{9,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,9},
	{9,0,0,0,1,0,1,1,0,1,0,0,0,0,0,0,0,0,1,9},
	{9,0,1,1,1,0,0,0,0,1,0,1,0,1,1,1,0,0,0,9},
	{9,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,0,1,0,9},
	{9,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,0,9},
	{9,0,1,0,0,0,0,0,0,0,1,1,1,0,1,1,0,1,0,9},
	{9,0,1,1,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,9},
	{9,0,1,0,0,0,1,0,1,1,1,0,1,1,0,0,0,1,0,9},
	{9,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,0,9},
	{9,0,1,1,1,0,0,0,1,0,0,0,1,0,1,1,0,0,1,9},
	{9,0,0,0,0,0,1,1,1,0,1,0,1,0,0,1,1,0,0,9},
	{9,1,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,9},
	{9,0,1,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,9},
	{9,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0,0,9},
	{9,0,1,0,1,1,0,1,1,0,0,0,1,1,0,0,0,1,0,9},
	{9,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,9},
	{9,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,0,0,0,9},
	{9,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,9},
	{9,0,1,1,0,1,1,0,1,0,1,0,1,1,0,1,1,1,0,9},
	{9,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,9},
	{9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
};

const u8 MAX_MAP_INDEX_I = MAP_SIZE_H-2;
const u8 MIN_MAP_INDEX_I = 1;
const u8 MAX_MAP_INDEX_J = MAP_SIZE_W-2;
const u8 MIN_MAP_INDEX_J = 1;

void initMap(){
   u8 *m = getMap();
   u16 i;
   for(i=0;i<MAP_MAX_ARRAY;i++){
      if(m[i]!=9 && m[i]!=1 && m[i]!=0){
         m[i] = 0;
      }
   }
}

/*
* Pinta el mapa basandose en la matriz que lo representa
*/
void drawMap() {
   u8 i, j;
   u8* pvmem;

   for(i=0;i<24;i++){
      for(j=0;j<20;j++){
         pvmem = getScrPtrFromMapIndex(i, j);
         switch(map[i][j]){
            case 1: cpct_drawTileAligned4x8_f(solidblock, pvmem); break;
            case 9: cpct_drawTileAligned4x8_f(border, pvmem); break;
            default: cpct_drawTileAligned4x8_f(block, pvmem); break;
         }
      }
   }
}

/*
* Devuelve un puntero a la matriz del mapa para trabjar con el
* como si de un array se tratara
*/
u8* getMap(){
   return &map;
}
/*
* Cambia el valor de una posición del mapa pasada como parametro
* Calcular posición de la matriz en el array (row * NUMCOLS) + column
*/
void changeMapPosition(u8 i, u8 j, TMapEntity value){
   u8* m = getMap();
   m[(i*MAP_SIZE_W)+j] = value;
}
/*
* Devuelve TRUE si en la posición recibida hay un muro o borde
* Devuelve FALSE en caso contrario
*/
u8 isWallOrBorder(u8 i, u8 j){
   if(map[i][j]==1 || map[i][j]==9)
      return 1;
   else
      return 0;
}

/*
* Devuelve una posición del mapa
*/
u8 checkMapPosition(u8 i, u8 j){
   return map[i][j];
}

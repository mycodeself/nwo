#ifndef _MAP_H_
#define _MAP_H_

#include <cpctelera.h>
#include "../sprites/sprites.h"
#include "../utils/utils.h"
#define MAP_SIZE_H 24
#define MAP_SIZE_W 20
#define SCR_VMEM (u8*)0xC000
#define MAP_MAX_ARRAY 480

extern const u8 MAX_MAP_INDEX_I;
extern const u8 MIN_MAP_INDEX_I;
extern const u8 MAX_MAP_INDEX_J;
extern const u8 MIN_MAP_INDEX_J;
/*
* Map[24][20] = 480 bytes 192x80 bytes
* Espacio habil real 22x18 = 176x72px
* 0=Empty; 1=solidblock; 2=character; 3=enemy; 9=border;
*/
extern const u8 map[MAP_SIZE_H][MAP_SIZE_W];
typedef enum {_empty, _solidblock, _character, _enemy, _allie}TMapEntity;
// public functions
void initMap();
void drawMap();
u8* getMap();
void changeMapPosition(u8 i, u8 j, TMapEntity value);
u8 checkMapPosition(u8 i, u8 j);
u8 isWallOrBorder(u8 i, u8 j);
#endif
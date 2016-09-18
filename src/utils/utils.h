#ifndef _UTILS_H_
#define _UTILS_H_
#include <cpctelera.h>
#define SCR_VMEM (u8*)0xC000


void initializeRandomGenerators(u8 num);
u8 mixedRandomGenerator();
u8* getScrPtrFromMapIndex(u8 i, u8 j);
void waitNVSYNCs(u8 n);  

#endif
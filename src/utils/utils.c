#include "utils.h"
/*
* Obtiene el puntero a la posición de la memoria de video 
* para pintar en las coordenadas pasadas como parametro
* correspondientes a los índices del array
*/
u8* getScrPtrFromMapIndex(u8 i, u8 j){
   return cpct_getScreenPtr(SCR_VMEM, j*4, (i+1)*8);
}

// Wait for n VSYNCs
//
void waitNVSYNCs(u8 n) {
   do {
      cpct_waitVSYNC();
      if (--n) {
         __asm__ ("halt");
         __asm__ ("halt");
      }
   } while (n);
}

u8 mixedRandomGenerator()
{
	return cpct_getRandomUniform_u8_f( cpct_getRandomu8_glfsr16());
}


void initializeRandomGenerators(u8 num) {
   cpct_setRandomSeedUniform_u8(0x55);
   cpct_setSeed_glfsr16(num);
   cpct_setTaps_glfsr16(GLFSR16_TAPSET_0512);
}



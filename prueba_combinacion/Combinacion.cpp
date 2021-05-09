#include "Combinacion.h"
void Combinacion::incrementaComb(int* comb,int valorPos, int pos){
   valorPos=valorPos+1;
    if(valorPos==16){
      valorPos=0;
      //incrementaComb(comb[pos-1],pos-1);
    }
    comb[pos]=valorPos;
    ///holahola
}
void Combinacion::incrementaCombprueba(int* comb,int valorPos, int pos){
   DEBUG_PRINT(0xA2);
   incrementaComb(comb,valorPos,pos);
}

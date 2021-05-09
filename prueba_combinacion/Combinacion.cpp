#include "Combinacion.h"
void Combinacion::incrementaComb(int* comb,int valorPos, int pos){
   valorPos=valorPos+1;
    if(valorPos==16){
      valorPos=0;
      incrementaComb(comb,comb[pos-1],pos-1);
    }
    comb[pos]=valorPos;
    ///holahola
}
byte Combinacion::generarByte(int valor1, int valor2){
  char aux1=cambiarHex(valor1);
  char aux2=cambiarHex(valor2);
  char textoaux[]="A2";
  textoaux[0]=aux1;
  textoaux[1]=aux2;
  unsigned long auxDevolver = strtoul(textoaux, NULL, HEX);
  return auxDevolver;
}
char Combinacion::cambiarHex(int valor){
  char devolver;
      switch(valor){
        case 0:
          devolver='0';
        break;
        case 1:
          devolver='1';
        break;
        case 2:
          devolver='2';
        break;
        case 3:
          devolver='3';
        break;
        case 4:
          devolver='4';
        break;
        case 5:
          devolver='5';
        break;
        case 6:
          devolver='6';
        break;
        case 7:
          devolver='7';
        break;
        case 8:
          devolver='8';
        break;
        case 9:
          devolver='9';
        break;
        case 10:
          devolver='A';
        break;
        case 11:
          devolver='B';
        break;
        case 12:
          devolver='C';
        break;
        case 13:
          devolver='D';
        break;
        case 14:
          devolver='E';
        break;
        case 15:
          devolver='F';
        break;
    }
  return devolver;
}

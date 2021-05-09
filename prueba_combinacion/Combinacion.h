#include "Arduino.h"
/*#define DEBUG_PRINTER Serial 
#define DEBUG_PRINT(...)        \{ DEBUG_PRINTER.print(__VA_ARGS__); }*/
class Combinacion{
  public:
  int combinacion[4];
  void incrementaComb(int* comb, int valorPos, int pos);
  void incrementaCombprueba(int* comb, int valorPos, int pos);
  char cambiarHex(int valor);
  byte generarByte(int byte1, int byte2);
};

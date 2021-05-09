#include "ComandoAT.h"
void ComandoAT::ComandoAT_LED(byte valor){
   Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x10);
  Serial.write(0x17);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFE);
  Serial.write(0x02);
  Serial.write('D');
  Serial.write('1');
  Serial.write(valor);
  long sum = 0x17 + 0xFF + 0xFF + 0xFF + 0xFE + 0x02 + 'D' + '1' + valor;
  Serial.write(0xFF-(sum & 0xFF)); 
}

#include "ComandoAT.h"
void ComandoAT::comandoAT_LED(byte valor){
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
void ComandoAT::comandoAT_CambiarIDR(byte valor1, byte valor2){
  Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x11);
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
  Serial.write('I');
  Serial.write('D');
  Serial.write(valor1);
  Serial.write(valor2);
  long sum = 0x17 + 0xFF + 0xFF + 0xFF + 0xFE + 0x02 + 'I' + 'D' + valor1 + valor2;
  Serial.write(0xFF-(sum & 0xFF)); 
}
void ComandoAT::comandoAT_CambiarIDC(byte valor1, byte valor2){
  Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x06);
  Serial.write(0x08);
  Serial.write(0x00);
  Serial.write('I');
  Serial.write('D');
  Serial.write(valor1);
  Serial.write(valor2);
  long sum = 0x17 + 'I' + 'D' + valor1 + valor2;
  Serial.write(0xFF-(sum & 0xFF)); 
}

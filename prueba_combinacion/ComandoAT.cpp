#include "ComandoAT.h"
void ComandoAT::comandoAT_LED(byte valor){
  Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x10);
  Serial.write(0x17);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x13);
  Serial.write(0xA2);
  Serial.write(0x00);
  Serial.write(0x41);
  Serial.write(0xC3);
  Serial.write(0x7F);
  Serial.write(0x17);
  Serial.write(0xFF);
  Serial.write(0xFE);
  Serial.write(0x02);
  Serial.write('D');
  Serial.write('1');
  Serial.write(valor);
  long sum = 0x17 + 0x13 + 0xA2 + 0x41 + 0xC3 + 0x7F + 0x17 + 0xFF + 0xFE + 0x02 + 'D' + '1' + valor;
  Serial.write(0xFF-(sum & 0xFF)); 
}
void ComandoAT::comandoAT_CambiarIDR(byte valor1, byte valor2){
  Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x11);
  Serial.write(0x17);
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0x13);
  Serial.write(0xA2);
  Serial.write(0x00);
  Serial.write(0x41);
  Serial.write(0xC3);
  Serial.write(0x7F);
  Serial.write(0x17);
  Serial.write(0xFF);
  Serial.write(0xFE);
  Serial.write(0x02);
  Serial.write('I');
  Serial.write('D');
  Serial.write(valor1);
  Serial.write(valor2);
  long sum = 0x17 + 0x13 + 0xA2 + 0x41 + 0xC3 + 0x7F + 0x17 + 0xFF + 0xFE + 0x02 + 'I' + 'D' + valor1 + valor2;
  Serial.write(0xFF-(sum & 0xFF)); 
}
void ComandoAT::comandoAT_CambiarIDC(byte valor1, byte valor2){
  //7E 00 06 08 01 49 44 12 A1 B6
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
  Serial.write(0x00);
  Serial.write(0x00);
  Serial.write(0xFF);
  Serial.write(0xFE);
  Serial.write(0x02);
  Serial.write('I');
  Serial.write('D');
  Serial.write(valor1);
  Serial.write(valor2);
  long sum = 0x17 + 0xFF + 0xFE + 0x02 + 'I' + 'D' + valor1 + valor2;
  //Serial.write(0xFF-(sum & 0xFF));
  Serial.write(0xFF-(sum & 0xFF)); 
}

void ComandoAT::comandoAT_PedirID(){
  //00 13 A2 00 41 C3 7F 17
  Serial.write(0x7E);
  Serial.write(0x00);
  Serial.write(0x0F);
  Serial.write(0x17);
  Serial.write(0x01);
  Serial.write(0x00);
  Serial.write(0x13);
  Serial.write(0xA2);
  Serial.write(0x00);
  Serial.write(0x41);
  Serial.write(0xC3);
  Serial.write(0x7F);
  Serial.write(0x17);
  Serial.write(0xFF);
  Serial.write(0xFE);
  Serial.write(0x02);
   Serial.write('I');
  Serial.write('D');
  long sum =  0x17 +0x01 + 0x13 + 0xA2 + 0x41 + 0xC3 + 0x7F + 0x17 + 0xFF + 0xFE + 0x02 + 'I' + 'D' ;
  Serial.write(0xFF-(sum & 0xFF));
}

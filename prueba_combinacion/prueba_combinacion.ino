#include "Combinacion.h"
#include "ComandoAT.h"
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  
}
//int combinacion[]={15,15,15,10};

void incrementaComb(int valorPos, int pos);
void cambiarHex();
void combHex();
void imprimirByte(byte byte1, byte byte2);

int combinacion[4];
Combinacion comb;
ComandoAT comando;
boolean cambiado;

void loop() {
  
  // put your main code here, to run repeatedly:
  //FALTA PROBAR 0000 PERO CREO QUE ESA NO VALE 
  
  //incrementaComb(combinacion[3],3);
  /*comb.incrementaComb(combinacion,combinacion[3],3);
  byte parte1Comb = comb.generarByte(combinacion[0],combinacion[1]);
  byte parte2Comb = comb.generarByte(combinacion[2],combinacion[3]);
  Serial.print(parte1Comb);
  Serial.print(" ");
  Serial.println(parte2Comb);
  //comando.comandoAT_LED(0x4);
  //Serial.write(parte2Comb);
  delay(2000);
  //combHex();*/
 //enviamos comando AT hay respuesta Serial.Avalible y Espera =false;
 //si 
 //cambiamos id router 
 //no
 //incrementamos id coordinador esperamos hasta que haya respuesta 

 /* byte apagaByte = comb.generarByte(0,4);
  byte enciendeByte = comb.generarByte(0,5);
  byte idPrueba1R = comb.generarByte(3,2);
  byte idPrueba2R = comb.generarByte(3,2);
  byte idPrueba1C = comb.generarByte(2,2);
  byte idPrueba2C = comb.generarByte(2,2);*/
  //generamos la combinacion en forma de bytes
  byte parte1Comb = comb.generarByte(combinacion[0],combinacion[1]);
  byte parte2Comb = comb.generarByte(combinacion[2],combinacion[3]);
  //pedimos informacion del router de la red
  comando.comandoAT_PedirID();
  delay(2000);
 
      //leemos los bytes del paquete hasta el que nos interesa.
    if(Serial.read()==0x7E){
    Serial.print("Combinacion: ");
    Serial.print(combinacion[0]);
    Serial.print(" ");
    Serial.print(combinacion[1]);
    Serial.print(" ");
    Serial.print(combinacion[2]);
    Serial.print(" ");
    Serial.print(combinacion[3]);
    Serial.println(" ");
    Serial.println(Serial.read(),HEX);
    byte tamano=Serial.read();
    Serial.println(tamano,HEX);
    while(Serial.available()){
        Serial.read();
    }
    //en este caso no existe recivimos error.
    if(cambiado){
      //descartamos el buffer de entrada para evitar fallos
      
      //actualizamos id del coordinador
      comando.comandoAT_CambiarIDC(parte1Comb,parte2Comb);
      //incrementamos id.
      
      comb.incrementaComb(combinacion,combinacion[3],3);
      cambiado=false;
    }else
    //recivimos respuesta por lo tanto el router existe.
    {
     if (tamano==0x17){
      Serial.println("HOLAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
      comando.comandoAT_LED(0x05);
      delay(2000);
      comando.comandoAT_LED(0x04);
      //modificamos ID del router
      comando.comandoAT_CambiarIDR(parte1Comb,parte2Comb);
      cambiado=true;
     }
      
      //para que se pueda monitorizar encendemos y apagamos led a forma de se??al
      /*
       
      comando.comandoAT_CambiarIDR(parte1Comb,parte2Comb);
      delay(2000);*/
    }
    }
   
  

   
  //ENCENDER Y APAGAR LED 
  
  
  
}
void combHex(){
  
  char textobyte1[]="A1";
  char textobyte2[]="A2";

  
  for(int i=0;i<4;i++){
 
    if(i<2){
        textobyte1[i%2]=(char)cambiarHex(combinacion[i]);
    }else{
        textobyte2[i%2]=(char)cambiarHex(combinacion[i]);
      }
  }
  unsigned long aux1 = strtoul(textobyte1, NULL, HEX);
  unsigned long aux2 = strtoul(textobyte2, NULL, HEX);

  imprimirByte(aux1,aux2);
}

char cambiarHex(int valor){
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
          devolver='4';//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
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

void incrementaComb(int valorPos, int pos)
{
  valorPos=valorPos+1;
  if(valorPos==16){
    valorPos=0;
    incrementaComb(combinacion[pos-1],pos-1);
  }
  combinacion[pos]=valorPos;
}

void imprimirByte(byte byte1, byte byte2){
  Serial.print(byte1);
  Serial.print(" ");
  Serial.println(byte2);
}

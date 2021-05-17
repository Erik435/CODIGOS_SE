 /* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Comunicación I2C configurar 1 maestro y 3 esclavos.  
 * OBJETIVO:Prender 3 les síncronos para cada esclavo mediante la pulsación de un caracter cualquiera para cada esclavo.
 * Nombre: Erik Flores
 * Fecha: 17/05/2021                      
 */
 //////////// ESCLAVO2 /////////
 #include <Wire.h>;           // libreria I2C
 char dat;                    // variable de almacenamiento de dato
 const int led7=8;            // led1 en pin8
 const int led8=9;            // led1 en pin9
 const int led9=10;           // led1 en pin10
  
void setup() {
  Wire.begin(1);              // ide esclavo
  Wire.onReceive(receiveEvent3);
  Serial.begin(9600);
  pinMode(led7,OUTPUT);       // pin8 como salida 
  pinMode(led8,OUTPUT);       // pin9 como salida 
  pinMode(led9,OUTPUT);       // pin10 como salida 
}

void loop() { 
}

void receiveEvent3(int bytes){
  while(Wire.available()){          //Mientras haya numero de byts disponibles.
    dat=Wire.read();
    while(dat=='c')
    {
      digitalWrite(led7,HIGH);       //Led 7 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led7,LOW);        //Led 7 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led8,HIGH);       //Led 8 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led8,LOW);        //Led 8 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led9,HIGH);       //Led 9 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led9,LOW);        //Led 9 se apaga
      delay(8000);                    //Tiempo de apagado
      dat=(' ');                  //Se da una condición en con cracter diferente en a para poder parar el ciclo.
    }
}
}

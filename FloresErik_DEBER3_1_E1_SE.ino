 /* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Comunicación I2C configurar 1 maestro y 3 esclavos.  
 * OBJETIVO:Prender 3 les síncronos para cada esclavo mediante la pulsación de un caracter cualquiera para cada esclavo.
 * Nombre: Erik Flores
 * Fecha: 17/05/2021                      
 */
 //////////// ESCLAVO1 /////////
 #include <Wire.h>;           // libreria I2C
 char dat;                    // variable de almacenamiento de dato
 const int led1=8;            // led1 en pin8
 const int led2=9;            // led1 en pin9
 const int led3=10;           // led1 en pin10
  
void setup() {
  Wire.begin(1);              // ide esclavo
  Wire.onReceive(receiveEvent1);
  Serial.begin(9600);
  pinMode(led1,OUTPUT);       // pin8 como salida 
  pinMode(led2,OUTPUT);       // pin9 como salida 
  pinMode(led3,OUTPUT);       // pin10 como salida 
}

void loop() { 
}

void receiveEvent1(int bytes){
  while(Wire.available()){           //Mientras haya numero de byts disponibles.
    dat=Wire.read();
    while(dat=='a')                  //Ciclo mientras se aplaste a se prenda los leds del primer esclavo.
    {
      digitalWrite(led1,HIGH);       //Led 1 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led1,LOW);        //Led 1 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led2,HIGH);       //Led 2 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led2,LOW);        //Led 2 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led3,HIGH);       //Led 3 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led3,LOW);        //Led 3 se apaga
      delay(8000);                    //Tiempo de apagado
      dat=(' ');                  //Se da una condición en con cracter diferente en a para poder parar el ciclo.
  }
}
}

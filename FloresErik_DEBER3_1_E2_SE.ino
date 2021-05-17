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
 const int led4=8;            // led1 en pin8
 const int led5=9;            // led1 en pin9
 const int led6=10;           // led1 en pin10
  
void setup() {
  Wire.begin(1);              // ide esclavo
  Wire.onReceive(receiveEvent2);
  Serial.begin(9600);
  pinMode(led4,OUTPUT);       // pin8 como salida 
  pinMode(led5,OUTPUT);       // pin9 como salida 
  pinMode(led6,OUTPUT);       // pin10 como salida 
}

void loop() { 
}

void receiveEvent2(int bytes){
  while(Wire.available()){           //Mientras haya numero de byts disponibles.
    dat=Wire.read();
    while(dat=='b') 
    {
      digitalWrite(led4,HIGH);       //Led 4 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led4,LOW);        //Led 4 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led5,HIGH);       //Led 5 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led5,LOW);        //Led 5 se apaga
      delay(8000);                   //Tiempo de apagado
      digitalWrite(led6,HIGH);       //Led 6 se prende
      delay(8000);                   //Determinación tiempo.
      digitalWrite(led6,LOW);        //Led 6 se apaga
      delay(8000);                    //Tiempo de apagado
      dat=(' ');                  //Se da una condición en con cracter diferente en a para poder parar el ciclo.
    }
}
}

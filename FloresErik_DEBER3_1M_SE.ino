/* 
 * CAPITULO III: MODULOS DE COMUNICACIÓN I2C.
 * CÓDIGO DEBER 3.1:Comunicación I2C configurar 1 maestro y 3 esclavos.  
 * OBJETIVO:Prender 3 les síncronos para cada esclavo mediante la pulsación de un caracter cualquiera para cada esclavo.
 * Nombre: Erik Flores
 * Fecha: 17/05/2021                      
 */
 ///////////////////////////////MASTER////////////////////////////////
 #include <Wire.h>
 char dat;                     //Variable de incremento de dato.
void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("DEBER 3.1--Erik Flores");
  Serial.println("Indicaciones  Activacion de Leds:");
  Serial.println("a=Activacion del primer esclavo");
  Serial.println("b=Activacion del segundo esclavo");
  Serial.println("c=Activacion de tercer esclavo");
  }

void loop() {
  if(Serial.available()>0){    //Condicion de bytes disponibles.
    dat=Serial.read();         //Lee o alamecena el dato en la variable
    Serial.println();          //Visualización de caracter y salto
    Wire.beginTransmission(1); //Empieza la transmision con la id establecisa.
    Wire.write(dat);           //Envio del dato a los esclavos
    Wire.endTransmission();    //Finaliza la Comunicación.
  }
}

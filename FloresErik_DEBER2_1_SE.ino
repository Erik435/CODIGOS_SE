/*
 * Capitulo II: PUERTOS DIGITALES
 * CODIGO 1: Manejo de puertos configurados como salidas.
 * OBJETIVO: Encender y apagar Leds mediante el uso de diferentes tipos de variables.
 * NOMBRE: Flores Erik.
 */

 //Variables
 #define led1 8 //Uso de define, variable que no se puede alterar, no existe una depuracion de error.
 int led2= 9; // Variable normal.
 const int led3= 10; //Variable contante.
 const int led4= 11; //Variable contante.
 
void setup() {
pinMode(led1,OUTPUT);//Declaro el pin 8 como primer salida. 
pinMode(led2,OUTPUT);//Declaro el pin 9 como segunda salida.
pinMode(led3,OUTPUT);//Declaro el pin 10 como tercer salida.
pinMode(led4,OUTPUT);//Declaro el pin 11 como cuarta salida.
}

void loop() {
digitalWrite(led1,HIGH);//Envia 5v al pin 8.
delay(500);             //Se detiene el microcontrolador al tiempo especificado.
digitalWrite(led1,LOW); //Envia 0v al pin 8.
delay(500);             //Se detiene el microcontrolador.

digitalWrite(led2,HIGH);//Envia 5v al pin 8.
delay(500);             //Se detiene el microcontrolador al tiempo especificado.
digitalWrite(led2,LOW); //Envia 0v al pin 8.
delay(500);             //Se detiene el microcontrolador.

digitalWrite(led3,HIGH);//Envia 5v al pin 8.
delay(500);             //Se detiene el microcontrolador al tiempo especificado.
digitalWrite(led3,LOW); //Envia 0v al pin 8.
delay(500);             //Se detiene el microcontrolador.

digitalWrite(led4,HIGH);//Envia 5v al pin 8.
delay(500);             //Se detiene el microcontrolador al tiempo especificado.
digitalWrite(led4,LOW); //Envia 0v al pin 8.
delay(500);             //Se detiene el microcontrolador.


}

/* 
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.1:CAD Y PWM   
 * OBJETIVO: Realizar lecturas de conversor analogo digital para determinar la velocidad de dos motor en DC, mediante una LCD para cada motor.
 * Nombre: Erik Flores
 * Fecha: 17/05/2021   
 * 
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,5,4,3,2);      //Seleccion de pines para LCD número 1.
const int btn=A4;                      // Creacion de la variables
int conversor;                         //Variable para adquirir datos del conversor entre 0-1023.
float voltaje;                         //Variable de conversion de conversor a voltaje.
int  dutty;
LiquidCrystal lcd1(A2,A3,9,8,7,6);      //Seleccion de pines para LCD número 2.
const int SW=A5;                        //Creacion del boton para acativar la segunda pantalla con información.
int conversor1;                         //Variable para adquirir datos del conversor entre 0-1023.
float voltaje1;                         //Variable de conversion de conversor a voltaje.
int  dutty1;                            
 
void setup() {
  lcd.begin(16,2);                      //Inicializa la LCD número 1.
  lcd1.begin(16,2);                     //Inicializa la LCD número 2.
  pinMode(btn,INPUT);                   //Define al boton como entrada de la primer LCD.
  pinMode(SW,INPUT);                    //Define el switch como entrada en la segunda LCD

}

void loop() {
  if(digitalRead(btn)==LOW)
  {
      conversor=analogRead(A1);             //Lectura del canal A1
      voltaje=(conversor*5.0)/1023.0;       //Conversor de voltaje.
      dutty=conversor/4;                    //Cambio la escala para el dutty cicle.
      analogWrite(11,dutty);                //Envio de valor al pin 11.
      lcd.setCursor(0,0);                   //Se da la ubicación para el mensaje.
      lcd.print("CAD: " );                  //Se imprime en dicha posición.
      lcd.setCursor(5,0);                   //Se da la ubicación para el mensaje.
      lcd.print(conversor);                 //Se imprime en dicha posición.
      lcd.setCursor(0,1);                   //Se da la ubicación para el mensaje.
      lcd.print("V: ");                     //Se imprime en dicha posición.
      lcd.setCursor(3,1);                   //Se da la ubicación para el mensaje.
      lcd.print(voltaje);                   //Se imprime en dicha posición.
      lcd.setCursor(9,1);                   //Se da la ubicación para el mensaje.
      lcd.print("PWM: ");                    //Se imprime en dicha posición.
      lcd.setCursor(13,1);                  //Se da la ubicación para el mensaje.
      lcd.print((dutty*100)/255);           //Se imprime en dicha posición.
      delay(300);
      lcd1.clear();
  }else{
    lcd1.clear();
  }
//Segundo control mediante Switch
  if(digitalRead(SW)==HIGH)
  {
      conversor1=analogRead(A0);              //Lectura del canal A0 del switch
      voltaje1=(conversor1*5.0)/1023.0;       //Conversor de voltaje.
      dutty1=conversor1/4;                    //Cambio la escala para el dutty cicle del Switch.
      analogWrite(10,dutty1);                 //Envio de valor al pin 10.
      lcd1.setCursor(0,0);                    //Se da la ubicación para el mensaje.
      lcd1.print("CAD: " );                   //Se imprime en dicha posición.
      lcd1.setCursor(5,0);                    //Se da la ubicación para el mensaje.
      lcd1.print(conversor1);                 //Se imprime en dicha posición.
      lcd1.setCursor(0,1);                    //Se da la ubicación para el mensaje.
      lcd1.print("V: ");                      //Se imprime en dicha posición.
      lcd1.setCursor(3,1);                    //Se da la ubicación para el mensaje.
      lcd1.print(voltaje1);                   //Se imprime en dicha posición.
      lcd1.setCursor(9,1);                    //Se da la ubicación para el mensaje.
      lcd1.print("PWM: ");                    //Se imprime en dicha posición.
      lcd1.setCursor(13,1);                   //Se da la ubicación para el mensaje.
      lcd1.print((dutty1*100)/255);          //Se imprime en dicha posición.
      delay(300);
      lcd1.clear();
  }
}

/*
 * CAPITULO IV: PERIFÉRICOS ESPECIALES
 * CÓDIGO 18: Uso del TIMER 2.
 * OBJETIVO: Reloj con TIMER 2.
 * Nombre: Erik Flores.
 * Funciones: 
 *            MsTimer2::set(1000,flash); //1s
 *            MsTimer2::start();
 *            MsTimer2::stop();
  */
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);        //Definir las variables de la LCD;
int segundos=0;                             //Variable de s
int minutos=0;                              //Varibale de m
int horas=0;                                //Varibale de h
void setup() {
  lcd.begin(20,4);                          //Inicializa la LCD.
  MsTimer2::set(10,reloj);
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void reloj()
{
  if(segundos<60)                         //Condicion de segundos
  {
    segundos++;                           //Incremento de variable
  }else{
    segundos=0;
    if(minutos<60)                        //Condicion de minutos
    {
      minutos++;                          //Incremento de variable
    }else{
      minutos=0;
      if(horas<24)                       //Condicion de horas
      {
        horas++;                          //Incremento de variable            
      }else{
        horas=0;
      }
    }
  }
  lcd.clear();                            //Borra el anterior mensaje.
  lcd.setCursor(0,0);                     //Ubicacion en la LCD
  lcd.print("SISTEMAS EMBEBIDOS");        //Mensaje en la LCD
  lcd.setCursor(0,1);                     //Ubicacion en la LCD
  lcd.print("FLORES ERIK");               //Mensaje en la LCD
  lcd.setCursor(0,2);                     //Ubicacion en la LCD
  lcd.print("HORAS");                     //Mensaje en la LCD
  lcd.setCursor(6,2);                     //Ubicacion en la LCD   
  lcd.print("MINUTO");                    //Mensaje en la LCD
  lcd.setCursor(13,2);                    //Ubicacion en la LCD 
  lcd.print("SEGUNDO");                   //Mensaje en la LCD
  lcd.setCursor(3,3);                     //Ubicacion en la LCD  
  lcd.print(horas);                       //Mensaje en la LCD
  lcd.setCursor(5,3);                     //Ubicacion en la LCD  
  lcd.print(":");                         //Mensaje en la LCD
  lcd.setCursor(9,3);                     //Ubicacion en la LCD  
  lcd.print(minutos);                     //Mensaje en la LCD
  lcd.setCursor(12,3);                    //Ubicacion en la LCD   
  lcd.print(":");                         //Mensaje en la LCD
  lcd.setCursor(15,3);                    //Ubicacion en la LCD   
  lcd.print(segundos);

}

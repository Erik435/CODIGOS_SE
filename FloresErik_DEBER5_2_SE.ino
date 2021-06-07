/*
 * UNIDAD V: FUNCIONES ESPECÍFICAS
 * DEBER 5.2: MANEJO DE MODOS SLEEP
 * OBJETIVO: realizar sin control de modos sleeps por medio de interrupciones
 * Modo sleep y consumo de batería
 * Nombre: Erik Flores Morale
 * Consumo de 100-500mA
 * Ahorro de bateria es hasta 10mA
 * Librerias:         avr/sleep.h
 *                    avr/power.h
 */
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include<EEPROM.h>
int dato;                             //Creacion de variable
int on=0;                             //Creacion de variable para la interrupcion

void(* resetFunc) (void) = 0;          //Funcion de reseteo de otra funcion//void on(void);


void setup() {
   dato=EEPROM.read(0);                //Lectura de la eeprom en 0
   Serial.begin(9600);                 //Inicializa la comunicacion serial
   Serial.println("INICIO");            //Impresion de mensaje de inicio
   if(dato==0){                        //Condicional del dato en la posicion 0 de la EEPROM
    set_sleep_mode(SLEEP_MODE_STANDBY);//Modo de Sleep a trabajar
    sleep_enable();                    //Hbilito el modo
    EEPROM.write(0,1);                 //Escribo en la memoria en la posicion
    wdt_enable(WDTO_8S);               //Habilita el wdt en 8s.
    }
    else{                              //Caso contrario
    sleep_disable();                   //Deshabilita el modo sleep
     EEPROM.write(0,0);                //Escribo en la memoria ahora 0
      MsTimer2::set(10000,tiempo);     //Configura timer 2 a un segundo
       MsTimer2::start();              //Inicializa en timer2
    }
   attachInterrupt(0,encender,LOW);    //Se inicializa la interrupcion, en este caso cuando cambie a bajo
}


void loop() {
if(dato==0){                           //Condicion para el dato
  Serial.println("DORMIDO");           //Se imprime el estado
  delay(20);                           //Se define el tiempo de retardo               
 sleep_mode();                         //Se activa el sleep mode.
}
 else{                                 //Caso contrario
  Serial.println("DESPIERTO");         //Se imprime el estado
  delay(1000);                         //Se define el tiempo de retardo
  }
}

void tiempo(){                        //Metodo de tiempo
  Serial.println("DORMIDO");          //Se imprime el estado
  delay(2000);                        //Se define el tiempo de retardo
  sleep_mode();                       //Se activa el sleep mode.
 }
 
 void encender (){                    //Metodo de encender
    resetFunc();                      //Llamo a motodo reseteo de la función 
 }

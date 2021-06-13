/*
 * DEBER 5.4: FUNCIONES ESPECÍFICAS
 * Creación de funciones en RTOS
 * OBJETIVO: Realizar el funcionamiento de un semáforo basados en las funciones y tareas de RTOS.
 *NOMBRE: Erik Flores
 */
 #include <FreeRTOSConfig.h>
 #include <Arduino_FreeRTOS.h> //Se llama la libreria de RTOS.
 const int verde = 8;          //Se define el pin del led verde.
 const int amarillo = 7;       //Se define el pin del led amarillo.
 const int rojo = 6;            //Se define el pin del  led rojo.
 #define configMAX_PRIORITIES 3;
 typedef int TaskProfiler;      //Se crea el objeto del gestor de tareas
 TaskProfiler verdeLEDProfiler;     //Definicion de tarea para led verde
 TaskProfiler amarilloLEDProfiler;  //Definicion de tarea para led amarilo
 TaskProfiler rojoLEDProfiler;      //Definicion de tarea para led rojo.
 TaskHandle_t verde_Handle,amarillo_Handle,rojo_Handle;
 int cont=0;
 
void setup() {
  //CREACION DE RUTINAS PARA CADA TAREA.
  xTaskCreate(verdeLEDControllerTask,"CIRCULAR",100,NULL,1,&verde_Handle);         //Se crea la rutina para la tarea del red verde con sus respectivos parámetros.
  xTaskCreate(amarilloLEDControllerTask,"PRECUACION",100,NULL,1,&amarillo_Handle);  //Se crea la rutina para la tarea del amarillo verde con sus respectivos parámetros.
  xTaskCreate(rojoLEDControllerTask,"ALTO",100,NULL,1,&rojo_Handle);               //Se crea la rutina para la tarea del red rojo con sus respectivos parámetros.
}

//Creacion de métodos para las rutinas.
void verdeLEDControllerTask(void *pvParameters){        //Creacion del metodo para la primer tarea
  pinMode(verde,OUTPUT);                                //Se define como trabaja el led verde
  while(1){                                             //Ciclo para led verde
    verdeLEDProfiler++;                                 //Aumento de la variable
    digitalWrite(verde,digitalRead(verde)^1);           //Escritura del valorr obtenido encendido o apagado.                                    
    vTaskDelay(1000);
    cont++; 
    if(cont==10){                                       //Condición a los 10 segundos   
    vTaskSuspend(amarillo_Handle);                      //suspendo el amarillo
    vTaskSuspend(rojo_Handle);                          //Suspendoel rojo
    }
  }
}

void amarilloLEDControllerTask(void *pvParameters){      //Creacion del metodo para la segunda tarea
  pinMode(amarillo,OUTPUT);                              //Se define como trabaja el led amarillo
  while(1){                                              //Ciclo para led verde
    amarilloLEDProfiler++;                               //Aumento de la variable
    digitalWrite(amarillo,digitalRead(amarillo)^1);      //Escritura del valorr obtenido encendido o apagado.
    vTaskDelay(500);
    cont++; 
    if(cont==20){                                        //Condicion a los 20 segundos  
    vTaskSuspend(verde_Handle);                          //Suspendo el verde
    vTaskSuspend(rojo_Handle);                           //Suspendo el rojo
    }
  }
}

void rojoLEDControllerTask(void *pvParameters){          //Creacion del metodo para la tercer tarea
  pinMode(rojo,OUTPUT);                                  //Se define como trabaja el led rojo
  while(1){                                              //Ciclo para led verde
    rojoLEDProfiler++;                                   //Aumento de la variable 
    digitalWrite(rojo,digitalRead(rojo)^1);              //Escritura del valorr obtenido encendido o apagado.
    vTaskDelay(750);                                     //Se define el tiempo para parar. 
    cont++; 
    if(cont==25){                                        //Condición de tiempo a los 25 segundos    
    vTaskSuspend(verde_Handle);                          //Suspendo el led verde
    vTaskSuspend(amarillo_Handle);                       //Suspendo el led rojo 
    if(cont=32){
    cont=0;
    }
    }        
  }
}
void loop() {
}

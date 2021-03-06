/* DEBER4.2: PERIFÉRICOS ESPECIALES-IINTERRUPCIONES
 * CÓDIGO : Manejo de interrupciones.
 * OBJETIVO: Activacion de juegos de leds por medio de una interrupcion del numero de veces a jugar con la interrupciones 1 .
 * Nombre: Erik Flores.
 * Funciones: interrupt 0:Inicio del sistema e ingreso de veces de juego.
  */
   const int leds[6]={13,12,11,10,9,8};
  int on;                             //Interrupcion 0
  int cont;                             //int 1.
  int i;                                //Variable de conteo.
  int j=0;                              //Variable de conteo
void setup() {
  for(i=0;i<6;i++)                      //Configuración de leds.
  {
    pinMode(leds[i], OUTPUT);           //Como salida
  }
  i=0;
  Serial.begin(9600);                   //Inicializacion de C.S
  attachInterrupt(0,activacion,LOW);    //Activacion 0 se habilita
  attachInterrupt(1,contador,LOW);   //Activacion 1 se habilita
  Serial.println("Flores Erik Deber-Presione IN para iniciar");
}

void loop() {       
  if(on==2)                           //Si la variable de inicializacion es a 2:
  {
    for(;i<cont;i++)                  //Realiza el recorrido para las veces que se quiere prender el led
    {
      for(j=0;j<6;j++)                //Recorrido para los leds 
      {
        digitalWrite(leds[j],HIGH);   //Se prende un led
        delay(200);                   //Tiempo activo
        digitalWrite(leds[j],LOW);    //Se desactiva el led
        delay(200);                   //Tiempo programado
      }
    }
  }
}
void activacion(){
  switch(on)                            //Opciones de los botones a definir
  {
    case 0:                             //Caso de inicio
    Serial.println("Inicio del Sistema: ");
    Serial.println("Ingrese el numero de veces que desee jugar");
    on++;
    break;                             //Caso al que entra al juego de leds
    case 1:
    Serial.println("Inicio de Juego"); //Se imprime lo que se esta ejecutando
    on++;
    break;
    case 2:                            //Caso final
    Serial.println("Juego finalizado");//Mensaje de finalización
    //Se reinicia las variables de nuevo con el sistema
    cont=0;
    on=0;
    i=0;
    break;
  }
}
void contador(){      //Metodo para mostrar las veces que se puede jugar
  if(on==1)
  {
    cont++;           //El conteo de veces de juego
    Serial.println(String("Juega ")+String(cont)+String(" veces")); //Se imprime el mensaje con el numero de veces a jugar.
  }
}  

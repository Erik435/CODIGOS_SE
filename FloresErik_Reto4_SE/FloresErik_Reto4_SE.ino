/*
 * DEBER 6.1: Retos Proseccing
 * Resolución de reto 4
 * OBJETIVO: Aplicar los conocimientos acerca de Processing y la interfaz gráfica.
 *NOMBRE: Erik Flores
 */ 
 const int led =3;
void setup() {
  Serial.begin(9600);       //Inicializacion de la comunicacion serial.
  pinMode(led,OUTPUT);
  }
void loop() {
  if(Serial.available()){     //Se verifica que haya indormacion
    char letra=Serial.read(); //Se lee el dato de tipo char
    if(letra=='P'){           //Se condiciona una letra cuando sea prendido
      digitalWrite(led,1);    //Se escribe el estado del led 
    }else if(letra=='A'){     //Se condiciona una letra para el estado apagado
      digitalWrite(led,0);    //Se escribe en el led el estado 0 o apagar.
    }
  }
}

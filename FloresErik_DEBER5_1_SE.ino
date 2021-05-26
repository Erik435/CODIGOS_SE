/*
 * CAPITULO 5: FUNCIONES ESPECIALES.
 * DEBER : Memoria EEPROM
 * OBJETIVO: Realizar la escritura de la memoria EEPROM a travez de un teclado matricial, el cual debe cumplir que se visualice en una 
 *           LCD cada caracter que se introduzca (uno por uno el que vayamos escribiendo en la memoria EEPROM), es decir, cada vez que se presione una tecla.
 * Nombre: Erik Flores
 * Fecha: 27/05/2021
 */
 #include <Keypad.h>
 #include <EEPROM.h>
 #include <LiquidCrystal.h>
 LiquidCrystal lcd(A0, A1, 13, 12, 11, 10);       //Definición de los pines de la LCD.
 const byte filas = 4;                            //Definir el número de filas.
 const byte colum = 4;                            //Definir el número de Columnas.
 int din=0;                                       //Diniri la variable para el conteo de char ingresados.
 int led1=A2;                                     //Definir el pin del led
 char datos[16];                                  //Se define el vector a llenar.
 char teclado[filas][colum] = {                   //Se crea la matriz para el teclado.
  {'1','2','3','A'},
  {'4','5','6','B'},                              //Se configura el teclado
  {'7','8','9','C'},
  {'*','0','#','D'},
 };
 byte pinesFilas[filas] = {9, 8, 7,6};          //Definir entrada de los pines de dilas conectadas al arduni.
 byte pinesColum[colum] ={5, 4, 3, 2};          //Definir entradas de los pines de columnas de el arduino.
 Keypad matriz = Keypad(makeKeymap(teclado), pinesFilas, pinesColum, filas, colum); //Creación de objeto con los datos de la matriz.

 
void setup() {                       
  lcd.begin(20,4);                             //Se inicializa la LCD en este caso con 20 columnas y 4 filas.
  pinMode(led1,OUTPUT);                        //Se inicializa el pin para el led de activación
  lcd.setCursor(0,0);                          //Se inicializa el cursor de inicio
  lcd.print("Mostrar datos = D ");             //Se ubica un mensaje por defecto.
}
        
void loop() {
  char tcl = matriz.getKey();                  //Crea la función para el teclado marticial e ir observando el dato.
  if(tcl != NO_KEY)                            // Si no se pulsa ningun valor dara NO_KEY
  {
  digitalWrite(led1,HIGH);                     //Se envia 5v para activar el Led
  delay(300);                                  //Tiempo de Espera del led.
  lcd.setCursor(0,1);                          //Ubicación para la lcd.
  lcd.print("Dat. Ingresando:");               //Mensaje en la LCD
  lcd.setCursor(16,1);                         //Ubicación para la lcd.
  lcd.print(tcl);                              //Mensaje en la del char ingresado.
  datos[din]=tcl;                              //Se guarda los char en un vector ya creado.
  digitalWrite(led1,LOW);                      //Se apaga el led
  delay(300);                                  //Tiempo de apagado de led.
  
  din++;                                       //Inicia el conteo para saber cuantas posiciones reocrren para el ingreso.
  }
  if(tcl=='D')                                 //Condicion cuando se aplaste D.
  {
    din=din-1;                                 //Inicializo la cantidad de char ingresados -1 para que no tome la letra D
    for(int i=0;i<din;i++){                    //Ciclo de recorrido para los char ingresados y poder almacenar todos
        lcd.setCursor(0,2);                    //Ubicación para la lcd.
        lcd.print("Dat. Ingresados:");         //Mensaje en la LCD
        lcd.setCursor(16,2);                   //Ubicación para la lcd.
        lcd.print(datos);                 //Mensaje en la LCD de dato         
        lcd.setCursor(0,3);                    //Ubicación para la lcd.
        lcd.print("Dat. EEPROM:");             //Mensaje en la LCD
        lcd.setCursor(12,3);                   //Ubicación para la lcd.
        EEPROM.put(i,datos[i]);                //Mensaje en la LCD de dato
        lcd.print(EEPROM.get(i,datos[i]));     //Lee los datos char para la memoria y se imprime se escoge en la posicion i para que no coja la letra D
        delay(300);                            //Tiempo para mostrar los caracteres que se guardan
    }     
  }
}

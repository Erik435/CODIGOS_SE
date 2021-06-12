/*
 * DEBER 6.1: Retos Proseccing
 * Resolución de retos
 * OBJETIVO: Aplicar los conocimientos acerca de Processing y la interfaz gráfica.
 *NOMBRE: Erik Flores
 */
void setup() {
Serial.begin(9600);     //Inicialización de comunicación serial a 9600 baudios
}
void loop() {                            
Serial.println(digitalRead(A0));  // Transfiere a través del puerto serial el estado digital del pin 0
delay(100);
} 

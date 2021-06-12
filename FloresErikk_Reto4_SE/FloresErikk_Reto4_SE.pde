import processing.serial.*;
/*
 * DEBER 6.1: Retos Proseccing
 * Resolución de reto 4
 * OBJETIVO: Aplicar los conocimientos acerca de Processing y la interfaz gráfica.
 *NOMBRE: Erik Flores
 */ 
 Serial Reto4;                                        //Se crea el objeto para la comunicacion
 void setup(){ 
   Reto4=new Serial(this,"COM3",9600);                //Se establece la comunicacion
   background( #9b9b9b );                             //Fondo de color plomo
   size(400,400);                                     //Tamaño del cuadrado
   textSize(20);                                      //Tamaño de la fuente
   fill(0);                                           //Color para las letras
   text("Presione el boton para ",90,50);             //SE Define el mensaje en el rectangulo
   text("Encender o apagar el led ",80,70);           //SE Define el mensaje en el rectangulo
   smooth();
   fill(#ff0000);                                     //Color para el circulo de inicio
   ellipse(200,200,200,200);                          //Se define la elipse
   fill(250);                                         //Color para las letras
   text("¡Apagado! ",150,200);                        //Se define el mesanjes centrado del circulo de inicio
 }
 void draw(){
 }
 
 void mousePressed(){
 float distancia=dist(mouseX, mouseY,200,200);       //Se Define el tamaño del click donde se activa
 if(distancia<100){                                  //Condicion con respecto al radio del circulo
 fill(#67FF2C);                                      //Se define el color verde
 ellipse(200,200,200,200);                           //Creacion de circulo y ubicacion
 Reto4.write('P');                                   //Se define el color del texto
 fill(250);                                          //Se define el color del texto 
 text("¡Prendido! ",150,200);                        //Se define el mesanjes centrado
 }
 }
 void mouseReleased(){
 float distancia=dist(mouseX, mouseY,200,200);      //Se Define el tamaño del click donde se desactiva
 if(distancia<100){                                 //Condicion con respecto al radio del circulo
 fill(#ff0000);
 ellipse(200,200,200,200);                         //Creacion de circulo y ubicacion
 fill(250);                                        //Se define el color del texto 
 text("¡Apagado! ",150,200);                       //Se define el mesanjes centrado
 Reto4.write('A');
 }
 }
 

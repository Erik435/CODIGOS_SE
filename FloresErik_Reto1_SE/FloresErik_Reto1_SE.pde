/*
*Deber 6.1-Reto1.
*Realizar la figura del reto 1 planteado en clase.
*Nombre: Erik Flores
*/
void setup(){
  size(400,400);              //Tamaño del cuadrado
  background(0);
  fill(#ff6800);
  strokeWeight(7);
  rect(10, 10, 380,380);      //Definicion de linea
  stroke(#0000ff);
  line(16, 16, 384,383);      //Definicion de linea
  line(16,385,383,16);        //Definicion de linea
  strokeWeight(0);
  fill(#FFFFFF);
  ellipse(200,200,200,200);   //Definicion del circulo
  stroke(#00ff00);
  strokeWeight(3);
  fill( #FF0000);
  ellipse(200,200,150,150);    //Definicion del circulo
}
void draw(){
}

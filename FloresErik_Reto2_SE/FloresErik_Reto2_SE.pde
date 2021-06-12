int i=250;
void setup(){
size(400,400);
background(#9b9b9b);
textSize(20);
fill(0);
text("Presione el boton para ",90,50);     //SE Define el mensaje en el rectangulo
text("Encender o apagar el led ",80,70);   //SE Define el mensaje en el rectangulo
smooth();
fill(#ff0000);                             //Se define el color del circulo
ellipse(200,200,200,200);                  //Ubicacion y tamaño del circulo
fill(250);                                 //Se define el color del texto 
text("¡Apagado! ",150,200);                //Se define el mesanjes centrado
}
void draw(){
noStroke();
}
void mousePressed(){                            //Metodo Presionado
  if(mouseButton==LEFT){                        //Si se tiene presionado el click izquierdo
    fill(#008f39);                              //Se define el color verde oscuro
    ellipse(200,200,200,200);                   //Se establece el circulo
  }
    if(mouseButton == RIGHT){                  //Si se tiene presionado el click derecho
    fill(#804000);                             //Se define el color cafe
    ellipse(200,200,200,200);                  //Se establece el circulo
    }
  }
void mouseReleased(){                         //Metodo para alzar el maouse

  if(mouseButton==LEFT){                      //Si se suelta el boton izquierdo
    fill(#ff0000 );                           //Se define el color rojo
    ellipse(200,200,200,200);                 //Se establece el circulo
    fill(250);                                 //Se define el color del texto 
    text("¡Apagado! ",150,200);                //Se define el mesanjes centrado
  }
    if(mouseButton == RIGHT){                 //Si se suelta el botón derecho
    fill(#00ff00);                            //Se define el color verde claro
    ellipse(200,200,200,200);                 //Se establece el circulo
    fill(250);                                //Color parael mensaje prendido
    text("¡Prendido! ",150,200);              //Se define el mesanjes centrado
    }
  }

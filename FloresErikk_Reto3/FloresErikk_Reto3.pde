import processing.serial.*;

Serial miPuerto;                                                //Se creael objeto para la comunicación
void setup(){
  size(400,400);
miPuerto = new Serial(this,"COM3",9600);                        //Se establece la comunicación
}
void draw(){
int pulsador = miPuerto.read();
println(pulsador);
if(pulsador=='1'){
    fill(#00ff00);                                              //Se crea la condición para 1
    ellipse(200,200,200,200);                                   //Se establece el circulo
    fill(0);                                                   //Crea el circulo
    text("BOTON ENCENDIDO-ERIK FLORES ",100,60);              //Se define el mesanjes centrado
}
if(pulsador=='0'){                                             //Condicion para el 0
    fill(#ff0000);                                            //Se define el color verde claro
    ellipse(200,200,200,200);                                //Se establece el circulo
    fill(0);                                                 //Color parael mensaje prendido
    text("BOTON APAGADO-ERIK FLORES ",100,60);              //Se define el mesanjes centrado
}
}

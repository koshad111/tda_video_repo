#include <cstdlib> 
#include <iostream> 
#include <string>
#include <image.h>
#include <video.h>
#include <cassert>

using namespace std;



int main (int argc, char ** argv) {

  Image origen, destino;    //en video morphing la imagen "origen" va a cambiarse a la imagen "distino"
  Video morphing;         //video de morphing que va a crearse

  if (argc != 5){
    cerr << endl << "Error: Número de parámetros incorrecto. " << endl;
    cerr << "Uso: " << argv[0] << " <imagen_entrada> <imagen_salida> <directorio para el video> <numero de frames>" << endl << endl;
    exit (1);
  }

  //conprueba si imagenes existen
  if (!origen.Load(argv[1])){
    cerr << "Error: " << argv[1] << " no es un fichero PGM válido" << endl;
    exit(1);
  }
  
  if (!destino.Load(argv[2]))
  {
    cerr << "Error: " << argv[2] << " no es un fichero PGM válido" << endl;
    exit(1);
  }

  //función morphing
  morphing.Morphing(origen, destino, stoi(argv[4]));

  //guarda nuevo video morphing
  bool exito= morphing.EscribirVideo(argv[3], "morph");

  //comprueba si esta guardado correctamente
  if(exito)
  {
    cout<<"Video morph creado"<<endl;
  }
  else
  {
    cout<<"El video no ha sido creado"<<endl;
  }

}



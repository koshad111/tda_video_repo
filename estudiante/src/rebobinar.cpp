#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

#include <video.h>

using namespace std;


int main (int argc, char ** argv) {

    Video origen, destino;

    //creo que no se supone que nosotros podemos cambiar numero de parametros
    if (argc != 3){
        cerr << endl << "Error: Número de parámetros incorrecto. " << endl;
        cerr << "Uso: " << argv[0] << " <RutaEntradaVideo> <RutaVideoRebobinado> "<< endl << endl;
        exit (1);
    }

    origen.LeerVideo(argv[1]);
    destino.Rebobinar(origen);
    bool es_rebobinado=destino.EscribirVideo(argv[2], "rebobinado");
    if(es_rebobinado==true)
    {
        cout<<"El video ha sido correctamente rebobinado"<<endl;
    }
    else
    {
        cout<<"El video no ha sido rebobinado"<<endl;
    }
    /*
    //codigo mio para comprobar el trabajo de Leer y Escribir
    //no se va a ejecutar sin morphing
    Video v;
    v.LeerVideo("/home/jrgeegr/tda_video_daria/videos/football"); //path to directory directa, para comprobar en otro ordenador hay que cambiarlo
    cout << v[3].get_pixel(1,1);
    const string prefijo = "foot";//rdefijo para ficheros de image de este video
    bool succes = v.EscribirVideo("/home/jrgeegr/Documentos/tda_video_daria/videos/football1", prefijo);//path to directory directa
    if (succes) {
        cout << "We created new video!" << endl;
    }
    */
    // TODO: Aplicar el codigo necesario para rebobinar el video origen y almacenar las imagenes en destino
    // para ello es necesario definir las funciones que leen y escriben un videdo como una secuencia de imagenes en una ruta dada
}



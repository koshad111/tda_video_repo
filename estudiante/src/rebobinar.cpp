#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>

#include <video.h>

using namespace std;


int main (int argc, char ** argv) {

    Video origen, destino;      //video "origen" aun no rebobinado, video "destino" con video rebobinado

    if (argc != 3){
        cerr << endl << "Error: Número de parámetros incorrecto. " << endl;
        cerr << "Uso: " << argv[0] << " <RutaEntradaVideo> <RutaVideoRebobinado> "<< endl << endl;
        exit (1);
    }

    //lee video de origen
    origen.LeerVideo(argv[1]);

    //pone rebobinado video "origen" a variable "destino"
    destino.Rebobinar(origen);

    //guarda rebobinado video "destino"
    bool es_rebobinado = destino.EscribirVideo(argv[2], "rebobinado");

    //comprueba si esta guardado correctamente
    if(es_rebobinado==true)
    {
        cout<<"El video ha sido correctamente rebobinado"<<endl;
    }
    else
    {
        cout<<"El video no ha sido rebobinado"<<endl;
    }
}



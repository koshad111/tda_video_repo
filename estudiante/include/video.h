#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <vector>
#include <cstdlib>
#include "image.h"
using namespace std;

class Video
{ /**
     @page repVideo Representación del TDA Video.

     @section invVideo Invariante de la representación.

     Un objeto válido 1 del TDA Video debe cumplir
     -V.seq es un contenedor de la STL (vector) que almacena imagenes.

     @section faVideo Función de abstraccion

     Un objeto válido 1 del TDA Video representa una secuencia de imagenes.

     **/


private:
    /**
      @brief Vector de la STL que almacena imagenes. Almacena tantas imagenes como fotogramas tenga el video
    **/
    vector<Image> seq;

public:
    /**
      * @brief Constructor por defecto .
      * @post Genera una instancia de la clase Video con O imagenes.
      * @return Video, el objeto video creado.
     */
    Video();

    /**
    * @brief Constructor de copias.
    * @param J Referencia a al video original que se quiere copiar.
    * @return Video, el objeto imagen creado.
    */
    Video(const Video & J);

    /**
    * @brief Constructor con parámetros.
    * @param n Número de fotogramas que tendrá el video
    * @pre n>0
    * @post El video creado tiene n casillas.
    * @post El video creado contiene valores "basura" (no está inicializado).
    * @return Video, el objeto video creado.
    */
    Video(int n);

    /**
    *@brief Operador de tipo destructor.
    *@post Libera los recursos ocupados por el video.
    *@post El video destruido no puede volver a usarse, salvo que se vuelva a realizar sobre él otra operación de construcción.
    *@return Nada.
    */
    ~Video();

    /**
    *@brief Consultar el número de fotogramas del video.
    *@post Calcula el numero de fotogramas del video.
    *@post El video no se modifica.
    *@return Numero de fotogramas.
    */
    int size() const;

    /**
    *@brief Consultar/Asignar una imagen al video.
    *@param foto Index del imagen
    *@post A través del operador [] el usuario puede consultar un fotograma del video.
    *@pre 0<=n<=size().
    *@return Devuelve la imagen asociada al fotograma foto-ésimo del video.
    */
    Image& operator[](int foto);

    /**
    *@brief A través del operador [] el usuario puede consultar un fotograma del video.
    *@param foto Index del imagen
    *@pre 0<=n<=size().
    *@return Devuelve la imagen asociada al fotograma foto-ésimo del video.
    */
    const Image& operator[](int foto) const;

    /**
    *@brief Insertar un nuevo fotograma.
    *@param k es la posicion donde se quiere insertar la imagen dentro del video
    *@param I es  la imagen que se quiere insertar
    *@post Inserta un nuevo fotograma I en la posición k.
    *@pre k debe indicar una posición válida dentro del video, es decir, en el rango [0,V.size()].
    *@post El video es modificado. Se inserta la nueva imagen en la posicion k y el vector se rehace añadiendo un espacio más y las imagenes siguientes se desplazan 1 unidad a la derecha
    */
    void Insertar(int k, const Image&I);

    /**
    *@brief Borrar un fotograma
    *@param k es la posicion del video a eliminar
    *@post Eliminar el fotograma de la posicion dada por un entero k
    *@pre k debe ser una posición válida dentro del vídeo, es decir, que pertenezca al rango [0,V.size()-1].
    *@post El video es modificado teniendo un fotograma menos, el vector elimina esa posicion y las imagenes siguientes quedan unidas al elemento anterior del borrado
    */
    void Borrar(int k);

    /**
    *@brief Leer un video
    *@param directory_path ruta al directorio de imagenes de video
    *@post Leer un video de disco
    *@pre en el directorio path debe almacenarse una secuencia temporal de fotogramas.
    *@post Devuelve true si la lectura tiene éxito y false en caso contrario
    */
    bool LeerVideo(const string & directory_path);

    /**
    *@brief Escribir un video
    *@param directory_path ruta al directorio de imagenes de video
    *@param prefijo nombre de las imagenes, que va a guardarse enumerado segun su orden en video
    *@post Escribe un video de disco
    *@pre En el directorio path se almacenará la secuencia temporal de fotogramas. Los fotogramas tomarán como nombre <prefijo>_01.pgm .. <prefijo>_0n.pgm siendo n el numero de fotogramas.
    *post Devuelve true si la escritura tiene éxito y false en caso contrario
    */
    bool EscribirVideo(const string & directory_path, const string &prefijo) const;

    /**
    *@brief a partir de un vídeo, obtenga el vídeo invertido
    *@param video un vídeo constante
    *@post devolverá un nuevo vídeo que será el vídeo invertido.
    *@pre Esto quiere decir que el fotograma v.size()-1 se podrá en la posición 0 del video rebobinado,
    *el v.size()-2 en la posición 1, y así hasta llegar al fotograma 0 que se colocará en la posición v.size()-1.
    */
    void Rebobinar(const Video &video);

    /**
     * @brief  cambia una imagen en otra
     * @param I1 image de inicio
     * @param I2 image de fin
     * @param nf numero de imagenes
     * *@post El morphing se usa para cambiar una imagen en otra o para proporcionar una transición suave
     * de una imagen a otra creando la ilusión de una transformación.
     */
    void Morphing(const Image &I1, const Image &I2, int nf);
};


#endif
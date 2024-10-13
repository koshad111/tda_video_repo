#ifndef _VIDEO_H_
#define _VIDEO_H_

#include <vector>
#include <cstdlib>
#include "image.h"
using namespace std;

class Video
{
private:
    /**
      @brief Vector que almacena imagenes
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
    *@post A través del operador [] el usuario puede consultar un fotograma del video.
    *@pre 0<=n<=size().
    *@return Devuelve la imagen asociada al fotograma foto-ésimo del video.
    */
    Image& operator[](int foto);

    /**
    *@brief A través del operador [] el usuario puede consultar un fotograma del video.
    *@pre 0<=n<=size().
    *@return Devuelve la imagen asociada al fotograma foto-ésimo del video.
    */
    const Image& operator[](int foto) const;

    /**
    *@brief Insertar un nuevo fotograma.
    *@post Inserta un nuevo fotograma I en la posición k.
    *@pre k debe indicar una posición válida dentro del video, es decir, en el rango [0,V.size()].
    *@post El video es modificado teniendo un nuevo fotograma más.
    */
    void Insertar(int k, const Image&I);

    /**
    *@brief Borrar un fotograma
    *@post Eliminar el fotograma de la posicion dada por un entero k
    *@pre k debe ser una posición válida dentro del vídeo, es decir, que pertenezca al rango [0,V.size()-1].
    *@post El video es modificado teniendo un fotograma menos
    */
    void Borrar(int k);

    /**
    *@brief Leer un video
    *@post Leer un video de disco
    *@pre en el directorio path debe almacenarse una secuencia temporal de fotogramas.
    *@post Devuelve true si la lectura tiene éxito y false en caso contrario
    */
    bool LeerVideo(const string & path);

    /**
    *@brief Escribir un video
    *@post Escribe un video de disco
    *@pre En el directorio path se almacenará la secuencia temporal de fotogramas. Los fotogramas tomarán como nombre <prefijo>_01.pgm .. <prefijo>_0n.pgm siendo n el numero de fotogramas.
    *post Devuelve true si la escritura tiene éxito y false en caso contrario
    */
    bool EscribirVideo(const string & path, const string &prefijo) const;




};


#endif
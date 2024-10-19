#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include <regex>
#include <dirent.h>  // Para opendir y trabajo con catalogos
#include <filesystem>

#include <image.h>
#include <imageIO.h>        //parece que no hace falta
#include <video.h>

using namespace std;

Video::Video(){
}

Video::Video(const Video & J)
{
    seq=J.seq;
}

Video::Video(int n)
{
    seq.reserve(n);
}

Video::~Video()
{
    seq.clear();
}

int Video::size() const
{
    return seq.size();
}

Image & Video::operator[](int foto)
{
    assert(0<=foto && foto<seq.size());
    return seq[foto];
}

const Image & Video::operator[](int foto) const
{
    assert(0<=foto && foto<seq.size());
    return seq[foto];
}

void Video::Insertar(int k, const Image&I)
{
    assert(k>=0 && k<=seq.size()); //SE PUEDE EN SEQ.SIZE?? no
    seq.insert(seq.begin()+k, I);
}

void Video::Borrar(int k)
{
    assert(k>=0 && k<seq.size());
    seq.erase(seq.begin()+k);       //no estoy segura que se hace seq.begin()+k
}

//ordena los nombres de imagenes de menor a mayor, para insertar al vector seq
void insertionSort(vector<string> &v, int n, std::function<bool(string, string)> compare) {
    for (int i = 1; i < n; i++) {
        string key = v[i];
        int j = i - 1;

        while (j >= 0 && compare(v[j], key)) {
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = key;
    }
}

//anade los nombres de las imagenes de directorio de video al vector de nombres de imagenes
void readDirectory(const std::string& name, vector<string>& v)
{
    //se utiliza dirent.h para leer el directorio
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

        v.push_back(dp->d_name);

    }
    closedir(dirp);
}

//maybe add to video load results

bool Video::LeerVideo(const string &path){

    vector<Image> images;
    vector<string> img_file_names;

    //lee directorio y aniade nombres de las imagenes al img_file_names
    readDirectory(path, img_file_names);

    //si no hay nada en img_file_names, LeerVideo devuelve false
    if (img_file_names.empty()) {
        return false;
    }

    //ordena los nombres de imagenes
    insertionSort(img_file_names, img_file_names.size(),
        [](string a, string b) { return a.compare(b)>0; });

    for (const auto & img_file_name : img_file_names){
        cout << path + img_file_name;
    }

    //lee imagenes via constructor de Image con ruta a imagen como parametro
    for (const auto & img_file_name : img_file_names){
        size_t found = img_file_name.find("pgm");
        if(img_file_name != "." && img_file_name != ".." && found == img_file_name.size()-3){
            string path_to_image = path + img_file_name;
            const char* to_image = path_to_image.c_str();
            Image img = Image(to_image); //el constructor comprueba si el fichero es "correcto" o no
            images.push_back(img);
        }
    }

    //comprueba si el vector con imagenes esta vacio
    if (images.empty()) {
        return false;
    }

    //guarda imagenes a seq
    this->seq = images;

    //resultado correcto
    return true;
}

bool Video::EscribirVideo(const string & path, const string &prefijo)const{

    //comprueba si seq esta vacio
    if (this->seq.size() == 0){
        return false;
    }

    //comprueba si directorio existe o no
    std::filesystem::path filepath =path;
    bool filepathExists = std::filesystem::is_directory(filepath);

    //si no existe, lo crea
    if (!filepathExists){
        bool created_new_directory= std::filesystem::create_directory(filepath);

        //si no ha creado, escribe comentario y devuelve false
        if (!created_new_directory){
            cout<<"No se puede crear el directorio "<<path<<endl;
            return false;
        }
        //si esta bien, escribe:
        else{
            cout<<" Se ha creado el directorio "<< path<<endl;
        }
    }

    //guarda imagenes al directorio con nombre, que esta compuesto de prefijo y index de imagen
    for (int i = 0; i < this->seq.size(); i++){
        std::stringstream s_index;
        s_index << std::setw(3) << std::setfill('0') << i;
        string image_path = path + "/" + prefijo + s_index.str() + ".pgm";
        if (!seq[i].Save(image_path.c_str())){
            return false;
        }
    }

    //resultado correcto
    return true;
}

void Video::Rebobinar (const Video &video)
{
    int contador=0;
    for(int i=video.size()-1; i>=0; i--)
    {
        this->Insertar(contador, video[i]);
        contador++;
    }
}

void Video::Morphing(const Image&I1, const Image&I2, int nf)
{
    assert(I1.get_cols()==I2.get_cols() && I1.get_rows()==I2.get_rows());
    Image fotograma(I1);
    for(int a=0; a<nf; a++)
    {
        for(int i=0; i<I1.get_rows(); i++)
        {
            for(int j=0; j<I1.get_cols(); j++)
            {
                fotograma.set_pixel(i,j,I1.get_pixel(i,j)*(1-a/nf)+(I2.get_pixel(i,j)*a/nf));
            }
        }
        this->Insertar(a,fotograma);

    }
}
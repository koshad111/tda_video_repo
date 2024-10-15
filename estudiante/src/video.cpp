#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>
#include <regex>
#include <dirent.h>  // Para opendir y trabajo con catalogos
#include <cstring>

#include <image.h>
#include <imageIO.h>        //parece que no hace falta
#include <video.h>

using namespace std;

Video::Video(){
    seq.reserve(0);
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
    assert(k>=0 && k<seq.size()); //SE PUEDE EN SEQ.SIZE?? no
    seq.insert(seq.begin()+k, I);
}

void Video::Borrar(int k)
{
    assert(k>=0 && k<seq.size());
    seq.erase(seq.begin()+k);       //no estoy segura que se hace seq.begin()+k
}

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

void readDirectory(const std::string& name, vector<string>& v)
{
    DIR* dirp = opendir(name.c_str());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {

        v.push_back(dp->d_name);

    }
    closedir(dirp);
}

bool Video::LeerVideo(const string &path){

    //USA read_directory PARA LEER los fichero de un directorio
    //COMPLETAR POR EL ESTUDIANTE

    vector<Image> images;
    vector<string> img_file_names;

    readDirectory(path, img_file_names);

    if (img_file_names.empty()) {
        return false;
    }

    insertionSort(img_file_names, img_file_names.size(), [](string a, string b) { return a.compare(b)>0; });
    //sort(image_names.begin(), image_names.end(), { return a > b; });

    for (const auto & img_file_name : img_file_names){
        string path_to_image = path + "/" + img_file_name;
        const char* to_image = path_to_image.c_str();
        Image img = Image(to_image);
        images.push_back(img);
    }

    if (images.empty()) {
        return false;
    }

    this->seq = images;
    return true;
}



#include <cstring>
#include <cassert>
#include <iostream>
#include <fstream>

#include <image.h>
#include <imageIO.h>
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
    assert(k>=0 && k<=seq.size()); //SE PUEDE EN SEQ.SIZE??
    seq.resize(seq.size()+1);
    seq[k]=I;

}

void Video::Borrar(int k)
{
    assert(k>=0 && k<seq.size());
    seq.erase(seq.begin()+k);
}

bool Video::LeerVideo(const string & path)
{
    ifstream arhivo(path);
    if(!archivo)
    {
        return false;
    }

    //NO SE HACERLO
}


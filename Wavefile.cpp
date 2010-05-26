/* 
 * File:   Wavefile.cpp
 * Author: rd
 * 
 * Created on 23 Май 2010 г., 12:08
 */

#include "Wavefile.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

//using namespace std;

Wavefile::Wavefile(const char* filename) {
    std::ifstream in(filename,std::ios::in | std::ios::binary);
    hdr=new Waveheader();
    hdr->load(in);

    data=malloc(hdr->dataSize);
    if(data==0)
        throw "Недостаточно памяти! :(";
    in.read((char *)data,hdr->dataSize);


    //неплохо бы проверить, действительно ли это конец, но зачастую оно так и есть
}

Wavefile::Wavefile(const Wavefile& orig) {
    throw "Не должен этот класс копироваться!";
}

Wavefile::~Wavefile() {
    if(data!=0)
        free(data);
    if(hdr!=0)
        delete hdr;
}


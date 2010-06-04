/* 
 * File:   Normalizer.cpp
 * Author: rd
 * 
 * Created on 4 Июнь 2010 г., 12:11
 */

#include "Normalizer.h"


#include "Normalizer.h"

inline short abs(short a){
    return a>=0 ? a : -a;
}

Normalizer::Normalizer() {
}

Normalizer::Normalizer(const Normalizer& orig) {
    throw "Не должен этот класс копироваться!";
}

Normalizer::~Normalizer() {
}

void Normalizer::apply(DataChunk& samples){
    unsigned short bytePerSample=samples.getFormat()->bitsPerSample()/8;
    unsigned int count=samples.getSize()/bytePerSample; //samples count
    char *data = samples.getData();

    short maxs =0,tmps;
    float k=0;

    for(int i=0;i<count;i++,data+=bytePerSample){
        switch(bytePerSample){
            case 1:
                tmps=abs(*((char*)data) - 80);
                break;
            case 2:
                tmps=abs(*((short*)data));
                break;
            default:
                throw "Такой битрейт пока не поддерживается";
        }
        maxs= maxs<tmps ? tmps : maxs;

    }

    switch(bytePerSample){
        case 1:
            k=127.0/maxs;
            break;
        case 2:
            k=32767.0/maxs;
            break;
    }

    Amplifier::set(k);
    DiskreteEffect::apply(samples);
}
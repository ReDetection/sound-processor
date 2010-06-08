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
    char *data8 = samples.getData();
    short *data16 = (short*)data8;

    short maxs =0,tmps;
    float k=0;

    switch (bytePerSample) {
        case 1:
            maxint=127;
            for(unsigned int i=0;i<count;i++)
                maxs= maxs<data8[i]-0x80 ? data8[i]-0x80 : maxs;
            break;
        case 2:
            maxint=32767;
            for(unsigned int i=0;i<count;i++)
                maxs= maxs<data16[i] ? data16[i] : maxs;
            break;
        default:
            throw "Такой битрейт пока не поддерживается";
    }

    k=maxint*1.0/maxs;
    Amplifier::set(k);
    DiskreteEffect::apply(samples);
}
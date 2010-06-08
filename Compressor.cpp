/* 
 * File:   Compressor.cpp
 * Author: rd
 * 
 * Created on 4 Июнь 2010 г., 20:32
 */

#include "Compressor.h"

inline int abs(int a){
    return a>=0 ? a : -a;
}
inline int sign(int a){
    return a>=0 ? 1 : -1;
}
Compressor::Compressor(double iknee,double oknee) {
    setKnee(iknee,oknee);
}

Compressor::Compressor(const Compressor& orig) {
}

Compressor::~Compressor() {
}
float Compressor::getOknee() const {
    return oknee;
}
void Compressor::setKnee(double iknee,double oknee) {
    this->iknee = iknee;
    this->oknee=oknee;
    a1=oknee/iknee;
    a2=(1.0-oknee)/(1.0-iknee);
}
float Compressor::getIknee() const {
    return iknee;
}

short Compressor::apply(short sample){
    if(abs(sample)<=maxint*iknee)
        return sample*a1;
    else
        return a2*sample + b*sign(sample);
}

void Compressor::apply(DataChunk& samples){
    switch( samples.getFormat()->bitsPerSample()/8){
        case 2:
            maxint =32767;break;
        case 1:
            maxint = 127;
            break;
    }
    b = (1.0-a2)*maxint;
    DiskreteEffect::apply(samples);
}
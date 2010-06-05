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
    float b2=(1.0-a2);
    bc = b2*127.0;
    bs = b2*32767.0;
}
float Compressor::getIknee() const {
    return iknee;
}

char Compressor::apply(char sample){
    int val =  (sample-0x80);
    if(abs(val)<=128.0*iknee)
        val*=a1;
    else
        val=a2*val + bc*sign(val);
    return val + 0x80;
};

short Compressor::apply(short sample){
    if(abs(sample)<=32768.0*iknee)
        return sample*a1;
    else
        return a2*sample + bs*sign(sample);
};
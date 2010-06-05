/* 
 * File:   Distortion.cpp
 * Author: rd
 * 
 * Created on 5 Июнь 2010 г., 15:03
 */

#include "Distortion.h"
inline short abs(short a){
    return a>=0 ? a : -a;
}
inline short sign(short a){
    return a>=0? 1: -1;
}
inline short modabs(short a,short mod){
    if(abs(a)>mod)
        return mod*sign(a);
    return a;
}

Distortion::Distortion() {
    s=0;
    samples=0;
}

Distortion::Distortion(const Distortion& orig) {
}

Distortion::~Distortion() {
}


char Distortion::apply(char sample){
    return modabs(sample-0x80,calc(sample-0x80)) + 0x80;
}
short Distortion::apply(short sample){
    return modabs(sample,calc(sample));

}

short Distortion::calc(short a){
    a=abs(a);
    if(samples<50)
        s=(s*samples + a)/(samples++ + 1);
    else
        s=(s*49+a)/50;
    return s ;
}

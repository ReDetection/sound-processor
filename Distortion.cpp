/* 
 * File:   Distortion.cpp
 * Author: rd
 * 
 * Created on 5 Июнь 2010 г., 15:03
 */
#include <stdio.h>
#include "Distortion.h"
inline short abs(short a){
    return a>=0 ? a : -a;
}
inline short sign(short a){
    return a>=0? 1: -1;
}
short Distortion::modabs(short a,short mod){
    if(abs(a)>mod){
        if(clip==0)
            clip=mod;
        return clip*sign(a);
    }else{
//        if(abs(a)>clip)
//            return clip*sign(a);
//        else{
            clip=0;
            return a;
//        }
    }
}

Distortion::Distortion() {
    s=0;
    samples=0;
    clip=0;
    smiddle=0;
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
    if(a<5)return s;
    if(samples<500)
        s=(s*samples + a)/(samples++ + 1);
    else
        s=(s*499+a)/500;
    return s ;
}
void Distortion::apply(DataChunk &samples){
    smiddle=samples.getFormat()->getSamplesPerSec()/100;
    printf("%d\n",smiddle);
    DiskreteEffect::apply(samples);
}
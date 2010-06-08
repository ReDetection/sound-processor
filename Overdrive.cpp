/* 
 * File:   Overdrive.cpp
 * Author: rd
 * 
 * Created on 6 Июнь 2010 г., 02:17
 */
#include "Overdrive.h"
inline short abs(short a){
    return a>=0 ? a : -a;
}
inline short sign(short a){
    return a>=0? 1: -1;
}
inline short amdl(short a,short b){
    return (a+b)/2;
}
short Overdrive::calc(short a,short mod){
    if(clip!=0){
        if(abs(a)>clip)
            return clip*sign(a);
        //else
        clip=0;
        return a;
    }else{
        if(abs(a)>mod*1.25){
            clip=mod;
            return clip*sign(a);
        }
        return a;
    }
}

Overdrive::Overdrive() {
    s=0;
    samples=0;
    smiddle=0;
    clip=0;
}

Overdrive::Overdrive(const Overdrive& orig) {
}

Overdrive::~Overdrive() {
}

short Overdrive::apply(short sample){
    return amdl(calc(sample,middle(sample)),sample);

}

short Overdrive::middle(short a){
    a=abs(a);
    if(a<5)return s;
    if(samples<smiddle)
        s=(s*samples + a)/(samples++ + 1);
    else
        s=(s*(smiddle-1)+a)/smiddle;
    return s ;
}
void Overdrive::apply(DataChunk &samples){
    smiddle=samples.getFormat()->getSamplesPerSec()/100;
    DiskreteEffect::apply(samples);
}
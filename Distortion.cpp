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
//inline short amdl(short a,short b){ //for overdrive test
//    return (a+a+b)/3;
//}
short Distortion::calc(short a,short mod){
//    if(clip!=0){
//        if(abs(a)>clip)
//            return clip*sign(a);
//        //else
//        clip=0;
//        return a;
//    }else{
//        if(abs(a)>mod){
//            clip=mod;
//            return clip*sign(a);
//        }
//    }


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

short Distortion::apply(short sample){
    return calc(sample,middle(sample));

}

short Distortion::middle(short a){
    a=abs(a);
    if(a<5)return s;
    if(samples<smiddle)
        s=(s*samples + a)/(samples++ + 1);
    else
        s=(s*(smiddle-1)+a)/smiddle;
    return s ;
}
void Distortion::apply(DataChunk &samples){
    smiddle=samples.getFormat()->getSamplesPerSec()/100;
    DiskreteEffect::apply(samples);
}
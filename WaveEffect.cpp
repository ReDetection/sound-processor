/* 
 * File:   WaveEffect.cpp
 * Author: rd
 *
 * Класс, от которого будут наследоваться звуковые эффекты.
 *
 * Created on 26 Май 2010 г., 14:36
 */

#include "WaveEffect.h"

WaveEffect::WaveEffect() {
    i=0;
}

WaveEffect::WaveEffect(const WaveEffect& orig) {
    throw "Не должен этот класс копироваться!";
}

WaveEffect::~WaveEffect() {
}

void WaveEffect::apply(char* samples,unsigned int size /*in bytes*/, unsigned short bytePerSample){
    size/=bytePerSample;
    for(i=0;i<size;i++,samples+=bytePerSample){
        switch(bytePerSample){
            case 1:
                apply(*((char*)samples));
                break;
            case 2:
                apply(*((short*)samples));
                break;
            default:
                throw "Такой битрейт пока не поддерживается";
        }
    }
}


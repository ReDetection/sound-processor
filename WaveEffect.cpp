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

void WaveEffect::apply(DataChunk &samples){
    unsigned short bytePerSample=samples.getFormat()->bitsPerSample()/8;
    unsigned int count=samples.getSize()/bytePerSample; //samples count
    char *data = samples.getData();

    for(i=0;i<count;i++,data+=bytePerSample){
        switch(bytePerSample){
            case 1:
                *((char*)data)=apply(*((char*)data));
                break;
            case 2:
                *((short*)data)=apply(*((short*)data));
                break;
            default:
                throw "Такой битрейт пока не поддерживается";
        }
    }
}


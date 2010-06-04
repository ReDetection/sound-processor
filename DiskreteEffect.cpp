/* 
 * File:   WaveEffect.cpp
 * Author: rd
 *
 * Класс, от которого будут наследоваться звуковые эффекты.
 *
 * Created on 26 Май 2010 г., 14:36
 */

#include "DiskreteEffect.h"

DiskreteEffect::DiskreteEffect() {
    i=0;
}

DiskreteEffect::DiskreteEffect(const DiskreteEffect& orig) {
    throw "Не должен этот класс копироваться!";
}

DiskreteEffect::~DiskreteEffect() {
}

void DiskreteEffect::apply(DataChunk &samples){
    unsigned short bytePerSample=samples.getFormat()->bitsPerSample()/8;
    unsigned int count=samples.getSize()/bytePerSample; //samples count
    char *data8 = samples.getData();
    short *data16 = (short*)data8;

    for(i=0;i<count;i++){
        switch(bytePerSample){
            case 1:
                data8[i]=apply(data8[i]);
                break;
            case 2:
                data16[i]=apply(data16[i]);
                break;
            default:
                throw "Такой битрейт пока не поддерживается";
        }
    }
}


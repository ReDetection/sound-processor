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

    switch (bytePerSample) {
        case 1:
            maxint=127;
            for(unsigned int i=0;i<count;i++)
                data8[i]=apply(data8[i]-0x80)+0x80;
            break;
        case 2:
            maxint=32767;
            for(unsigned int i=0;i<count;i++)
                data16[i]=apply(data16[i]);
            break;
        default:
            throw "Такой битрейт пока не поддерживается";
    }
}


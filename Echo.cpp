/* 
 * File:   Echo.cpp
 * Author: rd
 * 
 * Created on 4 Июнь 2010 г., 12:59
 */

#include "Echo.h"

Echo::Echo() {
}
void Echo::setVolume(float volume) {
    this->volume = volume;
}
float Echo::getVolume() const {
    return volume;
}
void Echo::setDelay(float delay) {
    this->delay = delay;
}
float Echo::getDelay() const {
    return delay;
}

Echo::Echo(const Echo& orig) {
    throw "Не должен этот класс копироваться!";
}

Echo::~Echo() {
}


void Echo::apply(DataChunk& samples){
    unsigned short bytePerSample=samples.getFormat()->bitsPerSample()/8;
    unsigned int count=samples.getSize()/bytePerSample; //samples count
    char *data8 = samples.getData();
    short *data16 = (short*)data8;
    unsigned int dl = samples.getFormat()->getAvgBytesPerSec()/bytePerSample*delay;

    for(unsigned int i=dl;i<count;i++){
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

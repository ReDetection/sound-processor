/* 
 * File:   Echo.cpp
 * Author: rd
 * 
 * Created on 4 Июнь 2010 г., 12:59
 */

#include "Echo.h"

Echo::Echo() {
    delay=1.0;
}

Echo::Echo(float delay, float volume) {
    setDelay(delay);
    setVolume(volume);
}
void Echo::setVolume(float volume) {
    Amplifier::set(volume);
    
}
float Echo::getVolume() const {
    return Amplifier::get();
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

    switch (bytePerSample) {
    case 1:
        maxint=127;
        for(unsigned int i=dl;i<count;i++)
            data8[i]+=Amplifier::apply(data8[i-dl]-0x80)+0x80;
        break;
    case 2:
        maxint=32767;
        for(unsigned int i=dl;i<count;i++)
            data16[i]=Amplifier::apply(data16[i-dl]);
        break;
    default:
        throw "Такой битрейт пока не поддерживается";
    }
}

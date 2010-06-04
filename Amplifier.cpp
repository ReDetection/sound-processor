/* 
 * File:   Amplifier.cpp
 * Author: rd
 * 
 * Created on 2 Июнь 2010 г., 17:53
 */

#include "Amplifier.h"

Amplifier::Amplifier(float k) {
    this->k=k;
}

Amplifier::Amplifier(const Amplifier& orig) {
    throw "Не должен этот класс копироваться!";
}

Amplifier::~Amplifier() {
}

char Amplifier::apply(char sample){
    return (sample-0x80)*k + 0x80;
}
short Amplifier::apply(short sample){
    return sample*k;
}
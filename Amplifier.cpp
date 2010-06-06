/* 
 * File:   Amplifier.cpp
 * Author: rd
 * 
 * Created on 2 Июнь 2010 г., 17:53
 */

#include "Amplifier.h"

Amplifier::Amplifier() {
    k=1.0;
}
Amplifier::Amplifier(float k) {
    this->k=k;
}

Amplifier::Amplifier(const Amplifier& orig) {
    throw "Не должен этот класс копироваться!";
}

Amplifier::~Amplifier() {
}

short Amplifier::apply(short sample){
    return sample*k;
}

void Amplifier::set(float k){
    this->k=k;
}

float Amplifier::get()const{
    return k;
}
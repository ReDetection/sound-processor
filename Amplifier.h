/* 
 * File:   Amplifier.h
 * Author: rd
 *
 * Created on 2 Июнь 2010 г., 17:53
 */

#ifndef _AMPLIFIER_H
#define	_AMPLIFIER_H

#include "WaveEffect.h"


class Amplifier:public WaveEffect {
public:
    Amplifier(float k);
    Amplifier(const Amplifier& orig);
    virtual ~Amplifier();


    virtual char apply(char sample);
    virtual short apply(short sample);
private:
    float k;
};

#endif	/* _AMPLIFIER_H */


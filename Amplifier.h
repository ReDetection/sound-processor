/* 
 * File:   Amplifier.h
 * Author: rd
 *
 * Created on 2 Июнь 2010 г., 17:53
 */

#ifndef _AMPLIFIER_H
#define	_AMPLIFIER_H

#include "DiskreteEffect.h"


class Amplifier:public DiskreteEffect {
public:
    Amplifier();
    Amplifier(float k);
    Amplifier(const Amplifier& orig);
    virtual ~Amplifier();

    virtual void set(float k);
    virtual float get()const;
    
    virtual char apply(char sample) ;
    virtual short apply(short sample);
private:
    float k;
};

#endif	/* _AMPLIFIER_H */


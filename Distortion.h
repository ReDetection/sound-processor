/* 
 * File:   Distortion.h
 * Author: rd
 *
 * Created on 5 Июнь 2010 г., 15:03
 */

#ifndef _DISTORTION_H
#define	_DISTORTION_H
#include "DiskreteEffect.h"

class Distortion : public DiskreteEffect {
public:
    Distortion();
    Distortion(const Distortion& orig);
    virtual ~Distortion();


    virtual char apply(char sample);
    virtual short apply(short sample);

private:

    short calc(short a);

    float s;
    short samples;

};

#endif	/* _DISTORTION_H */


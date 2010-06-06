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

protected:
    virtual short apply(short sample);

    virtual void apply(DataChunk &samples);

private:

    inline short calc(short a,short mod);
    short middle(short a);

    float s;
    short samples,smiddle;

    short clip;
};

#endif	/* _DISTORTION_H */


/* 
 * File:   Overdrive.h
 * Author: rd
 *
 * Created on 6 Июнь 2010 г., 02:17
 */

#ifndef _OVERDRIVE_H
#define	_OVERDRIVE_H
#include "DiskreteEffect.h"

class Overdrive : public DiskreteEffect {
public:
    Overdrive();
    Overdrive(const Overdrive& orig);
    virtual ~Overdrive();


    virtual char apply(char sample);
    virtual short apply(short sample);

    virtual void apply(DataChunk &samples);

private:

    inline short calc(short a,short mod);
    short middle(short a);

    float s;
    short samples,smiddle;

};

#endif	/* _OVERDRIVE_H */


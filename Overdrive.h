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

    virtual void apply(DataChunk &samples);

protected:
    virtual short apply(short sample);
    
private:

    inline short calc(short a,short mod);
    short middle(short a);

    float s;
    short samples,smiddle,clip;

};

#endif	/* _OVERDRIVE_H */


/* 
 * File:   Echo.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 12:59
 */

#ifndef _REVERB_H
#define	_REVERB_H
#include "Amplifier.h"

class Reverb : public Amplifier {
public:
    Reverb();
    Reverb(float delay,float volume);
    Reverb(const Reverb& orig);
    virtual ~Reverb();

    virtual void apply(DataChunk &samples);

    void setVolume(float volume);
    float getVolume() const;
    void setDelay(float delay);
    float getDelay() const;

private:
    float delay;

};

#endif	/* _REVERB_H */


/* 
 * File:   Echo.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 12:59
 */

#ifndef _ECHO_H
#define	_ECHO_H
#include "Amplifier.h"

class Echo : public Amplifier {
public:
    Echo();
    Echo(float delay,float volume);
    Echo(const Echo& orig);
    virtual ~Echo();

    virtual void apply(DataChunk &samples);

    void setVolume(float volume);
    float getVolume() const;
    void setDelay(float delay);
    float getDelay() const;

private:
    float delay;

};

#endif	/* _ECHO_H */


/* 
 * File:   Echo.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 12:59
 */

#ifndef _ECHO_H
#define	_ECHO_H
#include "DiskreteEffect.h"

class Echo : public Effect{
public:
    Echo();
    Echo(const Echo& orig);
    virtual ~Echo();

    void apply(DataChunk &samples);

    void setVolume(float volume);
    float getVolume() const;
    void setDelay(float delay);
    float getDelay() const;

private:
    float delay,volume;

};

#endif	/* _ECHO_H */


/* 
 * File:   Effect.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 14:51
 */

#ifndef _EFFECT_H
#define	_EFFECT_H

#include "DataChunk.h"

class Effect {
public:
    
    virtual void apply(DataChunk &samples)=0;
private:

};

#endif	/* _EFFECT_H */


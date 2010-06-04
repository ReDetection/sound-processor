/* 
 * File:   WaveEffect.h
 * Author: rd
 *
 * Created on 26 Май 2010 г., 14:36
 */

#ifndef _WAVEEFFECT_H
#define	_WAVEEFFECT_H

#include "DataChunk.h"


class WaveEffect {
public:
    WaveEffect();
    WaveEffect(const WaveEffect& orig);
    virtual ~WaveEffect();

    //модифицируем сэмплики
    virtual char apply(char sample)const =0;
    virtual short apply(short sample)const =0;

    virtual void apply(DataChunk &samples);
    
private:

    unsigned int i;

};

#endif	/* _WAVEEFFECT_H */


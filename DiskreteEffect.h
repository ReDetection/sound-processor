/* 
 * File:   WaveEffect.h
 * Author: rd
 *
 * Created on 26 Май 2010 г., 14:36
 */

#ifndef _WAVEEFFECT_H
#define	_WAVEEFFECT_H

#include "Effect.h"


class DiskreteEffect :public Effect {
public:
    DiskreteEffect();
    DiskreteEffect(const DiskreteEffect& orig);
    virtual ~DiskreteEffect();

    //модифицируем сэмплики
    virtual char apply(char sample) =0;
    virtual short apply(short sample) =0;

    virtual void apply(DataChunk &samples);

};

#endif	/* _WAVEEFFECT_H */


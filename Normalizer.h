/* 
 * File:   Normalizer.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 12:11
 */

#ifndef _NORMALIZER_H
#define	_NORMALIZER_H
#include "Amplifier.h"

class Normalizer : public Amplifier {
public:
    Normalizer();
    Normalizer(const Normalizer& orig);
    virtual ~Normalizer();

    virtual void apply(DataChunk& samples);
private:

};

#endif	/* _NORMALIZER_H */


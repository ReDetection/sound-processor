/* 
 * File:   Compressor.h
 * Author: rd
 *
 * Created on 4 Июнь 2010 г., 20:32
 */

#ifndef _COMPRESSOR_H
#define	_COMPRESSOR_H
#include "DiskreteEffect.h"

class Compressor :public DiskreteEffect{
public:
    Compressor(double iknee,double oknee);
    Compressor(const Compressor& orig);
    virtual ~Compressor();
    
    virtual void apply(DataChunk &samples);

    void setKnee(double iknee,double oknee);
    float getOknee() const;
    float getIknee() const;

protected:
    virtual short apply(short sample);
    
private:
    double iknee,oknee;
    double a1,a2,b;
};

#endif	/* _COMPRESSOR_H */


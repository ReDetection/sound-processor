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
    
    virtual char apply(char sample)const;
    virtual short apply(short sample)const;

    void setKnee(double iknee,double oknee);
    float getOknee() const;
    float getIknee() const;
private:
    double iknee,oknee;
    double a1,a2,bc,bs;
};

#endif	/* _COMPRESSOR_H */


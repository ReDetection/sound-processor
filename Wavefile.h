/* 
 * File:   Wavefile.h
 * Author: rd
 *
 * Created on 23 Май 2010 г., 12:08
 */

#ifndef _WAVEFILE_H
#define	_WAVEFILE_H
#include "Waveheader.h"
#include "WaveEffect.h"

class Wavefile {
public:

    Wavefile(const char* filename);//load from file
    //Wavefile(Waveheader &header);//create new one
    Wavefile(const Wavefile& orig);
    virtual ~Wavefile();
    

    void *getData();
    unsigned int getDataSize();

    void applyEffect(WaveEffect *effect);

    void store(const char* filename); //save into file
    

private:
    Waveheader *hdr;
    void *data;
};

#endif	/* _WAVEFILE_H */


/* 
 * File:   Wavefile.h
 * Author: rd
 *
 * Created on 23 Май 2010 г., 12:08
 */

#ifndef _WAVEFILE_H
#define	_WAVEFILE_H
#include "Waveheader.h"

class Wavefile {
public:

    Wavefile(const char* filename);//load from file
    //Wavefile(Waveheader &header);//create new one
    Wavefile(const Wavefile& orig);
    virtual ~Wavefile();


    void *getData();
    unsigned int getDataSize();

    template <class T> void applyEffect(T Effect);
    

private:
    Waveheader *hdr;
    void *data;
};

#endif	/* _WAVEFILE_H */


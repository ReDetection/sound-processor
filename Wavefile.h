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
    

private:
    Waveheader *hdr;
    void *data;
};

#endif	/* _WAVEFILE_H */


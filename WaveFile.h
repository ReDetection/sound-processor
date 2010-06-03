/* 
 * File:   Wavefile.h
 * Author: rd
 *
 * Created on 23 Май 2010 г., 12:08
 */

#ifndef _WAVEFILE_H
#define	_WAVEFILE_H
#include "WaveEffect.h"
#include "List.h"
#include "WaveChunk.h"

class WaveFile {
public:

    WaveFile(const char* filename);//load from file
    //Wavefile(Waveheader &header);//create new one
    WaveFile(const WaveFile& orig);
    virtual ~WaveFile();

    void applyEffect(WaveEffect *effect);

    void store(const char* filename); //save into file
    

private:
    List<WaveChunk> chunks;
    int globalsize;
};

#endif	/* _WAVEFILE_H */


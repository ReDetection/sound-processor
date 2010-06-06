/* 
 * File:   Wavefile.h
 * Author: rd
 *
 * Created on 23 Май 2010 г., 12:08
 */

#ifndef _WAVEFILE_H
#define	_WAVEFILE_H
#include "Effect.h"
#include "List.h"
#include "WaveChunk.h"

class WaveFile {
public:

    WaveFile();//load from file
    WaveFile(const WaveFile& orig);
    virtual ~WaveFile();

    bool wasError();
    void applyEffect(Effect *effect);

    bool load(const char* filename);//load from file
    void store(const char* filename); //save into file
    

private:
    List<WaveChunk> chunks;
    int globalsize;
    bool waserror;
};

#endif	/* _WAVEFILE_H */


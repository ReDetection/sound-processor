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

    WaveFile();
    WaveFile(const WaveFile& orig);
    virtual ~WaveFile();

    bool wasError()const;
    bool isLoaded()const;
    void applyEffect(Effect *effect);
    void applyEffects(const List<Effect> &effects);

    bool load(const char* filename);//load from file
    void store(const char* filename); //save into file
    

private:
    void applyEffect(Effect *effect,bool deleteEffect);
    List<WaveChunk> chunks;
    int globalsize;
    bool waserror,loaded;
};

#endif	/* _WAVEFILE_H */


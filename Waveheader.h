/* 
 * File:   Waveheader.h
 * Author: rd
 *
 * Created on 23 Май 2010 г., 12:13
 */

#ifndef _WAVEHEADER_H
#define	_WAVEHEADER_H
#include <fstream>

class Waveheader {
public:
    Waveheader();
    Waveheader(const Waveheader& orig);
    virtual ~Waveheader();

    void load(std::ifstream& in);


    unsigned short channels,blockAlign,bitsPerSample;
    unsigned int samplesPerSecond,bytesPerSecond,dataSize;
    

private:
    union ttype{
        unsigned int i;
        char c[4];
    };

    void seekChunk(std::ifstream& in, unsigned int chunk);

};

#endif	/* _WAVEHEADER_H */


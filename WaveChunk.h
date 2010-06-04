/* 
 * File:   WaveChunk.h
 * Author: rd
 *
 * Created on 2 Июнь 2010 г., 20:33
 */

#ifndef _WAVECHUNK_H
#define	_WAVECHUNK_H
#include <fstream>
#include "union.h"

class WaveChunk {
public:

    static const unsigned int FORMATID=544501094;
    static const unsigned int DATAID=1635017060;
    
    WaveChunk();
    WaveChunk(const WaveChunk& orig);
    virtual ~WaveChunk(){};

    unsigned int getSize()const;
    unsigned int getID()const;

    static WaveChunk *load(std::ifstream& in);
    void save(std::ofstream& out)const;

protected:
    
    virtual void loadData(std::ifstream& in)=0;
    virtual void saveData(std::ofstream& out)const=0;

private:

    void init(unsigned int id, unsigned int size);
    uintchar id,size;

};

#endif	/* _WAVECHUNK_H */


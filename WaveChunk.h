/* 
 * File:   WaveChunk.h
 * Author: rd
 *
 * Created on 2 Июнь 2010 г., 20:33
 */

#ifndef _WAVECHUNK_H
#define	_WAVECHUNK_H
#include "union.h"
#include <fstream>

class WaveChunk {
public:
    unsigned int getSize()const;
    uintchar getID()const;

    static void load(std::ifstream in);
    void save(std::ofstream out);

protected:
    
    virtual void loadData(std::ifstream in)=0;
    virtual void saveData(std::ofstream out)=0;

private:

    void init(uintchar id,uintchar size);
    uintchar id,size;

};

#endif	/* _WAVECHUNK_H */


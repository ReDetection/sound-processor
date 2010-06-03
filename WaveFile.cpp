/* 
 * File:   Wavefile.cpp
 * Author: rd
 * 
 * Created on 23 Май 2010 г., 12:08
 */

#include "WaveFile.h"
#include "union.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

WaveFile::WaveFile(const char* filename) {
    std::ifstream in(filename,std::ios::in | std::ios::binary);
    in.exceptions( std::ios::failbit);
    uintchar t;

    try{
        in.read(t.c,4);
        if( t.i!= 1179011410 ) // "RIFF"
            throw "This is not wavefile";

        in.read(t.c,4);
        globalsize=t.i;

        in.read(t.c,4);
        if( t.i!= 1163280727 ) // "WAVE"
            throw "This is not wavefile";

        WaveChunk sta; //фактически, обход невозможности вызвать статический метод у не экземпляра класса
        for(unsigned int i=4;i<globalsize;){
            WaveChunk *chunk = sta.load(in);
            chunks.append(chunk);
            i+=chunk->getSize();
            i+=8;
        }
    }catch(std::ios::failure f){
            throw "Неожиданный конец файла";
    }
}

WaveFile::WaveFile(const WaveFile& orig) {
    throw "Не должен этот класс копироваться!";
}

WaveFile::~WaveFile() {
}

void WaveFile::applyEffect(WaveEffect *effect){
//    effect->apply((char*)data,hdr->dataSize, hdr->bitsPerSample/8);
    delete effect;
}

void WaveFile::store(const char* filename){
    
}
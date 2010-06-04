/* 
 * File:   Wavefile.cpp
 * Author: rd
 * 
 * Created on 23 Май 2010 г., 12:08
 */

#include "WaveFile.h"
#include "union.h"
#include "FormatChunk.h"
#include "DataChunk.h"
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

        const FormatChunk *lastformat;
        for(unsigned int i=4;i<globalsize;){
            WaveChunk *chunk = WaveChunk::load(in);
            chunks.append(chunk);
            i+=chunk->getSize();
            i+=8;
            switch (chunk->getID()){
                case WaveChunk::FORMATID:
                    lastformat=(const FormatChunk*)chunk;
                    break;
                case WaveChunk::DATAID:
                    ((DataChunk*)chunk)->assignFormat(lastformat);
                    break;
            }
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

void WaveFile::applyEffect(Effect *effect){
    for(int i=chunks.getSize()-1;i>=0;i--)
        if(chunks[i].getID() == WaveChunk::DATAID)
            effect->apply((DataChunk&)(chunks[i]));
    delete effect;
}

void WaveFile::store(const char* filename){
    std::ofstream out(filename,std::ios::out | std::ios::binary);
    out.write("RIFF",4);
    out.write((char*)&globalsize,4);//TODO: пересчет через чанки
    out.write("WAVE",4);
    int max=chunks.getSize();
    for(int i=0;i<max;i++)
        chunks[i].save(out);
    out.close();
}
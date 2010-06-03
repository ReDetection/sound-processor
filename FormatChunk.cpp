/* 
 * File:   FormatChunk.cpp
 * Author: rd
 * 
 * Created on 3 Июнь 2010 г., 12:49
 */


#include "FormatChunk.h"
#include "WaveChunk.h"

FormatChunk::FormatChunk() {
}

FormatChunk::FormatChunk(const FormatChunk& orig) {
}

FormatChunk::~FormatChunk() {
}

void FormatChunk::loadData(std::ifstream& in){
    if(getSize()!=sizeof(WaveFormat))
        throw "Поврежденный format-chunk";
    in.read((char*)(&format),sizeof(WaveFormat));
}

void FormatChunk::saveData(std::ofstream& out)const{
    out.write((const char*)&format,sizeof(WaveFormat));
}


unsigned short FormatChunk::getFormatTag() const{
    
    
}
unsigned short FormatChunk::getChannels()const{

}
unsigned int FormatChunk::getSamplesPerSec()const{

}
unsigned int FormatChunk::getAvgBytesPerSec()const{

}
unsigned short FormatChunk::getBlockAlign()const{

}
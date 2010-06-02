/* 
 * File:   WaveChunk.cpp
 * Author: rd
 * 
 * Created on 2 Июнь 2010 г., 20:33
 */

#include "WaveChunk.h"
#include "UnknownChunk.h"

unsigned int WaveChunk::getSize()const {
    return size.i;
}
uintchar WaveChunk::getID() const{
    return id;
}

void WaveChunk::load(std::ifstream in){
    uintchar id,size;
    in.read(id.c,4);
    in.read(size.c,4);

    WaveChunk *chunk;
    switch (id.i){
        default:
            chunk = new UnknownChunk();
            break;
    }
    chunk->init(id,size);
    chunk->loadData(in);   

}

void WaveChunk::save(std::ofstream out){
    out.write(id.c,4);
    out.write(size.c,4);
    saveData(out);
}
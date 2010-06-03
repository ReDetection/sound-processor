/* 
 * File:   WaveChunk.cpp
 * Author: rd
 * 
 * Created on 2 Июнь 2010 г., 20:33
 */

#include "WaveChunk.h"
#include "UnknownChunk.h"

WaveChunk::WaveChunk(){
    id.i=0;
    size.i=0;
}

WaveChunk::WaveChunk(const WaveChunk& orig){
    throw "Не должен этот класс копироваться!";
}

unsigned int WaveChunk::getSize()const {
    return size.i;
}
uintchar WaveChunk::getID() const{
    return id;
}

WaveChunk* WaveChunk::load(std::ifstream& in){
    uintchar id,size;
    in.read(id.c,4);
    in.read(size.c,4);

    WaveChunk *chunk;
    
    switch (id.i){
  //      case 544501094: //"fmt "

          //  break;
        default:
            chunk = new UnknownChunk();
            break;
    }
    chunk->init(id.i,size.i);
    chunk->loadData(in);
    return chunk;

}

void WaveChunk::save(std::ofstream& out){
    out.write(id.c,4);
    out.write(size.c,4);
    saveData(out);
}

void WaveChunk::init(unsigned int id, unsigned int size){
    this->id.i=id;
    this->size.i=size;
}
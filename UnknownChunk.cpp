/* 
 * File:   UnknownChunk.cpp
 * Author: rd
 * 
 * Created on 2 Июнь 2010 г., 22:35
 */

#include <stdlib.h>

#include "UnknownChunk.h"

UnknownChunk::UnknownChunk() {
    data=0;
}

UnknownChunk::UnknownChunk(const UnknownChunk& orig) {
    throw "Не планировалось делать копирование этого класса";
}

UnknownChunk::~UnknownChunk() {
    if(data!=0)
        free(data);
}

void UnknownChunk::loadData(std::ifstream& in){
    int sz=getSize();
    data = malloc(sz);
    if(data==0)
        throw "Недостаточно памяти! :(";
    in.read(data,sz);
}

void UnknownChunk::saveData(std::ofstream& out){
    out.write(data,getSize());
}
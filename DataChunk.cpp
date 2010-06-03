/* 
 * File:   DataChunk.cpp
 * Author: rd
 * 
 * Created on 3 Июнь 2010 г., 21:58
 */

#include "DataChunk.h"

DataChunk::DataChunk() {
}

DataChunk::DataChunk(const DataChunk& orig) {
    throw "Не должен этот класс копироваться!";
}

DataChunk::~DataChunk() {
}


void DataChunk::assignFormat(const FormatChunk* format){
    this->format=format;
}

const FormatChunk * DataChunk::getFormat() const{
    return format;
}

/* 
 * File:   Waveheader.cpp
 * Author: rd
 * 
 * Created on 23 Май 2010 г., 12:13
 */


#include <stdlib.h>

#include "Waveheader.h"
#include "WaveFile.h"

Waveheader::Waveheader() {
    channels=blockAlign=bitsPerSample=0;
    samplesPerSecond=bytesPerSecond=dataSize=0;
}

Waveheader::Waveheader(const Waveheader& orig) {
    channels=orig.channels;
    blockAlign=orig.blockAlign;
    bitsPerSample=orig.bitsPerSample;
    samplesPerSecond=orig.samplesPerSecond;
    bytesPerSecond=orig.bytesPerSecond;
    dataSize=orig.dataSize;
}

Waveheader::~Waveheader() {

}

void Waveheader::load(std::ifstream& in){
    ttype t;
    in.read(t.c,4);
    if( t.i!= 1179011410 ) // "RIFF"
        throw "This is not wavefile";
    in.seekg(4,std::ios_base::cur);
    in.read(t.c,4);
    if( t.i!= 1163280727 ) // "WAVE"
        throw "This is bad wavefile :)";

    //тут должен начаться format chunk
    seekChunk(in,544501094); // "fmt "  //while - т.к. мало ли, вдруг всплывет файло с "лишними" чанками

    in.read(t.c,4);//размер
    if(t.i>0){ //ну чисто на всякий случай, оно всегда должно быть больше нуля
        in.read((char*)&channels,2);//это не channels, это format tag
        if(channels!=1) //для PCM он дожен быть 1
            throw "This is bad wavefile :)";
        in.read((char*)&channels,2);//а вот это уже channels :)
        in.read((char*)&samplesPerSecond,4);
        in.read((char*)&bytesPerSecond,4);//это средне-приблизительное значение, по нему не надо ориентироваться
        in.read((char*)&blockAlign,2);
        in.read((char*)&bitsPerSample,2);
    }

    //надо бы начать данные читать уже
    seekChunk(in,1635017060); // "data"
    in.read((char*)&dataSize,4);

    //вот на этом месте мне захотелось объединить wavefile и waveheader, но
    //глубокой ночью я не смог придумать должного объясняния, зачем мне это надо


   // а вот сейчас я понял, что надо бы вообще переделать wavefile и удалить waveheader, но ввести список чанков. но это потом..

}

/*
 заголовок нужногго чанка будет уже прочитан по завершении этого метода
 */
void Waveheader::seekChunk(std::ifstream& in, unsigned int chunk){
    ttype t;
    in.read(t.c,4);
    while( t.i!= chunk ){
        in.read(t.c,4);
        in.seekg(t.i,std::ios_base::cur);
        in.read(t.c,4);
    }
}
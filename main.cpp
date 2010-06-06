/* 
 * File:   main.cpp
 * Author: rd
 *
 * Created on 17 Май 2010 г., 22:48
 */

#include <stdlib.h>

#include "FileSelectorUI.h"
#include "WaveFile.h"
#include "EditUI.h"
/*
 * 
 */
int main(int argc, char** argv) {
////    StringArray array;
////    array.addConst("расрас");
////    array.addConst("двадва");
////    array.putConst("полтора",1);
////    array.raiseUp(2);
////    for(int i=array.getSize()-1;i>=0;i--)
////        printf("%s\n",array[i]);
////    std::ofstream of;
////    of.open("123",std::ios::binary | std::ios::out);
////    array.store(of);
////    of.close();
////
////    StringArray aa;
////    std::ifstream in;
////    in.open("123",std::ios::binary | std::ios::in);
////    aa.load(in);
////    for(int i=aa.getSize()-1;i>=0;i--)
////        printf("%s\n",aa[i]);
//
////    Menu menu(&array,"Так вот:");
////
////    menu.chooseIndex();
//
//
////    FileSelectorUI fselector;
////    printf("\n\n%s\n",fselector.select());
//
//    try{
//        WaveFile wave("/home/rd/Desktop/свалка/audiodump.wav");
////        WaveFile wave("/tmp/2.wav");
////        WaveFile wave("/tmp/lin1.wav");
////        wave.applyEffect(new Compressor(0.5,0.75));
////        wave.applyEffect(new Overdrive());
////        wave.applyEffect(new Distortion());
////        wave.applyEffect(new Amplifier(0.5));
////        wave.applyEffect(new Echo(0.025,0.8));
//        wave.applyEffect(new Distortion());
////        wave.applyEffect(new Overdrive());
////        wave.applyEffect(new Echo(0.07,0.5));
////        wave.applyEffect(new Echo(0.12,0.3));
//        wave.store("/tmp/3.wav");
//    }catch(const char* msg){
//        printf(msg);
////        throw msg;
//    }


    FileSelectorUI selector;

    WaveFile wave;
    bool loaded=false;//переписать эти пять строк костыля на что-нибудь приличное
    while(!loaded){
        try{
            wave.load(selector.select());
            loaded=true;
        }catch(std::ios::failure f){
            loaded=false;
        }
    }

    EditUI ui(wave);
    
    return (0);
}


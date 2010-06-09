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
#include "ArgsParser.h"


int main(int argc, char** argv){
    //какой-то в мэйне код сумбурный..

    ArgsParser::parse(argc,argv);
    const char *inputfile = ArgsParser::getInput(),
               *outputfile = ArgsParser::getOutput();
    
    FileSelectorUI selector;

    WaveFile wave;
    try{wave.load(inputfile);}catch(...){}
        
    while(!wave.isLoaded()){ 
        inputfile = selector.select();
        try{
            wave.load(inputfile);
        }catch(std::ios::failure f){}
    }

    if(ArgsParser::getEffects()!=0)
        wave.applyEffects(*ArgsParser::getEffects());
    else
        EditUI ui(wave);

    if(outputfile==0)
            outputfile=selector.select();
    wave.store(outputfile);

    return (0);
}


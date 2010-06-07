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
int main(int argc, char** argv){

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
    
    wave.store(selector.select());

    
    return (0);
}


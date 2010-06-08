/* 
 * File:   ArgsParser.cpp
 * Author: rd
 * 
 * Created on 8 Июнь 2010 г., 11:18
 */

#include "ArgsParser.h"
#include <cstring>

bool ArgsParser::debug=false;
int ArgsParser::effects=0;
List<int> ArgsParser::list;
const char * ArgsParser::input=0;
const char * ArgsParser::output=0;

void ArgsParser::parse(int argc, char** argv) {
    if(argc>0)
        for(int i=0;i<argc;i++){
            if(strcmp("-debug",argv[i])==0){
                debug=true;
                continue;
            }
            if(strcmp("-i",argv[i])==0){
                input=argv[++i];
                continue;
            }
            if(strcmp("-o",argv[i])==0){
                output=argv[++i];
                continue;
            }
            if(strncmp("-amp",argv[i],4)==0){
                
                continue;
            }


        }
}

bool ArgsParser::getDebug(){
    return debug;
}

const char * ArgsParser::getInput(){
    return input;
}

const char * ArgsParser::getOutput(){
    return output;
}


int ArgsParser::getEffects(){
    return effects;
}
int ArgsParser::getEffect(int index){
    return list[index];
}
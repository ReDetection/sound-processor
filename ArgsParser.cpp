/* 
 * File:   ArgsParser.cpp
 * Author: rd
 * 
 * Created on 8 Июнь 2010 г., 11:18
 */

#include "ArgsParser.h"
#include "Amplifier.h"
#include "Normalizer.h"
#include "Echo.h"
#include "Compressor.h"
#include "Overdrive.h"
#include "Distortion.h"
#include "Reverb.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

bool ArgsParser::debug=false;
List<Effect> ArgsParser::list;
const char * ArgsParser::input=0;
const char * ArgsParser::output=0;

void ArgsParser::parse(int argc, char** argv) {
    for(int i=1;i<argc;i++){
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
            list.append(new Amplifier(std::atof(argv[++i])));
            continue;
        }
        if(strncmp("-nor",argv[i],4)==0){
            list.append(new Normalizer());
            continue;
        }
        if(strcmp("-echo",argv[i])==0){
            float delay = atof(argv[++i]);
            list.append(new Echo(delay,atof(argv[++i])));
            continue;
        }
        if(strncmp("-cle",argv[i],4)==0){
            float delay = atof(argv[++i]);
            float amp=atof(argv[++i]);
            list.append(new Amplifier(1.0/(1.0+amp)));
            list.append(new Echo(delay,amp));
            list.append(new Normalizer());
            continue;
        }
        if(strncmp("-comp",argv[i],5)==0){
            float x = atof(argv[++i]);
            list.append(new Compressor(x,atof(argv[++i])));
            continue;
        }
        if(strncmp("-over",argv[i],5)==0){
            list.append(new Overdrive());
            continue;
        }
        if(strncmp("-dis",argv[i],4)==0){
            list.append(new Distortion());
            continue;
        }
        if(strncmp("-rev",argv[i],4)==0){
            float delay = atof(argv[++i]);
            list.append(new Reverb(delay,atof(argv[++i])));
            continue;
        }
        if(strcmp("-h",argv[i])==0 || strncmp("--h",argv[i],3)==0){
            std::cout << "Возможные опции:\n\t" << argv[0] << " [ -i ФАЙЛ ]"
                    " [ -o ФАЙЛ ] [ -debug ] [ ЭФФЕКТЫ... ]\n, где ЭФФЕКТЫ "
                    "могут состоять из:\n\t-amp, -amplifier КОЭФФИЦИЕНТ\n\t"
                    "-nor, -normalizer\n\t-echo ЗАДЕРЖКА КОЭФФ_АМПЛИТУДЫ\n\t"
                    "-cle, -cleverecho ЗАДЕРЖКА КОЭФФ_АМПЛИТУДЫ\n\t-rev, "
                    "-reverb ЗАДЕРЖКА КОЭФФ_АМПЛИТУДЫ\n\t-comp, "
                    "-compressor X Y, где X и Y - коориднаты точки перегиба,"
                    "\n\t\tобе больше нуля и меньше единицы\n\t-over, "
                    "-overdrive\n\t-dis, -distortion\n";
            exit(0);
        }
        std::cout<<"Неизвестная опция: " << argv[i] << std::endl;
        exit(1);

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


List<Effect> *ArgsParser::getEffects(){
    return list.getSize() > 0 ? &list : 0;
}
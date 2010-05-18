/* 
 * File:   main.cpp
 * Author: rd
 *
 * Created on 17 Май 2010 г., 22:48
 */

#include <stdlib.h>
#include "StringArray.h"
#include <stdio.h>
#include <fstream>
/*
 * 
 */
int main(int argc, char** argv) {
    StringArray array;
    array.addConst("расрас");
    array.addConst("двадва");
    array.putConst("полтора",1);
    array.raiseUp(2);
    for(int i=array.getSize()-1;i>=0;i--)
        printf("%s\n",array[i]);
    std::ofstream of;
    of.open("123",std::ios::binary | std::ios::out);
    array.store(of);
    of.close();

    StringArray aa;
    std::ifstream in;
    in.open("123",std::ios::binary | std::ios::in);
    aa.load(in);
    for(int i=aa.getSize()-1;i>=0;i--)
        printf("%s\n",aa[i]);
    
    return (EXIT_SUCCESS);
}


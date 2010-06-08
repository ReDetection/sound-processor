/* 
 * File:   ArgsParser.h
 * Author: rd
 *
 * Created on 8 Июнь 2010 г., 11:18
 */

#ifndef _ARGSPARSER_H
#define	_ARGSPARSER_H

#include "List.h"
#include "String.h"
#include "StringList.h"
#include "Effect.h"


class ArgsParser {
public:
    static void parse(int argc,char**argv);
    static const char* getInput();
    static const char * getOutput();
    static int getEffects();
    static int getEffect(int index);
    static bool getDebug();

private:
    static int argc;
    static char **argv;

    static int effects;
    static List<Effect> list;
    static bool debug;
    static const char * input,*output;
};

#endif	/* _ARGSPARSER_H */


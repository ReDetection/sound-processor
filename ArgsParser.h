/* 
 * File:   ArgsParser.h
 * Author: rd
 *
 * Created on 8 Июнь 2010 г., 11:18
 */

#ifndef _ARGSPARSER_H
#define	_ARGSPARSER_H

class ArgsParser {
public:
    ArgsParser(int argc,char**argv);
    ArgsParser(const ArgsParser& orig);
    virtual ~ArgsParser();


    const char* getInput()const;
    const char * getOutput()const;
    int getEffects()const;
    const int getEffect(int index);

private:

};

#endif	/* _ARGSPARSER_H */


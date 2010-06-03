/* 
 * File:   DataChunk.h
 * Author: rd
 *
 * Created on 3 Июнь 2010 г., 21:58
 */

#ifndef _DATACHUNK_H
#define	_DATACHUNK_H

#include "FormatChunk.h"
#include "UnknownChunk.h"


class DataChunk:public UnknownChunk {
public:
    DataChunk();
    DataChunk(const DataChunk& orig);
    virtual ~DataChunk();

    void assignFormat(const FormatChunk* format );
    const FormatChunk *getFormat()const;

private:
    const FormatChunk* format;
};

#endif	/* _DATACHUNK_H */


/* 
 * File:   StringArray.h
 * Author: rd
 *
 * Created on 17 Май 2010 г., 22:51
 *
 * Remark: после того, как я добавил в курсач список(List.h), появилось желание
 * использовать его вместо StringArray, но, посмотрев, сколько тут вкусного и
 * полезного, я передумал ) может, позже..
 */

#ifndef _STRINGLIST_H
#define	_STRINGLIST_H
#include <fstream>

#include "List.h"
#include "String.h"

class StringList {
public:
    StringList();
//    StringArray(int count);
    StringList(const StringList& orig);
    virtual ~StringList();

    const char* operator[](int n) const;
    const char* get(int n)const;

    //жесткая вставка в строго указанное место
    int putConst(const char* string, int place);
    int put(char* string, int place);
    int putClone(const char*string, int place);

    //вставка в начало(автоматический сдвиг)
    int addConst(const char* string);
    int add(char* string);
    int addClone(const char*string);

    int appendConst(const char* string);
    int append(char* string);
    int appendClone(const char* string);

    void raiseUp(int which);

    int getSize()const;//возвращает не size, а количество занятых мест в массиве!

    void store(std::ofstream& out)const;
    void load(std::ifstream& in);

protected:
    List<String> array;
};

#endif	/* _STRINGARRAY_H */


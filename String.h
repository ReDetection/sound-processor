/* 
 * File:   String.h
 * Author: rd
 *
 * Created on 6 Июнь 2010 г., 23:36
 */

#ifndef _STRING_H
#define	_STRING_H

class String {
public:
    String();
    String(const char * str);
    String(const String& orig);
    virtual ~String();

    void assign(const char* str); //использует существующую
    void load(const char *str);//копирует из объекта
    void set(char *str);//присваивает себе. при удалении объекта, освободит память

    const char* get()const;

private:
    inline void release();
    char *data;
    char state;
    static const char FREE=0,CONST=1,MY=2;
};

#endif	/* _STRING_H */


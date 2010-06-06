/* 
 * File:   String.cpp
 * Author: rd
 * 
 * Created on 6 Июнь 2010 г., 23:36
 */

#include "String.h"
#include <cstring>

String::String() {
    state=FREE;
}
String::String(const char* str){
    data=(char*)str;
    state=CONST;
}

String::String(const String& orig) {
    state=FREE;
    load(orig.get());
}

String::~String() {
    release();
}

const char* String::get()const{
    return data;
}
void String::load(const char *str){
    release();
    data=strdup(str);
}
void String::release(){
    if(state=MY)
        free(data);
}

void String::assign(const char* str){
    release();
    state=CONST;
    data=(char*)str;
}
void String::set(char* str){
    release();
    state=MY;
    data=str;
}


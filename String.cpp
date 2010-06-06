/* 
 * File:   String.cpp
 * Author: rd
 * 
 * Created on 6 Июнь 2010 г., 23:36
 */

#include "String.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

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
    if(state==MY)
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
void String::store(std::ofstream& out)const{
    if(state==FREE)
        throw "ээ, где-то я навалял, не должно быть тут такого";
    int len = strlen(data);
    out.write((char*)&len,sizeof(int));
    out.write(data,len);
}
void String::restore(std::ifstream& in){
    release();
    state=MY;
    int len;
    in.read((char*)&len,sizeof(int));
    data = (char*)malloc(len+1);
    in.read(data,len);
    data[len]=0;
}

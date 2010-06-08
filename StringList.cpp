/* 
 * File:   StringArray.cpp
 * Author: rd
 * 
 * Created on 17 Май 2010 г., 22:51
 */

#include <cstring>
#include <cstdlib>

#include "StringList.h"
#include "FileSelectorUI.h"

StringList::StringList() {}

StringList::StringList(const StringList& orig) {
    throw "Not implemented yet";
}

StringList::~StringList() {
}

const char * StringList::get(int n)const{
    return array.getItem(n)->get();
}
const char * StringList::operator [](int n)const{
    return get(n);
}

int  StringList::putConst(const char* string, int place){
    return array.append(new String(string),place);
}

int StringList::put(char* string, int place){
    String *a=new String();
    a->set(string);
    return array.append(a,place);
}
int StringList::putClone(const char* string, int place){
    return put(strdup(string),place);
}

int StringList::addConst(const char* string){
    return putConst(string,0);
}
int StringList::add(char* string){
    return put(string,0);

}
int StringList::addClone(const char* string){
    return add(strdup(string));
}

void StringList::raiseUp(int which){
    array.raiseUp(which);
}

int StringList::getSize()const{
    array.getSize();
}

void StringList::store(std::ofstream& out)const{
    char ID='S';
    out.write(&ID, 1);
    int len = array.getSize();
    out.write((char*)&len,sizeof(int));
    for(int i=0;i<len;i++)
        array.getItem(i)->store(out);
    
}

void StringList::load(std::ifstream &in){
    char ID=0;
    int size;
    in.read(&ID,1);//сверяем сигнатруру
    if(ID!='S'){
        in.seekg(-1);
        return; //TODO: или сделать исключение?
    }
    in.read((char*)&size,sizeof(int));
    for(int i=0;i<size;i++){
        String *a = new String();
        a->restore(in);
        array.append(a);
    }
}

int StringList::appendConst(const char* string){
    return array.append(new String(string));
}
int StringList::append(char* string){
    String *s = new String();
    s->set(string);
    return array.append(s);
}
int StringList::appendClone(const char* string){
    return append(strdup(string));
}
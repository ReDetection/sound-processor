/* 
 * File:   StringArray.cpp
 * Author: rd
 * 
 * Created on 17 Май 2010 г., 22:51
 */

#include <cstring>
#include <cstdlib>

#include "StringArray.h"
#include "FileSelectorUI.h"

StringArray::StringArray() {}

StringArray::StringArray(const StringArray& orig) {
    throw "Not implemented yet";
}

StringArray::~StringArray() {
}

const char * StringArray::get(int n)const{
    return array.getItem(n)->get();
}
const char * StringArray::operator [](int n)const{
    return get(n);
}

int  StringArray::putConst(const char* string, int place){
    return array.append(new String(string),place);
}

int StringArray::put(char* string, int place){
    String *a=new String();
    a->set(string);
    return array.append(a,place);
}
int StringArray::putClone(const char* string, int place){
    return put(strdup(string),place);
}

int StringArray::addConst(const char* string){
    return putConst(string,0);
}
int StringArray::add(char* string){
    return put(string,0);

}
int StringArray::addClone(const char* string){
    return add(strdup(string));
}

void StringArray::raiseUp(int which){
    array.raiseUp(which);
}

int StringArray::getSize()const{
    array.getSize();
}

void StringArray::store(std::ofstream& out)const{
    char ID='S';
    out.write(&ID, 1);
//    int size = getSize();
//    out.write((const char *)&size,sizeof(int));
//    for(int i=0,k=0;i<size && k<this->size;i++,k++){
//        if(native[i]==ITEMFREE){
//            i--;
//            continue;
//        }
//        int t = strlen(array[i]);
//        out.write((const char *)&t,sizeof(int));
//        out.write(array[i],t);
//    }
    int len = array.getSize();
    out.write((char*)&len,sizeof(int));
    for(int i=0;i<len;i++)
        array.getItem(i)->store(out);
    
}

void StringArray::load(std::ifstream &in){
    char ID=0;
    int size;
    in.read(&ID,1);//сверяем сигнатруру
    if(ID!='S'){
        in.seekg(-1);
        return; //TODO: или сделать исключение?
    }
//    destroy();//очистим-ка все по-ленивому :3
//    allocate();
//
//    //загружаемся из потока
//    in.read((char *)&size,sizeof(int));
//    for(int i=0;i<size;i++){
//        int len;
//        char *str;
//        in.read((char *)&len,sizeof(int));
//        str =(char*) malloc(len+1);
//        str[len]=0;
//        in.read(str,len);
//        put(str,i);
//    }
    in.read((char*)&size,sizeof(int));
    for(int i=0;i<size;i++){
        String *a = new String();
        a->restore(in);
        array.append(a);
    }
}
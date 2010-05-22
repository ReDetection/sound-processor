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

#define ITEMFREE 0
#define ITEMOK 1
#define ITEMCONST 2

void StringArray::allocate(){
    array =(char **) calloc(size,sizeof(char *));
    native =(char *) calloc(size,1);
    if(array==0 || native==0)
        throw "Недостаточно памяти";
}
StringArray::StringArray() {
    size=5;
    allocate();

}
StringArray::StringArray(int count) {
    size=count;
    allocate();
}

StringArray::StringArray(const StringArray& orig) {
    size = orig.size;
    allocate();
    memcpy(native,orig.native,size);//копируем массивчик
    for(int i=0;i<size;i++){//возможно, имеет смысл заменить этот 4хстрочный цикл еще одним копированием и двухстрочным циклом
        if(native[i]==ITEMOK)
            array[i]=strdup(orig.array[i]);
        else
            array[i]=orig.array[i];
    }
}

StringArray::~StringArray() {
    destroy();
}

const char * StringArray::get(int n)const{
    return array[n];
}
const char * StringArray::operator [](int n)const{
    return get(n);
}

void StringArray::putConst(const char* string, int place){
    if(native[place]==ITEMOK)
        free(array[place]);
    array[place]=(char*)string;
    native[place]= string==0 ? ITEMFREE : ITEMCONST;
}
void StringArray::put(char* string, int place){
    if(native[place]==ITEMOK)
        free(array[place]);
    array[place]=(char*)string;
    native[place]= string==0 ? ITEMFREE : ITEMOK;
}
void StringArray::putClone(const char* string, int place){
    put(strdup(string),place);
}

void StringArray::shift(){
    if(native[size-1]==ITEMOK)
        free(array[size-1]);
    for(int i=size-1;i>0;i--){
        native[i]=native[i-1];
        array[i]=array[i-1];
    }
}
void StringArray::addConst(const char* string){
    shift();
    native[0]=ITEMCONST;
    array[0]=(char*)string;
}
void StringArray::add(char* string){
    shift();
    native[0]=ITEMOK;
    array[0]=(char*)string;
}
void StringArray::addClone(const char* string){
    add(strdup(string));
}

void StringArray::raiseUp(int which){
    char *tlink = array[--which];
    char tnat = native[which];
    for(int i=which;i>0;i--){
        native[i]=native[i-1];
        array[i]=array[i-1];
    }
    native[0]=tnat;
    array[0]=tlink;
}

int StringArray::getSize()const{
    int n=0;
    for(int i=0;i<size;i++)
        if(native[i]!=ITEMFREE)
            n++;
    return n;
}

void StringArray::store(std::ofstream& out)const{
    char ID='A';
    out.write(&ID, 1);
    int size = getSize();
    out.write((const char *)&size,sizeof(int));
    for(int i=0,k=0;i<size && k<this->size;i++,k++){
        if(native[i]==ITEMFREE){
            i--;
            continue;
        }
        int t = strlen(array[i]);
        out.write((const char *)&t,sizeof(int));
        out.write(array[i],t);
    }
}

void StringArray::load(std::ifstream &in){
    char ID=0;
    int size;
    in.read(&ID,1);//сверяем сигнатруру
    if(ID!='A'){
        in.seekg(-1);
        return; //TODO: или сделать исключение?
    }
    destroy();//очистим-ка все по-ленивому :3
    allocate();

    //загружаемся из потока
    in.read((char *)&size,sizeof(int));
    for(int i=0;i<size;i++){
        int len;
        char *str;
        in.read((char *)&len,sizeof(int));
        str =(char*) malloc(len+1);
        str[len]=0;
        in.read(str,len);
        put(str,i);
    }
}
void StringArray::destroy(){
    for(int i=0;i<size;i++)
        if(native[i]==ITEMOK)
            free(array[i]);
    free(array);
    free(native);
}
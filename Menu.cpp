/* 
 * File:   Menu.cpp
 * Author: rd
 * 
 * Created on 18 Май 2010 г., 15:16
 */

#include "Menu.h"
#include "StringArray.h"
#include <iostream>

Menu::Menu(const StringArray* elems,const char * hint) {
    items=elems;
    this->hint=hint;
}
Menu::Menu(){
    items=0;
    back=hint=0;
}

void Menu::setElements(const StringArray* elem){
    items = elem;
}

void Menu::setHint(const char* hint){
    this->hint=hint;
}

Menu::Menu(const Menu& orig) {
    hint=orig.hint;
    items=orig.items;
}

Menu::~Menu() {}

const char* Menu::choose() const{
    return items->get(chooseIndex());
}

int Menu::chooseIndex() const{
    int size=items->getSize(),result;
    int min= back==0 ? 1 : 0;

    if(hint!=0)
        std::cout << "\n" << hint;
    std::cout << "\n\n";
    if(back)
        std::cout << "\t0. " << back << "\n";
    for(int i=1;i<=size;i++)
        std::cout << "\t" << i << ". " << items->get(i-1) << "\n";
    std::cout << '\n';
    do{
        std::cout << "Ваш выбор: " << std::flush;
        std::cin >> result;
    }while(result > size || result <min);
    return result;
}

void Menu::setBack(const char* hint){
    back=hint;
}
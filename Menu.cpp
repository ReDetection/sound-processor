/* 
 * File:   Menu.cpp
 * Author: rd
 * 
 * Created on 18 Май 2010 г., 15:16
 */

#include "Menu.h"
#include "StringArray.h"
#include <iostream>

Menu::Menu(const StringArray& elems,const char * hint) {
    items=elems;
    this->hint=hint;
}

Menu::Menu(const Menu& orig) {
    hint=orig.hint;
    items=orig.items;
}

Menu::~Menu() {}

const char* Menu::choose() const{
    return items[chooseIndex()];
}

int Menu::chooseIndex() const{
    int size=items.getSize(),result;
    std::cout << "/n" << hint << "/n/n";
    for(int i=0;i<size;i++)
        std::cout << "/t" << i << ". " << items[i] << "/n";
    do{
        std::cout << "/nВаш выбор: ";
        std::cin >> result;
    }while(result <= size || result >0);
    return result;
}
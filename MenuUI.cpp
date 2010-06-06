/* 
 * File:   Menu.cpp
 * Author: rd
 * 
 * Created on 18 Май 2010 г., 15:16
 */

#include "MenuUI.h"
#include "List.h"
#include "String.h"
#include <iostream>

MenuUI::MenuUI(const List<String> elems,const char * hint) {
    items=elems;
    this->hint=hint;
    back=0;
}
MenuUI::MenuUI(){
    items=0;
    back=hint=0;
}

void MenuUI::setElements(const StringArray* elem){
    items = elem;
}

void MenuUI::setHint(const char* hint){
    this->hint=hint;
}

MenuUI::MenuUI(const MenuUI& orig) {
    hint=orig.hint;
    items=orig.items;
    back=orig.back;
}

MenuUI::~MenuUI() {}

const char* MenuUI::choose() const{
    return items->get(chooseIndex());
}

int MenuUI::chooseIndex() const{
    int size=items->getSize(),result;
    int min= back==0 ? 1 : 0;

    std::cout << '\n';
    if(hint!=0)
        std::cout << hint;
    std::cout << '\n';
    for(int i=1;i<=size;i++)
        std::cout << '\t' << i << ". " << items->get(i-1) << '\n';
    if(back)
        std::cout << "\t0. " << back << '\n';
    std::cout << '\n';
    do{
        std::cout << "Ваш выбор: " << std::flush;
        std::cin >> result;
    }while(result > size || result <min);
    return result;
}

void MenuUI::setBack(const char* hint){
    back=hint;
}
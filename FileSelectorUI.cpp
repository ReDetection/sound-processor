/* 
 * File:   FileSelectorUI.cpp
 * Author: rd
 * 
 * Created on 17 Май 2010 г., 22:50
 */

#include "FileSelectorUI.h"
#include <fstream>
#include <iostream>
#include <cstring>
 
FileSelectorUI::FileSelectorUI() {
    menu.setElements(&elems);
    menu.setHint("Выберите файл");
    menu.setBack("Вручную");

    std::ifstream in("recent.fls",std::ios::in | std::ios::binary);
    if(in){
        elems.load(in);//если нечего будет делать, заменить эту статику на что-нибудь глобально загружающееся
        in.close();
    }
}

FileSelectorUI::FileSelectorUI(const FileSelectorUI& orig) {
    throw "Этот класс не должен копироваться вообще"; //TODO: изучить, чокаво про статические классы в плюсах.
}

FileSelectorUI::~FileSelectorUI() {
    std::ofstream out("recent.fls",std::ios::out | std::ios::binary);
    if(out){
        elems.store(out);
        out.close();
    }
}

const char* FileSelectorUI::select(){
    int result = elems.getSize()>0 ? menu.chooseIndex() : 0;
    if(result==0){
        char str[128];
        std::cout<<"Введите путь к файлу: " << std::flush;
        if(elems.getSize()>0)
            getchar();//фикс, чтобы fgets не съел перевод строки от выбора меню
        fgets(str,128,stdin);
        str[strlen(str)-1]=0;//стираем символ перевода строки
        elems.addClone(str);//TODO:добавить проверку на существование такого файла
        return elems[0];
    }else
        return elems[result-1];
}


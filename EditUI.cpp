/* 
 * File:   EditUI.cpp
 * Author: rd
 * 
 * Created on 6 Июнь 2010 г., 20:33
 */

#include "EditUI.h"

EditUI::EditUI() {
    wave=0;
    init();
}

EditUI::EditUI(WaveFile& wave) {
    init();
    ui(wave);
}

EditUI::EditUI(const EditUI& orig) {
    throw "Не должен этот класс копироваться!";
}

EditUI::~EditUI() {
    delete menu;
}

void EditUI::ui(WaveFile& wave){
    this->wave=&wave;

    menu->choose();
}

void EditUI::init(){
    items.addConst("Усилитель");
    items.addConst("Нормализация");
    items.addConst("Эхо");
    items.addConst("Компрессия");
    items.addConst("Перегруз");
    items.addConst("Дисторшн");
    menu = new MenuUI(&items,"Выберите эффект");
    menu->setBack("Закончить редактирование");
}


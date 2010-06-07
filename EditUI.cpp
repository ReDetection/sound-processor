/* 
 * File:   EditUI.cpp
 * Author: rd
 * 
 * Created on 6 Июнь 2010 г., 20:33
 */

#include "Distortion.h"


#include "EditUI.h"
#include "Amplifier.h"
#include "Normalizer.h"
#include "Echo.h"
#include "Compressor.h"
#include "Overdrive.h"
#include <iostream>

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

    int result= 1;
    while(result){
        result = menu->chooseIndex();
        Effect *eff;
        switch(result){
            case 1:
                eff=new Amplifier(input("Введите коэффициент усиления:"));
                break;
            case 2:
                eff = new Normalizer();
                break;
            case 3:
                eff= new Echo(input("Введите зедержку"),input("Введите амплитуду"));
                break;
            case 4:
                eff = new Compressor(input("Введите входную точку перегиба( 0.0<x<1.0)"),input("Введите выходную точку перегиба( 0.0<y<1.0)"));
                break;
            case 5:
                eff = new Overdrive();
                break;
            case 6:
                eff = new Distortion();
                break;
            default:
                continue;
        }
        wave.applyEffect(eff);
    }

}

void EditUI::init(){
    items.appendConst("Усилитель");
    items.appendConst("Нормализация");
    items.appendConst("Эхо");
    items.appendConst("Компрессия");
    items.appendConst("Перегруз");
    items.appendConst("Дисторшн");
    menu = new MenuUI(&items,"Выберите эффект");
    menu->setBack("Закончить редактирование");
}


float EditUI::input(const char * hint) const{
    std::cout << hint << std::endl;
    float t;
    std::cin >> t;
    return t;
}
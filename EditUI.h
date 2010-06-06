/* 
 * File:   EditUI.h
 * Author: rd
 *
 * Created on 6 Июнь 2010 г., 20:33
 */

#ifndef _EDITUI_H
#define	_EDITUI_H

#include "WaveFile.h"
#include "MenuUI.h"
#include "StringArray.h"


class EditUI {
public:
    EditUI();
    EditUI(WaveFile& wave);
    EditUI(const EditUI& orig);
    virtual ~EditUI();

    void ui(WaveFile &wave);

    void init();
    
private:
    WaveFile *wave;
    MenuUI *menu;
    StringArray *items;
};

#endif	/* _EDITUI_H */


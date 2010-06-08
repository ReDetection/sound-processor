/* 
 * File:   FileSelectorUI.h
 * Author: rd
 *
 * Created on 17 Май 2010 г., 22:50
 */

#ifndef _FILESELECTORUI_H
#define	_FILESELECTORUI_H
#include "MenuUI.h"
#include "StringList.h"

class FileSelectorUI {

public:
    FileSelectorUI();
    FileSelectorUI(const FileSelectorUI& orig);
    virtual ~FileSelectorUI();

    const char *select();

private:
    StringList elems;//пункты меню
    MenuUI menu;

};

#endif	/* _FILESELECTORUI_H */


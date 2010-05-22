/* 
 * File:   Menu.h
 * Author: rd
 *
 * Created on 18 Май 2010 г., 15:16
 */

#ifndef _MENU_H
#define	_MENU_H

#include "StringArray.h"


class Menu {
public:
    Menu(const StringArray* elem,const char * hint);
    Menu(const Menu& orig);
    virtual ~Menu();

    int chooseIndex()const;
    const char *choose()const;

protected:
    const StringArray *items;
    const char* hint;
private:

};

#endif	/* _MENU_H */


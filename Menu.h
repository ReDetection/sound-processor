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
    Menu();

    virtual ~Menu();

    int chooseIndex()const;
    const char *choose()const;

    void setElements(const StringArray* elem);
    void setHint(const char * hint);
    void setBack(const char *hint);

protected:
    const StringArray *items;
    const char *hint,*back;
private:

};

#endif	/* _MENU_H */


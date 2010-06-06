/* 
 * File:   Menu.h
 * Author: rd
 *
 * Created on 18 Май 2010 г., 15:16
 */

#ifndef _MENU_H
#define	_MENU_H

#include "StringArray.h"
#include "List.h"


class MenuUI {
public:
    MenuUI(const List<std::string>* elem,const char * hint);
    MenuUI(const MenuUI& orig);
    MenuUI();

    virtual ~MenuUI();

    int chooseIndex()const;
    const char *choose()const;

    void setElements(const List<std::string>* elem);
    void setHint(const char * hint);
    void setBack(const char *hint);

protected:
    const List<std::string> *items;
    const char *hint,*back;
private:

};

#endif	/* _MENU_H */


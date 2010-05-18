/* 
 * File:   StringArray.h
 * Author: rd
 *
 * Created on 17 Май 2010 г., 22:51
 */

#ifndef _STRINGARRAY_H
#define	_STRINGARRAY_H
#include <fstream>

class StringArray {
public:
    StringArray();
    StringArray(int count);
    StringArray(const StringArray& orig);
    virtual ~StringArray();

    const char* operator[](int n) const;
    const char* get(int n)const;

    //жесткая вставка в строго указанное место
    void putConst(const char* string, int place);
    void put(char* string, int place);
    void putClone(const char*string, int place);

    //вставка в начало(автоматический сдвиг)
    void addConst(const char* string);
    void add(char* string);
    void addClone(const char*string);

    void raiseUp(int which);

    int getSize()const;//возвращает не size, а количество занятых мест в массиве!

    void store(std::ofstream& out)const;
    void load(std::ifstream& in);

protected:
    int size;
    char **array;
    /*
     * массив состояний соответствующих элементов из array.
     * (const/не-const, занят/свободен..)
     * свободен = 0, изменяемый = 1, константный = 2
     */
    char *native;


private:
    void allocate();
    void shift();//сдвиг элементов массива на 1 элемент в сторону
    void destroy();//мне надо вызвать деструктор без разрушения самого объкета
};

#endif	/* _STRINGARRAY_H */


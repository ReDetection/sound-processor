/* 
 * File:   WaveChunk.h
 * Author: rd
 *
 * Created on 2 Июнь 2010 г., 20:33
 */

#ifndef _WAVECHUNK_H
#define	_WAVECHUNK_H
#include "union.h"
#include <fstream>

class WaveChunk {
public:
    WaveChunk();
    WaveChunk(const WaveChunk& orig);
    virtual ~WaveChunk(){};

    unsigned int getSize()const;
    uintchar getID()const;

    static WaveChunk *load(std::ifstream& in);
    void save(std::ofstream& out);

protected:
    /*
     * следующие две строки были pure (т.е. =0 ), пока мне не понадобилось
     * использовать load. я долго ругался на то, что нельзя вызвать статический
     *  метод у класса(т.е. не у экземпляра класса), после нескольких проб
     * с отдельными классами для загрузки чанка я пришел к выводу, что лучше
     * уж сделать этот класс не абстрактным и самому следить за наследованием,
     *  чем наплодить классов тучу, потерять красоту и простоту в этом.
     */
    virtual void loadData(std::ifstream& in){};
    virtual void saveData(std::ofstream& out){};

private:

    void init(uintchar id,uintchar size);
    uintchar id,size;

};

#endif	/* _WAVECHUNK_H */


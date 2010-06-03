/* 
 * File:   FormatChunk.h
 * Author: rd
 *
 * Created on 3 Июнь 2010 г., 12:49
 */

#ifndef _FORMATCHUNK_H
#define	_FORMATCHUNK_H
#include "WaveChunk.h"

class FormatChunk : public WaveChunk{
public:
    FormatChunk();
    FormatChunk(const FormatChunk& orig);
    virtual ~FormatChunk();


    unsigned short getFormatTag() const; // Категория формата
    unsigned short getChannels()const; // Число каналов
    unsigned int getSamplesPerSec()const; // Частота дискретизации
    unsigned int getAvgBytesPerSec()const; // Байт в секунду
    unsigned short getBlockAlign()const; // Выравнивание данных в data-чанке

protected:
    virtual void loadData(std::ifstream& in);
    virtual void saveData(std::ofstream& out)const;

private:

typedef struct
  {
  unsigned short wFormatTag; // Категория формата
  unsigned short nChannels; // Число каналов
  unsigned int nSamplesPerSec; // Частота дискретизации
  unsigned int nAvgBytesPerSec; // Байт в секунду
  unsigned short nBlockAlign; // Выравнивание данных в data-чанке
  } WaveFormat;

  WaveFormat format;



};

#endif	/* _FORMATCHUNK_H */


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
    unsigned short bitsPerSample()const;

protected:
    virtual void loadData(std::ifstream& in);
    virtual void saveData(std::ofstream& out)const;

private:

typedef struct
  {
  unsigned short formatTag; // Категория формата
  unsigned short channels; // Число каналов
  unsigned int samplesPerSec; // Частота дискретизации
  unsigned int avgBytesPerSec; // Байт в секунду
  unsigned short blockAlign; // Выравнивание данных в data-чанке
  unsigned short bitsPerSample; 
  } WaveFormat;

  WaveFormat format;



};

#endif	/* _FORMATCHUNK_H */


#include <iostream>
#include "Racional.h"

class SortableRacionalArray
{
private:
    Racional * _memoria;
    unsigned int _tamano;
public:
    SortableRacionalArray(unsigned int tamano);
    void escribir();
    void ordenarQSort();
    ~SortableRacionalArray();
};


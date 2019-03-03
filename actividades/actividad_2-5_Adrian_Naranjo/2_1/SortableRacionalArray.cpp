#include "SortableRacionalArray.h"

SortableRacionalArray::SortableRacionalArray(unsigned int tamano)
{
    _tamano = tamano;
    _memoria = (Racional *)malloc(sizeof(Racional) * _tamano);

    srand(time(NULL));

    int numerador = 0;
    int denominador = 0;
    for(int i = 0; i < _tamano; i++)
    {
        numerador = rand();
        do{
            denominador = rand();
        }while(denominador == 0);
        _memoria[i] = Racional(numerador,denominador);
    }
}

void SortableRacionalArray::escribir()
{
    for(int i = 0; i < _tamano; i++)
    {
        std::cout << _memoria[i].getNumerador() << "/" << _memoria[i].getDenominador() << " ";
    }

    std::cout << std::endl;
}

int compararRacional(const void * posicion1, const void * posicion2)
{
    if((*(Racional *)posicion1).getValor() > (*(Racional *)posicion2).getValor())
    {
        return -1;
    }else if ((*(Racional *)posicion2).getValor() == (*(Racional *)posicion1).getValor())
    {
        return 0;
    }else
    {
        return 1;
    }  
}

void SortableRacionalArray::ordenarQSort()
{
    qsort(_memoria,_tamano,sizeof(Racional),compararRacional);
}

SortableRacionalArray::~SortableRacionalArray()
{
    free(_memoria);
    _memoria = NULL;
}
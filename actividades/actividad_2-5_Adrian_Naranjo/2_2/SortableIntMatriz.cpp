#include <iostream>
#include <ctime>
#include "SortableIntMatriz.h"

SortableIntMatriz::SortableIntMatriz(int tamanoFila, int tamanoColumna)
{
    _n = tamanoFila;
    _m = tamanoColumna;
    _memoria = (int **)malloc(sizeof((int *)malloc(sizeof(int) * _m)) * _n);

    int numero;

    srand(time(NULL));
    for (int i = 0; i < _n; i++)
    {
        int *arrayInterno = (int *)malloc(sizeof(int) * _m);
        for (int j = 0; j < _m; j++)
        {
            numero = rand();
            arrayInterno[j] = numero;
        }

        _memoria[i] = arrayInterno;
    }
}

void SortableIntMatriz::escribirMatriz()
{
    for (int i = 0; i < _n; i++)
    {
        for (int j = 0; j < _m; j++)
        {
            std::cout << _memoria[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

void SortableIntMatriz::ordenarMatrizBurbujaInversa()
{
    _clockInicial = clock();
    int aux;
    for (int i = 0; i < _n; i++)
    {
        for (int j = _m; j > 0; j--)
        {
            for (int k = _m - 1; k > 0; k--)
            {
                if (_memoria[i][k] < _memoria[i][k - 1])
                {
                    aux = _memoria[i][k];
                    _memoria[i][k] = _memoria[i][k - 1];
                    _memoria[i][k - 1] = aux;
                }
            }
        }
    }
    _clockFinal = clock();
}

double SortableIntMatriz::mostrarTiempoMedio()
{
    unsigned long tiempoMedio = (_clockFinal - _clockInicial) / _n;
    return tiempoMedio / (double)CLOCKS_PER_SEC;
}

SortableIntMatriz::~SortableIntMatriz()
{
    for (int i = 0; i < _n; i++)
    {
        free(_memoria[i]);
    }
    free(_memoria);
    _memoria = NULL;
}

#include "ListaContigua.h"
#include <iostream>

bool ListaContigua::isLlena()
{
    // if (this->n == this->capacidad)
    // {
    //     return true;
    // }
    // return false;

    return (this->capacidad == this->n);
}

ListaContigua::ListaContigua()
{
    this->n = 0;
    this->capacidad = 0;
    this->vector = NULL;
}

ListaContigua::~ListaContigua()
{
    this->vector = NULL;
    free(this->vector);
}

int ListaContigua::getValor(int posicion)
{
    assert(posicion >= 0 && posicion < this->n);
    return this->vector[posicion];
}

void ListaContigua::setValor(int posicion, int nuevoValor)
{
    assert(posicion >= 0 && posicion < this->n);
    this->vector[posicion] = nuevoValor;
}

int ListaContigua::getN()
{
    return this->n;
}

int ListaContigua::getCapacidad()
{
    return this->capacidad;
}

void ListaContigua::insertarAlFinal(int nuevoValor)
{
    if (isLlena())
    {
        this->vector = (int *)realloc(this->vector, sizeof(int) * (capacidad + INCREMENTO));
        this->capacidad += INCREMENTO;
    }
    this->vector[n++] = nuevoValor;
}

void ListaContigua::eliminarAlFinal()
{
    this->n -= 1;
    if (this->capacidad - this->n >= INCREMENTO)
    {
        this->capacidad -= INCREMENTO;
        this->vector = (int *)realloc(this->vector, sizeof(int) * this->capacidad);
    }
}

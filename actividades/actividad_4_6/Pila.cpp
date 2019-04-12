#include "Pila.h"
#include <iostream>

bool Pila::isVacia()
{
    if (this->getN() == 0)
    {
        return true;
    }
    return false;
}

void Pila::push(int valor)
{
    this->insertar(0, valor);
}

int Pila::pop()
{
    assert(this->getN() > 0);
    int valor = this->verCima();
    this->eliminar(0);

    return valor;
}

int Pila::verCima()
{
    assert(this->getN() > 0);
    int valor = this->getValor(0);
    return valor;
}

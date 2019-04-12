#include "Cola.h"
#include <iostream>

bool Cola::isVacia()
{
    if (this->getN() == 0)
    {
        return true;
    }
    return false;
}

void Cola::push(int valor)
{
    this->insertar(this->getN(), valor);
}

int Cola::pop()
{
    assert(this->getN() > 0);
    int valor = this->verCima();
    this->eliminar(0);

    return valor;
}

int Cola::verCima()
{
    assert(this->getN() > 0);
    int valor = this->getValor(0);
    return valor;
}

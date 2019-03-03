#include "Racional.h"
#include <iostream>

Racional::Racional(int numerador, int denominador)
{
    _numerador = numerador;
    _denominador = denominador;
}

int Racional::getDenominador()
{
    return _denominador;
}

int Racional::getNumerador()
{
    return _numerador;
}

float Racional::getValor()
{
    return (float)_numerador/(float)_denominador;
}

Racional::~Racional()
{

}
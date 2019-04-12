#include "Calculadora.h"

Calculadora::Calculadora()
{
}

string Calculadora::convertirInfijoPostfijo(string expresion)
{
    string expresionFinal = "";

    for (int i = 0; i < expresion.size(); i++)
    {
        if (expresion[i] == '+')
        {
            if (pila1.isVacia())
            {
                pila1.push(expresion[i]);
            }
            else
            {
                bool salir = false;
                while (salir)
                {
                    if (pila1.verCima() == '+' || pila1.verCima() == '*')
                    {
                    }
                }
            }
        }
    }

    return expresionFinal;
}

int Calculadora::evaluarPostfijo(string expresion)
{
    int posicion = 0;
    while (expresion[posicion] != '\0')
    {
        if (expresion[posicion] == '+')
        {
            pila2.push(pila2.pop() + pila2.pop());
        }
        else if (expresion[posicion] == '*')
        {
            pila2.push(pila2.pop() * pila2.pop());
        }
        else
        {
            pila2.push(expresion[posicion] - '0');
        }
        posicion++;
    }

    return pila2.verCima();
}

int Calculadora::evaluar(string expresion)
{
    return evaluarPostfijo(convertirInfijoPostfijo(expresion));
}

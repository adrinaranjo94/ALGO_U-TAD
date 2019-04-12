#include "iostream"
#include <string>
#include "Pila.h"
#include "impresionListasEnlazadas.h"

using namespace std;

int main()
{
    string cadena;
    cin >> cadena;

    Pila pila;

    int posicion = 0;
    while (cadena[posicion] != '\0')
    {
        if (cadena[posicion] == '+')
        {
            pila.push(pila.pop() + pila.pop());
        }
        else if (cadena[posicion] == '*')
        {
            pila.push(pila.pop() * pila.pop());
        }
        else
        {
            pila.push(cadena[posicion] - '0');
        }
        posicion++;
    }

    cout << pila.verCima() << endl;
    ;
    return 0;
}

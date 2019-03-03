#include <iostream>
#include "Racional.h"

using namespace std;

int comprobarDenominadorRacional()
{
    int denominador;
    do
    {
        cin >> denominador;
    } while (denominador != 0);
    
    return denominador;
}

int main() {
    Racional a(4,54);
    Racional aux(1,4);
    Racional b = a.sumar(aux);

    //cout << b.getNumerador() << "/" << b.getDenominador(); 

    a.simplificar();

    a.escribir();

    aux.escribir();

    return 0;
}

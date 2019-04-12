#include <iostream>
#include "Mystr.h"

int main()
{
    Mystr texto = Mystr("Que pasa chavales");

    Mystr textoSub = texto.Substring(0, 2);

    textoSub.imprimir();

    return 0;
}
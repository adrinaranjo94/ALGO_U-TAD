#include <iostream>
#include "SortableRacionalArray.h"

using namespace std;

int main()
{
    int tamano = 0;
    do
    {
        cout << "Introduce el tamano del array (numero igual o mayor a 1): ";
        cin >> tamano;
    } while (tamano <= 0);

    SortableRacionalArray arrayRacionales = SortableRacionalArray(tamano);

    arrayRacionales.escribir();

    arrayRacionales.ordenarQSort();

    arrayRacionales.escribir();
    
    return 0;
}

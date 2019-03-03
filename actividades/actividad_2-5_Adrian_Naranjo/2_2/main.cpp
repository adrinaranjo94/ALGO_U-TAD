#include <iostream>
#include "SortableIntMatriz.h"

using namespace std;
int main()
{
    int tamano = 0;
    do
    {
        cout << "Introduce el tamano del array (numero igual o mayor a 1): ";
        cin >> tamano;
    } while (tamano <= 0);

    int numeroArrays = 0;
    do
    {
        cout << "Introduce el numero de arrays (numero igual o mayor a 1): ";
        cin >> numeroArrays;
    } while (tamano <= 0);

    SortableIntMatriz a = SortableIntMatriz(numeroArrays, tamano);
    a.escribirMatriz();
    a.ordenarMatrizBurbujaInversa();
    a.escribirMatriz();

    cout << a.mostrarTiempoMedio() << " segundos";
    return 0;
}

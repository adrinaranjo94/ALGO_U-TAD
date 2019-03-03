#include <iostream>
#include <ctime>

using namespace std;

/* VOID PARA MOSTRAR ARRAY */

void mostrarArray(int *array, int tamano)
{
    if (tamano <= 10)
    {
        for (int i = 0; i < tamano; i++)
        {
            cout << array[i] << " ";
        }
    }
    else
    {
        cout << "<demasiados componentes para mostrar> Posicion inicial del vector: " << &array << " Nº de elementos: " << tamano;
    }

    cout << endl;
}

/* VOID UTILIZADO POR QSORT */

int ordenarMenorMayorQuickSort(const void *posicion1, const void *posicion2)
{
    if (*(int *)posicion1 < *(int *)posicion2)
    {
        return -1;
    }
    else if (*(int *)posicion1 == *(int *)posicion2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/* VOIDS PARA ORDENAR ARRAY */

void ordenarAlgoritmoQSort(int *array, int tamano)
{
    qsort(array, tamano, sizeof(int), ordenarMenorMayorQuickSort);
}

void ordenarAlgoritmoInsercion(int *array, int tamano)
{
    for (int i = 1; i < tamano; i++)
    {
        int posicion = i;
        bool bucle = true;
        while (bucle)
        {
            posicion -= 1;
            // cout << "Posicion inicial: " << i << " -- Posicion comprobada " << posicion << endl;
            if (array[i] >= array[posicion] && posicion >= 0)
            {
                // cout << array[i] << " > " << array[posicion] << endl;
                if (posicion == 0)
                {
                    // cout << "Salgo por ser mayor y posicion igual a " << posicion << endl;
                    bucle = false;
                }
            }
            else
            {
                // cout << array[i] << " < " << array[posicion] << endl;
                // cout << "Salgo por ser menor" << endl;
                posicion += 1;
                bucle = false;
            }
        }

        // cout << "Numero a intercambiar final " << array[i] << " a la posicion " << posicion << " por " << array[posicion] << endl;

        int aux = array[i];
        for (int j = i - 1; j >= posicion; j--)
        {
            // cout << "De " << j << " a " << j + 1 << " -->" << array[j] << endl;
            array[j + 1] = array[j];
        }

        array[posicion] = aux;

        // mostrarArray(array, tamano);
    }
}

/* VOID PARA CREAR ARRAY */

int *crearArray(int tamano)
{
    int *array = (int *)malloc(sizeof(int) * tamano);
    int numero;
    for (int i = 0; i < tamano; i++)
    {
        numero = rand() % 1000;
        array[i] = numero;
    }

    return array;
}

/* VOID PARA CREAR MATRIZ */

int **crearMatriz(int tamano, int cantidadArrays)
{
    int **matriz = (int **)malloc(sizeof(malloc(sizeof(int) * tamano)) * cantidadArrays);

    for (int i = 0; i < cantidadArrays; i++)
    {
        matriz[i] = crearArray(tamano);
    }

    return matriz;
}

/* VOID PARA COPIAR MATRIZ */

int **copiarMatriz(int **matriz, int tamano, int cantidadArrays)
{
    int **matrizCopia = (int **)malloc(sizeof(malloc(sizeof(int) * tamano)) * cantidadArrays);
    for (int i = 0; i < cantidadArrays; i++)
    {
        matrizCopia[i] = (int *)malloc(sizeof(int) * tamano);

        memcpy(matrizCopia[i], matriz[i], sizeof(int) * tamano);
    }
    return matrizCopia;
}

/* VOID PARA MOSTRAR MATRIZ */

void mostrarMatriz(int **matriz, int tamano, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        mostrarArray(matriz[i], tamano);
    }
}

/* VOIDS PARA ORDENAR MATRIZ */

void ordenarMatrizInsercion(int **matriz, int tamano, int cantidadArrays)
{

    for (int i = 0; i < cantidadArrays; i++)
    {
        ordenarAlgoritmoInsercion(matriz[i], tamano);
    }
}

void ordenarMatrizQSort(int **matriz, int tamano, int cantidadArrays)
{

    for (int i = 0; i < cantidadArrays; i++)
    {
        ordenarAlgoritmoQSort(matriz[i], tamano);
    }
}

/* VOIDS PARA OBTENER TIEMPO ORDENACION */

double tiempoOrdenarMatrizInsercion(int **matriz, int tamano, int cantidadArrays)
{
    unsigned long clockInicial = clock();

    ordenarMatrizInsercion(matriz, tamano, cantidadArrays);

    unsigned long clockFinal = clock();
    unsigned long tiempoMedio = (clockFinal - clockInicial) / cantidadArrays;
    return tiempoMedio / (double)CLOCKS_PER_SEC;
}

double tiempoOrdenarMatrizQSort(int **matriz, int tamano, int cantidadArrays)
{
    unsigned long clockInicial = clock();

    unsigned long clockFinal = clock();

    unsigned long tiempoMedio = (clockFinal - clockInicial) / cantidadArrays;
    return tiempoMedio / (double)CLOCKS_PER_SEC;
}

/* VOID PARA LIBERAR MEMORIA DE MATRIZ */

void liberarMatriz(int **matriz, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    srand(time(NULL));
    int tamano = 0;
    do
    {
        cout << "Introduce el tamano del array (numero igual o mayor a 1): ";
        cin >> tamano;
    } while (tamano <= 0);

    int cantidadArrays = 0;
    do
    {
        cout << "Introduce el numero de arrays (numero igual o mayor a 1): ";
        cin >> cantidadArrays;
    } while (cantidadArrays <= 0);

    int **matriz1 = crearMatriz(tamano, cantidadArrays);
    int **matriz2 = copiarMatriz(matriz1, tamano, cantidadArrays);

    cout << "Matriz 1" << endl;
    mostrarMatriz(matriz1, tamano, cantidadArrays);
    cout << "Matriz 2" << endl;
    mostrarMatriz(matriz2, tamano, cantidadArrays);

    float tiempoInsercion = tiempoOrdenarMatrizInsercion(matriz1, tamano, cantidadArrays);
    float tiempoQSort = tiempoOrdenarMatrizQSort(matriz2, tamano, cantidadArrays);

    cout << tiempoInsercion << " segundos en ordenar por insercion" << endl;
    mostrarMatriz(matriz1, tamano, cantidadArrays);
    cout << tiempoQSort << " segundos en ordenar por qsort" << endl;
    mostrarMatriz(matriz2, tamano, cantidadArrays);
    liberarMatriz(matriz1, cantidadArrays);
    liberarMatriz(matriz2, cantidadArrays);

    return 0;
}

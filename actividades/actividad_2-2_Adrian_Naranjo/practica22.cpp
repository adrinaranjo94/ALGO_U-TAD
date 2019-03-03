#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

// Rellenar array de numeros mediante el metodo rand()
// Parametros:
// - tamano: indica la longitud del array
// - array: contiene el array que se va a rellenar
void rellenarArray(int tamano, int *array)
{
    for (int i = 0; i < tamano; i++)
    {
        array[i] = rand();
    }
}

// Ordenar array mediante el algoritmo seleccion
// Guardando en cada iteracion del for la posicion actual
// para encontrar con un for anidado el elemento más pequeño
// desde la posicion actual para intercambiarlos entre si
// Parametros:
// - tamano: indica la longitud del array
// - array: contiene el array que se va a rellenar
void ordenarArray(int tamano, int *array)
{
    for (int i = 0; i < tamano - 1; i++)
    {
        int posicionActual = i;
        for (int j = i; j < tamano; j++)
        {
            if (array[j] < array[posicionActual])
            {
                posicionActual = j;
            }
        }

        int aux = array[posicionActual];
        array[posicionActual] = array[i];
        array[i] = aux;
    }
}

// Mostrar el valor de las posiciones del array
// Parametros:
// - tamano: indica la longitud del array
// - array: contiene el array que se va a llenar
void mostrarArray(int tamano, int *array)
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
        cout << "<demasiados componentes para mostrar>";
    }

    cout << endl;
}

// Devolver un valor que utilizara quicksort para ordenar el array
// El valor se obtendra mediante la comparacion entre dos valores
// Parametros:
// - posicion1: indica el valor de la posicion1
// - posicion2: indica el valor de la posicion2
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

// Mostrar informacion de los clocks y segundos en funcion del algoritmo indicado
// Parametros
// - tipoAlgoritmo: 0 -> seleccion | 1 -> quicksort
// - clockInicial: indica el numero de clocks inicial
// - clockFinal: indica el numero de clocks final
// - tamano; indica la longitud del array
// - array: contiene el array que se va a utilizar
void mostrarInformacion(int tipoAlgoritmo, unsigned long clockInicial, unsigned long clockFinal, int tamano, int *array)
{
    // La primera parte se encarga de comprobar si el tipo de algoritmo esta incluido como opcion para este metodo
    // En caso contrario el algoritmo sera null
    string algoritmo;
    if (tipoAlgoritmo == 0)
    {
        algoritmo = "seleccion";
    }
    else if (tipoAlgoritmo == 1)
    {
        algoritmo = "Quicksort";
    }

    //En la segunda parte, si ha sido exitoso, algoritmo no sera null y procedera a mostrar la informacion
    if (!algoritmo.empty())
    {
        cout << "Clocks de inicio con ordenacion por " << algoritmo << ": " << clockInicial << endl;
        cout << "Clocks de fin con ordenacion por " << algoritmo << ": " << clockFinal << endl;
        cout << "CLOCK_PER_SEC: " << CLOCKS_PER_SEC << endl;
        cout << "Con ordenador por " << algoritmo << " he tardado " << (clockFinal - clockInicial) / (double)CLOCKS_PER_SEC << " segundos en ordenarlo." << endl;
        cout << "El vector resultado es:" << endl;
        mostrarArray(tamano, array);
    }
    else
    {
        cout << "El algoritmo utilizado no es valido" << endl;
    }
    cout << endl;
}

int main()
{
    srand(time(NULL));

    int tamano = 0;

    //Pediremos por teclado el tamaño del array que usaremos, entrara en bucle hasta que el numero sea mayor a 0
    do
    {
        cout << "Introduce el tamano del vector (numero igual o mayor a 1): ";
        cin >> tamano;
    } while (tamano <= 0);

    //Reserva del espacio en memoria para los dos arrays a utilizar
    int *arrayOriginal = (int *)malloc(sizeof(int) * tamano);
    int *arrayAlgoritmo = (int *)malloc(sizeof(int) * tamano);
    int *arrayQuickSort = (int *)malloc(sizeof(int) * tamano);

    //Rellenar el arrayOriginal de numeros aleatorios
    rellenarArray(tamano, arrayOriginal);

    //Realizamos copias del arrayOriginal en los demas arrays
    memcpy(arrayAlgoritmo, arrayOriginal, sizeof(int) * tamano);
    memcpy(arrayQuickSort, arrayOriginal, sizeof(int) * tamano);

    //------ SECCION ORDENACION ALGORITMO PROPIO ------//
    unsigned long startAlgoritmo = clock();
    ordenarArray(tamano, arrayAlgoritmo);
    unsigned long endAlgoritmo = clock();

    //------ SECCION ORDENACION ALGORITMO QUICKSORT ------//
    unsigned long startQuickSort = clock();
    qsort(arrayQuickSort, tamano, sizeof(int), ordenarMenorMayorQuickSort);
    unsigned long endQuickSort = clock();

    //------ SECCION INFORMACION AL USUARIO ------//
    cout << endl
         << "El vector original es el siguiente:" << endl;
    mostrarArray(tamano, arrayOriginal);
    cout << endl;

    mostrarInformacion(0, startAlgoritmo, endAlgoritmo, tamano, arrayAlgoritmo);
    mostrarInformacion(1, startQuickSort, endQuickSort, tamano, arrayQuickSort);

    //Liberamos memoria
    free(arrayOriginal);
    free(arrayAlgoritmo);
    free(arrayQuickSort);

    return 0;
}

#include <iostream>

bool is_empty(char **board, int posX, int posY)
{
    if (board[posX][posY] == '-')
    {
        return true;
    }
    return false;
}

bool is_valid(char **board, int size, int posX, int posY)
{
    if ((posX < size || posY < size) && (posX >= 0 || posY >= 0))
    {
        return true;
    }
    return false;
}

bool buscar(char **board, int size, int posX, int posY)
{
    // std::cout << "Entro buscar" << std::endl;
    if (posX == size - 1 && posY == size - 1)
    {
        board[posX][posY] = '>';
        // std::cout << "Llego final" << std::endl;
        return true;
    }

    if (is_empty(board, posX, posY))
    {
        if (is_valid(board, size, posX, posY))
        {

            // std::cout << "Esta vacia la posicion" << std::endl;
            board[posX][posY] = '>';
        }
        else
        {
            return false;
        }
        if (buscar(board, size, posX, posY - 1))
        {
            return true;
        }
        else if (buscar(board, size, posX + 1, posY))
        {
            return true;
        }
        else if (buscar(board, size, posX, posY + 1))
        {
            return true;
        }
        else if (buscar(board, size, posX - 1, posY))
        {
            return true;
        }
        else
        {
            board[posX][posY] = '?';
            // std::cout << "Camino incorrecto" << std::endl;
            return false;
        }
    }

    return false;
}

char *crearArray(int tamano)
{
    char *array = (char *)malloc(sizeof(char) * tamano);
    char letra;
    for (int i = 0; i < tamano; i++)
    {
        letra = '-';
        array[i] = letra;
    }

    return array;
}

/* VOID PARA CREAR MATRIZ */

char **crearMatriz(int tamano, int cantidadArrays)
{
    char **matriz = (char **)malloc(sizeof(malloc(sizeof(char) * tamano)) * cantidadArrays);

    for (int i = 0; i < cantidadArrays; i++)
    {
        matriz[i] = crearArray(tamano);
    }

    return matriz;
}

void mostrarArray(char *array, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void mostrarMatriz(char **matriz, int tamano, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        mostrarArray(matriz[i], tamano);
    }
}

void liberarMatriz(char **matriz, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

int main()
{
    int tamano = 5;
    int cantidadArrays = 5;
    char **matriz1 = crearMatriz(tamano, cantidadArrays);

    matriz1[0][1] = 'X';
    matriz1[2][0] = 'X';
    matriz1[2][1] = 'X';
    matriz1[2][2] = 'X';
    matriz1[2][3] = 'X';
    matriz1[1][3] = 'X';
    matriz1[3][2] = 'X';

    mostrarMatriz(matriz1, 5, 5);

    bool finalizado = buscar(matriz1, 5, 0, 0);
    std::cout << finalizado << std::endl;

    mostrarMatriz(matriz1, 5, 5);

    liberarMatriz(matriz1, 5);

    return 0;
}

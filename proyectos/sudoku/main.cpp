#include <iostream>

int *crearArray(int tamano)
{
    int *array = (int *)malloc(sizeof(int) * tamano);
    char letra;
    for (int i = 0; i < tamano; i++)
    {
        letra = -1;
        array[i] = letra;
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

void mostrarArray(int *array, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << " ";
        }
        if (array[i] == -1)
        {
            std::cout << " " << array[i];
        }
        else
        {
            std::cout << "  " << array[i];
        }
    }
    std::cout << std::endl;
}

void mostrarMatriz(int **matriz, int tamano, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        if (i % 3 == 0)
        {
            std::cout << std::endl;
        }
        mostrarArray(matriz[i], tamano);
    }
}

void liberarMatriz(int **matriz, int cantidadArrays)
{
    for (int i = 0; i < cantidadArrays; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

bool is_empty(int **matriz, int posX, int posY)
{
    if (matriz[posX][posY] == -1)
    {
        return true;
    }
    return false;
}

bool is_valid(int **matriz, int size, int posX, int posY, int valor)
{
    for (int i = 0; i < 9; i++)
    {
        if (matriz[posX][i] == valor)
            return false;
    }

    for (int i = 0; i < 9; i++)
    {
        if (matriz[i][posY] == valor)
            return false;
    }

    int despFila = (posX / 3) * 3;
    int despColumna = (posY / 3) * 3;
    for (int i = despFila; i < despFila + 3; i++)
    {
        for (int j = despColumna; j < despColumna + 3; j++)
        {
            if (matriz[i][j] == valor)
                return false;
        }
    }

    return true;
}

bool sudoku(int **matriz, int size, int posX, int posY, int valor)
{
    //std::cout << "Pos X" << posX << " Pos Y" << posY << " VALOR: " << valor << std::endl;
    //mostrarMatriz(matriz, 9, 9);
    // std::cout << std::endl;

    // std::cout << std::endl;

    if (is_empty(matriz, posX, posY))
    {
        // std::cout << "Vacio " << std::endl;
        if (is_valid(matriz, size, posX, posY, valor))
        {
            //std::cout << "Valor " << valor << "Pos X" << posX << " Pos Y" << posY << std::endl;
            matriz[posX][posY] = valor;
            if (posX == 8 && posY == 8)
            {
                return true;
            }
            if (posY == 8)
            {
                if (sudoku(matriz, size, posX + 1, 0, 1))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 2))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 3))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 4))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 5))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 6))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 7))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 8))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX + 1, 0, 9))
                {
                    return true;
                }
                else
                {
                    // std::cout << "no vale ningun numero" << std::endl;
                    matriz[posX][posY] = -1;
                    return false;
                }
            }
            else
            {
                if (sudoku(matriz, size, posX, posY + 1, 1))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 2))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 3))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 4))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 5))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 6))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 7))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 8))
                {
                    return true;
                }
                else if (sudoku(matriz, size, posX, posY + 1, 9))
                {
                    return true;
                }
                else
                {
                    // std::cout << "no vale ningun numero" << std::endl;
                    //std::cout << "x -> " << posX << " y -> " << posY << std::endl;
                    matriz[posX][posY] = -1;
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (posX == 8 && posY == 8)
        {
            return true;
        }
        if (posY == 8)
        {
            if (sudoku(matriz, size, posX + 1, 0, 1))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 2))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 3))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 4))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 5))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 6))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 7))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 8))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX + 1, 0, 9))
            {
                return true;
            }
            else
            {
                // std::cout << "no vale ningun numero" << std::endl;

                return false;
            }
        }
        else
        {
            if (sudoku(matriz, size, posX, posY + 1, 1))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 2))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 3))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 4))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 5))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 6))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 7))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 8))
            {
                return true;
            }
            else if (sudoku(matriz, size, posX, posY + 1, 9))
            {
                return true;
            }
            else
            {
                // std::cout << "no vale ningun numero" << std::endl;
                //std::cout << "x -> " << posX << " y -> " << posY << std::endl;

                return false;
            }
        }
    }
    return false;
}

int main()
{

    int tamano = 9;
    int **matriz1 = crearMatriz(tamano, tamano);

    matriz1[0][0] = 5;
    matriz1[0][1] = 3;
    matriz1[0][4] = 7;

    matriz1[1][0] = 6;
    matriz1[1][3] = 1;
    matriz1[1][4] = 9;
    matriz1[1][5] = 5;

    // matriz1[2][1] = 9;
    // matriz1[2][2] = 8;
    // matriz1[2][7] = 6;

    // matriz1[3][0] = 8;
    // matriz1[3][4] = 6;
    // matriz1[3][8] = 3;

    // matriz1[4][0] = 4;
    // matriz1[4][3] = 8;
    // matriz1[4][5] = 3;
    // matriz1[4][8] = 1;

    // matriz1[5][0] = 7;
    // matriz1[5][4] = 2;
    // matriz1[5][8] = 6;

    // matriz1[6][1] = 6;
    // matriz1[6][6] = 2;
    // matriz1[6][7] = 8;

    // // matriz1[7][3] = 4;
    // // matriz1[7][4] = 1;
    // // matriz1[7][5] = 9;
    // // matriz1[7][8] = 5;

    // // matriz1[8][4] = 8;
    // // matriz1[8][7] = 7;
    // // matriz1[8][8] = 9;

    bool finalizado = sudoku(matriz1, tamano, 0, 0, 1);

    std::cout << is_empty(matriz1, 1, 5);

    mostrarMatriz(matriz1, tamano, tamano);

    liberarMatriz(matriz1, tamano);

    std::cout << finalizado;
    return 0;
}

// else if (is_valid(matriz, size, posX, posY, 3))
// {
//     matriz[posX][posY] = 3;
//     std::cout << "Valor nuevo" << 3 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
// }
// else if (is_valid(matriz, size, posX, posY, 4))
// {
//     matriz[posX][posY] = 4;
//     std::cout << "Valor nuevo" << 4 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else if (is_valid(matriz, size, posX, posY, 5))
// {
//     matriz[posX][posY] = 5;
//     std::cout << "Valor nuevo" << 5 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else if (is_valid(matriz, size, posX, posY, 6))
// {
//     matriz[posX][posY] = 6;
//     std::cout << "Valor nuevo" << 6 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else if (is_valid(matriz, size, posX, posY, 7))
// {
//     matriz[posX][posY] = 7;
//     std::cout << "Valor nuevo" << 7 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else if (is_valid(matriz, size, posX, posY, 8))
// {
//     matriz[posX][posY] = 8;
//     std::cout << "Valor nuevo" << 8 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else if (is_valid(matriz, size, posX, posY, 9))
// {
//     matriz[posX][posY] = 9;
//     std::cout << "Valor nuevo" << 9 << std::endl;
//     if (sudoku(matriz, size, posX, posY + 1))
//     {
//         return true;
//     }
//     return false;
// }
// else
// {
//     std::cout << "Me quede sin valores" << std::endl;
//     matriz[posX][posY] = -1;
//     return false;
// }
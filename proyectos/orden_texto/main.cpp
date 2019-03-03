#include <iostream>
using namespace std;

void imprimir(char *frase, int size)
{
    // if (size >= 0)
    // {
    //     frase = frase + size;
    //     cout << frase[0];
    //     imprimir(frase, size);
    // }
    // else
    // {
    //     cout << endl;
    // }

    if (size != 0)

        imprimir(frase + 1, size - 1);
    cout << frase[0];
}

int main()
{
    char *frase = (char *)malloc(sizeof(char) * 10);
    frase = "hola mundo";
    imprimir(frase, strlen(frase) - 1);
    return 0;
}

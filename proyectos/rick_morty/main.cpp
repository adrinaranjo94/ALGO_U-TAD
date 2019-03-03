#include <iostream>
using namespace std;

void ask(char **texto, int posicionArray)
{
    int num = rand() % 2;
    if (num == 0)
    {
        cout << "Inside a simulation" << endl;
    }
    else
    {
        cout << texto[posicionArray] << endl;
        posicionArray--;
        ask(texto, posicionArray);
    }
}

void rellenarArray(const char **texto, int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        const char *frase = (char *)malloc(sizeof(char) * 10);
        frase = "Frase ";
        texto[i] = frase;
    }
}
int main()
{

    char **texto = (char **)malloc(sizeof(10 * sizeof(char *)));

    rellenarArray(texto, 10);
    ask(texto, 10);
    return 0;
}

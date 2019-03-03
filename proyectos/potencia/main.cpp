#include <iostream>
using namespace std;

int pow(int base, int exponente)
{
    return (exponente > 1) ? base * pow(base, exponente - 1) : base;
}

int main()
{
    int numero = pow(5, 3);
    cout << numero << endl;

    return 0;
}

#include "Pila.h"
#include <string>

using namespace std;

class Calculadora
{
private:
  string convertirInfijoPostfijo(string expresion);
  int evaluarPostfijo(string expresion);
  Pila pila1;
  Pila pila2;

public:
  Calculadora();
  int evaluar(string expresion);
};

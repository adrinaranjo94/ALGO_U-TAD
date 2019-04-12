#include "ListaEnlazada.h"
class Pila : public ListaEnlazada
{
public:
  bool isVacia();
  void push(int valor);
  int pop();
  int verCima();
};

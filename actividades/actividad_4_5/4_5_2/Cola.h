#include "ListaEnlazada.h"
class Cola : public ListaEnlazada
{
  public:
    bool isVacia();
    void push(int valor);
    int pop();
    int verCima();
};

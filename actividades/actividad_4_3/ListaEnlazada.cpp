#include "ListaEnlazada.h"
#include <iostream>

Nodo *ListaEnlazada::getNodo(int posicion)
{
    Nodo *auxNodo = (Nodo *)malloc(sizeof(Nodo));
    auxNodo = lista;

    assert(n > 0 && posicion < n && posicion >= 0);

    int i = 0;
    while (i < posicion)
    {
        auxNodo = auxNodo->siguienteNodo;
        i++;
    }
    return auxNodo;
}

ListaEnlazada::ListaEnlazada()
{
    lista = NULL;
    n = 0;
}

int ListaEnlazada::getValor(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    Nodo *auxNodo = (Nodo *)malloc(sizeof(Nodo));
    auxNodo = getNodo(posicion);
    return auxNodo->elemento;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    Nodo *auxNodo = (Nodo *)malloc(sizeof(Nodo));
    auxNodo = getNodo(posicion);
    auxNodo->elemento = nuevoValor;
}

int ListaEnlazada::getN()
{
    return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
    assert(posicion <= n && posicion >= 0);

    if (posicion == 0)
    {
        if (n == 0)
        {
            lista = (Nodo *)malloc(sizeof(Nodo));
            lista->elemento = nuevoValor;
            lista->siguienteNodo = NULL;
        }
        else
        {
            Nodo *siguienteNodo = (Nodo *)malloc(sizeof(Nodo));
            siguienteNodo->elemento = lista->elemento;
            siguienteNodo->siguienteNodo = lista->siguienteNodo;

            lista->elemento = nuevoValor;
            lista->siguienteNodo = siguienteNodo;
        }
    }
    else if (posicion > 0 && posicion == n)
    {
        Nodo *ultimoNodo = (Nodo *)malloc(sizeof(Nodo));
        ultimoNodo = getNodo(posicion - 1);

        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->elemento = nuevoValor;
        nuevoNodo->siguienteNodo = NULL;

        ultimoNodo->siguienteNodo = nuevoNodo;
    }
    else if (posicion > 0)
    {

        Nodo *anteriorNodo = (Nodo *)malloc(sizeof(Nodo));
        Nodo *siguienteNodo = (Nodo *)malloc(sizeof(Nodo));
        anteriorNodo = getNodo(posicion - 1);
        siguienteNodo = getNodo(posicion);

        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
        nuevoNodo->elemento = nuevoValor;
        nuevoNodo->siguienteNodo = siguienteNodo;

        anteriorNodo->siguienteNodo = nuevoNodo;
    }
    n++;
}

void ListaEnlazada::eliminar(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    if (posicion == 0)
    {
        if (n == 1)
        {
            free(lista);
            lista = NULL;
        }
        else
        {
            free(lista);
            lista = getNodo(posicion + 1);
        }
    }
    else if (posicion > 0 && posicion == n)
    {
        Nodo *anteriorNodo = (Nodo *)malloc(sizeof(Nodo));
        Nodo *actualNodo = (Nodo *)malloc(sizeof(Nodo));
        anteriorNodo = getNodo(posicion - 1);
        actualNodo = getNodo(posicion);

        actualNodo = NULL;
        free(actualNodo);

        anteriorNodo->siguienteNodo = NULL;
    }
    else if (posicion > 0)
    {
        Nodo *anteriorNodo = (Nodo *)malloc(sizeof(Nodo));
        Nodo *eliminarNodo = (Nodo *)malloc(sizeof(Nodo));

        anteriorNodo = getNodo(posicion - 1);
        eliminarNodo = getNodo(posicion);

        anteriorNodo->siguienteNodo = anteriorNodo->siguienteNodo->siguienteNodo;

        eliminarNodo = NULL;
        free(eliminarNodo);
    }
    n--;
}

ListaEnlazada::~ListaEnlazada()
{
    free(lista);
}

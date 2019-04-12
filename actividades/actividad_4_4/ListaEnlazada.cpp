#include "ListaEnlazada.h"
#include <iostream>

Nodo *ListaEnlazada::getNodo(int posicion)
{
    Nodo *auxNodo = (Nodo *)malloc(sizeof(Nodo));
    auxNodo = lista;

    assert(n > 0 && posicion < n && posicion >= 0);

    if (posicion == 0)
    {
        if (posicionUltimoNodoAccedido == 0)
        {
            return punteroUltimoNodoAccedido;
        }
        else if (posicionUltimoNodoAccedido == n - 1)
        {
            return punteroUltimoNodoAccedido->siguienteNodo;
        }
        else if (posicionUltimoNodoAccedido == 1)
        {
            return punteroUltimoNodoAccedido->anteriorNodo;
        }
    }
    else if (posicion == n - 1)
    {
        if (posicionUltimoNodoAccedido == 0)
        {
            return punteroUltimoNodoAccedido->anteriorNodo;
        }
        else if (posicionUltimoNodoAccedido == n - 1)
        {
            return punteroUltimoNodoAccedido;
        }
        else if (posicionUltimoNodoAccedido == n - 2)
        {
            return punteroUltimoNodoAccedido->siguienteNodo;
        }
    }
    else
    {
        if (posicionUltimoNodoAccedido == posicion)
        {
            return punteroUltimoNodoAccedido;
        }
        else if (posicionUltimoNodoAccedido == posicion - 1)
        {
            return punteroUltimoNodoAccedido->siguienteNodo;
        }
        else if (posicionUltimoNodoAccedido == posicion + 1)
        {
            return punteroUltimoNodoAccedido->anteriorNodo;
        }
    }

    int i;
    int direccion = n / 2;
    if (direccion > posicion)
    {
        i = 0;
        while (i < posicion)
        {
            auxNodo = auxNodo->siguienteNodo;
            i++;
        }
    }
    else
    {
        i = n;
        while (i > posicion)
        {
            auxNodo = auxNodo->anteriorNodo;
            i--;
        }
    }
    return auxNodo;
}

ListaEnlazada::ListaEnlazada()
{
    lista = NULL;
    punteroUltimoNodoAccedido = NULL;
    posicionUltimoNodoAccedido = -1;
    n = 0;
}

int ListaEnlazada::getValor(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    Nodo *auxNodo = (Nodo *)malloc(sizeof(Nodo));
    auxNodo = getNodo(posicion);

    punteroUltimoNodoAccedido = auxNodo;
    posicionUltimoNodoAccedido = posicion;

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
            lista->siguienteNodo = lista;
            lista->anteriorNodo = lista;
        }
        else
        {
            Nodo *siguienteNodo = (Nodo *)malloc(sizeof(Nodo));
            siguienteNodo->elemento = lista->elemento;
            siguienteNodo->siguienteNodo = lista->siguienteNodo;
            siguienteNodo->anteriorNodo = lista;

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
        nuevoNodo->siguienteNodo = lista;
        nuevoNodo->anteriorNodo = ultimoNodo;

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
        nuevoNodo->anteriorNodo = anteriorNodo;

        anteriorNodo->siguienteNodo = nuevoNodo;
    }
    n++;
    punteroUltimoNodoAccedido = NULL;
    posicionUltimoNodoAccedido = -1;
}

void ListaEnlazada::eliminar(int posicion)
{
    assert(n > 0 && posicion < n && posicion >= 0);

    if (posicion == 0)
    {
        if (n == 1)
        {
            lista = NULL;
            free(lista);
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

        anteriorNodo->siguienteNodo = lista;
    }
    else if (posicion > 0)
    {
        Nodo *anteriorNodo = (Nodo *)malloc(sizeof(Nodo));
        Nodo *eliminarNodo = (Nodo *)malloc(sizeof(Nodo));

        anteriorNodo = getNodo(posicion - 1);
        eliminarNodo = getNodo(posicion);

        anteriorNodo->siguienteNodo = anteriorNodo->siguienteNodo->siguienteNodo;
        anteriorNodo->siguienteNodo->siguienteNodo = anteriorNodo;

        eliminarNodo = NULL;
        free(eliminarNodo);
    }
    n--;
    punteroUltimoNodoAccedido = NULL;
    posicionUltimoNodoAccedido = -1;
}

ListaEnlazada::~ListaEnlazada()
{
    free(lista);
}

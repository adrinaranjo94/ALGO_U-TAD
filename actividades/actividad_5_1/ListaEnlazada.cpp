#include "ListaEnlazada.h"

Nodo *ListaEnlazada::getNodo(int posicion)
{
    assert(n > 0);
    assert(posicion >= 0 && posicion <= n - 1);

    Nodo *resultado = NULL; // AquÌ guardaremos el puntero al nodo resultado

    // Si el nodo que queremos buscar es igual que el ˙ltimo accedido
    if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido != -1)
        resultado = punteroUltimoNodoAccedido;

    // Si el nodo que queremos buscar es el siguiente al ˙ltimo accedido
    else if (posicion == posicionUltimoNodoAccedido + 1 && posicionUltimoNodoAccedido != -1)
    {
        resultado = punteroUltimoNodoAccedido->siguienteNodo;
    }

    // Si el nodo que queremos buscar es el anterior al ˙ltimo accedido
    else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1)
    {
        resultado = punteroUltimoNodoAccedido->anteriorNodo;
    }

    // Si el nodo no es contiguo al ultimo accedido, y se llega antes a Èl iterando hacia delante
    else if (posicion <= n / 2)
    {
        resultado = lista; // Hacemos que el resultado apunte al primer nodo
        for (int i = 0; i < posicion; i++)
            resultado = resultado->siguienteNodo;
    }

    // Si el nodo no es contiguo al ultimo accedido, y se llega antes a Èl iterando hacia atr·s
    else
    {
        resultado = lista->anteriorNodo; // Hacemos que el resultado apunte al ˙ltimo nodo
        for (int i = n - 1; i > posicion; i--)
            resultado = resultado->anteriorNodo;
    }

    // Actualizamos los atributos del ultimo nodo accedido
    posicionUltimoNodoAccedido = posicion;
    punteroUltimoNodoAccedido = resultado;

    return resultado;
}
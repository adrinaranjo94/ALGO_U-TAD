#include "Mystr.h"
#include <cstring>

using namespace std;

Mystr::Mystr()
{
    this->cadena = '\0';
    this->capacidad = 2;
}

Mystr::Mystr(const char *strCopy)
{
    memcpy(this->cadena, strCopy, sizeof(char) * strlen(strCopy));
    this->capacidad = strlen(strCopy) * 2;
}

Mystr::~Mystr()
{
    this->cadena = NULL;
}

char *Mystr::imprimir()
{
    cout << this->cadena;
}

unsigned int Mystr::Length()
{
    return strlen(this->cadena);
}

unsigned int Mystr::Capacity()
{
    return this->capacidad;
}

int Mystr::Replace(char find, char replaceBy)
{
    int numberEdits = 0;
    for (int i = 0; i < strlen(this->cadena); i++)
        if (this->cadena[i] == find)
        {
            cadena[i] = replaceBy;
            numberEdits += 1;
        }

    return numberEdits;
}

int Mystr::Compare(const Mystr &other)
{
    return strcmp(this->cadena, other.cadena);
}

int Mystr::Remove(char find)
{
}

Mystr Mystr::Right(unsigned int num)
{
}

Mystr Mystr::Left(unsigned int num)
{
}

Mystr Mystr::Substring(unsigned int initialIndex, unsigned int finalIndex)
{
    string aux = "";
    for (int i = initialIndex; i <= finalIndex; i++)
    {
        aux += this->cadena[i];
    }

    return Mystr(aux.c_str());
}

int Mystr::TrimRight()
{
}

int Mystr::TrimLeft()
{
}

int Mystr::Trim()
{
}

int Mystr::ToUpper()
{
}

int Mystr::ToLower()
{
}

bool Mystr::StartsWith(const Mystr &other)
{
}

bool Mystr::EndsWith(const Mystr &other)
{
}

Mystr Mystr::Concatenate(const Mystr &other)
{
}

Mystr Mystr::Introduce(const Mystr &other, unsigned int index)
{
}
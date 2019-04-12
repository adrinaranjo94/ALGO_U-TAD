//
//  Mystr.h
//  Practica_2
//
//  Adrian Naranjo 05/04/2019.
//  Copyright © 2019 NBTech. All rights reserved.
//

#include <cstring>
#include <iostream>

class Mystr
{
  //Cadena
  char *cadena;

  //Capacidad
  unsigned int capacidad;

public:
  /* CONSTRUCTORES & DESTRUCTORES*/

  // Constructor vacio
  Mystr();

  // Constructor Copia
  Mystr(Mystr const &strCopy);

  // Constructor copia por char *
  Mystr(const char *strCopy);

  // Destructor
  ~Mystr();

  /* METODOS */

  // Mostrar contenido de la cadena
  char *imprimir();

  // Tamaño del array de caracteres. Se recomienda usar strlen en vez de
  // almacenar el largo de la cadena en el objeto.
  unsigned int Length();

  //La capacidad de la memoria reservada.
  unsigned int Capacity();

  // Busca todos los caracteres iguales a “find” y los
  // sustituye por replaceBy. Devuelve el número de caracteres remplazados
  int Replace(char find, char replaceBy);

  // Devuelve 0 si ambas cadenas son iguales, 1 si la primera
  // cadena es mayor que la de “other”, -1 si la de “other” es mayor que la primera. -Se puede usar
  // strcmp
  int Compare(const Mystr &other);

  // Busca todos los caracteres iguales a “find” y los borra. Devuelve el
  // número de caracteres borrados. Atender al decremento de la capacidad
  int Remove(char find);

  // Devuelve la subcadena de “num” caracteres empezando por el final
  Mystr Right(unsigned int num);

  // Devuelve la subadena comprendida entre el inicio y “num”.
  Mystr Left(unsigned int num);

  // Devuelve la subcadena partiendo de initialIndex hasta llegar a finalIndex.
  Mystr Substring(unsigned int initialIndex, unsigned int finalIndex);

  // Elimina los espacios en blanco que haya por la derecha del texto. Devuelve el
  // número de espacios eliminados. Atender al decremento de la capacidad
  int TrimRight();

  // Elimina los espacios en blanco que haya por la izquierda del texto. Devuelve el
  // número de espacios eliminados. Atender al decremento de la capacidad
  int TrimLeft();

  // Elimina los espacios en blanco en ambos lados del texto. Devuelve el número de
  // espacios eliminados. Atender al decremento de la capacidad
  int Trim();

  // Convierte todos los caracteres en letras mayúsculas. Devuelve el número de
  // caracteres que han sido cambiados a mayúsculas. Se permite usar toupper de C.
  int ToUpper();

  // Convierte todos los caracteres en letras minúsculas. Devuelve el número de
  // caracteres que han sido cambiados a minúsculas. Se permite usar tolower de C.
  int ToLower();

  //Devuelve true si la cadena empieza con “other”
  bool StartsWith(const Mystr &other);

  //Devuelve true si la cadena termina con “other”.
  bool EndsWith(const Mystr &other);

  // Concatena la cadena añadiendo “other” de manera
  // consecutiva. Atender al incremento de la capacidad de la primera cadena
  Mystr Concatenate(const Mystr &other);

  // Concatena la cadena
  // introduciendola entre medias, empezando en la posición indicada por index. *Atender al
  // incremento de la capacidad de la primera cadena*
  Mystr Introduce(const Mystr &other, unsigned int index);

  /* SOBRECARGA DE OPERADORES */

  //Usar la función Compare
  inline bool operator==(const Mystr &other);

  //Puede ser el opuesto a ==
  inline bool operator!=(const Mystr &other);

  //Usar la función Compare (del siguiente apartado)
  inline bool operator<(const Mystr &other);

  //Usar la función Compare (del siguiente apartado)
  inline bool operator>(const Mystr &other);

  //Puede ser el opuesto a >
  inline bool operator<=(const Mystr &other);

  //Puede ser el opuesto a <
  inline bool operator>=(const Mystr &other);

  //Devuelve el caracter en el elemento “index”.
  inline char &operator[](int index);

  //Concatena una cadena a otra.
  inline Mystr operator+(const Mystr &other);
};
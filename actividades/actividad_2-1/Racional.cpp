#include <cstdlib>
#include <iostream>
#include "Racional.h"

using namespace std;

Racional::Racional(int numerador, int denominador)
{
    this->numerador = numerador;
    this->denominador = denominador;
}

int Racional::getDenominador()
{
    return denominador;
}

int Racional::getNumerador()
{
    return numerador;
}

Racional Racional::sumar(Racional racional)
{
    int numerador1 = this->numerador * racional.getDenominador();
    int numerador2 = this->denominador * racional.getNumerador();
    int numeradorFinal = numerador1 + numerador2;
    int denominadorFinal = this->denominador * racional.getDenominador();

    Racional racionalFinal(numeradorFinal,denominadorFinal);

    return racionalFinal;
}

Racional Racional::multiplicar(Racional racional)
{
    int numeradorFinal = this->numerador * racional.getNumerador();
    int denominadorFinal = this->denominador * racional.getDenominador();

    Racional racionalFinal(numeradorFinal,denominadorFinal);

    return racionalFinal;
}

int Racional::calcularMCD(int numero1, int numero2)
{
    //Recursividad
    if(abs(numero1) % abs(numero2) != 0){
        if(numero1 >= numero2){
            int numero3 = abs(numero1) % abs(numero2);
            int numeroFinal = calcularMCD(numero2,numero3);
            return numeroFinal;
        }else{
            int numeroFinal = calcularMCD(numero2,numero1);
            return numeroFinal;
        }
    }else{
        return numero2;
    }

    //Sin recursividad
    
    // int resto;
    // int numeroFinal;
    // do
    // {
    //     if(numero1 >= numero2){
    //         resto = numero1%numero2;
    //         numero1 = numero2;
    //         numeroFinal = numero2;
    //         numero2 = resto;
    //     }else{
    //         int aux = numero1;
    //         numero1=numero2;
    //         numero2=aux;
    //     }
    // } while (resto != 0);
    
    // return numeroFinal;
}

void Racional::simplificar()
{
    int numeroMCD = calcularMCD(this->numerador,this->denominador);
    this->numerador = this->numerador / numeroMCD;
    this->denominador = this->denominador / numeroMCD;
}

void Racional::escribir()
{
    if(this->numerador == 0){
        cout << 0;
    }else if(this->denominador == 1){
        cout << this->numerador;
    }else{
        cout << this->numerador << "/" << this->denominador;
    }
}

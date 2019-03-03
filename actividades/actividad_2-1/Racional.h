class Racional
{
private:
    int numerador;
    int denominador;
    int calcularMCD(int numero1, int numero2);
public:
    Racional(int numerador, int denominador);
    int getNumerador();
    int getDenominador();
    Racional sumar(Racional racional);
    Racional multiplicar(Racional racional);
    void simplificar();
    void escribir();
};


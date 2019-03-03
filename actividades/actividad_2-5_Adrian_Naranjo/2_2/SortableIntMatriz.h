class SortableIntMatriz
{
private:
  int _n;
  int _m;
  int **_memoria;
  float _clockInicial;
  float _clockFinal;

public:
  SortableIntMatriz(int n, int m);
  void escribirMatriz();
  void ordenarMatrizBurbujaInversa();
  double mostrarTiempoMedio();
  ~SortableIntMatriz();
};

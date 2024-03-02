#include <iostream>
#include <vector>

using namespace std;

// Función para ordenar un vector de punteros a elementos de un vector de double
void ordenar_por_valor(vector<double> &numeros, int longitud, vector<double*> &punteros) {
  // Inicializar los punteros
  for (int i = 0; i < longitud; i++) {
    punteros[i] = &numeros[i];
  }

  // Ordenar los punteros usando el algoritmo `sort`
  sort(punteros.begin(), punteros.end(), [](double* a, double* b) {
    return *a < *b;
  });
}

// Ejemplo de uso
int main() {
  // Crear un vector de números
  vector<double> numeros = {1.5, 3.2, 0.7, 4.1, 2.9};
  int longitud = numeros.size();

  // Reservar memoria para el vector de punteros
  vector<double*> punteros(longitud);

  // Ordenar los punteros
  ordenar_por_valor(numeros, longitud, punteros);

  // Imprimir los valores apuntados por los punteros ordenados
  for (double* puntero : punteros) {
    cout << *puntero << " ";
  }
  cout << endl;

  return 0;
}

        
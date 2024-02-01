#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  
/*Inicializa variables*/
  int filas=0;
  int columnas=0;
  
  /*Genera números aleatorios*/
  srand(time(nullptr));

  /*Pide dimensiones de la matriz*/
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> filas;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> columnas;
      cout<<endl;
  /*Crea la matriz*/
    int matriz[filas][columnas];

    /*Llenar matriz con numeros aleatorios*/
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 100; /*Numeros aleatorios de 0 a 99*/
        }
    }

  /*Imprimir matriz*/
    cout << "Matriz:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
/*Inicializa variables de acuerdo a la matriz*/
  int mayor = matriz[0][0];
  int menor = matriz[0][0];
  int posMayorFila = 0;
  int posMayorColumna = 0;
  int posMenorFila = 0;
  int posMenorColumna = 0;

  
  /*Busca mayor y menor elemento de la matriz*/
  for (int i = 0; i < filas; ++i) {
      for (int j = 0; j < columnas; ++j) {
          if (matriz[i][j] > mayor) {
              mayor = matriz[i][j];
              posMayorFila = i;
              posMayorColumna = j;
          }
          if (matriz[i][j] < menor) {
              menor = matriz[i][j];
              posMenorFila = i;
              posMenorColumna = j;
            }
        }
    }
  cout<<endl;
  /*Imprime resultados*/
  cout << " - El mayor elemento de la matriz es " << mayor << " en la posición (" << posMayorFila+1 << ", " << posMayorColumna+1 << ")." << endl;
  cout << " - El menor elemento de la matriz es " << menor << " en la posición (" << posMenorFila+1 << ", " << posMenorColumna+1 << ")." << endl;

}

#include <iostream>
#include <vector>

using namespace std;

vector<int> mcd(vector<int> primos1, vector<int> primos2) {
  """
  Calcula el máximo común divisor de dos números enteros a partir de sus
  descomposiciones en números primos.

  Parámetros:
    primos1 (vector<int>): Lista ordenada de los primos que descomponen el primer número.
    primos2 (vector<int>): Lista ordenada de los primos que descomponen el segundo número.

  Retorno:
    vector<int>: Lista ordenada de los primos que descomponen el máximo común divisor.
  """
  vector<int> mcd_primos;
  int i = 0, j = 0;
  while (i < primos1.size() && j < primos2.size()) {
    if (primos1[i] == primos2[j]) {
      mcd_primos.push_back(primos1[i]);
      i++;
      j++;
    } else if (primos1[i] < primos2[j]) {
      i++;
    } else {
      j++;
    }
  }
  return mcd_primos;
}

// Ejemplo de uso
int main() {
  vector<int> primos1 = {2, 3, 5};
  vector<int> primos2 = {2, 7, 11};
  vector<int> mcd_primos = mcd(primos1, primos2);
  cout << "MCD: ";
  for (int primo : mcd_primos) {
    cout << primo << " ";
  }
  cout << endl;
  return 0;
}

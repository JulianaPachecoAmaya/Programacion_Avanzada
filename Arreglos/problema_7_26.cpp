#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> sort(int n, vector<string> cadenas);

int main() {
  srand(time(NULL));

  int n = rand() % 50;
  vector<string> cadenas(n);

  for (int i = 0; i < n; i++) {
    cadenas[i] = 97 + rand() % (122 - 97);
  }

  for (int j = 0; j < n; j++) {
    cout << cadenas[j] << " ";
  }
  cout << endl;

  vector<string> cadena_ordenada = sort(n, cadenas);

  for (int k = 0; k < n; k++) {
    cout << cadena_ordenada[k] << " ";
  }
  cout << endl;
  
}
vector<string> sort(int n, vector<string> cadenas) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (cadenas[j] < cadenas[min]) {
        min = j;
      }
    }
    if (min != i) {
      swap(cadenas[i], cadenas[min]);
    }
  }
  return cadenas;
}
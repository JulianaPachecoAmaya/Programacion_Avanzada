#include <iostream>
#include <vector>
using namespace std;

void dividirVector(vector<double> &v) {

  int n = v.size();

  int inicio = 0;
  int fin = n - 1;

  while (inicio < n && v[inicio] <= v[0]) {
    inicio++;
  }

  while (fin >= 0 && v[fin] > v[0]) {
    fin--;
  }

  while (inicio < fin) {

    double temp = v[inicio];
    v[inicio] = v[fin];
    v[fin] = temp;

    while (inicio < n && v[inicio] <= v[0]) {
      inicio++;
    }

    while (fin >= 0 && v[fin] > v[0]) {
      fin--;
    }
  }
}

int main() {

  vector<double> v = {3.5, 2.0, 4.0, 1.5, 3.0};

  dividirVector(v);

  cout << "Vector dividido: ";
  for (double num : v) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

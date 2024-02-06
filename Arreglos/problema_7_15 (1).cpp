#include <iostream>
#include <cstdlib>
#include <ctime>

  using namespace std;

int main() {

  srand (time(NULL));
  int tam = 50;
  int lista[100] = {};
  double sum = 0.0;

  for(int i = 0; i<tam; i++){
  lista[i] = rand() % 99;
  }

  for(int j = 0; j<tam; j++){
    cout<< lista[j]<<" ";
  }

  for(int k = 0; k<tam; k++){
    sum += lista[k];
  }
  double prom = sum/tam;

  cout<<"la media aritmética de los valores en la lista es: "<<prom<<endl;
}

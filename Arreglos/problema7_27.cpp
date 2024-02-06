#include <iostream>

using namespace std;

int main() {
  int tam = 7;
  double suma = 0.0;
  double vector_horas[tam];
  
  for(int i = 0; i < tam; i++){
    cout << "Ingrese la cantidad de horas trabajadas del día " << i+1 <<endl;
    cin >> vector_horas[i];
  }

  for(int j = 0; j < tam; j++){
    cout << vector_horas[j]<< " "<<endl;
  }

  for(int k = 0; k < tam; k++){
    suma += vector_horas[k];
  }
  double promedio = suma/tam;

  cout <<"El promedio de horas trabajadas es: "<< promedio <<endl;
}
#include <iostream>
using namespace std;

int main() {
  /*Inicializa variales y arreglos*/
  int n=10;
  int array1 [10]= {1,2,3,4,5,6,7,8,9,10};
  int array2 [10];

  /*Imprime primer arreglo*/
  cout<<"Arreglo 1: ";
  for (int i=0; i<n; i++){
    cout<<array1[i]<<" ";
  }
  
  cout<<endl;
  cout<<"Arreglo 2 (inverso): ";
  /*Invierte datos e imprime arreglo final*/
  for (int i=0; i<10; i++){
    array2[i]=array1[n-1-i];
    cout<<array2[i]<<" ";
  }
}

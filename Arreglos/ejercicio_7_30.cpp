#include <iostream>
using namespace std;

int main() {
  /*Inicializa arreglo de caracteres*/
  char texto1[50];

cout<<"Ingrese cadena de caracteres (sin espacios): ";
  cin>>texto1;

   /* Calcula el tamaño del arreglo de caracteres, cuenta el numero hasta encontrar nulo*/
    int tamanio = 0;
    while (texto1[tamanio] != '\0') {
        tamanio++;
    }

  /*Inicializar el arreglo inverso*/
  char texto2[tamanio];

  /*Imrpimir arreglo ingresado*/
  cout<<"cadena de caracteres 1: ";
  for (int i=0; i<tamanio; i++){
    cout<<texto1[i]<<" ";
  }

  
  cout<<endl;
  cout<<"cadena de caracteres 2 (inverso): ";
  /*Invertir caracteres e imprimir datos de la cadena final*/
  for (int i=0; i<tamanio; i++){
    texto2[i]=texto1[tamanio-1-i];
    cout<<texto2[i]<<" ";
  }
}
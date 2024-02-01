#include <iostream>
using namespace std;

/*Función que verifica numero primo*/
bool esPrimo(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false; /*no es primo*/
        }
    }
    return true; /*es primo*/
}

int main() {
    int contador = 0;  /*Cantidad de numero de primos*/
    int num = 2; /*Numeros primos*/
    int arrayPrimos[80]; /*Arreglo de numeros primos*/

    cout << "Los primeros 80 números primos son:"<<endl;

  /*Ingresa numeros primos a un arreglo*/
    while (contador < 80) {
        if (esPrimo(num)) {
            arrayPrimos[contador]=num;
            contador++;
          }
      num++;
     }

  /*Imprime arreglo*/
  for(int i=0;i<80;i++){
  cout<<arrayPrimos[i]<<" ";
}
    return 0;
}

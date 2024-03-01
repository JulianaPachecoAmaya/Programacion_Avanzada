#include <iostream>
#include <cstring>

using namespace std;


int main() {
  int vector [1000];  /*Inicializar vector*/
  int *ptr =vector;  /*Inicializar puntero*/
  int numero;
  int contador =0;

  cout<< "Ingrese una cadena de numeros (ingese 0 cuando desee terminar de ingresar numeros)"<<endl;
  
  /*Ingresar datos*/
  for (int i=0; i<1000; i++){
    cout<< "numero: ";
    cin>>numero;

    if (numero==0){ /*Si el usuario ingresa 0 termina la entrada*/
      break;
    }
    
    *(ptr + i) = numero;
    
  /*Verifica si el numero es negativo*/
    if (*(ptr+i) < 0)
      *(ptr+i) *= -1; /*Cambia los numeros a positivos*/
     contador ++;
  }

  /*Imprime los numeros modificados*/
  cout<< "la cadena con los numeros modificados es: ";
  ptr=vector; /* Reiniciamos el puntero al inicio del arreglo*/
  
  for (int i = 0; i < contador; ++i) {
      cout << *(ptr + i) << " ";
  }
  cout << endl;

  return 0;
  }
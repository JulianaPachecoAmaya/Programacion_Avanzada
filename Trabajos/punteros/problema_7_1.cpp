
#include <iostream>
#include <cstring> // Para usar strlen()
using namespace std;


int main() {
  /*Inicializamos el vetor*/
    char vector[100];

    cout << "Ingresa una cadena de caracteres (menos de 100 caracteres): ";
    cin.getline(vector, 100); /*Guarda la cadena de caracteres */

/*Inicializamos el puntero al principio de la cadena*/
    char *ptr = vector;

  /*recorremos el vector*/
    while (*ptr != ' ' && *ptr != '\0') {
        ptr++; /*Mueve el puntero a la siguiente posicion*/
    }

    if (*ptr == ' ') {
        /*Imprime la primera posicion vacia que encuntre*/
      cout << "El primer espacio vacio se encuentra en la posición: " << (ptr - vector + 1) << endl; /*Hace la resta para imprimir la distancia y suma 1 por que las posiciones empiezan en 0*/
    } else {
        /*Si no encuntra ningun espacio vacio*/
      cout << "No se encontró ningún espacio vacio." << endl;
    }

    return 0;
}
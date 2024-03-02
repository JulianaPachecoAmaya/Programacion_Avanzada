#include <iostream>
#include <string>

using namespace std;

string subcadena(string cadena, int inicio, int longitud) {
  """
  Obtiene una subcadena de una cadena dada, sin usar el operador `[]`.

  Parámetros:
    cadena (string): La cadena original.
    inicio (int): Posición de inicio de la subcadena.
    longitud (int): Longitud de la subcadena.

  Retorno:
    string: La subcadena extraída.
  """
  string subcadena = "";
  for (int i = inicio; i < min(inicio + longitud, (int)cadena.size()); i++) {
    subcadena += cadena[i];
  }
  return subcadena;
}

// Ejemplo de uso
int main() {
  string cadena = "Hola mundo!";
  int inicio = 6;
  int longitud = 5;
  string subcadena = subcadena(cadena, inicio, longitud);
  cout << "Subcadena: " << subcadena << endl;
  return 0;
}

#include <iostream>

using namespace std;

void encadenar_cadena(char *destino, const char *fuente) {

  while (*destino) {
    destino++;
  }
  while (*fuente) {
    *destino = *fuente;
    destino++;
    fuente++;
  }
  *destino = '\0';
}
int comparar_cadena(const char *cadena1, const char *cadena2) {
  while (*cadena1 && *cadena2 && *cadena1 == *cadena2) {
    cadena1++;
    cadena2++;
  }
  return (*cadena1 < *cadena2) ? -1 : ((*cadena1 > *cadena2) ? 1 : 0);
}

int main() {
  char cadena1[100] = "Hola, ";
  const char *cadena2 = "mundo!";
  encadenar_cadena(cadena1, cadena2);
  cout << "Cadena resultante: " << cadena1 << endl;
  int resultado = comparar_cadena("hola", "hola");
  if (resultado == 0) {
    cout << "Las cadenas son iguales" << endl;
  } else if (resultado < 0) {
    cout << "La primera cadena es menor que la segunda" << endl;
  } else {
    cout << "La primera cadena es mayor que la segunda" << endl;
  }

  return 0;
}
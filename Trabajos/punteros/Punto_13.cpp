#include <iostream>

using namespace std;

int main() {
  // Definir los vectores
  int vector1[] = {1, 2, 3};
  int vector2[] = {4, 5, 6};
  int longitud = 3;

  // Declarar variables para el producto escalar y los apuntadores
  int producto_escalar = 0;
  int *ptr_vector1 = vector1;
  int *ptr_vector2 = vector2;

  // Recorrer los vectores y calcular el producto escalar
  for (int i = 0; i < longitud; i++) {
    producto_escalar += (*ptr_vector1) * (*ptr_vector2);
    ptr_vector1++;
    ptr_vector2++;
  }

  // Imprimir el producto escalar
  cout << "Producto escalar: " << producto_escalar << endl;

  return 0;
}

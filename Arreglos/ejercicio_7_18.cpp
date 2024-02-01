#include <iostream>
using namespace std;

int main() {
  
    char cadena[100];

    // Solicita al usuario que ingrese una cadena
    cout << "Ingresa una cadena: ";
    cin.getline(cadena, sizeof(100));

    // Calcula la longitud de la cadena
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        ++longitud;
    }

    // Imprime la cadena en un cuadro
    cout << "+";
    for (int i = 0; i < longitud + 2; ++i) {
        cout << "-";
    }
    cout << "+\n";

    cout << "| " << cadena << " |\n";

    cout << "+";
    for (int i = 0; i < longitud + 2; ++i) {
        cout << "-";
    }
    cout << "+\n";

    return 0;
}

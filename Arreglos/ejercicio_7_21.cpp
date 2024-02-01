#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int tamanoMaximo = 100;
    char palabra[tamanoMaximo];

    // Solicita al usuario que ingrese una palabra
    cout << "Ingresa una palabra: ";
    cin.getline(palabra, tamanoMaximo);

    // Obtiene la longitud de la palabra
    int longitud = std::strlen(palabra);

    // Invierte la palabra
    for (int i = 0, j = longitud - 1; i < j; ++i, --j) {
        swap(palabra[i], palabra[j]);
    }

    // Muestra la palabra invertida
    cout << "Palabra invertida: " << palabra << "\n";

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Leer la cadena de caracteres desde el teclado
    cout << "Ingrese la cadena a codificar/descodificar: ";
    string cadena;
    getline(cin, cadena);

    // Leer el desplazamiento para el cifrado simple
    cout << "Ingrese el desplazamiento para el cifrado (número entero): ";
    int desplazamiento;
    cin >> desplazamiento;

    // Codificar la cadena sumando el desplazamiento a cada carácter
    for (int i = 0; i < cadena.length(); ++i) {
        cadena[i] = cadena[i] + desplazamiento;
    }

    // Mostrar el resultado codificado
    cout << "Cadena codificada: " << cadena << endl;

    // Descodificar la cadena restando el desplazamiento a cada carácter
    for (int i = 0; i < cadena.length(); ++i) {
        cadena[i] = cadena[i] - desplazamiento;
    }

    // Mostrar el resultado descodificado
    cout << "Cadena descodificada: " << cadena << endl;

    return 0;
}

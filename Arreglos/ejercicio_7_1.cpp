#include <iostream>

using namespace std;

// Función para convertir un número romano a su equivalente arábigo
int romano_a_arabigo(const char romano[]) {
    int valores[] = {1000, 500, 100, 50, 10, 5, 1};
    char simbolos[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
   
    int resultado = 0;        // Almacena el resultado de la conversión
    int valorAnterior = 0;     // Almacena el valor del símbolo anterior durante la iteración
   
    // Itera sobre cada caracter de la cadena romana
    for (int i = 0; romano[i] != '\0'; ++i) {
        char caracter = romano[i];  // Caracter romano actual
        int valor = 0;               // Valor asociado al símbolo romano actual
   
        // Itera sobre los símbolos y valores para encontrar la correspondencia
        for (int j = 0; j < sizeof(simbolos); ++j) {
            if (caracter == simbolos[j]) {
                valor = valores[j];
                break;
            }
        }
   
        // Realiza la conversión según las reglas de los números romanos
        if (valor > valorAnterior) {
            resultado += valor - 2 * valorAnterior; // Restar dos veces el valor anterior
        } else {
            resultado += valor;
        }
   
        valorAnterior = valor;  // Actualiza el valor anterior para la próxima iteración
    }
   
    return resultado;  // Retorna el resultado final de la conversión
}

int main() {
    char arregloChar[100];  
    bool esNumeroRomanoValido;  

    cout << "Recuerda que solo puedes usar esto: M,D,C,L,X,V,I,II,III" << endl;

    do {
        cout << "Ingrese número romano: ";
        cin.getline(arregloChar, sizeof(arregloChar)); 
        esNumeroRomanoValido = true;  // Reinicia la bandera para cada iteración

        char arregloRom[]= {'M','D','C','L','X','V','I'};  // Símbolos romanos permitidos

        
        for (int i = 0; arregloChar[i] != '\0'; ++i) {
            bool esCaracterValido = false;
            for (int j = 0; j < sizeof(arregloRom); ++j) {
                if (arregloChar[i] == arregloRom[j]) {
                    esCaracterValido = true;
                    break;  // Sale del bucle interno si se encuentra una coincidencia
                }
            }

            // Si encuentra un carácter no válido, establece la bandera en falso y muestra un mensaje
            if (!esCaracterValido) {
                cout << "Carácter no válido. Por favor, ingresa un número romano válido." << endl;
                esNumeroRomanoValido = false;
                break;
            }
        }

        // Si la entrada es válida, muestra los resultados y sale del programa
        if (esNumeroRomanoValido) {
            cout << "Número romano ingresado: " << arregloChar << endl;
            cout << "Número arábigo equivalente: " << romano_a_arabigo(arregloChar) << endl;
            break;  // Sale del bucle principal
        }

    } while (true);  // Repite el bucle hasta que se ingrese un número romano válido

    return 0;
}

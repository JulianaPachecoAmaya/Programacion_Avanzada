#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

/* Función para seleccionar palabra aleatoria */
string seleccionarPalabra(string palabras[], int tam) {
    int num = rand() % tam;
    return palabras[num];
};

/* Función que muestra el tablero en pantalla */
void mostrarTablero(int intentosMax, int intentos, string letrasCorrectas, string palabra) {
    /* Imprime intentos restantes */
    cout << "Intentos restantes: " << intentosMax - intentos << endl;

    /* Imprime letras adivinadas o espacios */
    for (char letra : palabra) {
        if (letrasCorrectas.find(letra) != string::npos) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;

    /* Imprime estado del ahorcado */
    switch (intentos) {
        case 1:
            cout << "  !===N" << endl;
            cout << "      N" << endl;
            cout << "      N" << endl;
            cout << "      N" << endl;
            cout << "=======" << endl;
            break;

        case 2:
            cout << "  !===N" << endl;
            cout << "  O   N" << endl;
            cout << "      N" << endl;
            cout << "      N" << endl;
            cout << "=======" << endl;
            break;

        case 3:
            cout << "  !===N" << endl;
            cout << " _O  N" << endl;
            cout << "     N" << endl;
            cout << "     N" << endl;
            cout << "=======" << endl;
            break;

        case 4:
            cout << "  !===N" << endl;
            cout << " _O_  N" << endl;
            cout << "      N" << endl;
            cout << "      N" << endl;
            cout << "=======" << endl;
            break;

        case 5:
            cout << "  !===N" << endl;
            cout << " _O_  N" << endl;
            cout << "  |   N" << endl;
            cout << "      N" << endl;
            cout << "=======" << endl;
            break;

        case 6:
            cout << "  !===N" << endl;
            cout << " _O_  N" << endl;
            cout << "  |   N" << endl;
            cout << " |    N" << endl;
            cout << "=======" << endl;
            break;

        case 7:
            cout << "  !===N" << endl;
            cout << " _O_  N" << endl;
            cout << "  |   N" << endl;
            cout << " | |  N" << endl;
            cout << "=======" << endl;
            break;
    }
};

/* Función que solicita una letra al usuario */
char solicitar_letra(const string &letrasTodas) {
    char letra;
    while (true) {
        cout << endl << "Escribe una letra en mayúscula: ";
        cin >> letra;

        /* Verificar si la letra ya ha sido ingresada antes o no es válida */
        if (letrasTodas.find(letra) != string::npos) {
            cout << "Esa letra ya ha sido usada, introduce otra letra:" << endl;
        } else if (!isalpha(letra)) {
            cout << "Por favor, introduce una letra válida:" << endl;
        } else {
            return toupper(letra); /* Función para convertir letra a mayúscula */
        }
    }
}

/* Función que crea el archivo de palabras */
void crearArchivo() {
    ofstream archivoPalabras("palabras.txt");
    if (archivoPalabras.is_open()) {
        archivoPalabras << "SEQUENTIALACCESS BUFFER FILE ARRAY BINARY STRUCTURE DOUBLE DYNAMICARRAY FUNCTION STRING";
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivoPalabras.close();
}

/* Función que lee las palabras desde el archivo */
void leerPalabras(string palabras[], int tam) {
    ifstream archivoPalabras("palabras.txt");
    if (archivoPalabras.is_open()) {
        for (int i = 0; i < tam; ++i) {
            archivoPalabras >> palabras[i];
        }
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    archivoPalabras.close();
}

int main() {
    int tam = 10;
    const int intentosMax = 7;
    int intentos = 0;

    /* Generación de números aleatorios */
    srand(time(nullptr));

    /* Crear el archivo de palabras */
    crearArchivo();

    /* Declarar el arreglo de palabras */
    string palabras[tam];

    /* Leer palabras desde el archivo */
    leerPalabras(palabras, tam);

    /* Seleccionar una palabra aleatoria */
    string palabra = seleccionarPalabra(palabras, tam);
    string letrasCorrectas = "";
    string letrasTodas = "";

    while (intentos < intentosMax) {
        mostrarTablero(intentosMax, intentos, letrasCorrectas, palabra);
        char letra = solicitar_letra(letrasTodas);
        letrasTodas += letra;

        /* Verifica letra */
        if (palabra.find(letra) != string::npos) {
            letrasCorrectas += letra;

            /* Verificar letras de la palabra */
            bool palabraCompleta = true;
            for (char letraPalabra : palabra) {
                if (letrasCorrectas.find(letraPalabra) == string::npos) {
                    palabraCompleta = false;
                    break;
                }
            }

            /* Completa el tablero */
            if (palabraCompleta) {
                mostrarTablero(intentosMax, intentos, letrasCorrectas, palabra);
                cout << "¡Felicidades, Has adivinado la palabra!" << endl;
                break;
            }
        } else {
            intentos++;
        }
    }

    /* Terminan oportunidades, termina el juego */
    if (intentos == intentosMax) {
        mostrarTablero(intentosMax, intentos, letrasCorrectas, palabra);
        cout << "Has perdido. La palabra era: " << palabra << endl;
    }

    return 0;
}

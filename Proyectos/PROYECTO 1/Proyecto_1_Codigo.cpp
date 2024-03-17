#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip> // Necesario para setw

using namespace std;

struct Jugador {
    char* nombre;
    string color;
};

typedef vector<vector<string>> Tablero;

// Función para inicializar un tablero vacío para el juego de 4 en línea
void inicializarTablero(Tablero& tablero, int filas, int columnas) {
    tablero.resize(filas, vector<string>(columnas, " ")); // Inicializa el tablero con todas las celdas vacías (" ")
}

// Función para imprimir el tablero
void imprimirTablero(const Tablero& tablero) {
    // Imprimir números de columna
    cout << " ";
    for (int columna = 0; columna < tablero[0].size(); ++columna) {
        cout << setw(4) << columna << "  ";
    }
    cout << endl;

    // Imprimir el tablero
    for (int fila = 0; fila < tablero.size(); ++fila) {
        // Imprimir línea horizontal
        cout << " ";
        for (int columna = 0; columna < tablero[0].size(); ++columna) {
            cout << "+";
            cout << setw(5) << "-----";
        }
        cout << "+" << endl;

        // Imprimir celdas
        cout << " ";
        for (int columna = 0; columna < tablero[0].size(); ++columna) {
            cout << "|";
            cout << setw(5) << tablero[fila][columna];
        }
        cout << "|" << endl;
    }

    // Imprimir línea horizontal al final
    cout << " ";
    for (int columna = 0; columna < tablero[0].size(); ++columna) {
        cout << "+";
        cout << setw(5) << "-----";
    }
    cout << "+" << endl;
}

// Función para guardar el estado final del tablero en un archivo de texto
void guardarTablero(const Tablero& tablero) {
    ofstream archivo("estado_tablero.txt");

    if (archivo.is_open()) {
        for (const auto& fila : tablero) {
            for (const auto& celda : fila) {
                archivo << celda << " ";
            }
            archivo << endl;
        }
        archivo.close();
        cout << "El estado final del tablero se ha guardado en 'estado_tablero.txt'" << endl;
    } else {
        cerr << "Error al abrir el archivo para guardar el estado del tablero." << endl;
    }
}

// Función para dejar caer una ficha en una columna específica
bool dejarFicha(Tablero& tablero, int columna, string color) {
    for (int fila = tablero.size() - 1; fila >= 0; --fila) {
        if (tablero[fila][columna] == " ") {
            tablero[fila][columna] = color;
            return true;
        }
    }
    return false;
}

// Función para verificar si hay un ganador
bool hayGanador(const Tablero& tablero, int fila, int columna) {
    string color = tablero[fila][columna];

    // Verificar en horizontal
    int count = 0;
    for (int i = columna - 3; i <= columna + 3; ++i) {
        if (i >= 0 && i < tablero[0].size() && tablero[fila][i] == color)
            count++;
        else
            count = 0;
        if (count == 4)
            return true;
    }

    // Verificar en vertical
    count = 0;
    for (int i = fila - 3; i <= fila + 3; ++i) {
        if (i >= 0 && i < tablero.size() && tablero[i][columna] == color)
            count++;
        else
            count = 0;
        if (count == 4)
            return true;
    }

    // Verificar en diagonal (ascendente)
    count = 0;
    for (int i = -3; i <= 3; ++i) {
        int f = fila + i;
        int c = columna + i;
        if (f >= 0 && f < tablero.size() && c >= 0 && c < tablero[0].size() && tablero[f][c] == color)
            count++;
        else
            count = 0;
        if (count == 4)
            return true;
    }

    // Verificar en diagonal (descendente)
    count = 0;
    for (int i = -3; i <= 3; ++i) {
        int f = fila - i;
        int c = columna + i;
        if (f >= 0 && f < tablero.size() && c >= 0 && c < tablero[0].size() && tablero[f][c] == color)
            count++;
        else
            count = 0;
        if (count == 4)
            return true;
    }

    return false;
}

int main() {
    int filas = 6, columnas = 7;
    Tablero tablero(filas, vector<string>(columnas, " "));

    Jugador jugador1, jugador2;
    char nombre1[50], nombre2[50];

    do {
        cout << "Ingrese el nombre del jugador 1: ";
        cin >> nombre1;
        cout << "Ingrese el nombre del jugador 2: ";
        cin >> nombre2;

        jugador1.nombre = new char[strlen(nombre1) + 1];
        jugador2.nombre = new char[strlen(nombre2) + 1];
        strcpy(jugador1.nombre, nombre1);
        strcpy(jugador2.nombre, nombre2);

        if (strcmp(jugador1.nombre, jugador2.nombre) == 0) {
            cout << "No se pueden ingresar nombres iguales para ambos jugadores." << endl;
            delete[] jugador1.nombre;
            delete[] jugador2.nombre;
            continue;
        }

        cout << "Ingrese el color del jugador 1 (azul, rojo, rosa, gris): ";
        cin >> jugador1.color;

        cout << "Ingrese el color del jugador 2 (azul, rojo, rosa, gris): ";
        cin >> jugador2.color;

        if (jugador1.color == jugador2.color) {
            cout << "No se pueden ingresar colores iguales para ambos jugadores." << endl;
            delete[] jugador1.nombre;
            delete[] jugador2.nombre;
            continue;
        }

        break;

    } while (true);

    inicializarTablero(tablero, filas, columnas);
    imprimirTablero(tablero);

    // Iniciar el juego
    Jugador *jugadorActual = &jugador1; // Usamos puntero a Jugador
    bool empate = false;
    for (int turno = 0; turno < filas * columnas; ++turno) {
        cout << "Turno de " << jugadorActual->nombre << ". Elija una columna (0-6): ";
        int columna;
        cin >> columna;

        if (columna < 0 || columna >= columnas || !dejarFicha(tablero, columna, jugadorActual->color)) {
            cout << "Movimiento no válido. Inténtelo de nuevo." << endl;
            continue;
        }

        imprimirTablero(tablero);

        if (hayGanador(tablero, filas - 1, columna)) {
            cout << "¡Felicidades! " << jugadorActual->nombre << " ha ganado el juego." << endl;
            guardarTablero(tablero); // Guardar el estado final del tablero
            break;
        }

        if (turno == filas * columnas - 1) {
            empate = true;
            guardarTablero(tablero); // Guardar el estado final del tablero
            break;
        }

        // Cambio de turno
        if (jugadorActual == &jugador1) {
            jugadorActual = &jugador2;
        } else {
            jugadorActual = &jugador1;
        }
    }

    if (empate) {
        cout << "¡El juego ha terminado en empate!" << endl;
        guardarTablero(tablero); // Guardar el estado final del tablero
    }

    // Liberar la memoria asignada para los nombres
    delete[] jugador1.nombre;
    delete[] jugador2.nombre;

    return 0;
}
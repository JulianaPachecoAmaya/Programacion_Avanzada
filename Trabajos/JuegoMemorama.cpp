#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void generarArchivoRespuestas(const vector<vector<int>> &tablero,
                              const string &nombreArchivo) {
  ofstream archivo(nombreArchivo);
  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo para escribir las respuestas." << endl;
    return;
  }

  for (const auto &fila : tablero) {
    for (const auto &valor : fila) {
      archivo << valor << " ";
    }
    archivo << "\n";
  }
  archivo.close();
  cout << "Archivo de respuestas generado: " << nombreArchivo << endl;
}

void inicializarTablero(vector<vector<int>> &tablero, int filas, int columnas) {
  int totalCartas = filas * columnas;
  int carta = 1;
  int *ptr = tablero[0].data();

  for (int i = 0; i < totalCartas; i += 2) {
    ptr[i] = carta;
    ptr[i + 1] = carta;
    carta++;
  }

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(ptr, ptr + totalCartas, default_random_engine(seed));
}

void mostrarTablero(const vector<vector<int>> &tablero,
                    const vector<vector<bool>> &reveladas) {
  const int *ptr = tablero[0].data();

  for (int i = 0; i < tablero.size(); ++i) {
    for (int j = 0; j < tablero[0].size(); ++j) {
      if (reveladas[i][j]) {
        cout << setw(2) << tablero[i][j] << " ";
      } else {
        cout << setw(2) << "*" << " ";
      }
    }
    cout << "\n";
  }
}

bool comprobarFinJuego(const vector<vector<bool>> &reveladas) {
  for (const auto &fila : reveladas) {
    for (bool cartaRevelada : fila) {
      if (!cartaRevelada) {
        return false;
      }
    }
  }
  return true;
}

void elegirCarta(int &x, int &y, const vector<vector<bool>> &reveladas) {
  do {
    cout << "Elige una carta (fila y columna): ";
    cin >> x >> y;
    if (reveladas[x][y]) {
      cout << "Esta carta ya ha sido revelada. Elige otra carta.\n";
    }
  } while (reveladas[x][y]);
}

int main() {
  int filas = 4, columnas = 4;
  vector<vector<int>> tablero(filas, vector<int>(columnas));
  vector<vector<bool>> reveladas(filas, vector<bool>(columnas, false));

  inicializarTablero(tablero, filas, columnas);
  generarArchivoRespuestas(tablero, "respuestasMemorama.txt");

  int x1, y1, x2, y2;
  while (!comprobarFinJuego(reveladas)) {
    mostrarTablero(tablero, reveladas);

    elegirCarta(x1, y1, reveladas);
    reveladas[x1][y1] = true;
    mostrarTablero(tablero, reveladas);

    elegirCarta(x2, y2, reveladas);

    if (tablero[x1][y1] == tablero[x2][y2]) {
      cout << "¡Encontraste una pareja!\n";
      reveladas[x2][y2] = true;
    } else {
      cout << "No son una pareja. Intenta de nuevo.\n";
      reveladas[x1][y1] = false;
    }
  }

  cout << "¡Felicidades! Has completado el juego.\n";
  return 0;
}

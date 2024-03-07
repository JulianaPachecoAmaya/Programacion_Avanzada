#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Paciente {
    int cedula;
    int presionSistolicaMaxima;
    int presionDiastolicaMaxima;
};

Paciente* obtenerPacientes(const char* medidad, int& cantidadPacientes) {
    ifstream archivo("medidad.txt");
    string linea;
    cantidadPacientes = 0;


    while (std::getline(archivo, linea)) {
        cantidadPacientes++;
    }
    archivo.clear();
    archivo.seekg(0, std::ios::beg);

    // Crear un arreglo dinámico de pacientes
    Paciente* pacientes = new Paciente[cantidadPacientes];

    int index = 0;
    while (std::getline(archivo, linea)) {
        stringstream ss(linea);
        string token;
        getline(ss, token, ';'); // Obtener el número de cédula

        pacientes[index].cedula = std::stoi(token);

        int maxSistolica = 0;
        int maxDiastolica = 0;

        // Obtener las medidas de presión arterial
        while (std::getline(ss, token, ',')) {
            stringstream medida(token);
            string presionSistolica, presionDiastolica;
            getline(medida, presionSistolica, '-');
            getline(medida, presionDiastolica, '-');

            int sistolica = std::stoi(presionSistolica);
            int diastolica = std::stoi(presionDiastolica);

            if (sistolica > maxSistolica) {
                maxSistolica = sistolica;
            }

            if (diastolica > maxDiastolica) {
                maxDiastolica = diastolica;
            }
        }

        pacientes[index].presionSistolicaMaxima = maxSistolica;
        pacientes[index].presionDiastolicaMaxima = maxDiastolica;

        index++;
    }

    archivo.close();
    return pacientes;
}

void guardarPacientes(Paciente* pacientes, int cantidadPacientes) {
    ofstream archivo("Pacientes.dat", std::ios::binary);
    for (int i = 0; i < cantidadPacientes; ++i) {
        std::string mensaje;
        if (pacientes[i].presionSistolicaMaxima > 140 || pacientes[i].presionDiastolicaMaxima > 95) {
            mensaje = "ADVERTENCIA";
        } else if ((pacientes[i].presionSistolicaMaxima >= 130 && pacientes[i].presionSistolicaMaxima <= 140) ||
                   (pacientes[i].presionDiastolicaMaxima >= 90 && pacientes[i].presionDiastolicaMaxima <= 95)) {
            mensaje = "SEGUIMIENTO";
        }

        archivo.write(reinterpret_cast<const char*>(&pacientes[i].cedula), sizeof(int));
        archivo.write(reinterpret_cast<const char*>(&pacientes[i].presionSistolicaMaxima), sizeof(int));
        archivo.write(reinterpret_cast<const char*>(&pacientes[i].presionDiastolicaMaxima), sizeof(int));
        archivo.write(mensaje.c_str(), mensaje.size());
    }
    archivo.close();
}

int main() {
    int cantidadPacientes;
    Paciente* pacientes = obtenerPacientes("medidas.txt", cantidadPacientes);
    guardarPacientes(pacientes, cantidadPacientes);
    delete[] pacientes;
    return 0;
}
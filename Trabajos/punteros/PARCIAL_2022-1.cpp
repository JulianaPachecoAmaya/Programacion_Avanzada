#include <iostream>
#include <fstream>

// Función para eliminar los espacios de una cadena
char* eliminarEspacios(char* cadena) {
    char* p = cadena; // Puntero para recorrer la cadena original
    char* q = cadena; // Puntero para modificar la cadena eliminando espacios

    while (*p) {
        if (*p != ' ') {
            *q = *p;
            q++;
        }
        p++;
    }
    *q = '\0'; // Agrega el terminador de cadena
    return cadena;
}

// Función para determinar si una cadena es palíndroma
bool esPalindroma(const char* cadena) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }

    // Compara los caracteres de extremos hacia el centro
    for (int i = 0; i < longitud / 2; i++) {
        if (cadena[i] != cadena[longitud - 1 - i]) {
            return false; // No es palíndroma
        }
    }
    return true; // Es palíndroma
}

// Función para contar las líneas palíndromas en un archivo de texto
int contarLineasPalindromasEnArchivo(const char* rutaArchivo) {
    std::ifstream archivo(rutaArchivo); // Abre el archivo para lectura
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return -1; // Error al abrir el archivo
    }

    int contador = 0;
    const int tamLinea = 256;
    char* linea = new char[tamLinea]; // Tamaño máximo de una línea en el archivo

    // Lee cada línea del archivo
    while (archivo.getline(linea, tamLinea)) {
        eliminarEspacios(linea); // Elimina espacios de la línea
        if (esPalindroma(linea)) {
            contador++; // Incrementa el contador si la línea es palíndroma
        }
    }

    delete[] linea; // Libera la memoria asignada para la línea
    archivo.close(); // Cierra el archivo
    return contador;
}

// Función para crear un archivo de texto con el texto especificado
void crearArchivo(const char* rutaArchivo) {
    std::ofstream archivo(rutaArchivo); // Abre el archivo para escritura
    if (!archivo.is_open()) {
        std::cerr << "No se pudo crear el archivo." << std::endl;
        return;
    }

    // Escribe el texto en el archivo
    archivo << " a luna ese anula" << std::endl;
    archivo << "a ti no bonita" << std::endl;
    archivo << "a mercedes ese de crema" << std::endl;

    archivo.close(); // Cierra el archivo
}

int main() {
    const char* rutaArchivo = "archivo.txt";
    crearArchivo(rutaArchivo);
    std::cout << "Archivo creado correctamente." << std::endl;

    std::cout << "Cantidad de líneas palíndromas en '" << rutaArchivo << "': " << contarLineasPalindromasEnArchivo(rutaArchivo) << std::endl;

    return 0;
}

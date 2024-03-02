#include <iostream>

using namespace std;

void encontrar_mayor(const int* vector, int longitud, int*& max_ptr) {
    if (longitud <= 0) {
        max_ptr = nullptr;
        return;
    }

    max_ptr = const_cast<int*>(vector); 
    for (int i = 1; i < longitud; ++i) {
        if (vector[i] > *max_ptr) {
            max_ptr = const_cast<int*>(&vector[i]);
        }
    }
}

int main() {
    int vector[] = {5, 8, 3, 12, 7, 10};
    int longitud = sizeof(vector) / sizeof(vector[0]);
    int* max_ptr = nullptr;

    
    encontrar_mayor(vector, longitud, max_ptr);
    std::cout << "El elemento mayor del vector es: " << *max_ptr << std::endl;

    
    encontrar_mayor(vector, longitud / 2, max_ptr);
    cout << "El elemento mayor de la primera mitad es: " << *max_ptr << endl;

    
    encontrar_mayor(vector + longitud / 2, longitud - longitud / 2, max_ptr);
    cout << "El elemento mayor de la segunda mitad es: " << *max_ptr << endl;

    return 0;
}

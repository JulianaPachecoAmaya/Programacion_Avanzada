#include <iostream>
#include <sstream>
using namespace std;

int main() {

    char frase[200];

    // Ingresa la frase
    cout << "Ingresa una frase: ";
    cin.getline(frase, sizeof(frase));

    // Utiliza un stringstream para dividir la frase en palabras
    istringstream stream(frase);
    string palabra;
    

    // Imprime cada palabra en una nueva columna
    cout << "Palabras en columnas:"<< endl;
   while (stream >> palabra) {
        cout << palabra << " - " << palabra.length() <<endl;
    }
   
   

    return 0;
}

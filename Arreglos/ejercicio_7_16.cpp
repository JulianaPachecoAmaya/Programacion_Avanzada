#include <iostream>

using namespace std;

int main()
{
    int tamaño = 5;
    int lista[tamaño];
    int mayor = 0;
    cout << "Ingrese una lista de numeros" << endl;

    for (int i = 0; i < tamaño; i++)
    {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> lista[i];
    }

    for (int i = 0; i < tamaño ; i++)
    {
        if (mayor < lista[i])
        {
            mayor = lista[i];
        }
    }
    cout << "El numero mas grande es: " << mayor << endl;
}

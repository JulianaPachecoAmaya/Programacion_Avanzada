#include <iostream>
#include <string>

using namespace std;

int main() {
  char cad[1000];
  char *ptr= cad;

  cout << "Ingrese una cadena de caracteres: ";
  cin.getline (cad, 1000);
  cout << endl;

  for(int i=0; i<1000; i++)
    if (*ptr != ' ' && *ptr !='\0'){
      ptr ++;
    }
  
  cout << "La cadena de caracteres sin la primera palabra es:" << endl << ptr;
    ptr ++;

  return 0;
  
  }
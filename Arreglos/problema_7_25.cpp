#include <iostream>
#include <string>

using namespace std;

string conversion(string fecha);

int main() {

  string fecha;

  cout << "Introduzca la fecha en formato dd/mm/aa entre(1900-1999): "<< endl;
  cin >> fecha;

  cout << conversion(fecha) << endl;
}

string conversion(string fecha) {
  string dia, mes, año;
  int dia_conv, mes_conv, año_conv;
  string meses[12] = {"Enero",      "Febrero", "Marzo",     "Abril",
                      "Mayo",       "Junio",   "Julio",     "Agosto",
                      "Septiembre", "Octubre", "Noviembre", "Diciembre"};
  
  int posicion = 0;

  posicion = fecha.find("/");
  dia = fecha.substr(0, posicion);
  fecha = fecha.substr(posicion + 1);

  posicion = fecha.find("/");
  mes = fecha.substr(0, posicion);
  fecha = fecha.substr(posicion + 1);

  año = fecha;

  dia_conv = stoi(dia);
  mes_conv = stoi(mes);
  año_conv = stoi(año);

  string fecha_conversion = dia + " de " + meses[mes_conv - 1] + " de 19" + año;

  return fecha_conversion;
}
#include <iostream>

using namespace std;

struct forma_compleja{
  double real;
  double imaginario;
};
forma_compleja suma(forma_compleja num_1, forma_compleja num_2);
forma_compleja resta(forma_compleja num_1, forma_compleja num_2);
forma_compleja multiplicacion(forma_compleja num_1, forma_compleja num_2);
forma_compleja division(forma_compleja num_1, forma_compleja num_2);

int main() {
  forma_compleja num_1 = {2.1, 5.2};
  forma_compleja num_2 = {3.2, 4.3};

  forma_compleja res_suma = suma(num_1, num_2);
  cout << "La suma de los numeros complejos es: " << res_suma.real << " + " <<res_suma.imaginario<<"i "<<endl;

  forma_compleja res_resta = resta(num_1, num_2);
  cout << "La resta de los numeros complejos es: " << res_resta.real << " + " <<res_resta.imaginario<<"i "<<endl;

  forma_compleja res_multiplicacion = multiplicacion(num_1, num_2);
  cout << "La multiplicacion de los numeros complejos es: " << res_multiplicacion.real << " + " << res_multiplicacion.imaginario<<"i "<<endl;

  forma_compleja res_division = division(num_1, num_2);
  cout <<"La division de los numeros complejos es: " << res_division.real << " + " << res_division.imaginario <<"i "<<endl;
}

forma_compleja suma(forma_compleja num_1, forma_compleja num_2){
  
  forma_compleja resultado;
  resultado.real = num_1.real + num_2.real;
  resultado.imaginario = num_1.imaginario + num_2.imaginario;

  return resultado;
  
}
forma_compleja resta(forma_compleja num_1, forma_compleja num_2){
  forma_compleja resultado;
  resultado.real = num_1.real - num_2.real;
  resultado.imaginario = num_1.imaginario - num_2.imaginario;

  return resultado;
}
forma_compleja multiplicacion(forma_compleja num_1, forma_compleja num_2){
  forma_compleja resultado;
  resultado.real = num_1.real * num_2.real - num_1.imaginario * num_2.imaginario;
  resultado.imaginario = num_1.real * num_2.imaginario + num_1.imaginario * num_2.real;

  return resultado;
}
forma_compleja division(forma_compleja num_1, forma_compleja num_2){
  forma_compleja resultado;
  double denominador = num_2.real * num_2.real + num_2.imaginario * num_2.imaginario;
  resultado.real = (num_1.real * num_2.real + num_1.imaginario * num_2.imaginario) / denominador;
  resultado.imaginario = (num_1.imaginario * num_2.real - num_1.real * num_2.imaginario) / denominador;

  return resultado;
}

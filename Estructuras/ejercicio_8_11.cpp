#include <iostream>
#include <math.h>

using namespace std;

/*Inicializa estructura de puntos en el plano*/
struct puntosPlano{
  double x=0;
  double y=0;
};

int main() {
  /*Inicializa variables*/
  puntosPlano punto1, punto2;
  double distancia;
  float puntoMediox;
  float puntoMedioy;

  /*Pide coordenadas*/
  cout<<"Ingrese coordenadas x del primer punto:";
  cin>>punto1.x;
  cout<<"Ingrese coordenadas y del primer punto:";
  cin>>punto1.y;
  cout<<endl;

  cout<<"Ingrese coordenadas x del segundo punto:";
  cin>>punto2.x;
  cout<<"Ingrese coordenadas y del segundo punto:";
  cin>>punto2.y;
  cout<<endl;

  /*Formula para sacar la distancia entre los puntos*/
  distancia = sqrt(pow(punto2.x - punto1.x ,2) + pow(punto2.y - punto1.y ,2));

  /*Formula para sacar el punto medio de la linea que los une*/
  puntoMediox = (punto1.x + punto2.x)/2;
  puntoMedioy = (punto1.y + punto2.y)/2;

  /*Imprimir resultados*/
  cout<<"  ("<<punto1.x<<","<<punto1.y<<") "<<"("<<punto2.x<<","<<punto2.y<<")"<<endl;
  cout<<"La distancia entre los puntos es: "<<distancia<<endl;  
  cout<<"El punto medio de la linea que los une es: ("<<puntoMediox<<", "<<puntoMedioy<<")"<<endl;
}

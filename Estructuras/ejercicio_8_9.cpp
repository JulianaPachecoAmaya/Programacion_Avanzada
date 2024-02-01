#include <iostream>
#include <string>
using namespace std;

/*Inicializa estructura de equipos*/
struct equipos{
  string nombreEquipo;
  int numVictorias=0;
  int numDerrotas=0;
};

/*Inicializa estructura de equipo de baloncesto*/
struct baloncesto{
  int PerdidasBalon=0;
  int RebotesCogidos=0;
  string MejorJugador;
  int numTriples=0;
};

/*Inicializa estructura de equipo de futbol*/
struct futbol{
  int empates=0;
  int golesFavor=0;
  int golesContra=0;
  string goleador;
  int numGoles=0;
};

int main() {
  /*Inicializa variables*/
    const int maxPersonas=20;
    int cantEquipos=0;
    int cantBaloncesto=0;
    int cantFutbol=0;
    int opcion;
    char opcion2;
    equipos equipos[maxPersonas];
    baloncesto baloncesto[maxPersonas];
    futbol futbol[maxPersonas];

  do{
    /*Ingresa informacion de los equipos*/
    cout<<"Ingrese el nombre del equipo: ";
    cin>>equipos[cantEquipos].nombreEquipo;
    cout<<"Ingrese el numero de victorias del equipo: ";
    cin>>equipos[cantEquipos].numVictorias;
    cout<<"Ingrese el numero de derrotas del equipo: ";
    cin>>equipos[cantEquipos].numDerrotas;
    cantEquipos++;
    cout<<endl;

    /*Pregunta opcion a ejecutar*/
    cout<<"Escriba la opcion que desea ejecutar:"<<endl;
    cout<<"1. Ingresar datos de baloncesto"<<endl;
    cout<<"2. Ingresar datos de futbol"<<endl;
    cout<<"3. Salir"<<endl;
    cin>>opcion;
    cout<<endl;

    switch (opcion){
      /*Ingresa datos de equipos de baloncesto*/
      case 1:
      cout<< "Ingrese el numero de perdidas de balon: ";
      cin>>baloncesto[cantBaloncesto].PerdidasBalon;
      cout<< "Ingrese el numero de rebotes cogidos: ";
      cin>>baloncesto[cantBaloncesto].RebotesCogidos;
      cout<< "Ingrese el nombre del mejor anotador de triples: ";
      cin>>baloncesto[cantBaloncesto].MejorJugador;
      cout<< "Ingrese el numero de triples del mejor triplista: ";
      cin>>baloncesto[cantBaloncesto].numTriples;
        cantBaloncesto++;
        cout<<endl;
      break;

      /*Ingresa datos de equipos de futbol*/
      case 2:
      cout<< "Ingrese el numero de empates: ";
      cin>>futbol[cantFutbol].empates;
      cout<< "Ingrese el numero de goles a favor: ";
      cin>>futbol[cantFutbol].golesFavor;
      cout<< "Ingrese el numero de goles en contra: ";
      cin>>futbol[cantFutbol].golesContra;
      cout<< "Ingrese el nombre del goleador: ";
      cin>>futbol[cantFutbol].goleador;
      cout<< "Ingrese el numero de goles del goleador: ";
      cin>>futbol[cantFutbol].numGoles;
        cantFutbol++;
        cout<<endl;
      break;

      /*Termina el programa*/
      case 3:
      cout<<"Programa finalizado."<<endl;
      break;
      return 0;
    }
    
/*Opcion para ingresar informacion de otros equipos*/
    cout << "¿Desea ingresar información sobre otro equipo? (S/N): ";
    cin >> opcion2;
    } while (opcion2 == 'S' || opcion2 == 's');

  cout<<endl;

  /*Imprime informacion ingresada*/
  cout<<"Equipos: "<<endl;
    for(int i=0; i<cantEquipos; i++){
      cout<<"INFORMACION EQUIPO "<<i+1<<endl;
      cout<<"Nombre: "<<equipos[i].nombreEquipo<<endl;
      cout<<"Numero de victorias: "<<equipos[i].numVictorias<<endl;
      cout<<"Numero de derrotas: "<<equipos[i].numDerrotas<<endl;
      cout<<endl;
    }
      for(int i=0; i<cantBaloncesto; i++){
        cout<<"INFORMACION EQUIPO DE BALONCESTO "<<i+1<<endl;
        cout<<"Perdidas de balon: "<<baloncesto[i].PerdidasBalon<<endl;
        cout<< "Rebotes cogidos: "<<baloncesto[i].RebotesCogidos<<endl;
        cout<<"Mejor anotador de triples: "<<baloncesto[i].MejorJugador<<endl;
        cout<<"Numero de triples del mejor triplista: "<<baloncesto[i].numTriples<<endl;
        cout<<endl;
    }
      for(int i=0; i<cantFutbol; i++){
        cout<<"INFORMACION EQUIPO DE FUTBOL "<<i+1<<endl;
        cout<< "Empates: "<<futbol[i].empates<<endl;
        cout<<"goles a favor: "<<futbol[i].golesFavor<<endl;
        cout<<"goles en contra. "<<futbol[i].golesContra<<endl;
        cout<< "Nombre del goleador: "<<futbol[i].goleador<<endl;
        cout<<"Numero de goles del goleador: "<<futbol[i].numGoles<<endl;
        cout<<endl;
      }
  
  }

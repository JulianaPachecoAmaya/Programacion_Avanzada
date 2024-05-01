public class Componente{
  int id;
  String nombre;
  double peso;

  public Componente(int id, String nombre, double peso){
    this.id = id;
    this.nombre = nombre;
    this.peso = peso;
  }


//Setters y Getters
public void setId(int id) {this.id = id;}
public int getId() {return id;}

public void setNombre(String nombre) {this.nombre = nombre;}
public String getNombre() {return nombre;}

public void setPeso(double peso) {this.peso = peso;}
public double getPeso() {return peso;}

}
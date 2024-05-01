import java.util.ArrayList;

public class Robot{
  String codigo;
  double pesoMaximo;
  ArrayList<Componente> componentes;

  //Constructor con lista inicializada vacia
  public Robot(String codigo, double pesoMaximo) {
    this.codigo = " ";
    this.pesoMaximo = 0;
  }


//Setter y Getters
  public void setCodigo(String codigo) {this.codigo = codigo;}
  public String getCodigo() {return codigo;}
  
  public void setPesoMaximo(double pesoMaximo) {this.pesoMaximo = pesoMaximo;}
  public double getPesoMaximo() {return pesoMaximo;}


//metodo para agregar componentes
  public void anadirComponente(int id, String nombre, double peso){
    Componente componente = new Componente(id, nombre, peso);
    
    if(componente.getPeso() > pesoMaximo){
      System.out.println("El peso del componente supera el peso maximo del robot");
    } else{
      this.componentes.add(componente);
    }
  }

    
  //metodo para sumatoria de pesos de los compnenetes del robot
    public double sumatoriaPesos(){
      double pesoTotal = 0;
      for (Componente componente : componentes) {
          pesoTotal += componente.getPeso();
      }
      System.out.println("La sumatoria de los pesos de los componentes del robot es: " + pesoTotal);
      return pesoTotal;
      }
  }


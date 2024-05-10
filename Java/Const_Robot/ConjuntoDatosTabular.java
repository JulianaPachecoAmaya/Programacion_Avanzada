public class ConjuntoDatosTabular extends ConjuntoDatos {
int nColumnas;
  int nfilas;

  // Setters
  public void setNColumnas(int nColumnas) {
    this.nColumnas = nColumnas;
  }

  public void setNFilas (int nFilas) {
    this.nfilas = nFilas;
  }

  // Getters
  public int getNColumnas() {
    return nColumnas;
  }

  public int getNFilas() {
    return nfilas;
  }
  
// Constructor 
public ConjuntoDatosTabular(String nombre, int tamano, int nfilas, int nColumnas) {
    this.nombre = nombre; 
    this.tamano = tamano; 
    this.nfilas = nfilas;
    this.nColumnas = nColumnas;
}

// Metodo describir
    @Override
    public String describir(){
      String imagen = "Imagen de " + getNombre() + ", " + getTamano() + ", " +   getNFilas() + ", " + getNColumnas();
      return imagen;
      }
}

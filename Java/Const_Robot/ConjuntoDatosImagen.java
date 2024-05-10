public class ConjuntoDatosImagen extends ConjuntoDatos{
  int dpi;

// Setters y getters
  public void setDpi(int dpi) {
    this.dpi = dpi;
  }

  public int getDpi() {
    return dpi;
  }

  
// Constructor 
  public ConjuntoDatosImagen(String nombre, int tamano, int dpi) {
      this.nombre = nombre;
      this.tamano = tamano;
      this.dpi = dpi;
  }

  
  // Metodo describir 
@Override
public String describir(){
  String imagen = "Imagen de " + getNombre() + ", " + getTamano() + ", DPI: " +   getDpi();
  return imagen;
  }

}
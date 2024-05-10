public abstract class ConjuntoDatos {
  String nombre;
  int tamano;

  // Setter y getters
    public void setNombre(String nombre) {
    this.nombre = nombre;
  }

  public void setTamano(int tamano) {
    this.tamano = tamano;
  }

  public String getNombre() {
    return nombre;
  }

  public int getTamano() {
    return tamano;
  }

  // Llamar metodo describir
  public abstract String describir();


}
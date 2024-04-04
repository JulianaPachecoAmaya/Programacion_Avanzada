
public class Pasajero {
  // Atributos
  private String nombres;
  private String apellidos;
  private String numPasaporte;
  private String asiento;
  private int edad;

  // Constructor por defecto
  public Pasajero() {
    //inicializacion por defecto
    this.nombres = " ";
    this.apellidos = " ";
    this.numPasaporte = " ";
    this.asiento = " ";
    this.edad = 0;
  }
  
  // Constructor con parametros
  public Pasajero(String nombres, String apellidos, String numPasaporte, String asiento, int edad) throws IllegalStateException{
    
    //Validacion de datos ingresados
    if(nombres == null || nombres.isEmpty() || apellidos == null || apellidos.isEmpty() || numPasaporte == null  || numPasaporte.isEmpty() || asiento == null || asiento.isEmpty()|| edad < 0){
      throw new IllegalArgumentException("Error en los datos del pasajero");
    }

    //Asignacion de datos
    this.nombres = nombres;
    this.apellidos = apellidos;
    this.numPasaporte = numPasaporte;
    this.asiento = asiento;
    this.edad = edad;
  }

  // Metodos getter y setter
  public String getNombres() {
    return nombres;
  }

  public String getApellidos() {
    return apellidos;
  }

  public String getNumPasaporte() {
    return numPasaporte;
  }

  public String getAsiento() {
    return asiento;
  }

  public int getEdad() {
    return edad;
  }


  public void setNombres(String nombres) {
    this.nombres = nombres;
  }

  public void setApellidos(String apellidos) {
    this.apellidos = apellidos;
  }

  public void setNumPasaporte(String numPasaporte) {
    this.numPasaporte = numPasaporte;
  }

  public void setAsiento(String asiento) {
    this.asiento = asiento;
  }

  public void setEdad(int edad) {
    this.edad = edad;
  }


  public void MenorEdad(Pasajero pasajero1, Pasajero pasajero2){
    if (pasajero1.edad < pasajero2.edad){
      System.out.println("El pasajero " + pasajero1.nombres + " " + pasajero1.apellidos + " es el menor");
    } else {
      System.out.println("El pasajero " + pasajero2.nombres + " " + pasajero2.apellidos + " es menor");
    }
  }
  
}


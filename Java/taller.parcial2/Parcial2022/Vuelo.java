public class Vuelo {
  private String codigo;
  private String origen;
  private String destino;
  private int capacidad;
  private Pasajero[] pasajeros;
}

  // Constructor por defecto
  public Vuelo() {
    this.codigo = " ";
    this.origen = " ";
    this.destino = " ";
    this.capacidad = 0;
    this.pasajeros = new Pasajero[0];
  }

  // Constructor con parametros
  public Vuelo(String codigo, String origen, String destino, int capacidad, Pasajero pasajero) {
    this.codigo = codigo;
    this.origen = origen;
    this.destino = destino;
    this.capacidad = capacidad;
    this.pasajeros = pasajeros;
  }

  // Metodo para agregar pasajero
  public void agregarPasajero(Pasajero nuevoPasajero) {
    // Si excede la capacidad del vuelo
    if (pasajeros.size >= capacidad) {
      System.out.println("No se puede agregar el pasajero, el vuelo esta lleno");
      return;
    }
    // Si ya existe el numero de pasaporte
    for (Pasajero pasajero : pasajeros) {
      if (pasajero.getNumPasaporte().equals(nuevoPasajero.getNumPasaporte())) {
        System.out.println("Ya existe un pasajero con ese unmero de pasaporte");
        return;
      }
    }

    // Si el asiento esta ocupado
    for (Pasajero pasajero : pasajeros) {
      if (pasajero.getAsiento().equals(nuevoPasajero.getAsiento())) {
        System.out.println("El asiento ya esta ocupado");
        return;
      }
    }
    // Agrega el pasajero al vuelo
    pasajeros.add(nuevoPasajero);
  }

  // Metodos Setters
  public void setCodigo(String codigo) {
    this.codigo = codigo;
  }

  public void setOrigen(String origen) {
    this.origen = origen;
  }

  public void setDestino(String destino) {
    this.destino = destino;
  }

  public void setCapacidad(int capacidad) {
    this.capacidad = capacidad;
  }

  public void setPasajero(Pasajero pasajero) {
    this.pasajero = pasajero;
  }

  // Metodos Getters
  public String getCodigo() {
    return codigo;
  }

  public String getOrigen() {
    return origen;
  }

  public String getDestino() {
    return destino;
  }

  public int getCapacidad() {
    return capacidad;
  }

  public Pasajero getPasajero() {
    return pasajero;
  }

  public int NumPasajeros() {
    return pasajero.length;
  }

  // Metodo para eliminar a un pasajero por un numero de pasaporte
  public void eliminarPasajero(String numPasaporte) {
    for (Pasajero pasajero : pasajeros) {
      // Verificar si el número de pasaporte coincide con el proporcionado
      if (pasajero.getNumPasaporte().equals(numPasaporte)) {
        pasajeros.remove(pasajero);
        System.out.println("El pasajero ha sido eliminado");
        return;
      }
    }
  }

  // Metodo para obtener el pasajero mas joven
  public String PasajeroMasJoven() {
    // Verificar si no hay pasajeros registrados
    if (pasajeros.isEmpty()) {
      return "El vuelo está vacío";
    }

    // Encontrar al pasajero más joven
    Pasajero pasajeroMasJoven = pasajeros.get(0); // Suponemos que el primer pasajero es el más joven inicialmente
    for (Pasajero pasajero : pasajeros) {
      pasajeroMasJoven = Pasajero.compararEdad(pasajero, pasajeroMasJoven);
    }

    // Construir la cadena de caracteres con el formato requerido
    String resultado = "El pasajero más joven del vuelo es " + pasajeroMasJoven.getNombres() + " " +
        pasajeroMasJoven.getApellidos() + " (pasaporte: " + pasajeroMasJoven.getNumPasaporte() + "). ";
    resultado += "Tiene " + pasajeroMasJoven.getEdad() + " años y está sentado en el asiento " +
        pasajeroMasJoven.getAsiento() + ".";
    return resultado;
  }

}
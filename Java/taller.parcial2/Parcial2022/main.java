public class main {
  public static void main(String[] args) {
    // Crear pasajeros
    Pasajero pasajero1 = new Pasajero("Juliana", "Pacheco", "JR-123", "A1", 19);
    Pasajero pasajero2 = new Pasajero("Juan", "Perez", "JR-456", "A2", 20);

    // Mostrar el pasajero más joven
    pasajero1.MenorEdad(pasajero1, pasajero2);

    // Crear un vuelo
    Vuelo vuelo = new Vuelo("V001", "Madrid", "Barcelona", 100, null);

    // Agregar pasajeros
    vuelo.agregarPasajero(pasajero1);
    vuelo.agregarPasajero(pasajero2);

    // Mostrar el pasajero más joven del vuelo
    System.out.println(vuelo.obtenerPasajeroMasJoven());

    // Eliminar un pasajero del vuelo
    vuelo.eliminarPasajero("JR-123");

    // Mostrar el pasajero más joven del vuelo después de eliminar uno
    System.out.println(vuelo.obtenerPasajeroMasJoven());
  }
}

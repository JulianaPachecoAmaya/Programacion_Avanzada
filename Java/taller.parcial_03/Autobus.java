public class Autobus extends Vehiculo {
    private int numeroDeRutas;

    public Autobus(String marca, int capacidad, int numeroDeRutas) {
        super(marca, capacidad);
        this.numeroDeRutas = numeroDeRutas;
    }

    @Override
    public String tipoDeVehiculo() {
        return "Autobus";
    }

    public void mostrarInformacion() {
        super.mostrarInformacion();
        System.out.println("Número de rutas: " + numeroDeRutas);
    }
}
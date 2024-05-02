public class Taxi extends Vehiculo {
    private String licencia;

    public Taxi(String marca, int capacidad, String licencia) {
        super(marca, capacidad);
        this.licencia = licencia;
    }
    @Override
    public String tipoDeVehiculo() {
        return "Taxi";
    }

    public void mostrarInformacion() {
        super.mostrarInformacion();
        System.out.println("Licencia: " + licencia);
    }
}
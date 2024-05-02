public class Tranvia extends Vehiculo{
    private boolean rieles;

    public Tranvia(String marca, int capacidad, boolean rieles) {
        super(marca, capacidad);
        this.rieles = rieles;
    }
    @Override
    public String tipoDeVehiculo() {
        return "Tranvia";
    }

    public void mostrarInformacion() {
        super.mostrarInformacion();
        System.out.println("Rieles: " + (rieles? "Sí" : "No"));
    }
}
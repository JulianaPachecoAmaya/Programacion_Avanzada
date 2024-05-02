public abstract class Vehiculo {
    protected String marca;
    protected int Capacidad;

    public Vehiculo(String marca, int capacidad) {
        this.marca = marca;
        Capacidad = capacidad;
    }
    public void mostrarInformacion(String marca, int Capacidad){
        System.out.println("Marca: " + marca);
        System.out.println("Capacidad: " + Capacidad);
    }
    public abstract String tipoDeVehiculo();
}
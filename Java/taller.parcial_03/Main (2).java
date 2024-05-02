import java.util.ArrayList;
import java.util.List;
public class Main {
    public static void main(String[] args) {
        List<Vehiculo> vehiculoLista = new ArrayList<>();
        vehiculoLista.add(new Autobus("volvo", 1000, 8));
        vehiculoLista.add(new Tranvia("Clio", 2000, true));
        vehiculoLista.add(new Taxi("Spark", 4, "CVR073"));

        for(Vehiculo Vehiculo: vehiculoLista){
            System.out.println("Tipo de vehículo: " + Vehiculo.tipoDeVehiculo());
            Vehiculo.mostrarInformacion();
            System.out.println();
        }
    }


}
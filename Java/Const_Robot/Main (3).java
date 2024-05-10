public class Main {
    public static void main(String[] args) {

        // Crear un conjunto de datos
        CatalogoDatos catalogo = new CatalogoDatos("nombreArchivo", "rutaArchivo/");
        // Crear un conjunto de datos imagen
        ConjuntoDatosImagen imagen = new ConjuntoDatosImagen("nombre", 100.0, 300);
        // Crear un conjunto de datos tabular
        ConjuntoDatosTabular tabular = new ConjuntoDatosTabular("nombre", 200.0, 10, 20);

        // Metodos describir
        catalogo.agregarConjuntoDatos(imagen);
        catalogo.agregarConjuntoDatos(tabular);

        // Imprime el catalogo
        System.out.println(catalogo.estadisticas());
    }
}
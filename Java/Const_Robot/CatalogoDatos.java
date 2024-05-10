import java.io.*;
import java.util.ArrayList;

public class CatalogoDatos{
    //Archivos
     private static final String RUTA_ARCHIVO_PERSISTENCIA = "CatalogoDatos.dat";
        private List<ConjuntoDatos> conjuntos;
        private String rutaAcceso;

        public CatalogoDatos(String nombreArchivo, String rutaArchivo) {
            this.rutaAcceso = rutaArchivo + nombreArchivo;
            conjuntos = new ArrayList<>();
            cargarConjuntos();
        }

        private void cargarConjuntos() {
            File file = new File(rutaAcceso);
            if (!file.exists()) {
                try {
                    file.createNewFile();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(rutaAcceso))) {
                    conjuntos = (List<ConjuntoDatos>) ois.readObject();
                } catch (IOException | ClassNotFoundException e) {
                    e.printStackTrace();
                }
            }
        }

    // Metodo agregar conjunto de datos
        public void agregarConjuntoDatos(ConjuntoDatos conjunto) {
            if (!conjuntos.contains(conjunto)) {
                conjuntos.add(conjunto);
            }
        }
    
    // Metodo eliminar conjunto de datos
        public void eliminarConjuntoDatos(String nombre) throws Exception {
            boolean eliminado = conjuntos.removeIf(conjunto -> conjunto.nombre.equals(nombre));
            if (!eliminado) {
                throw new Exception("No se encontró un conjunto con el nombre: " + nombre);
            }
        }

    //metodo ordenar lista
        public void ordenar() {
            conjuntos.sort(Comparator.comparingDouble(conjunto -> conjunto.tamaño));
        }

    //metodo estadistica
        public String estadisticas() {
            int total = conjuntos.size();
            int imagenes = (int) conjuntos.stream().filter(conjunto -> conjunto instanceof ConjuntoDatosImagen).count();
            int tabulares = total - imagenes;
            double tamañoTotal = conjuntos.stream().mapToDouble(conjunto -> conjunto.tamaño).sum();
            return "Total de conjuntos: " + total + "(" + imagenes + " imágenes y " + tabulares + " tabulares). Tamaño total de datos: " + tamañoTotal + "(" + (100.0 * imagenes / total) + "% imágenes, " + (100.0 * tabulares / total) + "% tabulares)";
        }
    }
    /* ArrayList<ConjuntoDatos> Lista = new ArrayList<ConjuntoDatos>();

    String RUTA_PERSISTENCIA;

    public archivo(){
        String rutaArchivo = "miarchivo.txt";

        try {
            // Crear FileWriter con la ruta del archivo
            FileWriter archivoEscritura = new FileWriter(rutaArchivo);

            // Crear BufferedWriter para escribir en el archivo
            BufferedWriter escritor = new BufferedWriter(archivoEscritura);

            // Escribir en el archivo
            escritor.write("Este es el contenido del archivo de texto.");
            escritor.newLine(); // Agregar nueva línea
            escritor.write("Segunda línea.");

            // Cerrar BufferedWriter
            escritor.close();

            System.out.println("El archivo de texto ha sido creado exitosamente.");
        } catch (IOException e) {
            System.err.println("Error al crear el archivo: " + e.getMessage());
        }
    }

    // Metodo exportar
    public exportar( ){ 

        
    }

    // metodo AgregarConjuntoDatos
    public AgregarConjuntoDatos(ConjuntoDatos conjunto){
        Lista.add(conjunto);        
    }

    // Metodo eliminarConjuntoDatos
    public eliminarConjuntoDatos(String nombre){
        foreach(ConjuntoDatos conjuntoDatos : Lista){//recorrer la lista
            if(conjuntoDatos.getNombre() == nombre){
                Lista.remove(conjuntoDatos);
            }
        }
        
        
    }*/
}

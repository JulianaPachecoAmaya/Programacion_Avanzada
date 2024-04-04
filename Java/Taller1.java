import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Biblioteca {
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();
        biblioteca.iniciar();
    }

    public void iniciar() {
        List<Libro> libros = new ArrayList<>();
        List<Usuario> usuarios = new ArrayList<>();
        List<Prestamo> prestamos = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("Bienvenido al Sistema de Gestión de Biblioteca");
            System.out.println("1. Administrar libros");
            System.out.println("2. Administrar usuarios");
            System.out.println("3. Administrar préstamos");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    // Administrar libros
                    break;
                case 2:
                    // Administrar usuarios
                    break;
                case 3:
                    // Administrar préstamos
                    break;
                case 4:
                    System.out.println("Gracias por utilizar el Sistema de Gestión de Biblioteca");
                    break;
                default:
                    System.out.println("Opción inválida");
                    break;
            }
        } while (opcion != 4);
    }
}

class Libro {
    private String titulo, autor;
    private int año;

    public Libro(String titulo, String autor, int año) {
        this.titulo = titulo;
        this.autor = autor;
        this.año = año;
    }
}

class Usuario {
    private String nombre, apellido, dni;

    public Usuario(String nombre, String apellido, String dni) {
        this.nombre = nombre;
        this.apellido = apellido;
        this.dni = dni;
    }
}

class Prestamo {
    private Libro libro;
    private Usuario usuario;
    private String fechaInicio, fechaFin;

    public Prestamo(Libro libro, Usuario usuario, String fechaInicio, String fechaFin) {
        this.libro = libro;
        this.usuario = usuario;
        this.fechaInicio = fechaInicio;
        this.fechaFin = fechaFin;
    }
}

import java.util.Scanner;

public class HumanPlayer extends AbstractPlayer {
    private Scanner scanner;

    public HumanPlayer(String name, char disc, Scanner scanner) {
        super(name, disc);
        this.scanner = scanner;
    }

    @Override
    public int makeMove(Board board) {
        System.out.println(name + "'s turn. Ingrese numero de columna (0-6):");
        int col;
        while (true) {
            try {
                col = Integer.parseInt(scanner.nextLine());
                if (col >= 0 && col < 7 && board.isColumnAvailable(col)) {
                    break;
                } else {
                    System.out.println("Columna invalida o columna llena. Intente nuevamente.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Entrada invalida. Ingrese un numero entre 0 y 6.");
            }
        }
        return col;
    }
}

import java.util.Scanner;

public class Game {
    private Board board;
    private PlayerInterface player1;
    private PlayerInterface player2;
    private PlayerInterface currentPlayer;

    public Game() {
        board = new Board();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Ingrese nombre jugador 1: ");
        String name1 = scanner.nextLine();
        char disc1 = chooseDisc(scanner, "Player 1");

        System.out.print("Ingrese nombre jugador 2: ");
        String name2 = scanner.nextLine();
        char disc2 = (disc1 == 'R') ? 'Y' : 'R';

        player1 = new HumanPlayer(name1, disc1, scanner);
        player2 = new HumanPlayer(name2, disc2, scanner);
        currentPlayer = player1;
    }

    private char chooseDisc(Scanner scanner, String player) {
        char disc;
        while (true) {
            System.out.print(player + ", Escoja su disco (R/Y): ");
            disc = scanner.nextLine().toUpperCase().charAt(0);
            if (disc == 'R' || disc == 'Y') {
                break;
            } else {
                System.out.println("Elección invalida. Porfavor escoja 'R' or 'Y'.");
            }
        }
        return disc;
    }

    public void start() {
        boolean gameWon = false;
        while (!board.isFull() && !gameWon) {
            board.printBoard();
            int col;
            while (true) {
                try {
                    col = currentPlayer.makeMove(board);
                    board.insertDisc(col, currentPlayer.getDisc());
                    break;
                } catch (ColumnFullException e) {
                    System.out.println(e.getMessage());
                } catch (IllegalArgumentException e) {
                    System.out.println("Columna invalida. intente nuevamente.");
                }
            }

            if (board.checkWin(currentPlayer.getDisc())) {
                board.printBoard();
                System.out.println(currentPlayer.getName() + " gano!");
                gameWon = true;
            } else {
                currentPlayer = (currentPlayer == player1) ? player2 : player1;
            }
        }

        if (!gameWon) {
            board.printBoard();
            System.out.println("Es un empate");
        }
    }
}

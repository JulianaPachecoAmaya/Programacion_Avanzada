import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Scanner;

public class Connect4GUI extends JFrame {
    private Board board;
    private PlayerInterface player1;
    private PlayerInterface player2;
    private PlayerInterface currentPlayer;
    private JButton[] buttons;
    private JLabel[][] cells;

    public Connect4GUI() {
        board = new Board();

        String name1 = JOptionPane.showInputDialog(this, "Ingrese nombre del jugador 1:");
        char disc1 = chooseDisc("Player 1");

        String name2 = JOptionPane.showInputDialog(this, "Ingrese nombre del jugador 2:");
        char disc2 = (disc1 == 'R') ? 'Y' : 'R';

        player1 = new HumanPlayer(name1, disc1, new Scanner(System.in));
        player2 = new HumanPlayer(name2, disc2, new Scanner(System.in));
        currentPlayer = player1;

        setTitle("Connect 4");
        setSize(700, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        JPanel panel = new JPanel(new GridLayout(7, 7));
        buttons = new JButton[7];
        cells = new JLabel[6][7];

        for (int i = 0; i < 7; i++) {
            buttons[i] = new JButton(String.valueOf(i));
            final int col = i;
            buttons[i].addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    handleMove(col);
                }
            });
            panel.add(buttons[i]);
        }

        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 7; col++) {
                cells[row][col] = new JLabel(".", SwingConstants.CENTER);
                cells[row][col].setBorder(BorderFactory.createLineBorder(Color.BLACK));
                panel.add(cells[row][col]);
            }
        }

        add(panel, BorderLayout.CENTER);
    }

    private char chooseDisc(String player) {
        char disc;
        while (true) {
            String input = JOptionPane.showInputDialog(this, player + ", elige tu disco (R/Y):").toUpperCase();
            disc = input.charAt(0);
            if (disc == 'R' || disc == 'Y') {
                break;
            } else {
                JOptionPane.showMessageDialog(this, "Elección invalida. Porfavor escoja 'R' or 'Y'.");
            }
        }
        return disc;
    }

    private void handleMove(int col) {
        try {
            board.insertDisc(col, currentPlayer.getDisc());
            updateBoard();
            if (board.checkWin(currentPlayer.getDisc())) {
                JOptionPane.showMessageDialog(this, currentPlayer.getName() + " ganoo!");
                resetGame();
            } else if (board.isFull()) {
                JOptionPane.showMessageDialog(this, "Es un empate");
                resetGame();
            } else {
                currentPlayer = (currentPlayer == player1) ? player2 : player1;
            }
        } catch (ColumnFullException e) {
            JOptionPane.showMessageDialog(this, e.getMessage());
        }
    }

    private void updateBoard() {
        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 7; col++) {
                cells[row][col].setText(String.valueOf(board.getCell(row, col)));
            }
        }
    }

    private void resetGame() {
        board = new Board();
        currentPlayer = player1;
        updateBoard();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Connect4GUI().setVisible(true);
            }
        });
    }
}

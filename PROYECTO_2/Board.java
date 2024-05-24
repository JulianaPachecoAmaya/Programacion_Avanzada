public class Board {
    private final int rows = 6;
    private final int cols = 7;
    private char[][] board;

    public Board() {
        board = new char[rows][cols];
        initializeBoard();
    }

    private void initializeBoard() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = '.';
            }
        }
    }

    public boolean insertDisc(int col, char disc) throws ColumnFullException {
        if (col < 0 || col >= cols) {
            throw new IllegalArgumentException("Columna fuera de limites");
        }

        for (int i = rows - 1; i >= 0; i--) {
            if (board[i][col] == '.') {
                board[i][col] = disc;
                return true;
            }
        }
        throw new ColumnFullException("La columna esta llena");
    }

    public boolean isColumnAvailable(int col) {
        return board[0][col] == '.';
    }

    public void printBoard() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public boolean isFull() {
        for (int i = 0; i < cols; i++) {
            if (board[0][i] == '.') {
                return false;
            }
        }
        return true;
    }

    public boolean checkWin(char disc) {
        // Revisa horizontal, vertical, y diagonal (ambas direcciones) para ganar
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols - 3; col++) {
                if (board[row][col] == disc && board[row][col + 1] == disc &&
                    board[row][col + 2] == disc && board[row][col + 3] == disc) {
                    return true;
                }
            }
        }

        for (int row = 0; row < rows - 3; row++) {
            for (int col = 0; col < cols; col++) {
                if (board[row][col] == disc && board[row + 1][col] == disc &&
                    board[row + 2][col] == disc && board[row + 3][col] == disc) {
                    return true;
                }
            }
        }

        for (int row = 3; row < rows; row++) {
            for (int col = 0; col < cols - 3; col++) {
                if (board[row][col] == disc && board[row - 1][col + 1] == disc &&
                    board[row - 2][col + 2] == disc && board[row - 3][col + 3] == disc) {
                    return true;
                }
            }
        }

        for (int row = 3; row < rows; row++) {
            for (int col = 3; col < cols; col++) {
                if (board[row][col] == disc && board[row - 1][col - 1] == disc &&
                    board[row - 2][col - 2] == disc && board[row - 3][col - 3] == disc) {
                    return true;
                }
            }
        }

        return false;
    }

    public char getCell(int row, int col) {
        return board[row][col];
    }
}

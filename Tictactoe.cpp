#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class TicTacToe {
public:
    TicTacToe() {
        board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
        currentPlayer = 'X';
    }

    void playGame() {
        int mode;
        std::cout << "Select mode: 1. Human vs. Human, 2. Human vs. Robot: ";
        std::cin >> mode;

        while (!isGameOver()) {
            printBoard();
            if (mode == 1 || (mode == 2 && currentPlayer == 'X')) {
                makeMove();
            } else {
                makeRobotMove();
            }
            switchPlayer();
        }

        printBoard();
        printResult();
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void printBoard() {
        std::cout << "-------------" << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << "| ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << std::endl << "-------------" << std::endl;
        }
    }

    bool isCellEmpty(int row, int col) {
        return board[row][col] == ' ';
    }

    bool isGameOver() {
        return hasPlayerWon('X') || hasPlayerWon('O') || isBoardFull();
    }

    bool hasPlayerWon(char player) {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
        }
        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void makeMove() {
        int row, col;
        std::cout << "Player " << currentPlayer << ", Enter your move (row-column both start from 0): ";
        std::cin >> row >> col;
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || !isCellEmpty(row, col)) {
            std::cout << "Invalid move. Try again." << std::endl;
            makeMove();
        } else {
            board[row][col] = currentPlayer;
        }
    }

    void makeRobotMove() {
        std::cout << "Robot is making a move..." << std::endl;
        // Simple random move for the robot
        int row, col;
        // Generate a random move for the robot
        do {
            row = rand() % 3;// Generate a random row index (0, 1, or 2)
            col = rand() % 3;// Generate a random column index (0, 1, or 2)
        } while (!isCellEmpty(row, col)); // Repeat if the chosen cell is not empty
         // Place the robot's move on the game board
        board[row][col] = currentPlayer;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void printResult() {
        if (hasPlayerWon('X')) {
            std::cout << "Player X wins!" << std::endl;
        } else if (hasPlayerWon('O')) {
            std::cout << "Player O wins!" << std::endl;
        } else {
            std::cout << "It's a draw!" << std::endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    //initialising object for class in c++
    TicTacToe game;
    //calling method for object created
    game.playGame();
    return 0;
}

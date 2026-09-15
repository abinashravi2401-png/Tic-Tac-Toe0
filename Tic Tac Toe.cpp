#include <iostream>
#include <vector>

class TicTacToe {
private:
    char board[3][3];
    char currentMarker;

    void resetBoard() {
        char cellNumber = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = cellNumber++;
            }
        }
        currentMarker = 'X';
    }

    void drawBoard() const {
        std::cout << "\n";
        std::cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
        std::cout << "---|---|---\n";
        std::cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
        std::cout << "---|---|---\n";
        std::cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
        std::cout << "\n";
    }

    bool placeMarker(int slot) {
        int row = (slot - 1) / 3;
        int col = (slot - 1) % 3;

        if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            return false;
        }

        board[row][col] = currentMarker;
        return true;
    }

    bool checkWin() const {
        // Rows & Columns check
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                return true;
            }
        }
        // Diagonals check
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            return true;
        }

        return false;
    }

    bool checkDraw() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }

    void swapPlayer() {
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
    }

public:
    void playGame() {
        char replayChoice;
        do {
            resetBoard();
            bool gameOver = false;

            while (!gameOver) {
                drawBoard();
                int slot;
                std::cout << "Player " << currentMarker << ", enter slot (1-9): ";
                std::cin >> slot;

                if (!placeMarker(slot)) {
                    std::cout << "Invalid move! Slot is either taken or out of range. Try again.\n";
                    continue;
                }

                if (checkWin()) {
                    drawBoard();
                    std::cout << "Congratulations! Player " << currentMarker << " wins!\n";
                    gameOver = true;
                } else if (checkDraw()) {
                    drawBoard();
                    std::cout << "It's a draw!\n";
                    gameOver = true;
                } else {
                    swapPlayer();
                }
            }

            std::cout << "Do you want to play again? (y/n): ";
            std::cin >> replayChoice;

        } while (replayChoice == 'y' || replayChoice == 'Y');

        std::cout << "Thanks for playing!\n";
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
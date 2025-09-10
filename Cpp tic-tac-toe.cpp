#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    char currentPlayer;
    bool gameOver;
    int moves;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 'X';
        gameOver = false;
        moves = 0;
    }

    void displayBoard() {
        cout << "\n   |   |   " << endl;
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
            if (i < 2) {
                cout << "___|___|___" << endl;
                cout << "   |   |   " << endl;
            }
        }
        cout << "   |   |   " << endl << endl;
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3) {
            cout << "Invalid position! Please choose between 1-3 for row and column." << endl;
            return false;
        }
        
        if (board[row][col] != ' ') {
            cout << "Position already occupied! Choose another spot." << endl;
            return false;
        }

        board[row][col] = currentPlayer;
        moves++;
        return true;
    }

    bool checkWin() {
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++) {
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }

        // Check diagonals
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }

        return false;
    }

    bool checkDraw() {
        return moves == 9;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        cout << "=== TIC TAC TOE ===" << endl;
        cout << "Player 1: X" << endl;
        cout << "Player 2: O" << endl;
        cout << "Enter row and column numbers (1-3) separated by space" << endl;

        while (!gameOver) {
            displayBoard();
            cout << "Player " << currentPlayer << "'s turn" << endl;

            int row, col;
            cout << "Enter row and column (1-3): ";
            
            // Input validation
            while (!(cin >> row >> col)) {
                cout << "Invalid input! Please enter numbers only." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter row and column (1-3): ";
            }

            // Convert to 0-based indexing
            row--;
            col--;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins! 🎉" << endl;
                    gameOver = true;
                } else if (checkDraw()) {
                    displayBoard();
                    cout << "It's a draw! 🤝" << endl;
                    gameOver = true;
                } else {
                    switchPlayer();
                }
            }
        }
    }

    void resetGame() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';
        gameOver = false;
        moves = 0;
    }
};

int main() {
    char playAgain;
    
    do {
        TicTacToe game;
        game.playGame();
        
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
        
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;
    
    return 0;
}

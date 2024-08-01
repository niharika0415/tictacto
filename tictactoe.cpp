#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Function to check if a player has won
bool hasWon(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

int main() {
    // Initialize game board and current player
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int moveCount;

    cout << "Welcome to Tic-Tac-Toe!\n";

    // Game loop
    for (moveCount = 0; moveCount < 9; moveCount++) {
        // Display the current board state
        displayBoard(board);

        // Prompt the player for their move until a valid one is made
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Please try again.\n";
            } else {
                break; // Valid move entered
            }
        }

        // Apply the player's move to the board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (hasWon(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break; // End the game if there is a winner
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the final board state
    displayBoard(board);

    // Check for a draw
    if (moveCount == 9 && !hasWon(board, 'X') && !hasWon(board, 'O')) {
        cout << "It's a draw!\n";
    }

    return 0;
}

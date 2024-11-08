#include <iostream>
using namespace std;


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


bool hasWon(char board[3][3], char player) {
    
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

int main() {
    
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    int row, col;
    int moveCount;

    cout << "Welcome to Tic-Tac-Toe!\n";

    
    for (moveCount = 0; moveCount < 9; moveCount++) {
        
        displayBoard(board);

        
        while (true) {
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Please try again.\n";
            } else {
                break; 
            }
        }

     
        board[row][col] = currentPlayer;

     
        if (hasWon(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break; 
        }

      
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

  
    displayBoard(board);

   
    if (moveCount == 9 && !hasWon(board, 'X') && !hasWon(board, 'O')) {
        cout << "It's a draw!\n";
    }

    return 0;
}

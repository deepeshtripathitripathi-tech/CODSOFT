#include <iostream>
using namespace std;

const int SIZE = 3;

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
            if (j < SIZE - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if (i < SIZE - 1) {
            cout << "---------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char currentPlayer = 'X';
    int move;

    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << "'s turn. Enter your move (1-9): ";
        cin >> move;

        // Validate move
        if (move < 1 || move > 9) {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        // Update board
        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Position already occupied. Please try again." << endl;
            continue;
        }
        board[row][col] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    }

    return 0;
}
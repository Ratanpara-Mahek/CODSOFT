#include <iostream>
using namespace std;

const int GRID_SIZE = 3;
char gameBoard[GRID_SIZE][GRID_SIZE];
char activePlayer = 'X';

void resetBoard() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            gameBoard[i][j] = ' ';
        }
    }
}

void printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << i << " ";
        for (int j = 0; j < GRID_SIZE; ++j) {
            cout << gameBoard[i][j];
            if (j < GRID_SIZE - 1) cout << "|";
        }
        cout << endl;
        if (i < GRID_SIZE - 1) cout << "  -----\n";
    }
}

bool isValidMove(int row, int col) {
    return row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE && gameBoard[row][col] == ' ';
}

void placeMove(int row, int col) {
    if (isValidMove(row, col)) {
        gameBoard[row][col] = activePlayer;
        activePlayer = (activePlayer == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move. Try again.\n";
    }
}

bool hasWon() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        if (gameBoard[i][0] != ' ' && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]) return true;
        if (gameBoard[0][i] != ' ' && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]) return true;
    }
    if (gameBoard[0][0] != ' ' && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]) return true;
    if (gameBoard[0][2] != ' ' && gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]) return true;
    return false;
}

bool isDraw() {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (gameBoard[i][j] == ' ') return false;
        }
    }
    return true;
}

void togglePlayer() {
    activePlayer = (activePlayer == 'X') ? 'O' : 'X';
}

int main() {
    bool playMore = true;
    while (playMore) {
        resetBoard();
        activePlayer = 'X';
        bool gameWon = false;
        bool gameDrawn = false;
        
        while (!gameWon && !gameDrawn) {
            printBoard();
            cout << "Current player: " << activePlayer << endl;
            int row, col;
            cout << "Player " << activePlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            placeMove(row, col);
            gameWon = hasWon();
            gameDrawn = isDraw();
        }
        
        printBoard();
        if (gameWon) {
            togglePlayer(); // Switch back to the winner
            cout << "Player " << activePlayer << " wins!" << endl;
        } else if (gameDrawn) {
            cout << "The game is a draw!" << endl;
        }
        
        char answer;
        cout << "Do you want to play again? (y/n): ";
        cin >> answer;
        playMore = (answer == 'y' || answer == 'Y');
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}

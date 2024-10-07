#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << " ---|---|---" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    currentMarker = 'X';
    currentPlayer = 1;
    int playerWon = 0;
    int slot;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        cout << "It's player " << currentPlayer << "'s turn. Enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9 || !placeMarker(slot)) {
            cout << "Invalid move, try again.\n";
            i--;
            continue;
        }

        drawBoard();
        playerWon = winner();

        if (playerWon == 1) {
            cout << "Player 1 wins! Congratulations!\n";
            break;
        } else if (playerWon == 2) {
            cout << "Player 2 wins! Congratulations!\n";
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        cout << "It's a tie!\n";
    }

    return 0;
}
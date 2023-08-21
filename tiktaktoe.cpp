#include <iostream>
#include <conio.h>

using namespace std;


void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}


bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}


bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3];  
    char currentPlayer = 'X';  
    bool gameWon = false;
    bool gameDraw = false;
    int playerXScore = 0;  
    int playerOScore = 0;  

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    

    while (!gameWon && !gameDraw) {
        system("cls");  
       // cout << "TIC-TAC-TOE GAME" << endl;
        displayBoard(board);
        cout << "Current Player: " << currentPlayer << endl;
        cout << "Enter row (0-2): ";
        int row;
        cin >> row;
        cout << "Enter column (0-2): ";
        int col;
        cin >> col;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);
            if (!gameWon) {
                gameDraw = checkDraw(board);
                if (!gameDraw) {
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  
                }
            }
        }
    }

    system("cls");
    displayBoard(board);

    if (gameWon) {
        cout << "Player " << currentPlayer << " wins!" << endl;
        if (currentPlayer == 'X') {
            playerXScore++;  
        } else {
            playerOScore++;  
        }
    } else {
        cout << "It's a draw!" << endl;
    }

    cout << "Scoreboard:" << endl;
    cout << "Player X: " << playerXScore << " | Player O: " << playerOScore << endl;

    cout << "Do you want to play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();  
    }

    return 0;
}

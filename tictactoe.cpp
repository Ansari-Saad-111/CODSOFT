#include <iostream>
#include <vector>
using namespace std;

void dispboard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

bool chwin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    
    return false;
}

bool chdraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentP = 'X';
    bool gamefinished = false;
    
    do {
        system("clear"); // Clear the console (for Linux/macOS)
        dispboard(board);
        
        int row, col;
        cout << "Player " << currentP << ", enter your move (row and column): ";
        cin >> row >> col;
        
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentP;
            
            if (chwin(board, currentP)) {
                system("clear");
                dispboard(board);
                cout << "Player " << currentP << " wins!!" << endl;
                gamefinished = true;
            } else if (chdraw(board)) {
                system("clear");
                dispboard(board);
                cout << "It's a draw!!" << endl;
                gamefinished = true;
            } else {
                currentP = (currentP == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    } while (!gamefinished);
    
    char playagain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playagain;
    
    if (playagain == 'y' || playagain == 'Y') {
        main(); 
    }
    
    return 0;
}

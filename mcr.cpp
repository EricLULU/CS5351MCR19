/*
1. Doesn't show who the winners are
2. Doesn't handle invalid inputs
3. Doesn't handle occupied cells
4. Doesn't initialise all elements in the array game
*/

#include <iostream>
using namespace std;

char isWin(char game[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && (game[i][0] == 'X' || game[i][0] == 'O')) {
            return game[i][0]; // return winner ('X' or 'O')
        }
    }
    
    // 检查列
    for (int j = 0; j < 3; j++) {
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && (game[0][j] == 'X' || game[0][j] == 'O')) {
            return game[0][j]; 
        }
    }
    
    // 检查对角线
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) {
        return game[0][0]; 
    }
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) {
        return game[0][2]; 
    }
    
    return ' '; // tie
}

// Tic-tac-toe
int main() {
    char game[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char player1 = 'X';
    char player2 = 'O';
    bool turn = false; 
    cout << "X = Player 1" << endl << "O = Player 2" << endl;

    for (int n = 0; n < 9; n++) {
        bool validInput = false;
        while (!validInput) {
            cout << (turn ? "Player 2: " : "Player 1: ");
            cout << "Which cell to mark? i:[0..2], j:[0..2]: ";
            int i, j;
            cin >> i >> j;

            // Check if input is valid
            if (cin.fail() || (i < 0 || i > 2) || (j < 0 || j > 2)) {
                cout << "Invalid input. Please enter values between 0 and 2." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the input buffer
            } else if (game[i][j] == 'X' || game[i][j] == 'O') {
                cout << "Cell already marked. Please choose another cell." << endl;
            } else {
                validInput = true;
                game[i][j] = turn ? 'O' : 'X';  
            }
        }
 
        if (isWin(game)!=' ') {
            string winner;
            if(isWin(game)=='X') winner = "Player 1";
			else winner = "Player 2";
            cout << winner << " " << "Win!" << endl;
            break; // need to terminate the problem
        }
        turn = !turn;
    }
    
    if (isWin(game)==' ') // all cells have been inputted above but no winner yet
        cout << "Tie!" << endl;

    // show the game to console
    cout << game[0][0] << " " << game[0][1] << " " << game[0][2] << endl;
    cout << game[1][0] << " " << game[1][1] << " " << game[1][2] << endl;
    cout << game[2][0] << " " << game[2][1] << " " << game[2][2] << endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV
// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos);
void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;

    initBoard(board, xPos, yPos);

    while(hasChar(board, GOAL))
    {
        char action;
        clearScreen();
        showGrid(board);
        cout << "Where would you like to go? (l, r, u, d) " << endl;
        cin >> action;

        updateGrid(board, xPos, yPos, action);
    }

    clearScreen();
    showGrid(board);
    cout << "You found the cookie!  Congratulations!\n";

    return 0;
}

void initBoard(char board[lengthX][lengthY], int &xPos, int &yPos) {
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {
                board[curCol][curRow] = BLANK;
            }
        }

        board[0][0] = GOAL;
        board[lengthX/2][lengthY/2] = ROBOT;

        xPos = lengthX/2;
        yPos = lengthY/2;
}

bool hasChar(char board[lengthX][lengthY], char findMe) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            if(board[curCol][curRow] == findMe) {
                return true;
            }
        } //end curCol loop
    } // end curRow loop

    return false;
}

void clearScreen() {
    for(int i = 0;i<screen_num_lines;i++) {
        cout << endl;
    }
}

void showGrid(char board[lengthX][lengthY]) {
    for(int curRow=0; curRow < lengthY; curRow++) {
        for(int curCol=0; curCol < lengthX; curCol++) {
            cout << board[curCol][curRow];
        } // end curCol loop
        cout << endl;
    } // end curRow loop
}

void updateGrid(char board[lengthX][lengthY],int & xPos, int & yPos,char action) {
    board[xPos][yPos] = BLANK;
    if       (action == 'l' && xPos > 0) {
            xPos--;
    } else if(action == 'r' && xPos < lengthX - 1) {
            xPos++;
    } else if(action == 'u' && yPos > 0) {
            yPos--;
    } else if(action == 'd' && yPos < lengthY - 1) {
            yPos++;
    }
    board[xPos][yPos] = ROBOT;
}

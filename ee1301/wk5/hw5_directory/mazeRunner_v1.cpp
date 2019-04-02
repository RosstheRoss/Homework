#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
ifstream fin;
ofstream fout;

const char BLANK = '-';
const char ROBOT = 'X';
const char GOAL = 'O';
const char WALL = 'W';
const int screen_num_lines = 25;
const int lengthX = 10;       // for now we only support square boards
const int lengthY = 10;       // it "should" work with non-square, YMMV
// Board is described by the following coordinate system:
// 0 --> +X
// |
// |
// V
// +Y

void initBoardDefault(char board[lengthX][lengthY], int &xPos, int &yPos);
void initBoardCustom(char board[lengthX][lengthY], int &xPos, int &yPos);
void clearScreen();
void showGrid(char board[lengthX][lengthY]);

bool hasChar(char board[lengthX][lengthY], char findMe);
void updateGrid(char board[lengthX][lengthY], int &xPos, int &yPos, char action);

int main()
{
    srand(time(NULL));
    char board[lengthX][lengthY] = {0};
    int xPos = 0, yPos = 0;
    fin.open("maze.txt"); //maze.txt is in the directory that it is run in
    if (!fin.is_open()) //If a custom maze does not exist, generate one automatically
    {
        initBoardDefault(board, xPos, yPos);
    } else {
        initBoardCustom(board, xPos, yPos);
    }
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

//The default (no custom file) maze is procedurally generated
void initBoardDefault(char board[lengthX][lengthY], int &xPos, int &yPos) {
        for(int curRow=0; curRow < lengthY; curRow++) {
            for(int curCol=0; curCol < lengthX; curCol++) {
                if ( (rand() % 5) + 1 == 4 || (rand() % 10) + 1 == 7) { 
                    board[curCol][curRow] = WALL;
                        } else {
                        board[curCol][curRow] = BLANK;
                        }
            }
        }
        

        board[0][0] = GOAL;
        board[lengthX/2][lengthY/2] = ROBOT;

        xPos = lengthX/2;
        yPos = lengthY/2;
}

void initBoardCustom(char board[lengthX][lengthY], int &xPos, int &yPos)
{
    for (int curRow = 0; curRow < lengthY; curRow++)
    {
        for (int curCol = 0; curCol < lengthX; curCol++)
        {
            fin >> board[curCol][curRow];
            if (board[curCol][curRow] == 'X') {
                board[curCol][curRow] = ROBOT;
                xPos = curCol;
                yPos = curRow;
            }
        }
    }

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
    int oldX = xPos; int oldY = yPos;
    if       (action == 'l' && xPos > 0) {
            xPos--;
    } else if(action == 'r' && xPos < lengthX - 1) {
            xPos++;
    } else if(action == 'u' && yPos > 0) {
            yPos--;
    } else if(action == 'd' && yPos < lengthY - 1) {
            yPos++;
    }
    //Hit detection
    if (board[xPos][yPos] == WALL) {  
        xPos = oldX;
        yPos = oldY;
        board[xPos][yPos] = WALL;
    } else {
        board[oldX][oldY] = BLANK;
    }
    board[xPos][yPos] = ROBOT;
}

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define SIZE 100
int maxRow = 0, maxColumn = 0;
void getInput(int input[SIZE][SIZE]);
int main() {
  int column = 0, row = 0;
  /*
    Array is set up as follows
        C
      R 0 1 ...
        1
        ...
  */
  int inputArray[SIZE][SIZE] = {0};
  getInput(inputArray);
  
}

void getInput(int input[SIZE][SIZE]) {
  string test;
  while (getline(cin,test)) {
    istringstream ss(test);
    string temp;
    while(getline(ss,temp,' '))
      maxRow=0;
      {
        input[maxRow][maxColumn] = stoi(temp);
        maxRow++;
      }
    maxColumn++;
  }
  cout << maxRow << " " << maxColumn << endl;
}
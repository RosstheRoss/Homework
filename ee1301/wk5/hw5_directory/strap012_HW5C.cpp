#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
ifstream fin;

#define SIZE 100
int maxRow = 0, maxColumn = 0;
void getInput(int input[SIZE][SIZE]);
void makeNewArray(int oldArray[SIZE][SIZE], int newArray[SIZE][SIZE]);
void pixelAverage(int array[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);

int main() {
  fin.open("testData.txt");
  int column = 0, row = 0;
  int inputArray[SIZE][SIZE] = {0};
  getInput(inputArray);
  int outputArray[SIZE][SIZE] = {0};
  makeNewArray(inputArray, outputArray);
  pixelAverage(outputArray);
  printArray(outputArray);
}

void getInput(int input[SIZE][SIZE]) {
  string test, temp1; int temp2=0;
  //I would mainly like to thank some random person on StackOverflow for solving my problem
  while (getline(fin,test)) {
    temp2 = 0;
    istringstream ss(test);
    while(getline(ss,temp1,' ')) {
      temp2++;
      input[maxRow][temp2] = stoi(temp1);
      }
      if (temp2>maxColumn) {
          maxColumn = temp2+2; //2 is added to make the math work.
      }
    maxRow++;
  }
  maxRow++;
}

void makeNewArray(int oldArray[SIZE][SIZE], int newArray[SIZE][SIZE]) {
  for (int i = 0; i < SIZE-1; i++) {
    for (int j = 2; j < SIZE-1; j++) {
      newArray[i][j] = oldArray[i-1][j-1];
    }
  }
}

void pixelAverage(int array[SIZE][SIZE]) {
  for (int i = 0; i < maxRow; i++) {
    for (int j = 0; j < maxColumn; j++) {

    }
  }
}

void printArray (int array[SIZE][SIZE]) {
  //It is unknown why these for loops do not start at 0.
  //Since they work for all 2D arrays with size<100, no negative effects are known.
    for (int j = 1; j < maxRow; j++)
    {
      for (int i = 2; i < maxColumn; i++)
      {
        cout << array[j][i] << " ";
      }
      cout << endl;
    }
}
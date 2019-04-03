#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
ifstream fin;

#define SIZE 100
int maxRow = -1, maxColumn = 0;
void getInput(int input[SIZE][SIZE]);
void makeNewArray(int oldArray[SIZE][SIZE], int newArray[SIZE][SIZE]);
void pixelAverage(int inArray[SIZE][SIZE], int outArray[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);

int main() {
  fin.open("testData.txt");
  int inputArray[SIZE][SIZE] = {0},
      outputArray[SIZE][SIZE] = {0};
  getInput(inputArray);
  makeNewArray(inputArray, outputArray);
  pixelAverage(inputArray, outputArray);
  printArray(outputArray);
}

void getInput(int input[SIZE][SIZE]) {
  string test, temp1; int temp2=0;
  //I would mainly like to thank some random person on StackOverflow for solving my problem
  while (getline(cin,test)) {
    temp2 = -2;
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
    for (int j = 0; j < SIZE-1; j++) {
      newArray[i][j] = oldArray[i-1][j-1];
    }
  }
}

void pixelAverage(int inArray[SIZE][SIZE], int outArray[SIZE][SIZE]) {
  int sum = 0, n = 0, average, timesRan=0; //n is the number of surrounding pixels
  for (int i = -1; i < maxRow-1; i++) {
    for (int j = -1; j < maxColumn-1; j++) {
      sum=0; n=0;
      if ( !((i-1)<1) ) {
        cout << "LEFT)" << inArray[i-1][j] << " ";
        sum += inArray[i-1][j];
        n++;
      }
      if ( (i+1)<maxRow ) {
        cout << "DOWN)" << inArray[i+1][j] << " ";
        sum += inArray[i+1][j];
        n++;
      }
      if ( !((j-1)<1) ) {
        cout << "UP)" << inArray[i][j-1] << " ";
        sum += inArray[i][j-1];
        n++;
      }
      if ( (j+1)<maxColumn ) {
        cout << "RIGHT)" << inArray[i][j+1] << " ";
        sum += inArray[i][j+1];
        n++;
      }
      if ( !((i-1)<0) && !((j-1)<0) ) {
        cout << "UPLEFT)" << inArray[i-1][j-1] << " ";
        sum += inArray[i-1][j-1];
        n++;
      }
      if ( !((i-1)<0) && ( (j+1)<maxColumn ) ) {
        cout << "DOWNLEFT)" << inArray[i-1][j+1] << " ";
        sum += inArray[i-1][j+1];
        n++;
      }
      if ( (i+1)<maxRow && (j+1)<maxColumn ) {
        cout << "DOWNRIGHT)" << inArray[i+1][j+1] << " ";
        sum += inArray[i+1][j+1];
        n++;
      }
      if ( !((j-1)<0)  && (i+1)<maxRow) {
        cout << "UPRIGHT)" << inArray[i+1][j-1] << " ";
        sum+=inArray[i+1][j-1];
        n++;
      }
      cout << inArray[i][j] << " ";
      sum+=inArray[i][j];
      n++;
      timesRan++;
      average = sum/n;
      cout << endl << sum << " " << n << " " << average << endl;
      outArray[i+1][j+1]=average;
    }
  }
  cout << timesRan << endl;
}

void printArray (int array[SIZE][SIZE]) {
    for (int i = 0; i < maxRow; i++)
    {
      for (int j = 0; j < maxColumn; j++)
      {
        cout << array[i][j] << " ";
      }
      cout << endl;
    }
}
/*
Date: April 4 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE 1301
Term: Spring 2019
Lab/assignment number: HW 5C
Short Program Description: Pixel Averaging
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#define SIZE 100
int maxRow = -1, maxColumn = 0;
void getInput(int input[SIZE][SIZE]);
void makeNewArray(int oldArray[SIZE][SIZE], int newArray[SIZE][SIZE]);
void pixelAverage(int inArray[SIZE][SIZE], int outArray[SIZE][SIZE]);
void printArray(int array[SIZE][SIZE]);

int main() {
  int inputArray[SIZE][SIZE] = {0},
      outputArray[SIZE][SIZE] = {0};
  getInput(inputArray);
  makeNewArray(inputArray, outputArray);
  pixelAverage(inputArray, outputArray);
  printArray(outputArray);
}

// Function: getInput
//  ---------------------------
// Takes the stream of stdin, puts that into a stringsream and puts that stringsteam into an integer array
// input: an empty array of SIZE, as defined in line 15.
void getInput(int input[SIZE][SIZE]) {
  string test, temp1; int temp2=0;
  //I would mainly like to thank whatever user on StackOverflow solved my problem
  while (getline(cin,test,'\n')) {
    temp2 = -1;
    istringstream ss(test);
    while(getline(ss,temp1,' ')) {
      temp2++;
      input[maxRow][temp2] = stoi(temp1);
      }
      if (temp2>maxColumn) {
          maxColumn = temp2+1; //1 is added to make the math work.
      }
    maxRow++;
  }
  maxRow++;
}

// Function: makeNewArray
//  ---------------------------
// Takes the array made in getInput and puts that same array into a new array to manipulate
// oldArray: Array generated in getInput of SIZE
// newArray: Array of same dimensions and data
void makeNewArray(int oldArray[SIZE][SIZE], int newArray[SIZE][SIZE]) {
  for (int row = 0; row < maxRow; row++) {
    for (int column = 0; column < maxColumn; column++) {
      newArray[row][column] = oldArray[row][column];
    }
  }
}

// Function: pixelAverage
//  ---------------------------
// The meat of the program, taking the surrounding values, adding them, and divides by the number of surrounding values
// inArray: Generated in getInput
// outArray: Generated in makeNewArray
void pixelAverage(int inArray[SIZE][SIZE], int outArray[SIZE][SIZE]) {
  int sum = 0, n = 0, average; //n is the number of surrounding pixels
  for (int row = -1; row < maxRow-1; row++) {
    for (int column = -1; column < maxColumn-1; column++) {
      sum=0; n=0; //Sum and n are reset every loop
      if ( !((row)<0) ) { //True when array is in lower bounds row-wise
        sum += inArray[row-1][column];
        n++;
      }
      if ( (row+1)<maxRow-1 ) { //True when array is in upper bounds row-wise
        sum += inArray[row+1][column];
        n++;
      }
      if ( !((column)<0) ) { //True when array is in lower bounds column-wise
        sum += inArray[row][column-1];
        n++;
      }
      if ( (column+1)<maxColumn-1 ) {//True when array is in upper bounds column-wise
        sum += inArray[row][column+1];
        n++;
      }
      //All of these if statements are combinations are previous statements for the diagonal aspects
      if ( !((row)<0) && !((column)<0) ) {
        sum += inArray[row-1][column-1];
        n++;
      }
      if ( !((row)<0) && ( (column+1)<maxColumn-1 ) ) {
        sum += inArray[row-1][column+1];
        n++;
      }
      if ( (row+1)<maxRow-1 && (column+1)<maxColumn-1 ) {
        sum += inArray[row+1][column+1];
        n++;
      }
      if ( (!((column)<0)  && (row+1)<maxRow-1) ) {
        sum+=inArray[row+1][column-1];
        n++;
      }
      sum+=inArray[row][column];
      n++;
      average = sum/n;
      outArray[row+1][column+1]=average;
    }
  }
}

// Function: printArray
//  ---------------------------
// Prints the new array after the pixel averaging
// array: Array generated in pixelAverage
void printArray (int array[SIZE][SIZE]) {
    for (int row = 0; row < maxRow; row++)
    {
      for (int column = 0; column < maxColumn; column++)
      {
        cout << array[row][column] << " ";
      }
      cout << endl;
    }
}

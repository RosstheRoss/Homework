/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2A
Short Program Description: Useless Counter
*/

#include <iostream>
using namespace std;
int main () {
  int countOG= 0, i=0, j=0;
  
do {
  do {
  cout << "Enter an integer from -50 to 50: ";
  cin >> countOG;
  } while (countOG > 50 || countOG < -50);
  int count=countOG; //Store original integer for comparison to break loop
  
  if (countOG < 0){
   count*=-1;
   for (i=count; i>0; i--) {
    for (j=count; j>0; j--) {
      cout << count;
    }
    count--;
    cout << endl;
   }
  }

  if (countOG > 0) {
    count=1;   //Sets initial printing of countOG to 1
    for (i=1; i<=countOG; i++) {
      for (j=0; j<count; j++) {
        cout << i;
      }
      count++;
      cout << endl;
    }
  }
} while (countOG != 0);
  cout << "Goodbye." << endl;
  return 0;
}
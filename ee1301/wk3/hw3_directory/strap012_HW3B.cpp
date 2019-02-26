/*
27 Feb 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 3B
Character Detection
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main () {
    int test;
    char character;
    bool isAlphaNumeric=true;
    while (isAlphaNumeric) {
      cout << "Enter a single digit or an alphabetic character: ";
      cin >> character;
      cout << "You entered " << character << ", ";
      test = charTest(character);
      if (test==0) {
        isAlphaNumeric=false;
        cout << "which is not a letter or a number.";
      }
      if (test==1) {
        cout << "which is a number.";
      }
      if (test==2) {
        cout << "which is a lower case letter.";
      }
      if (test==3) {
        cout << "which is an upper case letter.";
      }
      cout << endl;
    }
}


// Function: charTest
//  ---------------------------
// Tests to see what kind of character was inputted
// character: Self-explanatory
// returns: 1 if number, 2 if lower case, 3 if upper case, 0 if not any of the previous

int charTest (char character) {
  if (character >= '0' && character <= '9')
    {
      return 1;
    } else {
        if (character>='a' && character<='z') {
            return 2;
        } else {
            if (character>= 'A' && character<='Z') {
                return 3;
            } else {
                return 0;
            }
        }
    }
}
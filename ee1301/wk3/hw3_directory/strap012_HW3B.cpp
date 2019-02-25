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
    char character;
    bool isNotAlphaNumeric=false;
    while (!isNotAlphaNumeric) {
    cout << "Enter a single digit or an alphabetic character: ";
    cin >> character;
    cout << "You entered " << character;
    if (character >= '0' && character <= '9')
    {
        cout <<  ", which is a number." << endl;
    } else {
        if (character>='a' && character<='z') {
            cout << ", which is a lower case letter." << endl;
        } else {
            if (character>= 'A' && character<='Z') {
                cout << ", which is an upper case letter." << endl;
            } else {
                isNotAlphaNumeric=true;
                cout << ", which is not a letter or a number." << endl;
            }
        }
        }
    }
}

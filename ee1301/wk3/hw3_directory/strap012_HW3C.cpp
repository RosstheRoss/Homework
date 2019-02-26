/*
27 Feb 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 3C
Character Detection
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    char character;
    do { //This loops until '@' is entered
        cout << "Please enter a character that is an ASCII letter in the range [A-Za-z]: ";
        cin >> character;
        if (character!='@') {
            swapCase(character);
        }
    } while (character!='@');
}

// Function: swapCase
//  ---------------------------
// Swaps the case of a latin ASCII character and prints an error if not one
// s: the character inputted

void swapCase(char s) {
    char New;
    cout << "You entered " << s;
    if (s >= 'a' && s <= 'z') {
        New= s - 32;
        cout << ", I respond with " << New;
    } else {
        if (s >= 'A' && s <= 'Z') {
            New = s + 32;
            cout << ", I respond with " << New;
        } else {
            cout << ", which is not a valid character";
        }
    }
    cout << "." << endl;
}
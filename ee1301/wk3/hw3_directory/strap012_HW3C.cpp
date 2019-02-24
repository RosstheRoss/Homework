#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;
char swapCase(char s) {
    char New;
    cout << "You entered " << s;
    if (s >= 'a' && s <= 'z')
    {
        New= s - 32;
        cout << ", I respond with " << New;
    }
    else
    {
        if (s >= 'A' && s <= 'Z')
        {
            New = s + 32;
            cout << ", I respond with " << New;
        }
        else
        {
            cout << ", which is not a valid character";
        }
    }
    cout << "." << endl;
}

int main()
{
    char character;
    do {
        cout << "Please enter a character that is an ASCII letter in the range [A-Za-z]: ";
        cin >> character;
        if (character!='@') {
            swapCase(character);
        }
    } while (character!='@');
}
/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2C
Short Program Description: One-armed Bandit
*/

#include <iostream>
#include <time.h>

using namespace std;
int main () {
    srand (time(NULL)); //This seeds the randomness based on the current time
    bool win=false;
    int d=0, spin1, spin2, spin3, spin4;
  do {
      do {
        win=false;      //Reset win from before, otherwise win will always be true after it is true once
        cout << "How many values do you want on each wheel? ";
        cin >> d;
      } while (d==0);   //Without this failsafe, the program does undefined things at d=0, usually crashing
      
        spin1= rand () % d + 1;
        spin2= rand () % d + 1;
        spin3= rand () % d + 1;
        spin4= rand () % d + 1;
        cout << "The wheels spin to give:  " << spin1 << " " << spin2 << " " << spin3 << " " << spin4 << "  ";
        if (spin1==spin2) { // These nested statements only let the bool "win" be true if all of the spinners match
            if (spin2==spin3) {
                if (spin3==spin4) {
                    win=true;
                }
            }
        }
        if (win) {
            cout << "Eureka!";
        }
        else {
            cout << "You lose.";
            
        }
    cout << endl;
  } while (d!=-1);
  cout << "OK, goodbye." << endl;
  return 0;
}
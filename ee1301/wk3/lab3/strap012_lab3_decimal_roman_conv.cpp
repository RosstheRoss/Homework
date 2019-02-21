//Matthew Strapp
//5449340
//20 February 2018
//Lab 3 Workout

#include <iostream>
using namespace std;
int main () {
  int decimal;
  cout << "Enter an integer value from 1 to 999: ";
  cin >> decimal;
  if (decimal<1 || decimal>999) {
    cout << "       Invalid Input.    Program terminated." << endl;
    return 1453;
  } else {
      cout << "Roman numeral equivalent: ";
  while (decimal!=0) {
      if (decimal>900 && decimal<1000) {
        cout << "CM"; decimal-=900;
        }
      if (decimal>=500 && decimal<900) {
        cout << "D"; decimal-=500;
        }
      if (decimal>=400 && decimal<500) {
        cout << "CD"; decimal-=400;
        }
      if (decimal>=100 && decimal<400) {
        cout << "C"; decimal-=100;
        }
      if (decimal>=90 && decimal<100) {
        cout << "XC"; decimal-=90;
        }
      if (decimal>=50 && decimal<90) {
        cout << "L"; decimal-=50;
        }
      if (decimal>=40 && decimal<50) {
        cout << "XL"; decimal-=40;
        }
      if (decimal>=10 && decimal<40) {
        cout << "X"; decimal-=10;
        }
      if (decimal==9) {
        cout << "IX"; decimal-=9;
        }
      if (decimal>=5 && decimal<9) {
        cout << "V"; decimal-=5;
        }
      if (decimal==4) {
        cout << "IV"; decimal-=4;
        }
      if (decimal>=1 && decimal<4) {
        cout << "I"; decimal-= 1;
        }
      }
    }
  cout << endl;
  return 0;
}

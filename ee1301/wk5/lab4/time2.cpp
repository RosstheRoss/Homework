#include <iostream>
#include <string>

using namespace std;

void minutesToTime(int minute_value, int& hours, int& mins);
int main() {
  int hours, mins;
  char cont = 'y';
  do {
    cout << "Enter a number of minutes: ";
    cin >> mins;
    minutesToTime(mins, hours, mins);
    cout << hours << ":";
    if (mins<10) {
      cout << '0' << mins << endl;
    } else {
      cout << mins << endl;
    }
    do {
      cout << "Continue? (y/n):";
      cin >> cont;
    } while ( !( !(cont!='n') != !(cont!='y') ) );
    //The last logic is a XNOR gate of magic, touching will disturb the magic
  } while ((cont=='y'));
}

void minutesToTime(int minute_value, int& hours, int& mins) {
  mins=minute_value%60;
  hours=0;
  for (int i=minute_value/60; i>0; i--) {
    hours++;
    if (hours>12)
      hours=1;
  }
}

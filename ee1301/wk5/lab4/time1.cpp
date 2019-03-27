#include <iostream>
#include <string>

using namespace std;

int timeToMinutes(int hours, int mins);
int main() {
  int hours, minutes;
  char colon, cont = 'y';
  do {
    cout << "Enter a time duration (hh:mm) ";
    cin >> hours >> colon >> minutes;
    cout << "Total minutes: " << timeToMinutes(hours, minutes) << endl;
    do {
      cout << "Continue? (y/n):";
      cin >> cont;
    } while ( !( !(cont!='n') != !(cont!='y') ) );
    //The last logic is a XNOR gate of magic, please do not touch
  } while ((cont=='y'));
}

int timeToMinutes(int hours, int mins) {
  return mins + hours * 60;
}

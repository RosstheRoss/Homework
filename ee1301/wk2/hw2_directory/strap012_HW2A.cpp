/*
20 Feb 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 2A
Useless Counter
*/

#include <iostream>
using namespace std;
int main () {
  int countOG, i, j;
  
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
    for (count=1; count<=countOG; count++) {
      for (i=0; i<count; i++) {
        cout << count;
      }
      cout << endl;
    }
  }
  
} while (countOG != 0);

  cout << "Goodbye." << endl;
  return 0;
}
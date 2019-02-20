#include <iostream>
#include <cmath>
using namespace std;

double gennewGuess(double n, double old_guess) {
  bool WA=true;
  double real, old;
  //if (WA) {
    real=sqrt(n);
    WA=false;
  //}
  double new_guess = ( old_guess + n / old_guess ) / 2;
  old=new_guess;
  if (((new_guess-real)/real)>0.01) {
    cout << old << endl;
    return gennewGuess(n, old);
  } else {
    cout << old << endl;
    return new_guess;
  }
}
int main () {
  double temp, temp2;
  cout << "Enter the Number to find square root: ";
  cin >> temp;
  if (temp<=0) {
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return -1;
  }
  cout << "Guessing..." << endl;
  double real=sqrt(temp);
  temp2=temp;
  temp = gennewGuess(temp, 1.0);
  cout << "The Final Guess: " << temp << endl
   << "Actual Value: " << real << endl;
}

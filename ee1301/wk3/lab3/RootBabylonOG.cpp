#include <iostream>
#include <cmath>
using namespace std;

double gennewGuess(double n, double old_guess) {
  double real, old;
  real=sqrt(n);
  double new_guess = ( old_guess + n / old_guess ) / 2;
  old=new_guess;
  if (((new_guess-real)/real)>0.01) { //This will be true if the difference between the real root and guess is more than 1%.
    cout << old << endl;
    return gennewGuess(n, old);
  } else {
    cout << old << endl;
    return new_guess;
  }
}
int main () {
  double temp;
  cout << "Enter the Number to find square root: ";
  cin >> temp;
  if (temp<=0) {
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return sqrt(-1);
  }
  cout << "Guessing..." << endl;
  double real=sqrt(temp);
  temp = gennewGuess(temp, 1.0);
  cout << "The Final Guess: " << temp << endl
   << "Actual Value: " << real << endl;
}

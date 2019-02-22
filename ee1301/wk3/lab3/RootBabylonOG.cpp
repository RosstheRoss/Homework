#include <iostream>
#include <cmath>
using namespace std;

double gennewGuess(double n, double old_guess) {
  double new_guess = ( old_guess + ( n / old_guess ) ) / 2;
  return new_guess;
  }
  
double BabylonRoot(double n) {
  double real, guess=1; //Initial guess is set to 1
  real=sqrt(n);
  do {
    guess = gennewGuess(n,guess);
    cout << guess << endl;
  } while (abs(guess-real)/real>0.01); //Keep guessing unitl within 1% of the actual square root
  return guess;
}

int main () {
  double n, guess;
  cout << "Enter the Number to find square root: ";
  cin >> n;
  if (n<=0) {
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return 2;
  }
  cout << "Guessing..." << endl;
  double real=sqrt(n);
  guess = BabylonRoot(n);
  cout << "The Final Guess: " << guess << endl
   << "Actual Value: " << real << endl;
   return 0;
}
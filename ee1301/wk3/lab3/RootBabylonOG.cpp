#include <iostream>
#include <cmath>
using namespace std;

double gennewGuess(double n, double old_guess) {
  double new_guess = (old_guess+n/old_guess)/2;
  return new_guess;
  }
  
double BabylonRoot(double n) {
  double real, guess=1; //Initial guess is set to 1
  real=sqrt(n);
  do {
    guess = gennewGuess(n,guess);
    cout << guess << endl;
  } while ((guess-real)/real>0.01);
  return guess;
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
  temp = BabylonRoot(temp);
  cout << "The Final Guess: " << temp << endl
   << "Actual Value: " << real << endl;
}

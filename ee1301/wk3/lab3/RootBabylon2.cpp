#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double gennewGuess(double n, double old_guess) {
  double real, old;
  real=sqrt(n);
  double new_guess = ( old_guess + n / old_guess ) / 2;
  old=new_guess;
  if (((new_guess-real)/real)>0.01) { //This will be true if the difference between the real root and guess is more than 1%.
  //  cout << old << endl;
    return gennewGuess(n, old);
  } else {
  //  cout << old << endl;
    return new_guess;
  }
}
int main () {
  double temp;
  char cont;
  do {
  cout << "enter a value: ";
  cin >> temp;
  int n=temp;
  if (temp<=0) {
    cout << "Please enter a valid input(Positive Integer)." << endl;
    return sqrt(-1);
  }
  //cout << "Guessing..." << endl;
  temp = gennewGuess(temp, 1.0);
  cout << fixed << setprecision(0) << "square root of " << n << " is " << temp << endl
  << "continue? (y/n): ";
  cin >> cont;
  if (cont!='n'&&cont!='y') {
    return -1;
  }
} while (cont!='n');
  // << "Actual Value: " << real << endl;
}

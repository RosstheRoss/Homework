#include <iostream>
#include <cmath>
using namespace std;

double genNewGuess(double n, double oldGuess); {
  New=(oldGuess+n/oldGuess)/2;
  oldGuess=New;
  return New;
}
int main () {
  double temp;
  cout << "Enter the Number to find square root: ";
  cin >> n;
  if (n==0) {
    cout << "Nah fam." << endl;
    return -1
  }
  cout << "Guessing..."
  double real=sqrt(n);
  do {
    
  } (while abs(New-real)/real<0.1)
}
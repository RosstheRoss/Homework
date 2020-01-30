#include <iostream>
#include <cmath>
using namespace std;

void factorFinder (unsigned long long n) {
  unsigned long long i=2;
  while (pow(i,2)<=n) {
    if (n%i==0) {
      cout << i << "*";
      n/=i;
    } else {
      i++;
    }
  }
  if (n>1) {
    cout << n << endl;
  }
}

int main () {
  unsigned long long n;
  cout << "Input a positive integer: ";
  cin >> n;
  cout << "Factors: ";
  factorFinder(n);
}

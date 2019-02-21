#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int primefinder (long long n) {
  for (long long i=n; i>1; --i) {

      if (n%i==0 && n!=i) {
        primefinder(i);
        cout << i << "*";
      }
    }
    return composite;
}
int main () {
  long long n;
  cout << "Input a positive integer:  ";
  cin >> n;
  primefinder(n);
  cout << endl;
}

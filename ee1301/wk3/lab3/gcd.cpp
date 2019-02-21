#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b) {
  int gcd=0;
  a=abs(a); b=abs(b);
  if (a>b) {
    //do nothing
  } else {
    if (b>a) {
     int foo=a; a=b; b=foo;
   } else {
      return 1;
    }
  }
  gcd=(a/b)+(a%b);
  return gcd;
}
int main () {
  int a=0, b=0;
  cout << "Enter two integers: ";
  cin >> a, b;
  cout << GCD(a,b) << endl;
}

#include <iostream>
#include <cmath>
using namespace std;

int GCD(int a, int b) {
  int gcd=1;
  a=abs(a); b=abs(b);
  if (a>b) {
    //do nothing
  } else {
    if (b>a) {
     int foo=a; a=b; b=foo;
   } else {
      return -1;
    }
  }
  gcd=(a%b);
  while (gcd!=0) {
    return GCD(b,gcd);
  }
  return b;

}
int main () {
  int a=0, b=0;
  char cont;
  do {
    cout << "enter two integer values: ";
    cin >> a >> b;
    cout << "greatest common divisor is: " << GCD(a,b) << endl;
    cout << "continue? (y/n): ";
    cin >> cont;
    cout << endl;
  } while (cont!='n');
  
}

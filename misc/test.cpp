#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main () {
  unsigned long long x;
  cout << "Enter a number:";
  cin >> x;
  unsigned long long i = (x-1);
  int a;
  for (i=x; i>1; --i) {
    if (x%i==0 && x!=i) {
      cout << "Not prime!" << endl;
      a=1;
      break;
      return 3;
    }
  }
  
  if (a!=1)
  cout << "Prime!" << endl;
  return 2;
}

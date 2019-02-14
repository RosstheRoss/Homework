#include <iostream>
using namespace std;

int main () {
  unsigned long long x,i;
  bool a;
  cout << "Enter a number:"; cin >> x;
  
  for (i=x; i>1; --i)
    {
      if (x%i==0 && x!=i) {
      cout << x << " is not prime!" << endl;
      cout << "Divisible by " << i << "." << endl << endl;
      a=1;
      break;
      }
    }
  
  if (!a){
  cout << x << " is a prime number!" << endl << endl;
  return 0;
  }
}
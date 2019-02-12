#include <iostream>
using namespace std;

int main () {
  unsigned long long x,i;
  bool a;
  cout << "Enter a number:"; cin >> x;
  
  for (i=x; i>1; --i)
    
    {
      if (x%i==0 && x!=i) {
      cout << "Not prime!" << endl;
      a=1;
      break;
      return i; }
    }
  
  if (!a)
  cout << "Prime!" << endl;
  return 0;
}

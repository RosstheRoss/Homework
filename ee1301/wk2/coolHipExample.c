#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
  int x=2,n=0;
  int og=x;
  for (int i=n; i>1; i--){
    x*=og;
  }
  
  cout << og << "^" << n << "=" << x << endl;
}
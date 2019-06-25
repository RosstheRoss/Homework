#include <iostream>
using namespace std;
int main()
{
  unsigned long long fib1=0, fib2=1, count, fib3=1;
  cout << "How many Fibonacci numbers should be computed? ";
  cin >> count;
  bool firstRun=true;
  for (int i=1; i<(count+1); i++) {
    if (!firstRun) { //The contents are run when i is not 1.
      fib3=fib1+fib2;
      fib1=fib2;
      fib2=fib3;
    }
    firstRun=false;
    cout << fib3 << " ";
    if (i%10==0 && i!=0)
      cout << endl;
  }
  cout << endl;
}

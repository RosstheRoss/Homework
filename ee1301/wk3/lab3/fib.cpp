#include <iostream>
using namespace std;
int main()
{
  unsigned long long fib1=0, fib2=1, count, temp;
  cout << "How many Fibonacci numbers should be computed? ";
  cin >> count;
  for (int i=1; i<(count+1); i++) {
    temp=fib1+fib2;
    fib1=fib2;
    fib2=temp;
    cout << temp << " ";
    if (i%10==0 && i!=0)
      cout << endl;
  }
  cout << endl;
}
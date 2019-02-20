#include <iostream>
using namespace std;

int main () {
  int sum = 0;
  for(int i=0; i<=100; i++)
  {
      if(i % 7 == 0)
          sum++;
  }
cout << sum;
}
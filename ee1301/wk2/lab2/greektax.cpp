#include <iostream>
using namespace std;
int main () {
  int income;
  int tax=0;
  cout << "Enter your income: ";
  cin >> income;
  if (income>10000) {
    int k10=income-10000;
    if (k10<=0){
    tax+=((income-10000)*.1);
  }
    else {
      tax+=2000;
    }
    if (income>30000) {
      int k30=income-10000;
      if (k30<=0){
      tax+=((income-30000)*.2);
    }
      else {
        tax+=8000;
      }
      if (income>70000) {
        tax+=((income-70000)*.3);
      }
    }
  }

  cout << "You owe " << tax << " drachmas in tax." << endl;

}

#include <iostream>
using namespace std;
int main () {
  int Income;
  int Tax=0;
  cout << "Enter your Income: ";
  cin >> Income;
  if (Income>10000) {
    int k10=Income-10000; //Income under 10000 is not taxed
    if (k10<=0){
    Tax+=((Income-10000)*.1); //Income between 10000 and 30000 is taxed at 10%
  }
    else {
      Tax+=2000;
    }
    if (Income>30000) {
      int k30=Income-10000;
      if (k30<=0){
      Tax+=((Income-30000)*.2); //Income between 30000 and 70000 is taxed at 20%
    }
      else {
        Tax+=8000;
      }
      if (Income>70000) {
        Tax+=((Income-70000)*.3); //Income over 70000 is taxed at 30%
      }
    }
  }
  cout << "You owe " << Tax << " drachmas in tax." << endl;

}

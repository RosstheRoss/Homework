#include <iostream>
using namespace std;
int main () {
  int Income;
  int Tax=0;
  cout << "Enter your Income: ";
  cin >> Income;
  if (Income>10000) {
    int k10=Income-10000;
    if (k10<=0){
    Tax+=((Income-10000)*.1);
  }
    else {
      Tax+=2000;
    }
    if (Income>30000) {
      int k30=Income-10000;
      if (k30<=0){
      Tax+=((Income-30000)*.2);
    }
      else {
        Tax+=8000;
      }
      if (Income>70000) {
        Tax+=((Income-70000)*.3);
      }
    }
  }
  cout << "You owe " << Tax << " drachmas in tax." << endl;

}

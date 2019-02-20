#include <iostream>
using namespace std;
int main() {
  int row=1, column=1;
  for (row; row<=10; row++) {
    for (column=10; column>0; column--) {
      int temp = row*column;
      if (temp!=100) {
        cout << " ";
      }
      if (temp<10) {
        cout << " ";
      }
      cout << temp;
    }
  cout << endl;
  }
}
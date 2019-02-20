#include <iostream>
using namespace std;
int main() {
  int r=1, c=1;
  for (r; r<=10; r++) {
    for (c=10; c>0; c--) {
      int ans = r*c;
      if (ans!=100) {
        cout << " ";
      }
      if (ans<10) {
        cout << " ";
      }
      cout << ans;
    }
  cout << endl;
  }
}

//Matthew Strapp
//EE1301
//17 April 2019
//HW 6B: Recursion and ff(x)
#include <iostream>

int ff(int x);
int main() {
  int x;
  do {
    std::cout << "Please enter a value of x: ";
    std::cin >> x;
  } while (x<0);
  std::cout << "Beginning calculation of ff(x)...\n";
  std::cout << "Calcuation complete, ff(x) = " << ff(x) << std::endl;
}

// This function either returns 1 when x is one of two recrusive conditions depending on if x is even or odd.
int ff(int x) {
  if (x > 1) {
    if (x%2 == 0) {
      // x is even
      std::cout << "Calling ff(" << x/2 << ")\n";
      return x*ff(x/2);
    } else {
      // x is odd but not 1
      std::cout << "Calling ff(" << x-2 << ")\n";
      return x*ff(x-2);
    }
  } else {
    // x is 1 (or 0)
    return 1;
  }
}

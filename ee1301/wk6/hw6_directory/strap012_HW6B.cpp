//Matthew Strapp
//EE1301
//17 April 2019
//HW 6B: Recursion and ff(x)
#include <iostream>

int ff(int x);

int main() {
  int value;
  do {
  std::cout << "Please enter a value of x: ";
    std::cin >> value;
  } while (value<0);
  std::cout << "Beginning calculation of ff(x)...\n";
  int ffx = ff(value);
  std::cout << "Calcuation complete, ff(x) = " << ffx << std::endl;
}

// This function either returns 1 when x is one of two recrusive conditions depending on if x is even or odd.
int ff(int x) {
  if (x > 1) {
    if (x%2 == 0) {
      //x is even
      std::cout << "Calling ff(" << x/2 << ")\n";
      return x*ff(x/2);
    } else {
      // x is odd but not 1
      std::cout << "Calling ff(" << x-2 << ")\n";
      return x*ff(x-2);
    }
  } else {
    // x is 1
    //std::cout << "Returning from ff(1) = 1\n";
    return 1;
  }
}

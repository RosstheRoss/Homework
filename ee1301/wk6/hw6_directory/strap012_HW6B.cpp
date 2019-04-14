#include <iostream>

int ff(int x);

int main() {
  int value = -1024;
  do {
  std::cout << "Please enter a value of x: ";
    std::cin >> value;
  } while (value<0);
  std::cout << "Beginning calculation of ff(x)...\n";
  int ffx = ff(value);
  std::cout << "Calcuation complete, ff(x) = " << ffx << std::endl;
}

int ff(int x) {
  if (x > 1) {
    if (x%2 == 0) {
      std::cout << "Calling ff(" << x/2 << ")\n";
      return x*ff(x/2);
    } else {
      std::cout << "Calling ff(" << x-2 << ")\n";
      return x*ff(x-2);
    }
  } else {
    //std::cout << "Returning from ff(1) = 1\n";
    return 1;
  }
}

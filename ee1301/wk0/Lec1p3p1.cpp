#include <iostream>
#include <bitset>
using namespace std;

int main()
{

  // Store data in MEMORY
  int X = 0b0;
  int Y = 0b1;

  // Load data, perform AND instruction, store result to memory
  int X_and_Y = X & Y;

  // Load data, perform OR instruction, store result to memory
  int X_or_Y = X | Y;

  // Write the results to terminal
  cout << "X AND Y = " << bitset<1>(X_and_Y) << endl;
  cout << "X OR Y = " << bitset<1>(X_or_Y) << endl;

  return 0;
} 

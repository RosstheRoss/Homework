/*
27 Feb 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 3A
One-armed Bandit Simulator
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
using namespace std;

// Function: spin_the_wheel
//  ---------------------------
// Simulates the one-armed bandit from the previous HW
// d: the number of options on the spinner
// w: the number of spinners
// returns: Either 1 for win or 0 for loss

int spin_the_wheel(int d, int w) {
  int spinOG=0, spinNew=0, win=0;
  spinOG = ( (rand() % d) + 1); //Original spin is always the same
  for (int i=0; i<w; i++) {
    spinNew = ( (rand() % d) + 1);
    if (spinOG==spinNew) {
      win++;
    }
  }
  if (win==w) { //The only win condition is if every wheel matches
    return 1;
  } else {
    return 0;
  }
}

int main () {
  srand(88888888); //Seeds the RNG of the program to a constant of eight 8s
  int w, d, m, winTest;
  for (w=3; w<=6; w++) {
    m=0;
    for (d=9; d<=27; d++) {
      m=0;
      for (long n=1000000; n>0; n--) {
        int winTest = spin_the_wheel(d, w);
        m+=winTest;
      }
      double win=m;
      cout << "w=" << w << ", d=" << d
           << ": Simulated probability = m/n = " << (win / 100000.0) * 100.0 << "%. "   //Note that 100,000!=1,000,000
           << "Theoretical probability = " << (d / (pow(d, w))) * 100 << "%." << endl;  //This is because otherwise the percentage was off by a factor of 10
      d+=2;
    }
  }
}
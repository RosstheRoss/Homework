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

int spin_the_wheels(int d, int w);

int main () {
  srand(time(NULL));
  int w, d, winCount, winTest;
  for (w=3; w<=6; w++) {
    winCount=0;
    for (d=9; d<=27; d++) {
      winCount=0;
      for (long n=1000000; n>0; n--) { //The simulation is always done 1,000,000 times
        winTest = spin_the_wheels(d, w);
        winCount+=winTest;
      }
      if (w==6) {
        std::cout << std::scientific;
      }
      std::cout << "w=" << w << ", d=" << d
           << ": Simulated probability = m/n = " << (winCount / 1000000.0) * 100.0 << "%. "
           << "Theoretical probability = " << (d / (pow(d, w))) * 100 << "%." << std::endl;
      d+=2;
    }
  }
}

// Function: spin_the_wheels
//  ---------------------------
// Simulates the one-armed bandit from the previous HW
// d: the number of options on the spinner
// w: the number of spinners
// returns: Either 1 for win or 0 for loss

int spin_the_wheels(int d, int w) {
  int spinOG=0, spinNew=0, win=0;
  spinOG = ( (rand() % d) + 1); //Original spin is always the same
  w-=1; //The first wheel was spun as spinOG
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
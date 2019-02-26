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

int spin_the_wheel(int d, int w) {
  int spinOG=0, spinNew=0, win=0;
  spinOG = ( (rand() % d) + 1);
  for (int i=0; i<w; i++) {
    //spinOG = ( (rand() % d) + 1);
    spinNew = ( (rand() % d) + 1);
    if (spinOG==spinNew) {
      win++;
    }
  }
  if (win==w) {
    return 1;
  } else {
    return 0;
  }
}

int main () {
  srand(88888888); //See
  int w, d, m, test;
  for (w=3; w<=6; w++) {
    m=0;
    for (d=9; d<=27; d++) {
      m=0;
      for (long long n=1000000; n>0; n--) {
        int test = spin_the_wheel(d, w);
        m+=test;
      }
      double win=m;
      cout << "w=" << w << ", d=" << d
           << ": Simulated probability = m/n = " << (win / 100000.0) * 100.0 << "%. "
           << "Theoretical probability = " << (d / (pow(d, w))) * 100 << "%." << endl;
      d+=2;
    }
  }
}
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
#include <time.h>
using namespace std;

int spin_the_wheel(int d, int w) {
  int spinOG=0, spinNew=0, win=0;
  for (int i=1; i<=w; i++) {
    spinOG = ( (rand() % d) + 1);
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
  srand(time(NULL));
  long n = 0;
  int m = 0;
  float test;
  int w = 3;
  int d = 9;
  for (n; n <= 1000000; n++)
  {
    test = spin_the_wheel(d, w);
    m+=test;
  }

  cout << "w=" << w << ", d=" << d;
  cout << ": Simulated probability = m/n = " << (m/n)*100 << "%. ";
  cout << "Theoretical probability = " << (d/(pow(d,w)))*100 << "%." << endl;
}
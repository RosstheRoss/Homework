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
  int spinOG, spinNew;
  spinOG = rand() % d + 1
  for (int i=w; i>0; i--) {
    spinNew = rand() % d + 1
    if (spinNew==spingOG) {
      //Do nothing
    } else {
      return 0;
    }
  }
  return 1;
}
int main () {
    int win;
    int d= 3;
    int w= 9;
    for (long n=1000000; n>0; n--) {
      win = spin_the_wheel(d,w);
      if (win==1) {
        win++;
      }
    }
    cout << "w=" << w << ", d=" << d;
    cout << ": Simulated probability = m/n = " << (m/n)*100 << ". ";
    cout << "Theoretical probability = " << (d/pow(d,w))*100 << "." << endl;
}
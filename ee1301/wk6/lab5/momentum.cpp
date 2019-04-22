#include <iostream>

double* momentum (double velocity[3], double mass);

int main() {
  double velocity[3];
  double mass;
  std::cout << "Please enter velocity (x y z) [m/s]: ";
  std::cin >> velocity[0] >> velocity[1] >> velocity [2];
  std::cout << "Please enter mass [kg]: ";
  std::cin >> mass;
  momentum(&velocity[3], mass);
}

double* momentum(double velocity[3], double mass) {
  double* vector;
  vector = new double[3];
  for (int i=0; i<2; i++) {
    vector[i]=velocity[i]*mass;
  }
  return vector;
}
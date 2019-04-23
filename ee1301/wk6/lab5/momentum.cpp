#include <iostream>

double momentum (double velocity, double mass);

int main() {
  double velocity[3];
  double mass;
  std::cout << "Please enter velocity (x y z) [m/s]: ";
  std::cin >> velocity[0] >> velocity[1] >> velocity [2];
  std::cout << "Please enter mass [kg]: ";
  std::cin >> mass;
  
  double* vector;
  vector = new double[3];
  std::cout << "Momentum: <";
  for (int i=0; i<=2; i++) {
    vector[i]=momentum(velocity[i], mass);
    std::cout << vector[i];
    if ((i<2))
      std::cout << ",";
  }
  delete[] vector;
  std::cout << ">" << std::endl;
}

double momentum(double velocity, double mass) {
  return velocity * mass;
}
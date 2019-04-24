#include <iostream>

double randVec();
double momentum (double velocity);
int main() {
  srand(time(NULL));
  double sum[3]={0,0,0};
  double* randVel;  double* momArray;
  randVel = new double[1000];
  momArray = new double[1000];
  for (int i=0; i<1000; i++) {
    randVel[i]=randVec();
    momArray[i]=momentum(randVel[i]);
    int j=i%3;
    sum[j]+=momArray[i];
  }
  std::cout << '<' << sum[0]/1000.0 << ',' <<  sum[1]/1000.0 << ',' << sum[2]/1000.0 << '>' << std::endl;
  delete[] randVel;
  delete[] momArray;
}


double randVec() {
  double vector[3];
  for (int i=0; i<3; i++) {
    if (rand()%2+1==1) {
      vector[i]=rand()%100+1.0;
    } else {
      vector[i]=rand()%100*-1.0+1.0;
    }
  }
  return *vector;
}

double momentum(double velocity) {
  double mass;
  if (rand()%2+1==0) {
    mass=rand()%10+1.0;
  } else {
    mass=rand()%10*-1.0+1.0;
  }
  return mass*velocity;
}
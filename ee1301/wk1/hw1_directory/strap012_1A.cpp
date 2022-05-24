#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  float r; //Radius
  float h; //Height
  
  cout << "Input the radius of the sphere: ";
   cin >> r;
  cout << "Input the height of the fluid: ";
   cin >> h;
  
  cout << fixed << setprecision(2) //Set rounding to 2 decimal places
    << "Volume of the entire tank: " << ((4.0/3) * M_PI * pow(r, 3)) << endl
    << "Surface area of the entire tank: " << (4 * M_PI * pow(r, 2)) << endl
    << "Volume of the fluid: " << (1.0/3) * (M_PI * pow(h, 2) * (3 * r - h )) << endl
    << "Surface area covered by the fluid: " << (2 * M_PI * r * h) << endl << endl;
}
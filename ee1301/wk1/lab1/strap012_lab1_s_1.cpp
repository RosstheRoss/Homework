#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x=20;
    double h = 1e-14;
    cout << (pow(x+h, 3)-pow(x,3))/h << endl;
}
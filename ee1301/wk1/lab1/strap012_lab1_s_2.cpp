#include <iostream>
using namespace std;

int main()
{
    double tf;
    cout << "Enter temperature in degrees Celsius: ";
    cin >> tf;
    char c = 'F';
    double tc = tf;
    char f = 'C';
    cout << tc << " degrees " << f << " = " << tf * (9/5.0) + 32 <<" degrees " << c << endl;
}


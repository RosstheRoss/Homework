#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x = 5;
    cout << x << "! = " << x * (x / x + x / x + x / x + x / x) * (x / x + x / x + x / x) * (x / x + x / x) * (x / x) << endl;
}
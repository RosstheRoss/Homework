#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first, last;
    cout << "What is your full name?" << endl;
    getline (cin,first);
    //cin.ignore();
    getline (cin,last);
    cout << last << ", " << first << endl;
}

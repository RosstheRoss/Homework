#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first;
    string middle;
    string last = " ";
    cout << "What is your full name?" << endl;
    cin >> first >> middle >> last;
    if (last == " ")
    {
        cout << middle << ", " << first;
    }
    else
    {
        cout << last << ", " << first << " " << middle << endl;
    }
}

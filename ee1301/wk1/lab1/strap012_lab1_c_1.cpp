#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name1;
    string name2;
    int h1, h2;
    
    cout << "Enter your name: ";
    getline (cin,name1);
    cout << "Enter your height: ";
    cin >> h1;
    cout << "Enter your comrade's name: ";
    cin.ignore();
    getline (cin,name2);
    cout << "Enter your comrade's height: ";
    cin >> h2;
    
    cout << name1 << " and " << name2 << " standing on top of each other are " << h1+h2 << " feet tall!" << endl;
  
  
}

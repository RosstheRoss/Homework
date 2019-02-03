#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  string option;
  cout << "Are input components int or float (i/f)? ";
  cin >> option;
  
  if (option == "i") {
    int r;
    int g;
    int b;
    cout << "Input r, g, b: ";
    cin >> r >> g >> b;
    cout << fixed << setprecision(2) << "Float representation: " << r / 255.0 << ", " << g / 255.0 << ", " << b / 255.0;
    }else{ if (option == "f") {
       double r;
       double g;
       double b;
       cout << "Input r, g, b: ";
       cin >> r >> g >> b;
       cout << fixed << setprecision(0) << "Integer representation: " << r * 255 << ", " << g * 255 << ", " << b * 255;
      }else{
        cout << "Invalid option." << endl;
        return 0;
      }
  }
    cout << endl; 
}
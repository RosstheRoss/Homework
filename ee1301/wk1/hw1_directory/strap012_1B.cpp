#include <iostream>
#include <string>
using namespace std;

int main()
{
  string option;
  cout << "Are input components int or float (i/f)? ";
  cin >> option;
  
  if (option == "i") {
    cout << "E";
    }else{ if (option == "f") {
      cout << "e";
      }else{
          cout << "nah.";
      }
  }
}
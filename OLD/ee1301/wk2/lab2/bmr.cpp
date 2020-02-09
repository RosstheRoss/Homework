#include <iostream>
using namespace std;

int main () {
  int age,height,weight,chocolate;
  double BMR;
  char sex;
  cout << "Enter weight in pounds:"; cin >> weight;
  cout << "Enter height in inches:"; cin >> height;
  cout << "Enter age in years:"; cin >> age;
  cout << "Enter Sex(M/F)"; cin >> sex;

  if (sex=='F' || sex=='f'){
    BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    cout << "Your BMR is: " << BMR;
  }

  if (sex=='M' || sex=='m'){
    BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    cout << "Your BMR is: " << BMR;
  }

  chocolate = BMR/230;
  cout << endl << "Number of 230 Calories bars you can have is: " << chocolate << endl;
  return 0;
}

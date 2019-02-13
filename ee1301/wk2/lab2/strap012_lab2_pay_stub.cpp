#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  int dependents, hours;
  int OT = 0; int Health = 0;
  double SSI, MN, Fed, GroPay, NetPay;
  cout << "How many hours did you work this week?: ";
  cin >> hours;
  cout << "How many dependents do you have?: ";
  cin >> dependents;
  if (hours > 40) {
    OT=hours-40;
  }
  if (dependents >= 3) {
    Health=35;
  }
  GroPay = hours * 16.78 + OT * 16.78 * 1.5;
  SSI = GroPay * 0.06;
  Fed = GroPay * 0.14;
  MN = GroPay * .05;
  NetPay = GroPay-SSI-Fed-MN-Health-10;       //$10 union dues

  cout << fixed << setprecision(2) << "Your gross (before withholdings) pay is $" << GroPay << "." << endl
  << "Social Security withholding: $" << SSI << endl
  << "Federal income tax withholding: $" << Fed << endl
  << "State income tax withholding: $" << MN << endl
  << "Union Dues: $10" << endl
  << "Medical cost: $" << Health << endl //<< endl

  << "Your net (after witholdings) pay is $" << NetPay << "." << endl;
}
//cout << fixed << setprecision(2)

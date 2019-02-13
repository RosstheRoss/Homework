/*
Date: 13 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Workout
Short Program Description: Pay Stub Calculator
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main () {
  int dependents, Hours;
  int OT = 0; int Health = 0; //Set values to zero to prevent problems
  double SSI, MN, Fed, GrossPay, NetPay;
  cout << "How many hours did you work this week?: ";
  cin >> Hours;
  cout << "How many dependents do you have?: ";
  cin >> dependents;
  if (Hours > 40) {
    OT=Hours-40; //Overtime pay is extra so it needs to be seperate
  }
  if (dependents >= 3) {
    Health=35;
  }
  GrossPay = Hours * 16.78 + OT * 16.78 * 1.5;
  SSI = GrossPay * 0.06;
  Fed = GrossPay * 0.14;
  MN = GrossPay * .05;
  NetPay = GrossPay-SSI-Fed-MN-Health-10;       //$10 union dues

  cout << fixed << setprecision(2) << "Your gross (before withholdings) pay is $" << GrossPay << "." << endl
  << "Social Security withholding: $" << SSI << endl
  << "Federal income tax withholding: $" << Fed << endl
  << "State income tax withholding: $" << MN << endl
  << "Union Dues: $10" << endl
  << "Medical cost: $" << Health << endl

  << "Your net (after witholdings) pay is $" << NetPay << "." << endl;
}

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
  int Dependents, Hours;
  int OT = 0; int Health = 0; int Union =0;   //Set values to zero to prevent problems
  double SocSec, State, Fed, GrossPay, NetPay;
  cout << "How many hours did you work this week?: ";
  cin >> Hours;
    if (Hours < 0) {
      cout << "Invalid option!" << endl;
      return 2;
    }
    else{
  cout << "How many dependents do you have?: ";
  cin >> Dependents;
  if (Hours > 40) { //Every hour over 40 constitutes as overtime
    OT=Hours-40;
  }
  if (Dependents >= 3) {  //More than 3 dependents carries a fee
    Health=35;
  }
  GrossPay = Hours * 16.78 + OT * 16.78 * 1.5;
  SocSec = GrossPay * 0.06;
  Fed = GrossPay * 0.14;
  State = GrossPay * .05;
  if (GrossPay>0){
    Union=10;
  }
  NetPay = GrossPay-SocSec-Fed-State-Health-Union; //$10 union dues are constant
  cout << fixed << setprecision(2) << endl << "Your gross (before withholdings) pay is $" << GrossPay << "." << endl
  << "Social Security withholding: $" << SocSec << endl
  << "Federal income tax withholding: $" << Fed << endl
  << "State income tax withholding: $" << State << endl
  << "Union Dues: $" << Union << endl
  << "Medical cost: $" << Health << endl

  << "Your net (after witholdings) pay is $" << NetPay << "." << endl;
}
}

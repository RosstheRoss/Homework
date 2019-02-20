/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2B
Short Program Description: Time Travel Calculator
*/
//15

#include <iostream>
using namespace std;
int main()
{

  bool change12=0, foo=0, bar=false; //Workaround to prevent unneeded if statements
  char Time, travel;          //"time" is reserved by C++, "Time" is not
  int hourOG, hourChange, hourNew, intervalChange = 0, timeChange = 1;
  cout << "Enter current time (A for AM, P for PM): ";
  cin >> hourOG >> Time;
  cout << "How many hours forward or backward do you want to move the clock (F for forwards, B for backward): ";
  cin >> hourChange >> travel;
 
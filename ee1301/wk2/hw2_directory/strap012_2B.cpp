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

  bool change12=0, foo=0, bar=true; //Workaround to prevent unneeded if statements
  char Time, travel;          //"time" is reserved by C++, "Time" is not
  int hourOG, hourChange, hourNew, intervalChange = 0, timeChange = 1;
  cout << "Enter current time (A for AM, P for PM): ";
  cin >> hourOG >> Time;
  cout << "How many hours forward or backward do you want to move the clock (F for forwards, B for backward): ";
  cin >> hourChange >> travel;
  for (int i = hourChange; i >= 0; i--)
  {
    if (travel=='F') {
      if (hourOG+hourChange>=12 && bar) {
        if (hourOG+hourChange==12) {
          timeChange++;
        } else {
        hourNew=(hourOG+hourChange)-12;
        bar=false;
        }
      }
    }
    if (travel=='B') {

    }
    if (intervalChange >= 12) {
      intervalChange = 0;
      timeChange++;
    }
  }

  for (timeChange; timeChange > 1; timeChange--) {
    //if (change12) {
    if (Time == 'A')
    {
      Time += 15;
      //foo = true;
    } else {
      if (Time == 'P') { //&& !foo) {
      Time -= 15;
    }
    //foo = false;
    }
  }
  if (travel == 'F')
  {
    //hourNew = hourOG + intervalChange;
  }
  if (travel == 'B')
  {
    hourNew = hourOG + intervalChange;
  }
  //Deprecated, doesn't work
  //hourNew=hourOG+intervalChange;
  cout << "The new time is: " << hourNew << " " << Time << "M" << endl;
  return 0;
}
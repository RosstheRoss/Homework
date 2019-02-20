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

  bool change12 = 0, foo = 0; //Workaround to prevent unneeded if statements
  char Time, travel;          //"time" is reserved by C++, "Time" is not
  int hourOG, hourChange, hourNew, intervalChange = 0, timeChange = 1;
  cout << "Enter current time (A for AM, P for PM): ";
  cin >> hourOG >> Time;
  cout << "How many hours forward or backward do you want to move the clock (F for forwards, B for backward): ";
  cin >> hourChange >> travel;
  for (int i = hourChange; i >= 0; i--)
  {
    if (i != 0)
    {
      intervalChange++;
    }
    do
    {
      if (travel == 'B' && hourOG - intervalChange < 0)
      {
        if (hourChange < 12)
        {
          intervalChange -= 12;
        }
        else
        {
          intervalChange = 12 - intervalChange;
          if (intervalChange >= 13)
          {
            intervalChange -= 12;
          }
        }
        timeChange++;
      }
    } while (intervalChange > 12);
    if (intervalChange >= 12)
    {
      //if (intervalChange !=12)    {i
      intervalChange = 0;
      timeChange++;
      //change12=1;
    }
  }

  /*  if (hourOG+hourChange>=12 || hourOG-hourChange<=0) {
    if (hourOG!=0 ^ hourOG!=12) {
       hourOG-=12;
    }
    if (hourChange>12) {
      do {
        hourChange-=12;
        timeChange+=1;
        } while (hourChange >=11);
  }
    change12=1;
  }
*/

  for (timeChange; timeChange > 1; timeChange--)
  {
    //if (change12) {
    if (Time == 'A')
    {
      Time += 15;
      foo = true;
    }
    if (Time == 'P' && !foo)
    {
      Time -= 15;
    }
    foo = 0;
    //}
  }

  if (travel == 'F')
  {
    hourNew = hourOG + intervalChange;
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
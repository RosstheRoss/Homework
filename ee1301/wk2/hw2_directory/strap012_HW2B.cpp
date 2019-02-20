/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2B
Short Program Description: Time Travel Calculator
*/
//The backwards part stumps me.

#include <iostream>
using namespace std;
int main()
{

  bool foo = 0, bar = false; //Workaround to prevent unneeded if statements
  char Time, travel;                       //"time" is reserved by C++, "Time" is not
  int hourOG, hourChange, hourNew, intervalChange = 0, timeChange = 0;
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
    if (travel == 'F')
    {
      if (hourOG + hourChange >= 12)
      {
        if (hourOG + hourChange == 12)
        {
          timeChange++;
        }
        else //This else statement is a complete hackjob. It works consistently though.
        {
          int temp = (hourOG + hourChange) - 12;
          bar=true;
          while (temp>12) {
            temp-=12;
            timeChange++;
          }
          hourNew=temp;
     }
        }
        timeChange++;
      }
    if (travel == 'B')
    {
    }
    if (intervalChange >= 12)
    {
      intervalChange = 0;
      timeChange++;
    }
  }
  for (timeChange; timeChange > 1; timeChange--)
  {
    if (Time == 'A')
    {
      Time += 15; //15 is the difference in the ASCII table between 'A' and 'P'
    }
    else
    {
      if (Time == 'P')
      {
        Time -= 15; //See line 64
      }
    }
  }
  if (travel == 'F' && !bar)
  {
    hourNew = hourOG + intervalChange;
  }
  if (travel == 'B')
  {
    hourNew = hourOG - intervalChange;
  }
  cout << "The new time is: " << hourNew << " " << Time << "M" << endl;
  return 0;
}
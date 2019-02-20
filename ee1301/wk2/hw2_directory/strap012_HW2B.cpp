/*
20 Feb 2019
Matthew Strapp
5449340
EE1301
Spring 2019
Homework 2B
Time Travel Calculator
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
  cin >> travel >> hourChange;
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
      if (hourOG - hourChange <= 0)
      {
          int temp = (hourOG - hourChange) + 12;
          bar=true;
          while (temp>12) {
            temp-=12;
            timeChange++;
          }
          if (hourChange<=24) {
            hourNew=temp;
          } else {
            for (int k=(hourChange%24); k>0; k--) {
              hourNew=temp+12;
            }
          }
        }
        timeChange++;
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
        Time -= 15;
      }
    }
  }
  if (travel == 'F' && !bar)
  {
    hourNew = hourOG + intervalChange;
  }
  if (travel == 'B' && !bar)
  {
    hourNew = hourOG - intervalChange;
  }
  cout << "The new time is: " << hourNew << " " << Time << "M" << endl;
  return 0;
}
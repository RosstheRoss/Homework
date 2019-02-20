/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2B
Short Program Description: Time Travel Calculator
*/

//PROGRAMMER'S NOTE: This problem legitimately stumped me. I won't be suprised if this is where I lose most of my points for this assignment.
//I've been trying this for more than six hours and it has still made no sense
//Nested if and for statements are a nightmare

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
    /* do
    {
      STILL BROKEN
      if (travel == 'B' && hourOG - intervalChange < 0)
      {
        if (hourChange < 12)
        {
          intervalChange = 12 - hourChange;
        }
        else
        {
          intervalChange = hourChange - 12;
          if (intervalChange >= 13)
          {
            intervalChange -= 12;
          }
        }
        timeChange++;
      }
      STILL BROKEN 

    } while (intervalChange > 12); */
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
      Time += 15;
      foo = true;
    }
    if (Time == 'P' && !foo)
    {
      Time -= 15;
    }
    foo = 0;
  }

  if (travel == 'F')
  {
    hourNew = hourOG + intervalChange;
  }
  if (travel == 'B')
  {
    hourNew = hourOG + intervalChange;
  }
  cout << "The new time is: " << hourNew << " " << Time << "M" << endl;
  return 0;
}
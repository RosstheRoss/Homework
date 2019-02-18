/*
Date: 20 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: Homework 2C
Short Program Description: Pay Stub Calculator
*/
//15

#include <iostream>
using namespace std;
int main () {
  bool change12=0; //Workaround to prevent unneeded if statements
  char Time, travel; //"time" is reserved
  int hourOG, hourChange, hourNew, timeChange=0;
  cout << "Enter current time (A for AM, P for PM): ";
  cin >> hourOG >> Time;
  cout << "How many hours forward or backward do you want to move the clock (F for forwards, B for backward): ";
  cin >> hourChange >> travel;
    
  if (hourOG+hourChange>=12 || hourOG-hourChange<=0) {
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
  for (timeChange; timeChange>0; timeChange--) {
    if (change12) {
      if (Time=='A') {
        Time+=15;
      }
      if (Time=='P') {
        Time-=15;
      }
    }
  }
  if (travel=='F') {
    hourNew=hourOG+hourChange;
  }
  if (travel=='B'){
    hourNew=hourOG-hourChange;
  }
  
  cout << "The new time is: " << hourNew << " " << Time << "M" << endl;
  return 0;
  
  
}
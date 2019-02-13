/*
Date: 13 Feb 2019
Name: Matthew Strapp
Student ID number: 5449340
Course number: EE1301
Term: Spring 2019
Lab/assignment number: W-Up 1
Short Program Description: Special Relativity equation tool
*/

#include <iostream>
#include <cmath>
using namespace std;

int main () {
	double L,v,c;
	c=3e+10;

	cout << "Enter L: "; cin >> L;
	cout << "Enter V: "; cin >> v;
	cout << "Relative Length = " <<
	L * sqrt(1-(v*v)/(c*c)) //Relativistic Equation
	<< endl;
	return 0;
}

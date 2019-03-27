#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();


int main()
{
	string fullName[2]; //fullName1, fullName2;
	double height[2];   //height1, height2;

	fullName[0] = requestName();
	height[0] = requestHeight(fullName[0]);
	fullName[1] = requestName();
	height[1] = requestHeight(fullName[1]);

	cout << "If " << fullName[0] << " and " << fullName[1]
	     << " form a human tower, their combined height will be "
	     << (height[0] + height[1]) << endl;
	
}

string requestName()
{
	string name;
	cout << "Please enter full name: ";
	getline(cin, name);
	return name;
}

double requestHeight(string fullName)
{
	double height;
	cout << "Please enter " << fullName << "'s height: ";
	cin >> height;
	cin.ignore(2, '\n'); // gets rid of \n in the buffer
	
	return height;
}

int requestNumberOfPartners()
{
	int numberOfPartners;
	cout << "How many partners are there?";
	cin >> numberOfPartners;
	
	return numberOfPartners;
}


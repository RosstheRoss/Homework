#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void NotinMain(string array1[], const int length1, double array2[], const int length2);

int main()
{
	string fullName[2]; //fullName1, fullName2;
	double height[2];   //height1, height2;

	fullName[0] = requestName();
	height[0] = requestHeight(fullName[0]);
	fullName[1] = requestName();
	height[1] = requestHeight(fullName[1]);
	NotinMain(fullName, 2, height, 2);
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

void NotinMain(string array1[], const int length1, double array2[], const int length2) {
  	cout << "If " << array1[0] << " and " << array1[1]
	     << " form a human tower, their combined height will be "
	     << (array2[0] + array2[1]) << endl;
  }
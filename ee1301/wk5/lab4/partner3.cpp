#include <iostream>

using namespace std;

string requestName();
double requestHeight(string fullName);
int requestNumberOfPartners();
void NotinMain(string array1[], double array2[], int numberOfPartners);

int main()
{
	int numberOfPartners = requestNumberOfPartners();
	string fullName[100]; //fullName1, fullName2;
	double height[100];   //height1, height2;

	// fullName[0] = requestName();
	// height[0] = requestHeight(fullName[0]);
	for (int i=0; i<numberOfPartners; i++) {
		fullName[i] = requestName();
		height[i] = requestHeight(fullName[i]);
	}
	NotinMain(fullName, height, numberOfPartners);
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
	cout << "How many partners are there? ";
	cin >> numberOfPartners;
	cin.ignore(2, '\n');

	return numberOfPartners;
}

void NotinMain(string array1[100], double array2[100], int numberOfPartners) {
  double heightTotal=0;
	cout << "If " << array1[0];
	for (int i=1; i<numberOfPartners-1; i++) {
		cout << ", " << array1[i];
		heightTotal += array2[i];
	}
		cout << " and " << array1[numberOfPartners-1]
	     << " form a human tower, their combined height will be "
	     << (array2[0] + heightTotal + array2[numberOfPartners-1]) << endl;
  }

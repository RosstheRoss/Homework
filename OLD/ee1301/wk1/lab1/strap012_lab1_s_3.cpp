#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main () {
	string name, quest, color, assyria, swallowSpeed;
	cout << "Before you cross this bridge, answer the questions three." << endl << endl << "Question the first: what is your name? ";
	cin >> name;
	cout << "What is your quest? ";
	cin >> quest;
	int a = rand() % 3 + 1;
	if (a == 1) {
		cout << "What is your favorite color? ";
		cin >> color; }
	if (a == 2) {
		cout << "What is the captial of Assyria? ";
		cin >> assyria; }
	if (a == 3) {
		cout << "What is the air speed of an unladen swallow?";
		getline(cin,swallowSpeed); }

	if (color == "null" || assyria == "Nineveh" || swallowSpeed == "African or European?") {
		cout << endl << "Go on." << endl; }
		else {
			cout << "BEGONE" << endl;
			return 100; }

}

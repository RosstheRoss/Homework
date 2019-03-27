#include <iostream>
#include <string>
using namespace std;

bool mystery(string fstr);
int main () {
  string e = "Sargent Pepper's Lonely Hearts Club Band";
  cout << mystery(e) << endl;
}

bool mystery(string fstr) {
	string rstr;	 // a string is like an array of chars, e.g., char[]
	for(int i=fstr.length()-1; i>=0 ;i--){
	    rstr +=  fstr[i];  // fstr[i] gets the char at index i
   }
   cout << fstr << endl << rstr << endl;
   return rstr == fstr;
}

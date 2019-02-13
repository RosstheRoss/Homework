#include <iostream>
using namespace std;

int main () {
  int a,b;
  char op;
  cout << "Enter an equation: ";
  cin >> a >> op >> b;
  cout << a << op << b << " = ";

   if (op=='+'){ //Addition
     cout << a + b;
   }

   if (op=='-'){ //Subtraction
     cout << a - b;
   }

   if (op=='*'){ //Multiplication
     cout << a * b;
   }

   if (op=='/'){ //Division
     cout << a / b;
   }

   cout << endl;
 }

#include <iostream>
using namespace std;

int main () {
  int a,b;
  char op;
  cout << "Enter an equation: ";
  cin >> a >> op >> b;
  cout << a << op << b << " = ";
  
   if (op=='+'){
     cout << a + b;
   }

   if (op=='-'){
     cout << a - b;
   }

   if (op=='*'){
     cout << a * b;
   }

   if (op=='/'){
     cout << a / b;
   }

   cout << endl;
 }

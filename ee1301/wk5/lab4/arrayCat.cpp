#include <iostream>
using namespace std;
void append (char first[], int l1, char second[], int l2, char result[200]);

int main () {
  char first[] = {'I', ' ', 'a', 'm', ' '};
  char second[] = {'i', 'r', 'o', 'n', 'm', 'a', 'n', '\0'};
  char result[200];
  append(first, 5, second, 8, result);
  cout << result << endl;
}

void append (char first[],int l1, char second[],int l2, char result[200]) {
  int length=0;
  for (int i=0; i<l1; i++) {
    result[length]=first[i];
    length++;
  }
  for (int i=0; i<l2; i++) {
    result[length]=second[i];
    length++;
  }
}

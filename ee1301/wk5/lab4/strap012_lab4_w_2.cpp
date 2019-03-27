#include <iostream>
using namespace std;

void bsort(int list[], int length);
void swap (int &a, int &b);
void printArray (int list[], int length);
void makeArray (int list[], int length);
const int n=50;

int main () {
int list[n];
makeArray(list,n);
bsort(list, n);
printArray(list, n);
}

//This function makes the array used for the rest of the program.
void makeArray(int list[], int length) {
  int temp=100;
  for (int i=0; i<n; i++) {
    list[i]=temp;
    temp--;
  }
}

//This function is the algorithm.
void bsort(int list[], int length) {
  for (int i=0; i<n; i++) {
    for (int j=0; j<n-1; j++) {
      if (list[j]>list[j+1]) {
        //This is so the bubble can happen
        swap(list[j], list[j+1]);
      }
    }
  }
}

//This function simply swaps two values so the bubbling can commence
void swap (int &a, int &b) {
  int temp;
  temp=a; a=b; b=temp;
}

//This function prints the array at 5 per line.
void printArray (int list[], int length) {
  int k=0;
  for (int j=0; j<(n/10)*2; j++) {
    for (int i=0; i<5; i++) {
      cout << list[k] << " ";
      k++;
    }
  cout << endl;
  }
}

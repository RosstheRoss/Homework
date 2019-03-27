#include <iostream>
using namespace std;

void swap (int &a, int &b);
int main(int argc, char* argv[])  {
        if (argc !=2) {
          cout << "Incorrect number of arguments! USAGE:" << endl
	         << "     swappy <string>" << endl;;
          return 3;
        }
        int i;
        for (i=0; i<10000; i++) {
          if (argv[1][i]=='\0') {
            break;
          }
        }
        swap(argv[1][0],argv[1][(i-1)]);
        cout << argv[1] << endl;

}
void swap (char &a, char &b) {
  char temp;
  temp=a; a=b; b=temp;
}

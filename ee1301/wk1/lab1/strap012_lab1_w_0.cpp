#include <iostream>
using namespace std;

int main()
{
   int students;
   int section;
    cout << "Number of students: ";
    cin >> students;
    cout << "Number of sections: ";
    cin >> section;
    cout << "The lecture to lab ratio is " << students/section << ":1." << endl;
}
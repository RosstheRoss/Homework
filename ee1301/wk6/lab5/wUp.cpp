#include <iostream>
using namespace std;

class Point
{
   public:
void showPoint( );
Point( );
Point(int newX, int newY) {
	xlocation = newX;
	ylocation = newY;
}
int	xlocation;
int   ylocation;
} ;


int main() {
  int a(1);
  int b(2);
  int *p1;
  p1 = &a;
  Point *p2 = new Point(*p1, b);
  *p1 = p2->ylocation;
  p2->xlocation = 10;
  cout << p2->xlocation << ' ' << *p1 << ' ' << b << ' ' << a << endl;
}
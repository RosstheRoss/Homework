#include <iostream>

#ifndef BUG_H

#define BUG_H
class Bug {
private:
  int position, dir;
public:
  Bug() {
    position=0;
    dir=1;
  }
  Bug(int pos) {
    position=pos;
    dir=1;
  }
  void move() {
    position+=dir;
  }
  void turn() {
    dir*=-1;
  }
  void display() {
    std::cout << "position = " << position << ", direction = " << dir << std::endl;
  }
};
#endif

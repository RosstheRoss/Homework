#include <iostream>
int xorMask(int Byte) {
	Byte = Byte ^ 8;
    return Byte;
}

int main() {
    int a = xorMask(15);
    std::cout << a << std::endl;
    return 0;
}
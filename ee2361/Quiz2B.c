#include <stdio.h>

int is_odd(int x);  //Definition
int main() {
    printf("%d", (1 << 4) | (1 << 7));
    printf("\n");
    printf("%d", (10 & 7));
    printf("\n");
    printf("%d", is_odd(512));
    printf("\n");
    printf("%d", is_odd(1023));
    printf("\n");
}
int is_odd(int x){  //Actual Function
    return x & 1;
}
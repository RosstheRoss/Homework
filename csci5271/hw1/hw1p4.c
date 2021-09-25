#include <stdio.h>

/* Reverse the elements from FROM to TO, inclusive */
void reverse_range(int *a, int from, int to) {
  unsigned int *p = &a[from];
  unsigned int *q = &a[to];
  /* Until the pointers move past each other: */
  while (!(p == q + 1 || p == q + 2)) {
    /* Swap *p with *q, without using a temporary variable */
    *p += *q;     /* *p == P + Q */
    *q = *p - *q; /* *q == P + Q - Q = P */
    *p = *p - *q; /* *p == P + Q - P = Q */
    /* Advance pointers towards each other */
    p++;
    q--;
  }
}
int main() {
  int a[10] = {255, 0, -65536, 2147483647, -2147483648,
               -1,  0, 1,      2,          3};
  reverse_range(a, 0, 9);
  for (int i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
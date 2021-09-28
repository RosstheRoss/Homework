# Homework 1

## Q1



## Q2

### A: Perl

After adding a name to the request, add a semicolon followed by the command. The semicolon is the shell command separator which allows it to parse commands.

#### Example Request

```
"?field-name=;perl+-e+'`command`'"
```

### B: C

## Q3

## Q4

### A

#### Mistake 1a: Potentially overloading the array

If the function is called with `to` larger than outer bound of the array, there is a buffer overflow that happens. For example, running it by default with an array of size 10 with a `to` of 11 on gcc 11.1 causes it to crash because of stack smashing.

##### Mistake 1b: Underloading the array

If the function is called with `from` smaller than 0 will cause some values of the array to be replaced with other values from memory addresses nearby. It did not crash, but it is not the intended behavior.

#### Mistake 2

a

#### Mistake 3

### B: Same Signature

```c
void reverse_range(int *a, int from, int to) {
    unsigned int *p = &a[from];
    unsigned int *q = &a[to];
/* Until the pointers move past each other: */
    while (!(p == q + 1 || p == q + 2)) {
/* Swap *p with *q, without using a temporary variable */
        *p += *q; /* *p == P + Q */
        *q = *p - *q; /* *q == P + Q - Q = P */
        *p = *p - *q; /* *p == P + Q - P = Q */
/* Advance pointers towards each other */
        p++;
        q--;
    }
}

```

### C: Different Signature

```c
    int* reverse_range(int arr[], int arrSize, int from, int to) {
        if (from < 0 || to >= arrSize || to < from)
            return NULL;
        for (int i = from; i < to; i++) {
            int temp = arr[i];
            arr[i] = arr[to];
            arr[to] = temp;
            to--;
        }
        return arr;
    }
```

## Q5

### A

Start out with the binary representation of 20, 00010100. Then shift the bits to the right and toggle bit 31. Then left shift (multiply by 2) and you get 20.
2147483668 and 2 are two numbers that give 20 when multiplied.
Also works with 1073741829 and 4.

### B

The easiest way at first would seems like it would be to get the largest unsigned integer, divide it by 7 and add 3 to get the overflow to 20, getting back to multiplying and you get 7. The problem is that doesn't work. You get 17.
The next thing to try is doubling the integer and adding 20 to get it to overflow twice. Thankfully `0x200000014` is cleanly divisible by 7.

`200000014*7=20`

### C

```c
    printf("$1%.27d spear%c%.0x %.7sion %o\n", 0, 104, 962029, "evacuate", 13023);
```

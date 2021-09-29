# Homework 1

## Q1

### Database Threat Model

The main threat of the model is accessing the database. Any access to the server of the database is considered a threat because it can potentially be used as a vector for privilege escalation and database access. The server can be accessed either over a network that may or may not exist or directly connecting to the machine itself.

The potential attackers would be any students or other users who potentially have access to the machine with the database.

The most reasonable attacks would be guessing the credentials to access the database, most likely by brute forcing a password if one exists.

Impossible threats would be from people and devices that cannot access the machine containing the database.

### Without Network

Without networking hardware, one major threat vector (the network) is gone.

One way to mitigate threats is to encrypt the database and the computer containing the database with a password resistant to brute forcing if someone were to obtain the computer. If the algorithm is slow, an old computer could be even more slowed down by the decryption.

Another way to mitigate threats is to lock the computer up when it is not being used.

## Q2

### A: Perl

After adding a name to the request, add a semicolon followed by the command. The semicolon is the shell command separator which allows it to parse new commands.

#### Example Request Body

```perl
'field-name=; ls'
```

### B: C

## Q3

Overfilling the buffer normally causes the program to crash from stack smashing. This can be undone by finding the canary value and using it to overwrite the canary value after the buffer overflow. The CFI can be beaten by jumping to a known legal target.

On big and little endian machines, the byte order is reversed.

## Q4

### A

#### Mistake 1a: Potentially overloading the array

If the function is called with `to` larger than outer bound of the array, there is a buffer overflow that happens. For example, running it by default with an array of size 10 with a `to` of 11 on gcc 11.1 causes it to crash because of stack smashing.

#### Mistake 1b: Negative numbers the array

If the function is called with `from` smaller than 0 will cause the array to look at addresses before the array, potentially causing the program to segfault.

#### Mistake 2: Swapping the to and from

If the function is called with `from` larger than `to`, the program will segfault from accessing invalid memory addresses.

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
    void reverse_range(int *arr, int arrSize, int from, int to) {
        //Program should exit if it works backwards or goes out of bounds
        if (from < 0 || to >= arrSize || to < from)
            return;
        for (int i = from; i < to; i++) {
            int temp = arr[i];
            arr[i] = arr[to];
            arr[to] = temp;
            to--;
        }
        return;
    }
```

The main difference is that the function needs the size of the array since it can't be found from the scope of the function itself.

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

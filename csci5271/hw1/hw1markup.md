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
If the function is called with `to` larger than outer bound of the array, there is a buffer overflow that happens. For example, running it by default with an array of size 10 with a `to` of size 11 on gcc 11.1 causes it to crash because of stack smashing.
##### Mistake 1b: Underloading the array
If the function is called with `from` smaller than 0 will cause some values of the array to be replaced with other values from memory. It did not crash, but it is not the intended behavior.
#### Mistake 2:

#### Mistake 3:

### B: Same Signature
```c
    void reverse_range(int *a, int from, int to) {
        
```
### C: Different Signature
```c
    int* reverse_range(int arr[], int arrSize, int from, int to) {
        if (from < 0 || to >= arrSize)
            return NULL;
        for (int i = from; i < to; i++) {
            int temp = arr[i];
            arr[i] = arr[to];
            arr[to] = temp;
            to--;
        }
        return arr;
```
## Q5
#include "include/main.h"
#include "include/address.h"

/*
 * Write getAddress function
 * void getAddress(char * address);
 * Prints a prompt "Enter your address: " to get an address,
 * Reads in the user's address
 */

void getAddress(char * address) {
    printf("Enter your address: ");
    fgets(address, maxLen, stdin);
    fflush(stdin);
}
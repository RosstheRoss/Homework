/*
 * Recitation section number:
 * Breakout Group Number:
 * Member name (email address):
 * Member name (email address):
 * Member name (email address):
 * Member name (email address):
 * Member name (email address):
 * Member name (email address):
 * Member name (email address):
 */

#include "include/main.h"
#include "include/name.h"
#include "include/address.h"
#include "include/major.h"

int main() {

    char name[maxLen];
    char address[maxLen];
    char major[maxLen];

    printf("Hi there! \nTell me more about you.\n");
    getName(name);
    getAddress(address);
    getMajor(major);

    printf("Thanks for your information!\n");
    printf("Your name: %s", name);
    printf("Your address: %s", address);
    printf("Your major: %s", major);
    printf("Bye!\n");

    return 0;
}
#include <stdio.h>
#include <string.h>

void payment(char *name, double amount_cny, char *purpose, int purpose_len)
{
    double amount_usd = amount_cny / 6.466;
    char memo[40];
    strcpy(memo, "Payment for: ");
    memcpy(memo + strlen(memo), purpose, purpose_len);
    //write_check(name, amount_usd, memo);
    printf("address of amount_usd: %p\naddress of memo: %p\n", &amount_usd, memo);
    printf("purpose_len: %d\n", purpose_len);
    printf("amount_usd: %f\npurpose: %s\n", amount_usd, purpose);
    return;
}

int main()
{
    char name[] = "username";
    double amount_cny = 646.60;
    char purpose[] = "\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41\x41";
    int purpose_len = strlen(purpose);
    payment(name, amount_cny, purpose, purpose_len);
    return 0;
}
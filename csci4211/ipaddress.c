// Author Name: Matt Strapp
// Date: 2022-01-26
// x500: strap012

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int IPv4ToInt(char *ipv4, int isBigEndian) {
  unsigned int ipv4Int = 0;
  short int i = 0;
  char *chunk = strtok(ipv4, ".");
  while (chunk != NULL) {
    int ipv4Segment = atoi(chunk);
    if (ipv4Segment > 255 || ipv4Segment < 0) {
      printf("ERROR\n");
      exit(0);
    }
    ipv4Int = (isBigEndian) ? (ipv4Int << 8) | ipv4Segment
                            : (ipv4Int >> 8) + (ipv4Segment << 24);
    i++;
    chunk = strtok(NULL, ".");
  }
  if (i != 4) {
    printf("ERROR\n");
    exit(0);
  }
  return ipv4Int;
}

char *IntToIPv4(long ipv4_int, int isBigEndian) {
  if (ipv4_int > 4294967295 || ipv4_int < 0) {
    printf("ERROR\n");
    exit(0);
  }
  char *ipv4 = (char *)calloc(16, sizeof(char));
  int i = 0;
  while (i < 4) {
    int ipv4Segment = (isBigEndian) ? (ipv4_int >> (8 * (3 - i))) & 255
                                    : (ipv4_int >> (8 * i)) & 255;
    sprintf(ipv4 + strlen(ipv4), "%d", ipv4Segment);
    if (i != 3)
      sprintf(ipv4 + strlen(ipv4), ".");
    i++;
  }
  return ipv4;
}

int main(int argc, char **argv) {
  int toHuman = atoi(argv[1]);
  int isBigEndian = atoi(argv[3]);
  if (toHuman) {
    long toIpv4 = strtol(argv[2], NULL, 10);
    char *ret = IntToIPv4(toIpv4, isBigEndian);
    printf("%s\n", ret);
    free(ret);
  } else {
    unsigned int ret = IPv4ToInt(argv[2], isBigEndian);
    printf("%u\n", ret);
    return 0;
  }
}
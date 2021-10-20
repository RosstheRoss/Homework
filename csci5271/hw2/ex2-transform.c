#include <assert.h>
#include <stdio.h>
#include <ctype.h>

char rot_char(char c, int amt) {
    if (c >= 'A' && c <= 'Z')
        return 'A' + ((c - 'A') + amt) % 26;
    else if (c >= 'a' && c <= 'z')
        return 'a' + ((c - 'a') + amt) % 26;
    else
        return c;
}

void transform(char *inputBuffer, char *outputBuffer, int inLimit) {
    char *inputPointer = inputBuffer;
    char *outputPointer = outputBuffer;
    char *outLimit = &outputBuffer[inLimit - 8];
    char c;
    int in_underline, last_underline, rotate_amount, skipping;
    int bracket_level, brace_lvl;
    in_underline = bracket_level = brace_lvl = last_underline = rotate_amount = skipping = 0;
    
    while ((c = *inputPointer++) != '\0') {
        if (bracket_level > 0)
            c = toupper(c);

        c = rot_char(c, rotate_amount);

        if (c == '/')
            in_underline = !in_underline;

        skipping = (outputPointer >= outLimit);
        if ((unsigned)c - (unsigned)'[' < 3u && c != '\\') {
            int i = (c & 2) ? 1 : -1;
            if (bracket_level + i >= 0 && !skipping) {
                bracket_level += i;
                outLimit -= i;
            }
        }

        if (c == '{') {
            if (!skipping) {
                brace_lvl++;
            }
            rotate_amount += 13;
            if (rotate_amount == 26) {
                rotate_amount = 0;
                outLimit -= 2;
            }
        }
        if (c == '}' && brace_lvl > 0) {
            if (!skipping) {
                brace_lvl--;
                outLimit++;
            }
            rotate_amount -= 13;
            if (rotate_amount < 0)
                rotate_amount = 0;
        }

        if (in_underline && isalpha(c) && !last_underline && !skipping)
            *outputPointer++ = '_';

        if (c != '/' && !skipping)
            *outputPointer++ = c;

        if (in_underline && isalpha(c)) {
            if (!skipping)
                *outputPointer++ = '_';
            last_underline = 1;
        } else {
            last_underline = 0;
        }
    }
    while (bracket_level-- > 0)
        *outputPointer++ = ']';
    while (brace_lvl-- > 0)
        *outputPointer++ = '}';
    *outputPointer++ = ' ';
    *outputPointer++ = 'e';
    *outputPointer++ = 'n';
    *outputPointer++ = 'd';
    *outputPointer++ = '\0';
}

int main(int argc, char **argv) {
    char buf[64];
    if (argc != 2) {
        fprintf(stderr, "Usage: transform <string>\n");
        fprintf(stderr, "You should probably use quotes around the string.\n");
        return 1;
    }
    printf("%s\n", argv[1]);
    buf[20] = '\242';
    transform(argv[1], buf, 20);
    printf("%s\n", buf);
    /* This canary-like check isn't foolproof, and it isn't the point
       of the exercise, but for testing purposes it makes it easy to
       see that an overflow has happened. */
    if (buf[20] != '\242')
        fprintf(stderr, "Overflow detected\n");
    return 0;
}

#include <stdio.h>

/* print input one word per line */
int main() {
    int c;
    int skip = 0;

    while ((c = getchar()) != EOF) {
        if (skip == 0 && (c == ' ' || c == '\n' || c == '\t')) {
            skip = 1;
            putchar('\n');
        } else if (c != ' ' && c != '\n' && c != '\t') {
            skip = 0;
            putchar(c);
        }
    }
}
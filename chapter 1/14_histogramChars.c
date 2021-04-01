#include <stdio.h>
#define MAXLENGTH   1000

/* print histogram of word lengths in file */
int main() {
    int c;
    int length = 0;
    int inside = 0;
    int array[MAXLENGTH] = {0};

    c = getchar();
    do {
        // non-whitespace means we're inside a word
        if (c != ' ' && c != '\t' && c != '\n') {
            array[c]++;
        }
    } while ((c = getchar()) != EOF); // check after iterating so last word isn't missed

    int printing = 0;

    for (int i = 0; i < MAXLENGTH; i++) {
        // print rows descending from highest value
        if (array[i]) {
            putchar(i);
            printf("\t");
            for (int j = 0; j < array[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }
}
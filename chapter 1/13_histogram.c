#include <stdio.h>
#define MAXLENGTH   100

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
            inside = 1;
            length++;
        // whitespace while inside terminates, if not inside do nothing
        } else if (inside) {
            if (length >= MAXLENGTH) {
                array[MAXLENGTH-1]++;
            } else {
                array[length-1]++;
            }
            length = 0;
            inside = 0;
        }
    } while ((c = getchar()) != EOF); // check after iterating so last word isn't missed

    int printing = 0;

    for (int i = MAXLENGTH-1; i >= 0; i--) {
        // print rows descending from highest value
        if (array[i]) {
            printing = 1;
        }
        if (array[i] || printing) {
            printf("%d\t", i+1);
            for (int j = 0; j < array[i]; j++) {
                putchar('*');
            }
            putchar('\n');
        }
    }

    /* now let's print a vertical histogram */

    printf("\n\n");

    int maxfreq = 0;

    for (int i = 0; i < MAXLENGTH; i++) {
        if (array[i] > maxfreq) {
            maxfreq = array[i];
        }
    }

    for (int i = maxfreq; i >= 0; i--) {
        printf("%d\t ", i);
        for (int j = 0; j < MAXLENGTH; j++) { // check each length
            if (array[j] > i) { // add * if frequency matches row
                printf("* ");
            } else {
                printf("  ");
            }
        }
        putchar('\n');
    }

    printf("\t");
    for (int i = 0; i < 9; i++) {
        printf("%2d", i+1);
    }
    printf(" ... \n");
}
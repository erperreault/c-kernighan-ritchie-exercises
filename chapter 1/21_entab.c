#include <stdio.h>
#define TABSIZE 8

/* replace spaces with equivalent tabs */
int main() {
    int c, col = 0;

    while ((c = getchar()) != EOF) {
        // reset column each newline
        if (c == '\n') {
            putchar(c);
            col = 0;
        } else if (c == '\t') {
            putchar('\t');
            while (col % TABSIZE > 0) {
                col++;
            }
        } else if (c == ' ') {
            // find out how many consecutive spaces are coming up
            int counter = 1;
            while ((c = getchar()) == ' ') {
                counter++;
            }
            // add spaces up to next tabstop
            while (col % TABSIZE && counter > 0) {
                putchar(' ');
                col++;
                counter--;
            }
            // add as many tabs as possible
            while (counter > TABSIZE) {
                putchar('\t');
                col += TABSIZE;
                counter -= TABSIZE;
            }
            // add spaces until counter is exhausted
            while (counter > 0) {
                putchar(' ');
                col++;
                counter--;
            }
            // don't forget the non-space character which terminated counter loop
            putchar(c);
            col++;
        } else {
            putchar(c);
            col++;
        }
    }
}
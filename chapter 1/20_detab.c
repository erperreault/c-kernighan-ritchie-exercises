#include <stdio.h>
#define TABSIZE 4

/* replace tabs with equivalent spaces */
int main() {
    int c, col = 0;

    while ((c = getchar()) != EOF) {
        // reset column each newline
        if (c == '\n') {
            putchar(c);
            col = 0;
        } else if (c == '\t') {
            // if already on a tabstop, bump for next tabstop
            if (col % TABSIZE == 0) {
                putchar(' ');
                col++;
            }
            // add spaces until tabstop reached
            while (col % TABSIZE != 0) {
                putchar(' ');
                col++;
            }
        } else {
            putchar(c);
            col++;
        }
    }
}
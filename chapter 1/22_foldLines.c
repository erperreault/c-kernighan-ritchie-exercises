#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 10

/* fold long lines into multiple shorter lines */
int main() {
    int c, col = 0;

    while ((c = getchar()) != EOF) {
        // reset column each newline
        if (col >= MAXLINE-1 && (c!=' '&&c!='\t'&&c!='\n')) {
            putchar('\n');
            putchar(c);
            col = 0;
        } else if (c == '\n') {
            putchar(c);
            col = 0;
        } else if (c == '\t') {
            putchar('\t');
            while (col % TABSIZE > 0) {
                col++;
            }
        } else {
            putchar(c);
            col++;
        }
    }
}
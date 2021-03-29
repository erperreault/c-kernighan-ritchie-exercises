#include <stdio.h>

/* reduce all multi-spaces to one space */
/* test spaces here:                    */
int main() {
    int c;
    int skip = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' && !skip) {
            putchar(c);
            skip = 1;
        } else if (c != ' ') {
            putchar(c);
            skip = 0;
        }
    }
}
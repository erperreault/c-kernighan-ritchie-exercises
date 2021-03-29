#include <stdio.h>

/* reduce all multi-spaces to one space */
/* test characters here: \ \    \       */
int main() {
    int c;
    int skip = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\\t");
        } else if (c == '\b') {
            printf("\\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
}
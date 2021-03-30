#include <stdio.h>

/* replace tabs, backspaces, and backslashes 
in input with \t, \b, or \\              

test characters here: \ \    \           */

int main() {
    int c;
    
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

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
// tester tabs here:                                                                    

int getLine(char line[], int maxline);

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
    int c, i, j;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        if (c != '\n' && c != '\t' && c != ' ') {
            j = i; // saves index of last non-whitespace character
        }
        s[i] = c;
    }

    if (c == '\n') {
        s[j+1] = c;
        ++i;
    }

    s[j+2] = '\0';
    return i;
}

/* print the longest input line */
int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > 1) {
            printf("%s", line);
        }    
    }

    printf("\n");
    return 0; 
} 
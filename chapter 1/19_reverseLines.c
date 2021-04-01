#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

/* getReversedLine: read a line backwards into s, return length */
int getReversedLine(char s[], int lim) {
    int c, i, j;
    char original[MAXLINE];

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        original[i] = c;
    }

    // copy from original backwards into target string forwards
    for (j = i; j >= 0; j--) {
        s[(i-j)-1] = original[j];
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

/* print the longest input line */
int main() {
    int len;                /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = getReversedLine(line, MAXLINE)) > 0) {
            printf("%s", line);
    }

    printf("\n");
    return 0; 
}
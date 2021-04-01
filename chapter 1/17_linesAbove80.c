#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
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

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len >= 80) {
            printf("%s", line);
        }
    }

    printf("\n");
    return 0; 
}

// Testers:
// 198h23rc39812y5098v32750n1v85y01239485yv108957y134057vn0698-134u6-341896ubm436819u346b-13n98m
// 1-8u15nv9815ubv10985uy12348yu698n61b09843y16b0938uy6134nb813-4u6134-u4136801
// 1923805098123468-134u6b-u634189-789817-=09134=098317913847=09580938730947u3-1
#include <stdio.h>
#include <string.h>
/* Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character constants properly. 
C comments don't nest. */
// Quote demo below.
char demo[] = "This is a //demonstration that /* quotes can include */ comment symbols.";

/* naively print everything until matching quotation mark */
void put_quote(int quote) {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == quote) {
            break;
        }
    }
}

/* do nothing until newline */
void skip_line_comment() {
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        ;
    }
    putchar('\n'); // preserve newline for line comments
}

/* do nothing until encountering --> */
void skip_multi_comment() {
    int c;
    int star = 0;
    while ((c = getchar()) != EOF) {
        if (star && c == '/') {
            getchar(); // get rid of trailing newline for multi-line comments
            break;
        } else {
            star = 0;
        }

        if (c == '*') {
            star = 1;
        }
    }
}

int main() {
    int c;
    int slash = 0;

    while ((c = getchar()) != EOF) {
        if (slash) switch (c) {
            case '/' :
                skip_line_comment();
                slash = 0;
                break;
            case '*' :
                skip_multi_comment();
                slash = 0;
                break;
            default :
                putchar('/');
                putchar(c);
                slash = 0;
        }

        else switch (c) {
            case '\'' :
                putchar(c);
                put_quote('\'');    // pass ' to end at single quote
                break;
            case '"' :
                putchar(c);
                put_quote('"');     // pass " to end at double quote
                break;
            case '/' :
                slash = 1;          // enter slash state for next iteration
                break;
            default :
                putchar(c);
        }
    }
}
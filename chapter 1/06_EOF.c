#include <stdio.h>

/* verify that (getchar() != EOF) is 0 or 1 */
int main() {
    int c;

    while (c = (getchar() != EOF)) {
        printf("%d", c);
    }
    printf("%d", c);
}

#include <stdio.h>

/* print Fahrenheit-Celsius table descending*/

double fahrToCelsius(int fahr) {
    return (5.0/9.0)*(fahr-32);
}

int main() {
    int fahr;

    for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d\t%6.1f\n", fahr, fahrToCelsius(fahr));
    }
}
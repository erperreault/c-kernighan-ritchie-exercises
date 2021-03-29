#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("Celsius\t\tFahrenheit\n");
    while (celsius <= upper) {
        fahr = (celsius * (9.0/5.0)) + 32;
        printf("%3.0f\t\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
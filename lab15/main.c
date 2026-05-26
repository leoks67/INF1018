#include <stdio.h>

float foo(double a, float b);

int main(void)
{
    double a = 10.0;
    float b = 2.0;

    printf("Resultado: %.2f\n", foo(a, b));

    return 0;
}
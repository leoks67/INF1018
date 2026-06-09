#include <stdio.h>

double foo(double a, int b);

int main(void)
{
    printf("foo(2.5, 4)   = %.2f\n", foo(2.5, 4));
    printf("foo(-3.0, 5)  = %.2f\n", foo(-3.0, 5));
    printf("foo(10.0, -2) = %.2f\n", foo(10.0, -2));
    printf("foo(0.0, 7)   = %.2f\n", foo(0.0, 7));
    printf("foo(1.5, 0)   = %.2f\n", foo(1.5, 0));

    return 0;
}
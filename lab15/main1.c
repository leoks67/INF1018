#include <stdio.h>
#include <math.h>

float foo1(float a, float b);

int main(void)
{
    float a = M_PI_2;
    float b = 2.0;

    printf("Resultado: %.2f\n", foo1(a, b));

    return 0;
}
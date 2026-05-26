#include <stdio.h>
#include <math.h>

double foo2(float a, float b);

int main(void)
{
    float a = M_PI_2;
    float b = 0.0;

    printf("Resultado: %.2f\n", foo2(a, b));

    return 0;
}
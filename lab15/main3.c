#include <stdio.h>
#include <math.h>

double foo3(double *a, int n);

int main(void)
{
    double v[3];
    v[0] = 0.0;
    v[1] = M_PI_2;
    v[2] = 0.0;
    
    printf("Resultado: %.2f\n", foo3(v, 3));
    
    return 0;
}
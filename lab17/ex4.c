#include <stdio.h>

struct X1 {
    int vi;
    float vf;
};

double pack1(struct X1 *px, int n);

double foo(double a, int b)
{
    return a * (-b);
}

int main(void)
{
    struct X1 v[] =
    {
        {1, 4.0f},
        {2, 2.0f},
        {3, 1.5f}
    };

    printf("Resultado = %.2f\n", pack1(v, 3));

    return 0;
}
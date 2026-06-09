#include <stdio.h>

struct X {
    int vi;
    double vd;
    struct X *next;
};

double pack(struct X *px);

double foo(double a, int b)
{
    return a * (-b);
}

int main(void)
{
    struct X x3 = {3, 1.5, NULL};
    struct X x2 = {2, 2.0, &x3};
    struct X x1 = {1, 4.0, &x2};

    printf("Resultado = %.2f\n", pack(&x1));

    return 0;
}
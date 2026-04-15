#include <stdio.h>

void foo (int a[], int n);

int main(void)
{
    int v[] = {1, 2, 0, 3, 4, 0, 5};

    int i;
    int n = sizeof(v)/sizeof(int);

    foo(v, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>

typedef int (*funcp)(int x);

int main(void)
{
    unsigned char codigo[] =
    {
        0x55,
        0x48, 0x89, 0xE5,
        0x89, 0xF8,
        0x83, 0xC0, 0x01,
        0xC9,
        0xC3
    };

    funcp f = (funcp)codigo;
    int i;

    i = (*f)(10);

    printf("Resultado: %d\n", i);

    return 0;
}
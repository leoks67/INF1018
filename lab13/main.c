#include <stdio.h>

typedef int (*funcp)(int x);

int add(int x) {
    return x + 1;
}

int main(void)
{
    unsigned char codigo[] =
    {
        0x55,
        0x48, 0x89, 0xE5,
        0xE8, 0x00, 0x00, 0x00, 0x00,
        0xC9,
        0xC3
    };

    funcp f = (funcp)codigo;
    int i;

    long deslocamento = (unsigned char *)add - (codigo + 9);

    codigo[5] = deslocamento & 0xFF;
    codigo[6] = (deslocamento >> 8) & 0xFF;
    codigo[7] = (deslocamento >> 16) & 0xFF;
    codigo[8] = (deslocamento >> 24) & 0xFF;

    i = (*f)(10);

    printf("Resultado: %d\n", i);

    return 0;
}
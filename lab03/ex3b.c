#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
    unsigned char parte_alta = x >> 4;
    unsigned char parte_baixa = x << 4;

    return parte_baixa|parte_alta;
}

unsigned char rotate_left(unsigned char x, int n) {
    return (x << n)|(x >> (8 - n));
}

int main(void) {
    unsigned char x = 0xAB;
    unsigned char resultado;

    resultado = switch_byte(x);

    printf("Valor original: %02X\n", x);
    printf("Valor apos switch_byte: %02X\n", resultado);

    unsigned char valor = 0x61;

    printf("Testes da funcao rotate_left:\n");
    printf("rotate_left(%02X, 1) = %02X\n", valor, rotate_left(valor, 1));
    printf("rotate_left(%02X, 2) = %02X\n", valor, rotate_left(valor, 2));
    printf("rotate_left(%02X, 7) = %02X\n", valor, rotate_left(valor, 7));

    return 0;
}
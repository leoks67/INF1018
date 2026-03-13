#include <stdio.h>

unsigned char switch_byte(unsigned char x) {
    unsigned char parte_alta = x >> 4;
    unsigned char parte_baixa = x << 4;

    return parte_baixa|parte_alta;
}

int main(void) {
    unsigned char x = 0xAB;
    unsigned char resultado;

    resultado = switch_byte(x);

    printf("Valor original: %02X\n", x);
    printf("Valor apos switch_byte: %02X\n", resultado);

    return 0;
}
#include <stdio.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
    float f;
    unsigned int i;
} U;

float float2(float f) {
    U u;
    unsigned int s, e, frac;

    u.f = f;

    if (u.i == 0)
        return f;

    s = getsig(u.i);
    e = getexp(u.i);
    frac = getfrac(u.i);

    e = e + 1;

    u.i = makefloat(s, e, frac);

    return u.f;
}

int main() {
    float x = 3.5;

    printf("%f -> %f\n", x, float2(x));

    return 0;
}
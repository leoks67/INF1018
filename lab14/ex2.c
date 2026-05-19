#include <stdio.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
    float f;
    unsigned int i;
} U;

float int2float(int i)
{
    U u;
    unsigned int s = 0;
    unsigned int exp;
    unsigned int frac;
    unsigned int v;
    int msb = 0;

    if (i == 0)
        return 0.0f;

    if (i < 0) {
        s = 1;
        v = -i;
    } else {
        v = i;
    }

    while ((v >> msb) != 1)
    {
        msb++;
    }
    exp = msb + 127;

    if (msb <= 23)
    {
        frac = (v << (23 - msb)) & 0x7fffff;
    }
    else
    {
       frac = (v >> (msb - 23)) & 0x7fffff; 
    }

    u.i = makefloat(s, exp, frac);

    return u.f;
}

int main() {
   int i;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 1;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d -> %10.4f\n", i, int2float(i));
   i = 0x7fffffff;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   return 0;
}
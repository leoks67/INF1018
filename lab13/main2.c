#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

typedef int (*funcp)(int x);

int add(int x) {
    return x + 1;
}

#define PAGE_START(P) ((intptr_t)(P)&~(pagesize-1))
#define PAGE_END(P) (((intptr_t)(P)+pagesize-1)&~(pagesize-1))

/*
 * The execpage() function shall change the specified memory pages
 * permissions into executable.
 *
 * void *ptr  = pointer to start of memory buff
 * size_t len = memory buff size in bytes
 *
 * The function returns 0 if successful and -1 if any error is encountered.
 * errono may be used to diagnose the error.
 */
int execpage(void *ptr, size_t len) {
    int ret;
    const long pagesize = sysconf(_SC_PAGE_SIZE);

    if (pagesize == -1)
        return -1;

    ret = mprotect((void *)PAGE_START(ptr),
         PAGE_END((intptr_t)ptr + len) - PAGE_START(ptr),
         PROT_READ | PROT_WRITE | PROT_EXEC);

    if (ret == -1)
        return -1;

    return 0;
}

#undef PAGE_START
#undef PAGE_END

int main(void)
{
    unsigned char codigo[] =
    {
        0x55,
        0x48, 0x89, 0xE5,
        0xE9, 0x00, 0x00, 0x00, 0x00
    };

    funcp f = (funcp)codigo;
    int i;
    long deslocamento;

    execpage(codigo, sizeof(codigo));

    deslocamento = (unsigned char *)add - (codigo + 9);

    codigo[5] = deslocamento & 0xFF;
    codigo[6] = (deslocamento >> 8) & 0xFF;
    codigo[7] = (deslocamento >> 16) & 0xFF;
    codigo[8] = (deslocamento >> 24) & 0xFF;

    i = (*f)(10);

    printf("Resultado: %d\n", i);

    return 0;
}
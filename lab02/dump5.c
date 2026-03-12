#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {

  char a[] = "A";
  char espaco[] = " ";
  char novalinha[] = "\n";
  char cifrao[] = "$";

  printf("Caractere 'A':\n");
  dump(a, sizeof(a));

  printf("\nCaractere ' ' (espaco):\n");
  dump(espaco, sizeof(espaco));

  printf("\nCaractere '\\n':\n");
  dump(novalinha, sizeof(novalinha));

  printf("\nCaractere '$':\n");
  dump(cifrao, sizeof(cifrao));

  return 0;
}
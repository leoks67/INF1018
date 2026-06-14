#include <stdio.h>
#include <string.h>
#include "cria_func.h"

typedef int (*func_ptr_1) (int x);
typedef int (*func_ptr_0) ();
typedef int (*func_ptr_str) (void* candidata, size_t n);
typedef int (*func_ptr_mult) (int y);

int mult(int x, int y)
{
  return x * y;
}

int sub(int x, int y)
{
  return x - y;
}

char fixa[] = "quero saber se a outra string é um prefixo dessa";

int main(void)
{
  DescParam params[3];
  unsigned char codigo[500];

  printf("Iniciando bateria de testes (TDD)...\n\n");

  //Teste 1: Passagem de parâmetro FIX
  printf("Teste 1: mult(x, 10)\n");

  params[0].tipo_val = INT_PAR;
  params[0].orig_val = PARAM;
  params[1].tipo_val = INT_PAR;
  params[1].orig_val = FIX;
  params[1].valor.v_int = 10;

  cria_func(mult, params, 2, codigo);

  func_ptr_1 f_mult = (func_ptr_1) codigo;
  int res1 = f_mult(5);
  printf("mult(5, 10) = %d (Esperado: 50) -> %s\n", res1, res1 == 50 ? "PASSOU" : "FALHOU");

  //Teste 2: Passagem de parâmetro IND
  printf("\nTeste 2: mult(i, 10) com IND\n");

  int i = 7;
  params[0].tipo_val = INT_PAR;
  params[0].orig_val = IND;
  params[0].valor.v_ptr = &i;
  params[1].tipo_val = INT_PAR;
  params[1].orig_val = FIX;
  params[1].valor.v_int = 10;

  cria_func(mult, params, 2, codigo);
  func_ptr_0 f_mult_ind = (func_ptr_0) codigo;
  int res2 = f_mult_ind();
  printf("mult(i=7, 10) = %d (Esperado: 70) -> %s\n", res2, res2 == 70 ? "PASSOU" : "FALHOU");

  i = 8;
  res2 = f_mult_ind();
  printf("mult(i=8, 10) = %d (Esperado: 80) -> %s\n", res2, res2 == 80 ? "PASSOU" : "FALHOU");

  //Teste 3: Prefix de string com memcmp
  printf("\nTeste 3: memcmp\n");

  char s[] = "quero saber tudo";
  params[0].tipo_val = PTR_PAR;
  params[0].orig_val = FIX;
  params[0].valor.v_ptr = fixa;
  params[1].tipo_val = PTR_PAR;
  params[1].orig_val = PARAM;
  params[2].tipo_val = INT_PAR;
  params[2].orig_val = PARAM;

  cria_func(memcmp, params, 3, codigo);
  func_ptr_str mesmo_prefixo = (func_ptr_str) codigo;
  int tam = 12;
  int res3 = mesmo_prefixo(s, tam);
  printf("Prefixo tamanho 12 de '%s' (Esperado: 0 - SIM) -> res=%d %s\n", s, res3, res3 == 0 ? "PASSOU" : "FALHOU");

  // Teste 4: Inversão de Parâmetros e Conflito de Registradores
  printf("\nTeste 4: sub(10, y)\n");

  params[0].tipo_val = INT_PAR;
  params[0].orig_val = FIX;
  params[0].valor.v_int = 10;
  params[1].tipo_val = INT_PAR;
  params[1].orig_val = PARAM;

  cria_func(sub, params, 2, codigo);
  func_ptr_mult f_sub = (func_ptr_mult) codigo;

  int res4 = f_sub(4);
  printf("sub(10, 4) = %d (Esperado: 6) -> %s\n", res4, res4 == 6 ? "PASSOU" : "FALHOU");
  
  return 0;
}
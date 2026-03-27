/*
int nums[] = {10, -21, -30, 45};
int main() {
  int i, *p;
  int sum = 0;
  for (i = 0, p = nums; i != 4; i++, p++)
    sum += *p;
  printf("%d\n", sum);
  return 0;
}
*/

.data
nums:  .int  10, -21, -30, 45
Sf:  .string "%d\n"

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

  movl  $0, %ebx      /* i = 0 */
  movq  $nums, %r12   /* p = nums */
  movl  $0, %edx      /* sum = 0 */

L1:
  cmpl  $4, %ebx      /* if (i == 4) */
  je    L2

  movl  (%r12), %eax  /* eax = *p */
  addl  %eax, %edx    /* sum += *p */

  addl  $1, %ebx      /* i++ */
  addq  $4, %r12      /* p++ */
  jmp   L1

L2:
/********************************************************/
/* imprime sum (valor em edx) */
  movq    $Sf, %rdi
  movl    %edx, %esi
  call    printf
/********************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/
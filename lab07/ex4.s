/*
int nums[4] = {65, -105, 111, 34};
int main (void) {
  int i;
  int s = 0;

  for (i=0;i<4;i++)
    s = s+nums[i];

  printf ("soma = %d\n", s);

  return 0;
}
*/

.data
nums: .int 65, -105, 111, 34
Sf:   .string "soma = %d\n"

.text
.globl main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movl $0, %ebx
  movl $0, %r12d

L1:
  cmpl $4, %ebx
  je   L2

  movq $nums, %rcx
  movl %ebx, %eax
  imull $4, %eax
  addq %rax, %rcx

  movl (%rcx), %eax
  addl %eax, %r12d

  addl $1, %ebx
  jmp  L1

L2:
/********************************************************/
/* imprime resultado */
  movq  $Sf, %rdi
  movl  %r12d, %esi
  movl  $0, %eax
  call  printf
/********************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret
/***************************************************************/
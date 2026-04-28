/*
int f(int x);

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}
*/

.text
.globl map2
map2:
  pushq %rbp
  movq  %rsp, %rbp

  movl  $0, %ecx          /* i = 0 */

L1:
  cmpl  %edx, %ecx        /* i < n ? */
  jge   L2

  pushq %rdi              /* salva um */
  pushq %rsi              /* salva outro */

  movl  (%rdi,%rcx,4), %edi   /* f(um[i]) */
  call  f

  popq  %rsi              /* recupera outro */
  popq  %rdi              /* recupera um */

  movl  %eax, (%rsi,%rcx,4)   /* outro[i] = resultado */

  addl  $1, %ecx          /* i++ */
  jmp   L1

L2:
  leave
  ret
/*
struct X {
  int val1;
  int val2;
};

int f(int i, int v);

void boo (struct X *px, int n, int val) {
  while (n--) {
    px->val2 = f(px->val1, val);
    px++;
  }
}
*/

.text
.globl boo
boo:
  pushq %rbp
  movq  %rsp, %rbp

  movl  %esi, %ecx      /* ecx = n */
  movl  %edx, %r8d      /* r8d = val */

L1:
  cmpl  $0, %ecx
  je    L2

  pushq %rdi            /* salva px */

  movl  (%rdi), %edi    /* arg1 = px->val1 */
  movl  %r8d, %esi      /* arg2 = val */
  call  f

  popq  %rdi            /* recupera px */

  movl  %eax, 4(%rdi)   /* px->val2 = resultado */

  addq  $8, %rdi        /* px++ */
  subl  $1, %ecx        /* n-- */

  jmp   L1

L2:
  leave
  ret
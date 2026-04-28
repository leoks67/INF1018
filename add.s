/*
struct X {
  int val;
  struct X *next;
};

int add (struct X *x) {
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
}
*/

.text
.globl add
add:
  pushq %rbp
  movq  %rsp, %rbp

  movl  $0, %eax        /* a = 0 */

L1:
  cmpq  $0, %rdi        /* x == NULL ? */
  je    L2

  addl  (%rdi), %eax    /* a += x->val */

  movq  8(%rdi), %rdi   /* x = x->next */

  jmp   L1

L2:
  leave
  ret
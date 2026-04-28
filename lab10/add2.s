/*
struct X {
  int val;
  struct X *next;
};

int add2 (struct X *x) {
  if (x == NULL) return 0;
  else return x->val + add2(x->next);
}
*/

.text
.globl add2
add2:
  pushq %rbp
  movq  %rsp, %rbp

  cmpq  $0, %rdi        /* if (x == NULL) */
  jne   L1

  movl  $0, %eax        /* return 0 */
  jmp   L2

L1:
  pushq %rdi            /* salva x */

  movq  8(%rdi), %rdi   /* x = x->next */
  call  add2            /* add2(x->next) */

  popq  %rdi            /* recupera x */

  addl  (%rdi), %eax    /* x->val + resultado */

L2:
  leave
  ret
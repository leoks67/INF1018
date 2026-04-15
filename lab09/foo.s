/*
void foo (int a[], int n) {
  int i;
  int s = 0;
  for (i=0; i<n; i++) {
    s += a[i];
    if (a[i] == 0) {
      a[i] = s;
      s = 0;
    }
  }
}
*/

.text
.globl foo
foo:
  pushq %rbp
  movq  %rsp, %rbp

  pushq %rbx
  pushq %r12

  movl  $0, %ebx        /* i = 0 */
  movl  $0, %r12d       /* s = 0 */

L1:
  cmpl  %esi, %ebx      /* i == n ? */
  jge   L2

  movq  %rdi, %rcx      /* rcx = base de a */
  movl  %ebx, %eax
  imull $4, %eax        /* i * 4 */
  addq  %rax, %rcx      /* &a[i] */

  movl  (%rcx), %edx    /* edx = a[i] */

  addl  %edx, %r12d     /* s += a[i] */

  cmpl  $0, %edx
  jne   Lnext

  movl  %r12d, (%rcx)   /* a[i] = s */
  movl  $0, %r12d       /* s = 0 */

Lnext:
  addl  $1, %ebx        /* i++ */
  jmp   L1

L2:
  popq  %r12
  popq  %rbx
  leave
  ret
/*
double foo3 (double *a, int n) {
  int i;
  double r = 0.0;
  for (i=0; i<n; i++) {
    r += sin(*a);
    a++;
  }
  return r;
}
*/

.text
.globl foo3

foo3:
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp

    pushq %rbx
    pushq %r12

    movq %rdi, %rbx
    movl %esi, %r12d

    pxor %xmm1, %xmm1
    movsd %xmm1, -8(%rbp)
    movl $0, %ecx

L1:
    cmpl %r12d, %ecx
    jge L2

    movsd (%rbx), %xmm0
    call sin
    addsd -8(%rbp), %xmm0
    movsd %xmm0, -8(%rbp)

    addq $8, %rbx

    incl %ecx
    jmp L1

L2:
    movsd -8(%rbp), %xmm0

    popq %r12
    popq %rbx

    leave
    ret
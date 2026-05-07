/*
int bemboba (int num) {
  int local[4];
  int *a;
  int i;

  for (i=0,a=local;i<4;i++) {
    *a = num;
    a++;
  }
  return addl (local, 4);
}
*/

.text
.globl bemboba

bemboba:
    # prólogo
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp

    movl  $0, %ecx

L1:
    cmpl  $4, %ecx
    jge   L2

    movl  %edi, -16(%rbp,%rcx,4)

    addl  $1, %ecx
    jmp   L1

L2:
    leaq  -16(%rbp), %rdi
    movl  $4, %esi
    call  addl
    
    leave
    ret
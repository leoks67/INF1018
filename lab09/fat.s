/*
int fat (int n) {
  if (n==0) return 1;
  else return n*fat(n-1);
}
*/

.text
.globl fat
fat:
  pushq %rbp
  movq  %rsp, %rbp

  cmpl  $0, %edi
  jne   L1

  movl  $1, %eax
  jmp   L2

L1:
  pushq %rdi

  subl  $1, %edi
  call  fat

  popq  %rdi
  imull %edi, %eax

L2:
  leave
  ret
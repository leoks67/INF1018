/*
int add (int a, int b, int c) {
  return a+b+c;
}
*/

.text
.globl add
add:
  pushq %rbp
  movq  %rsp, %rbp

  movl  %edi, %eax
  addl  %esi, %eax
  addl  %edx, %eax

  popq  %rbp
  ret
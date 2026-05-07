/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}
*/

.data
Msg: .string "numero: "
Sf:  .string "%d"

.text
.globl novonum

novonum:
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp

    movq  $Msg, %rdi
    movl  $0, %eax
    call  printf

    movq  $Sf, %rdi
    leaq  -4(%rbp), %rsi
    movl  $0, %eax
    call  scanf

    movl  -4(%rbp), %eax

    leave
    ret
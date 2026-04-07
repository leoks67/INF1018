.data
  s1: .string "ls -ls"

  .text
  .globl main
  main:
  /* prologo */
    pushq %rbp
    movq  %rsp, %rbp

  /* coloque seu codigo aqui */
  /* chamada da funcao system */
  movq  $s1, %rdi
  call  system

  /* valor de retorno = 0 */
  movl  $0, %eax

  /* finalizacao */
    leave
    ret
/*
float foo (double a, float b) {
  return (a+b)*(a-b);
}
*/

.text
.globl foo

foo:
    pushq %rbp
    movq  %rsp, %rbp

    /*xmm0 = a (double)*/
    /*xmm1 = b (float)*/

    cvtss2sd %xmm1, %xmm1   #converte b para double
    movapd %xmm0, %xmm2
    addsd  %xmm1, %xmm2
    subsd  %xmm1, %xmm0
    mulsd  %xmm2, %xmm0
    cvtsd2ss %xmm0, %xmm0

    leave
    ret
.text
.globl foo

foo:
    pushq %rbp
    movq %rsp, %rbp

    cvtsi2sd %edi, %xmm1      # xmm1 = (double)b

    movsd menos_um(%rip), %xmm2
    mulsd %xmm2, %xmm1        # xmm1 = -b

    mulsd %xmm1, %xmm0        # xmm0 = a * (-b)

    leave
    ret

menos_um:
    .double -1.0
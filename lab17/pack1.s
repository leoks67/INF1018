.text
.globl pack1

pack1:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp

    movq %rdi, -24(%rbp)      # salva px
    movl %esi, -28(%rbp)      # salva n

    pxor %xmm2, %xmm2         # acc = 0
    movl $0, -4(%rbp)         # i = 0

L1:
    movl -4(%rbp), %eax
    cmpl -28(%rbp), %eax
    jge Lfim

    movslq %eax, %rdx
    imulq $8, %rdx, %rdx

    movq -24(%rbp), %rcx      # recupera px

    movss 4(%rcx,%rdx), %xmm0
    cvtss2sd %xmm0, %xmm0

    movl (%rcx,%rdx), %edi

    movsd %xmm2, -16(%rbp)
    call foo
    movsd -16(%rbp), %xmm2

    addsd %xmm0, %xmm2

    addl $1, -4(%rbp)
    jmp L1

Lfim:
    movsd %xmm2, %xmm0
    leave
    ret
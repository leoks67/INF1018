.text
.globl pack

pack:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    pxor %xmm2, %xmm2          # acc = 0.0

L1:
    cmpq $0, %rdi
    je Lfim

    movq %rdi, -16(%rbp)       # salva px

    movsd 8(%rdi), %xmm0       # px->vd
    movl 0(%rdi), %edi         # px->vi

    movsd %xmm2, -8(%rbp)      # salva acc
    call foo
    movsd -8(%rbp), %xmm2      # recupera acc

    addsd %xmm0, %xmm2         # acc += foo(...)

    movq -16(%rbp), %rdi       # recupera px
    movq 16(%rdi), %rdi        # px = px->next

    jmp L1

Lfim:
    movsd %xmm2, %xmm0

    leave
    ret
.text
.globl criafunc

criafunc:
    pushq   %rbp
    movq    %rsp, %rbp

    movq    %rdi, %r8
    movq    %rsi, %r9
    movq    %rdx, %r10

    movl    %r8d, %edi          
    movl    $10, %esi
    movl    (%r11), %edx        
    movabsq $0xabcdef0123456789, %rax
    call    *%rax

    movq    %rbp, %rsp
    popq    %rbp
    ret
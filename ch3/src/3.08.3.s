        .file   "main.c"
        .text
        .globl  getbuf
        .type   getbuf, @function
getbuf:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $64, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movq    -56(%rbp), %rcx
        movabsq $-3689348814741910323, %rdx
        movq    %rcx, %rax
        mulq    %rdx
        shrq    $5, %rdx
        movq    %rdx, %rax
        salq    $2, %rax
        addq    %rdx, %rax
        salq    $3, %rax
        subq    %rax, %rcx
        movq    %rcx, %rdx
        movq    %rdx, %rax
        movq    -8(%rbp), %rsi
        xorq    %fs:40, %rsi
        je      .L3
        call    __stack_chk_fail
.L3:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   getbuf, .-getbuf
        .globl  main
        .type   main, @function
main:
.LFB1:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movl    $0, %eax
        call    getbuf
        movl    $0, %eax
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE1:
        .size   main, .-main
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
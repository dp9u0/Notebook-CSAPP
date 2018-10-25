        .file   "main.c"
        .text
        .globl  createRec
        .type   createRec, @function
createRec:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $48, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movl    $1, -36(%rbp)
        movl    $10, -32(%rbp)   ; rec.i
        movl    $20, -28(%rbp)   ; rec.j
        movl    $30, -24(%rbp)   ; rec.a[0]
        movl    $40, -20(%rbp)   ; rec.a[1]
        leaq    -36(%rbp), %rax  ; &i
        movq    %rax, -16(%rbp)  ; rec.p
        nop
        movq    -8(%rbp), %rax
        xorq    %fs:40, %rax
        je      .L2
        call    __stack_chk_fail
.L2:
        leave ; movq %rbp,%rsp pop %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   createRec, .-createRec
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
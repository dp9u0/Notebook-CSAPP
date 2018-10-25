        .file   "main.c"
        .text
        .globl  proc
        .type   proc, @function
proc:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        movq    %rdi, -8(%rbp)
        movq    %rsi, -16(%rbp)
        movl    %edx, -20(%rbp)
        movq    %rcx, -32(%rbp)
        movl    %r8d, %edx
        movq    %r9, -40(%rbp)
        movl    16(%rbp), %eax
        movw    %dx, -24(%rbp)
        movb    %al, -44(%rbp)
        movq    -16(%rbp), %rax
        movq    (%rax), %rdx
        movq    -8(%rbp), %rax
        addq    %rax, %rdx
        movq    -16(%rbp), %rax
        movq    %rdx, (%rax)
        movq    -32(%rbp), %rax
        movl    (%rax), %edx
        movl    -20(%rbp), %eax
        addl    %eax, %edx
        movq    -32(%rbp), %rax
        movl    %edx, (%rax)
        movq    -40(%rbp), %rax
        movzwl  (%rax), %eax
        movl    %eax, %edx
        movzwl  -24(%rbp), %eax
        addl    %edx, %eax
        movl    %eax, %edx
        movq    -40(%rbp), %rax
        movw    %dx, (%rax)
        movq    24(%rbp), %rax
        movzbl  (%rax), %eax
        movl    %eax, %edx
        movzbl  -44(%rbp), %eax
        addl    %edx, %eax
        movl    %eax, %edx
        movq    24(%rbp), %rax
        movb    %dl, (%rax)
        nop
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   proc, .-proc
        .globl  call_proc
        .type   call_proc, @function
call_proc:
.LFB1:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        subq    $32, %rsp
        movq    %fs:40, %rax
        movq    %rax, -8(%rbp)
        xorl    %eax, %eax
        movq    $1, -16(%rbp)
        movl    $2, -20(%rbp)
        movw    $3, -22(%rbp)
        movb    $4, -23(%rbp)
        movzbl  -23(%rbp), %eax
        movsbl  %al, %edi
        movzwl  -22(%rbp), %eax
        movswl  %ax, %r10d
        movl    -20(%rbp), %edx
        movq    -16(%rbp), %rax
        leaq    -22(%rbp), %r9
        leaq    -20(%rbp), %rcx
        leaq    -16(%rbp), %rsi
        leaq    -23(%rbp), %r8
        pushq   %r8
        pushq   %rdi
        movl    %r10d, %r8d
        movq    %rax, %rdi
        call    proc
        addq    $16, %rsp
        movl    -20(%rbp), %eax
        movslq  %eax, %rdx
        movq    -16(%rbp), %rax
        leaq    (%rdx,%rax), %rcx
        movzwl  -22(%rbp), %eax
        movswl  %ax, %edx
        movzbl  -23(%rbp), %eax
        movsbl  %al, %eax
        subl    %eax, %edx
        movl    %edx, %eax
        cltq
        imulq   %rcx, %rax
        movq    -8(%rbp), %rsi
        xorq    %fs:40, %rsi
        je      .L4
        call    __stack_chk_fail
.L4:
        leave
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE1:
        .size   call_proc, .-call_proc
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
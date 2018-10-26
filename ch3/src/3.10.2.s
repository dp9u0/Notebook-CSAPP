        .file   "main.c"
        .text
        .globl  circum
        .type   circum, @function
circum:
.LFB45:
        .cfi_startproc
        vmulsd  .LC0(%rip), %xmm0, %xmm0
        ret
        .cfi_endproc
.LFE45:
        .size   circum, .-circum
        .globl  area
        .type   area, @function
area:
.LFB46:
        .cfi_startproc
        vmulsd  .LC1(%rip), %xmm0, %xmm1
        vmulsd  %xmm0, %xmm1, %xmm0
        ret
        .cfi_endproc
.LFE46:
        .size   area, .-area
        .globl  cel2fahr
        .type   cel2fahr, @function
cel2fahr:
.LFB47:
        .cfi_startproc
        vmulsd  .LC2(%rip), %xmm0, %xmm0
        vaddsd  .LC3(%rip), %xmm0, %xmm0
        ret
        .cfi_endproc
.LFE47:
        .size   cel2fahr, .-cel2fahr
        .section        .rodata.str1.1,"aMS",@progbits,1
.LC5:
        .string "lo = %u (0x%x)\n"
.LC6:
        .string "hi = %u (0x%x)\n"
.LC7:
        .string "exp = %d (0x%x)\n"
.LC8:
        .string "hi_frac = %d (0x%x)\n"
.LC9:
        .string "frac = %lu (0x%lx)\n"
.LC10:
        .string "frac_val = %.15g\n"
.LC11:
        .string "val = %.15g\n"
        .text
        .globl  decode
        .type   decode, @function
decode:
.LFB48:
        .cfi_startproc
        pushq   %r13
        .cfi_def_cfa_offset 16
        .cfi_offset 13, -16
        pushq   %r12
        .cfi_def_cfa_offset 24
        .cfi_offset 12, -24
        pushq   %rbp
        .cfi_def_cfa_offset 32
        .cfi_offset 6, -32
        pushq   %rbx
        .cfi_def_cfa_offset 40
        .cfi_offset 3, -40
        subq    $24, %rsp
        .cfi_def_cfa_offset 64
        movl    %edi, %edx
        movl    %esi, %ebp
        movl    %esi, %ebx
        shrl    $20, %ebx
        movl    %esi, %r13d
        andl    $1048575, %r13d
        movq    %r13, %rcx
        salq    $32, %rcx
        movabsq $4503599627370496, %rax
        addq    %rcx, %rax
        movl    %edi, %ecx
        leaq    (%rax,%rcx), %r12
        vxorpd  %xmm0, %xmm0, %xmm0
        vcvtsi2sdq      %r12, %xmm0, %xmm0
        vmulsd  .LC4(%rip), %xmm0, %xmm1
        vmovsd  %xmm1, 8(%rsp)
        movl    %edi, %ecx
        movl    $.LC5, %esi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk
        movl    %ebp, %ecx
        movl    %ebp, %edx
        movl    $.LC6, %esi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk
        movl    %ebx, %ecx
        movl    %ebx, %edx
        movl    $.LC7, %esi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk
        movl    %r13d, %ecx
        movl    %r13d, %edx
        movl    $.LC8, %esi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk
        movq    %r12, %rcx
        movq    %r12, %rdx
        movl    $.LC9, %esi
        movl    $1, %edi
        movl    $0, %eax
        call    __printf_chk
        vmovsd  8(%rsp), %xmm0
        movl    $.LC10, %esi
        movl    $1, %edi
        movl    $1, %eax
        call    __printf_chk
        leal    -1023(%rbx), %ecx
        movl    $1, %eax
        sall    %cl, %eax
        vxorpd  %xmm0, %xmm0, %xmm0
        vcvtsi2sd       %eax, %xmm0, %xmm0
        vmulsd  8(%rsp), %xmm0, %xmm0
        movl    $.LC11, %esi
        movl    $1, %edi
        movl    $1, %eax
        call    __printf_chk
        addq    $24, %rsp
        .cfi_def_cfa_offset 40
        popq    %rbx
        .cfi_def_cfa_offset 32
        popq    %rbp
        .cfi_def_cfa_offset 24
        popq    %r12
        .cfi_def_cfa_offset 16
        popq    %r13
        .cfi_def_cfa_offset 8
        ret
        .cfi_endproc
.LFE48:
        .size   decode, .-decode
        .globl  main
        .type   main, @function
main:
.LFB49:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        pushq   %rbx
        .cfi_def_cfa_offset 24
        .cfi_offset 3, -24
        subq    $8, %rsp
        .cfi_def_cfa_offset 32
        movq    %rsi, %rbp
        movl    $1074340347, %esi
        movl    $1413754136, %ebx
        cmpl    $3, %edi
        jne     .L9
        movq    8(%rbp), %rdi
        movl    $0, %edx
        movl    $0, %esi
        call    strtoul
        movl    %eax, %ebx
        movq    16(%rbp), %rdi
        movl    $0, %edx
        movl    $0, %esi
        call    strtoul
        movl    %eax, %esi
.L9:
        movl    %ebx, %edi
        call    decode
        movl    $0, %eax
        addq    $8, %rsp
        .cfi_def_cfa_offset 24
        popq    %rbx
        .cfi_def_cfa_offset 16
        popq    %rbp
        .cfi_def_cfa_offset 8
        ret
        .cfi_endproc
.LFE49:
        .size   main, .-main
        .section        .rodata.cst8,"aM",@progbits,8
        .align 8
.LC0:
        .long   1413754136
        .long   1075388923
        .align 8
.LC1:
        .long   1413754136
        .long   1074340347
        .align 8
.LC2:
        .long   3435973837
        .long   1073532108
        .align 8
.LC3:
        .long   0
        .long   1077936128
        .align 8
.LC4:
        .long   0
        .long   1018167296
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
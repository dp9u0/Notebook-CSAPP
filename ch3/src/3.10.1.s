        ; gcc -O1 -S -mavx2 main.c && cat main.s
        .file   "main.c"
        .text
        .globl  float_mov
        .type   float_mov, @function
float_mov:
.LFB0:
        .cfi_startproc
        vmovss  (%rdi), %xmm1
        vmovss  %xmm0, (%rsi)
        vmovaps %xmm1, %xmm0
        ret
        .cfi_endproc
.LFE0:
        .size   float_mov, .-float_mov
        .ident  "GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
        .section        .note.GNU-stack,"",@progbits
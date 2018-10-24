	.file	"3.06.3.c"
	.text
	.globl	swap_add
	.def	swap_add;	.scl	2;	.type	32;	.endef
	.seh_proc	swap_add
swap_add:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movq	16(%rbp), %rax
	movl	-8(%rbp), %edx
	movl	%edx, (%rax)
	movq	24(%rbp), %rax
	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	movl	-4(%rbp), %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	caller
	.def	caller;	.scl	2;	.type	32;	.endef
	.seh_proc	caller
caller:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	$534, -12(%rbp) 
	.args1 赋值 -> 栈 -12(%rbp) 
	movl	$1057, -16(%rbp)
	.args2 赋值 -> 栈 -16(%rbp)
	leaq	-16(%rbp), %rdx
	.args2  参数地址 -> %rdx
	leaq	-12(%rbp), %rax
	movq	%rax, %rcx
	.args2  参数地址 -> 第一个参数
	call	swap_add
	movl	%eax, -4(%rbp) 
	. result -> 栈 -4(%rbp) 
	movl	-12(%rbp), %edx 
	. args1 -> %edx
	movl	-16(%rbp), %eax
	. args2 -> %eax
	subl	%eax, %edx
	. 计算 diff = args1 + args2 -> %edx
	movl	%edx, %eax
	. diff -> %eax
	movl	%eax, -8(%rbp)
	. diff -> 栈 -8(%rbp)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	.%rax = sum * diff 
	addq	$48, %rsp 
	.释放申请的堆栈 48 bytes
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"

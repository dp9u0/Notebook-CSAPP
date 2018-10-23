	.file	"3.05.1.c"
	.text
	.p2align 4,,15
	.globl	rand
	.def	rand;	.scl	2;	.type	32;	.endef
	.seh_proc	rand
rand:
	.seh_endprologue
	imull	$1103515245, next(%rip), %eax
	addl	$12345, %eax
	movl	%eax, next(%rip)
	shrl	$16, %eax
	andl	$32767, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	srand
	.def	srand;	.scl	2;	.type	32;	.endef
	.seh_proc	srand
srand:
	.seh_endprologue
	movl	%ecx, next(%rip)
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	init_seed
	.def	init_seed;	.scl	2;	.type	32;	.endef
	.seh_proc	init_seed
init_seed:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	xorl	%ecx, %ecx
	call	*__imp__time64(%rip)
	movl	%eax, next(%rip)
	addq	$40, %rsp
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	random_int
	.def	random_int;	.scl	2;	.type	32;	.endef
	.seh_proc	random_int
random_int:
	.seh_endprologue
	movl	next(%rip), %edx
	movl	$32, %r8d
	xorl	%eax, %eax
	.p2align 4,,10
.L6:
	imull	$1103515245, %edx, %edx
	addl	$12345, %edx
	movl	%edx, %ecx
	shrl	$16, %ecx
	andl	$1, %ecx
	orl	%ecx, %eax
	addl	%eax, %eax
	subl	$1, %r8d
	jne	.L6
	movl	%edx, next(%rip)
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	absdiff
	.def	absdiff;	.scl	2;	.type	32;	.endef
	.seh_proc	absdiff
absdiff:
	.seh_endprologue
	movl	%edx, %r8d
	movl	%ecx, %eax
	subl	%ecx, %r8d
	subl	%edx, %eax
	cmpl	%edx, %ecx
	cmovl	%r8d, %eax
	ret
	.seh_endproc
	.p2align 4,,15
	.globl	cmovdiff
	.def	cmovdiff;	.scl	2;	.type	32;	.endef
	.seh_proc	cmovdiff
cmovdiff:
	.seh_endprologue
	movl	%edx, %r8d
	movl	%ecx, %eax
	subl	%ecx, %r8d
	subl	%edx, %eax
	cmpl	%edx, %ecx
	cmovl	%r8d, %eax
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	call	__main
	xorl	%ecx, %ecx
	call	*__imp__time64(%rip)
	movl	%eax, next(%rip)
	xorl	%eax, %eax
	addq	$40, %rsp
	ret
	.seh_endproc
	.data
	.align 4
next:
	.long	1
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"

	.text
	.globl	z
	.bss
	.align 4
	.type	z, @object
	.size	z, 4
z:
	.zero	4
	Passou GLOBAL_DECL
	.globl	k
	.align 4
	.type	z, @object
	.size	k, 4
k:
	.zero	4
	Passou GLOBAL_DECL
	.text
	.globl main
	.type main, @function
main:
	pushq 	%rbp
	movq 	%rsp, %rbp
	subq 	$40, %rsp
	Passou VARIABLE
	Passou VARIABLE
	Passou VARIABLE
	Passou VARIABLE
	movl $9, %eax
	Passou LITERAL
	movl $4, %eax
	Passou LITERAL
	Passou VARIABLE
	Passou VARIABLE
	movl	0(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	Passou VARIABLE

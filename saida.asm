	.text
	.globl	z
	.bss
	.align 4
	.type	z, @object
	.size	z, 4
z:
	.zero	4
	Passou GLOBAL_DECL z
	.globl	k
	.align 4
	.type	z, @object
	.size	k, 4
k:
	.zero	4
	Passou GLOBAL_DECL k
	.text
	.globl main
	.type main, @function
main:
	pushq 	%rbp
	movq 	%rsp, %rbp
	subq 	$40, %rsp
	Passou VARIABLE d, desl -4
	Passou VARIABLE c, desl -8
	Passou VARIABLE b, desl -12
	Passou VARIABLE a, desl -16
	movl $9, %eax
	Passou LITERAL 9
	movl $4, %eax
	Passou LITERAL 4
	Passou OPERAND z, desl 0
	Passou OPERAND b, desl 0
	movl	0(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	Passou OPERAND b, desl 0

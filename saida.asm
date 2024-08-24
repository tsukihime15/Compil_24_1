	.text
	.globl	z
	.bss
	.align 4
	.type	z, @object
	.size	z, 4
z:
	.zero	4
	.globl	k
	.align 4
	.type	z, @object
	.size	k, 4
k:
	.zero	4
	.text
	.globl main
	.type main, @function
main:
.LFB0:
	pushq 	%rbp
	movq 	%rsp, %rbp
	subq 	$40, %rsp

# CODIGO DO RETURN
	movq	%rbp, %rsp
	popq	%rbp
	ret

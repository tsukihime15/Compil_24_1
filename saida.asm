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
	movl d(%rip), %eax 
# Passou VARIABLE d, desl -4
	movl c(%rip), %eax 
# Passou VARIABLE c, desl -8
	movl b(%rip), %eax 
# Passou VARIABLE b, desl -12
	movl a(%rip), %eax 
# Passou VARIABLE a, desl -16
	movl $9, %eax 
	movl $4, %eax 
	movl 0(%rip), %eax 
	push %eax
	movl 0(%rip), %eax 
	pop %ecx
	addl %ecx, %eax
# Passou OPERAND z, desl 0
# Passou OPERAND b, desl 0
	movl	0(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
# Passou OPERAND b, desl 0

.file   "main.c"
	.text
	.globl  main
	.type   main, @function
main:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $32, %rsp
1
	movq    %rbp, %rsp
	popq    %rbp
	ret

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int mmult_asm(double *c, 
	  double *a, int aRows, int aCols, 
	  double *b, int bRows, int bCols) {

  int i, j, k;

/* original C code
  for (i = 0; i < aRows; i++)
    for (j = 0; j < bCols; j++) {
	c[i*bCols + j] = 0;
	for (k = 0; k < aCols; k++)
		c[i*bCols + j] += a[i*aCols + k] * b[k*bCols + j];
	}
  return 0;
*/

/* original assembly code
	.file	"mmult_asm.c"
	.text
	.globl	mmult_asm
	.type	mmult_asm, @function
mmult_asm:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -36(%rbp)
	movl	%ecx, -40(%rbp)
	movq	%r8, -48(%rbp)
	movl	%r9d, -52(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L7:
	movl	$0, -8(%rbp)
	jmp	.L3
.L6:
	movl	-12(%rbp), %eax
	imull	16(%rbp), %eax
	movl	%eax, %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	pxor	%xmm0, %xmm0
	movsd	%xmm0, (%rax)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-12(%rbp), %eax
	imull	16(%rbp), %eax
	movl	%eax, %edx
	movl	-8(%rbp), %eax
	addl	%edx, %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-12(%rbp), %eax
	imull	16(%rbp), %eax
	movl	%eax, %ecx
	movl	-8(%rbp), %eax
	addl	%ecx, %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movsd	(%rax), %xmm1
	movl	-12(%rbp), %eax
	imull	-40(%rbp), %eax
	movl	%eax, %ecx
	movl	-4(%rbp), %eax
	addl	%ecx, %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-32(%rbp), %rax
	addq	%rcx, %rax
	movsd	(%rax), %xmm2
	movl	-4(%rbp), %eax
	imull	16(%rbp), %eax
	movl	%eax, %ecx
	movl	-8(%rbp), %eax
	addl	%ecx, %eax
	cltq
	leaq	0(,%rax,8), %rcx
	movq	-48(%rbp), %rax
	addq	%rcx, %rax
	movsd	(%rax), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, (%rdx)
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	-40(%rbp), %eax
	jl	.L5
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	16(%rbp), %eax
	jl	.L6
	addl	$1, -12(%rbp)
.L2:
	movl	-12(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	.L7
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	mmult_asm, .-mmult_asm
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
*/


__asm__ ("pushq	%rbp\n\t"
	"movq	%rsp, %rbp\n\t"
	"movq	%rdi, -24(%rbp)\n\t"
	"movq	%rsi, -32(%rbp)\n\t"
	"movl	%edx, -36(%rbp)\n\t"
	"movl	%ecx, -40(%rbp)\n\t"
	"movq	%r8, -48(%rbp)\n\t"
	"movl	%r9d, -52(%rbp)\n\t"
	"movl	$0, -12(%rbp)\n\t"
	"jmp	.L2\n\t"
".L7:\n\t"
	"movl	$0, -8(%rbp)\n\t"
	"jmp	.L3\n\t"
".L6:\n\t"
	"movl	-12(%rbp), %eax\n\t"
	"imull	16(%rbp), %eax\n\t"
	"movl	%eax, %edx\n\t"
	"movl	-8(%rbp), %eax\n\t"
	"addl	%edx, %eax\n\t"
	"cltq\n\t"
	"leaq	0(,%rax,8), %rdx\n\t"
	"movq	-24(%rbp), %rax\n\t"
	"addq	%rdx, %rax\n\t"
	"pxor	%xmm0, %xmm0\n\t"
	"movsd	%xmm0, (%rax)\n\t"
	"movl	$0, -4(%rbp)\n\t"
	"jmp	.L4\n\t"
".L5:\n\t"
	"movl	-12(%rbp), %eax\n\t"
	"imull	16(%rbp), %eax\n\t"
	"movl	%eax, %edx\n\t"
	"movl	-8(%rbp), %eax\n\t"
	"addl	%edx, %eax\n\t"
	"cltq\n\t"
	"leaq	0(,%rax,8), %rdx\n\t"
	"movq	-24(%rbp), %rax\n\t"
	"addq	%rax, %rdx\n\t"
	"movl	-12(%rbp), %eax\n\t"
	"imull	16(%rbp), %eax\n\t"
	"movl	%eax, %ecx\n\t"
	"movl	-8(%rbp), %eax\n\t"
	"addl	%ecx, %eax\n\t"
	"cltq\n\t"
	"leaq	0(,%rax,8), %rcx\n\t"
	"movq	-24(%rbp), %rax\n\t"
	"addq	%rcx, %rax\n\t"
	"movsd	(%rax), %xmm1\n\t"
	"movl	-12(%rbp), %eax\n\t"
	"imull	-40(%rbp), %eax\n\t"
	"movl	%eax, %ecx\n\t"
	"movl	-4(%rbp), %eax\n\t"
	"addl	%ecx, %eax\n\t"
	"cltq\n\t"
	"leaq	0(,%rax,8), %rcx\n\t"
	"movq	-32(%rbp), %rax\n\t"
	"addq	%rcx, %rax\n\t"
	"movsd	(%rax), %xmm2\n\t"
	"movl	-4(%rbp), %eax\n\t"
	"imull	16(%rbp), %eax\n\t"
	"movl	%eax, %ecx\n\t"
	"movl	-8(%rbp), %eax\n\t"
	"addl	%ecx, %eax\n\t"
	"cltq\n\t"
	"leaq	0(,%rax,8), %rcx\n\t"
	"movq	-48(%rbp), %rax\n\t"
	"addq	%rcx, %rax\n\t"
	"movsd	(%rax), %xmm0\n\t"
	"mulsd	%xmm2, %xmm0\n\t"
	"addsd	%xmm1, %xmm0\n\t"
	"movsd	%xmm0, (%rdx)\n\t"
	"addl	$1, -4(%rbp)\n\t"
".L4:\n\t"
	"movl	-4(%rbp), %eax\n\t"
	"cmpl	-40(%rbp), %eax\n\t"
	"jl	.L5\n\t"
	"addl	$1, -8(%rbp)\n\t"
".L3:\n\t"
	"movl	-8(%rbp), %eax\n\t"
	"cmpl	16(%rbp), %eax\n\t"
	"jl	.L6\n\t"
	"addl	$1, -12(%rbp)\n\t"
".L2:\n\t"
	"movl	-12(%rbp), %eax\n\t"
	"cmpl	-36(%rbp), %eax\n\t"
	"jl	.L7\n\t"
	"movl	$0, %eax\n\t"
	"popq	%rbp\n\t"
	"ret");


}



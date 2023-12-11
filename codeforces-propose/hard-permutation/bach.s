	.file	"bach.cpp"
	.text
	.align 2
	.p2align 4
	.type	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0, @function
_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0:
.LFB4260:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movslq	%ecx, %rax
	addl	%ecx, %ecx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	%edx, %r14d
	movl	%ecx, %edx
	movslq	%ecx, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	orl	$1, %edx
	movl	%r9d, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movslq	%edx, %r10
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	(%rax,%rax,2), %rbx
	salq	$5, %rbx
	addq	%rdi, %rbx
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movl	4(%rbx), %edi
	movl	%edx, 4(%rsp)
	cmpl	24(%rbx), %edi
	je	.L48
.L2:
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movl	44(%rax), %edi
	cmpl	64(%rax), %edi
	je	.L49
.L3:
	leal	(%rsi,%r14), %r12d
	sarl	%r12d
	cmpl	%r13d, %esi
	jg	.L4
	cmpl	%r8d, %r12d
	jl	.L4
	cmpl	%r8d, %esi
	jl	.L5
	cmpl	%r13d, %r12d
	jg	.L5
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	192(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	200(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
.L4:
	leal	1(%r12), %esi
	cmpl	%esi, %r13d
	jl	.L6
	cmpl	%r8d, %r14d
	jl	.L6
	cmpl	%esi, %r8d
	jg	.L7
	cmpl	%r13d, %r14d
	jg	.L7
	leaq	(%r10,%r10,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	192(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	200(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
.L6:
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movl	4(%rax), %esi
	movl	8(%rax), %ecx
	movl	12(%rax), %edi
	movl	20(%rax), %r11d
	movl	24(%rax), %edx
	movl	28(%rax), %r9d
	movl	%esi, 72(%rsp)
	movq	(%rax), %rsi
	movl	32(%rax), %r12d
	movl	%ecx, 24(%rsp)
	movl	44(%rax), %ecx
	movslq	36(%rax), %r14
	movl	%edi, 36(%rsp)
	movq	40(%rax), %rdi
	movl	60(%rax), %r8d
	movq	%rsi, 40(%rsp)
	movl	16(%rax), %esi
	movl	64(%rax), %r15d
	movl	%ecx, 76(%rsp)
	movl	52(%rax), %ecx
	movslq	76(%rax), %r13
	movq	%rdi, 48(%rsp)
	movl	56(%rax), %edi
	movl	%esi, 56(%rsp)
	movl	%ecx, 32(%rsp)
	movl	48(%rax), %esi
	movl	72(%rax), %ecx
	movl	%edi, 60(%rsp)
	movzbl	80(%rax), %edi
	movl	%esi, 28(%rsp)
	movl	%ecx, 4(%rsp)
	movl	68(%rax), %esi
	movb	%dil, 8(%rsp)
	leaq	(%r10,%r10,2), %rdi
	movzbl	81(%rax), %ecx
	salq	$5, %rdi
	movq	88(%rax), %rax
	addq	%rdi, %rbp
	movb	%cl, 16(%rsp)
	movl	0(%rbp), %edi
	testl	%edi, %edi
	je	.L8
	movl	24(%rbp), %r10d
	movl	4(%rbp), %ecx
	addq	88(%rbp), %rax
	movl	%r10d, 80(%rsp)
	movl	28(%rbp), %r10d
	movl	%ecx, 104(%rsp)
	movl	%r10d, 64(%rsp)
	movl	32(%rbp), %r10d
	movq	%rax, 96(%rsp)
	movl	%r10d, 84(%rsp)
	movl	44(%rbp), %r10d
	movl	%r10d, 68(%rsp)
	cmpl	%ecx, %edx
	je	.L50
	movb	$0, 8(%rsp)
.L9:
	movl	60(%rbp), %edi
	movl	20(%rbp), %r11d
	movl	36(%rbp), %r14d
	movl	64(%rbp), %edx
	movl	%edi, 88(%rsp)
	movl	72(%rbp), %edi
	movl	68(%rbp), %r9d
	movl	%edi, 72(%rsp)
	movl	76(%rbp), %edi
	movl	%edi, 96(%rsp)
	cmpl	68(%rsp), %r15d
	je	.L51
	movb	$0, 16(%rsp)
.L15:
	movl	72(%rsp), %esi
	movl	%edx, %r15d
	movl	96(%rsp), %r13d
	movl	88(%rsp), %r8d
	movl	84(%rsp), %r12d
	movl	%esi, 4(%rsp)
	movl	80(%rsp), %edx
	movl	%r9d, %esi
	movl	64(%rsp), %r9d
.L8:
	movq	40(%rsp), %rdi
	movl	24(%rsp), %ecx
	movl	%esi, 68(%rbx)
	movl	4(%rsp), %esi
	movl	%edx, 24(%rbx)
	movq	%rdi, (%rbx)
	movq	48(%rsp), %rdx
	movl	%ecx, 8(%rbx)
	movl	36(%rsp), %edi
	movl	%esi, 72(%rbx)
	movl	56(%rsp), %ecx
	movzbl	8(%rsp), %esi
	movl	%edi, 12(%rbx)
	movl	%ecx, 16(%rbx)
	movl	28(%rsp), %edi
	movq	%rdx, 40(%rbx)
	movl	32(%rsp), %ecx
	movb	%sil, 80(%rbx)
	movl	60(%rsp), %edx
	movzbl	16(%rsp), %esi
	movl	%r12d, 32(%rbx)
	movl	%r14d, 36(%rbx)
	movl	%r15d, 64(%rbx)
	movl	%r13d, 76(%rbx)
	movl	%r11d, 20(%rbx)
	movl	%r9d, 28(%rbx)
	movl	%edi, 48(%rbx)
	movl	%ecx, 52(%rbx)
	movl	%edx, 56(%rbx)
	movl	%r8d, 60(%rbx)
	movb	%sil, 81(%rbx)
	movq	%rax, 88(%rbx)
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	.cfi_restore_state
	movl	200(%rsp), %eax
	movl	%r14d, %edx
	movl	%r13d, %r9d
	movq	%rbp, %rdi
	movq	%r10, 8(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 200
	movl	200(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	20(%rsp), %ecx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 200
	popq	%rdx
	.cfi_def_cfa_offset 192
	movq	8(%rsp), %r10
	jmp	.L6
	.p2align 4,,10
	.p2align 3
.L5:
	movl	200(%rsp), %eax
	movl	%r13d, %r9d
	movl	%r12d, %edx
	movq	%rbp, %rdi
	movq	%r10, 16(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 200
	movl	200(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	%r8d, 24(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 200
	popq	%rsi
	.cfi_def_cfa_offset 192
	movq	16(%rsp), %r10
	movl	8(%rsp), %r8d
	jmp	.L4
	.p2align 4,,10
	.p2align 3
.L49:
	leaq	(%r15,%r15,2), %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	cmpl	44(%rdx), %edi
	je	.L3
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %r12
	movslq	56(%rax), %r11
	movl	%edi, 64(%rdx)
	imulq	%r9, %r12
	movq	%r9, 8(%rsp)
	movq	88(%rdx), %r9
	movl	%r11d, 76(%rdx)
	movl	%r11d, 56(%rdx)
	imulq	8(%rsp), %r11
	subq	%r12, %r9
	movl	%edi, 44(%rdx)
	movslq	56(%rax), %rdi
	addq	%r9, %r11
	movq	%r11, 88(%rdx)
	movl	44(%rax), %r11d
	leaq	(%r10,%r10,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%edi, 76(%rax)
	movq	88(%rax), %r12
	movl	%edi, 56(%rax)
	imulq	%rdx, %r9
	movl	%r11d, 64(%rax)
	imulq	%rdx, %rdi
	movl	%r11d, 44(%rax)
	subq	%r9, %r12
	movq	%r12, %r9
	addq	%rdi, %r9
	movq	%r9, 88(%rax)
	jmp	.L3
	.p2align 4,,10
	.p2align 3
.L48:
	leaq	(%r15,%r15,2), %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	cmpl	4(%rdx), %edi
	je	.L2
	movslq	8(%rdx), %r9
	movslq	16(%rdx), %r12
	movslq	16(%rbx), %r11
	movl	%edi, 24(%rdx)
	imulq	%r9, %r12
	movq	%r9, 8(%rsp)
	movq	88(%rdx), %r9
	movl	%r11d, 16(%rdx)
	movl	%r11d, 36(%rdx)
	imulq	8(%rsp), %r11
	subq	%r12, %r9
	movl	%edi, 4(%rdx)
	addq	%r9, %r11
	movslq	16(%rbx), %r9
	movq	%r11, 88(%rdx)
	leaq	(%r10,%r10,2), %rdx
	movl	4(%rbx), %r12d
	salq	$5, %rdx
	addq	%rbp, %rdx
	movslq	8(%rdx), %rdi
	movslq	16(%rdx), %r11
	movl	%r9d, 36(%rdx)
	movl	%r9d, 16(%rdx)
	imulq	%rdi, %r11
	movq	%rdi, 8(%rsp)
	movq	88(%rdx), %rdi
	imulq	8(%rsp), %r9
	movl	%r12d, 24(%rdx)
	movl	%r12d, 4(%rdx)
	subq	%r11, %rdi
	addq	%rdi, %r9
	movq	%r9, 88(%rdx)
	jmp	.L2
	.p2align 4,,10
	.p2align 3
.L50:
	movl	12(%rbp), %eax
	leaq	_ZN11Solve_merge6SparseE(%rip), %r10
	movl	%eax, 120(%rsp)
	movzbl	80(%rbp), %eax
	movb	%al, 127(%rsp)
	movl	%edi, %eax
	subl	%r11d, %eax
	cltq
	movl	100001000(%r10,%rax,4), %ecx
	movl	$1, %eax
	movl	%ecx, 88(%rsp)
	sall	%cl, %eax
	movl	%edi, %ecx
	subl	%eax, %ecx
	movslq	%ecx, %rax
	movslq	88(%rsp), %rcx
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rcx, %rax
	movq	%rax, 88(%rsp)
	movslq	%r11d, %rax
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rax, %rcx
	movl	(%r10,%rcx,4), %eax
	movq	%rcx, 112(%rsp)
	movq	88(%rsp), %rcx
	cmpl	%eax, (%r10,%rcx,4)
	cmovle	(%r10,%rcx,4), %eax
	movl	%r9d, %ecx
	cmpl	8(%rbp), %r9d
	cmovl	8(%rbp), %ecx
	addl	8(%rbp), %r9d
	movslq	%r9d, %r9
	movl	%ecx, 108(%rsp)
	movq	96(%rsp), %rcx
	imulq	%r14, %r9
	subq	%r9, %rcx
	movq	%rcx, 96(%rsp)
	movq	88(%rsp), %rcx
	movl	50000500(%r10,%rcx,4), %r9d
	movq	112(%rsp), %rcx
	cmpl	%r9d, 50000500(%r10,%rcx,4)
	cmovge	50000500(%r10,%rcx,4), %r9d
	subl	%r11d, %edi
	movl	68(%rsp), %ecx
	subl	%eax, %r9d
	addl	$1, %ecx
	addl	$1, %r9d
	cmpl	%eax, %ecx
	je	.L52
	cmpl	%edi, %r9d
	je	.L53
.L24:
	movb	$0, 8(%rsp)
.L11:
	movslq	108(%rsp), %rax
	movl	80(%rsp), %ecx
	movq	%rax, %rdi
	imulq	%r14, %rax
	addq	96(%rsp), %rax
	cmpl	%edx, 72(%rsp)
	movl	24(%rsp), %edx
	cmove	%edi, %edx
	cmpl	%ecx, 104(%rsp)
	cmovne	64(%rsp), %edi
	movl	%edx, 24(%rsp)
	movl	%edi, 64(%rsp)
	jmp	.L9
	.p2align 4,,10
	.p2align 3
.L51:
	movl	40(%rbp), %r10d
	movl	48(%rbp), %ecx
	movl	52(%rbp), %edi
	movl	%ecx, 108(%rsp)
	movl	%r10d, %ecx
	movl	%r10d, %r12d
	movl	%edi, 120(%rsp)
	movzbl	81(%rbp), %edi
	subl	%r8d, %ecx
	movl	$1, %ebp
	movslq	%ecx, %rcx
	movl	%r10d, 112(%rsp)
	movslq	%r8d, %r10
	movb	%dil, 127(%rsp)
	leaq	_ZN11Solve_merge6SparseE(%rip), %rdi
	leaq	(%r10,%r10,4), %r10
	movslq	100001000(%rdi,%rcx,4), %rcx
	sall	%cl, %ebp
	subl	%ebp, %r12d
	leaq	(%r10,%r10,4), %rbp
	movslq	%r12d, %r10
	movl	108(%rsp), %r12d
	addq	%rcx, %rbp
	leaq	(%r10,%r10,4), %r10
	leaq	(%r10,%r10,4), %r10
	addq	%rcx, %r10
	movl	50000500(%rdi,%r10,4), %ecx
	cmpl	%ecx, 50000500(%rdi,%rbp,4)
	cmovge	50000500(%rdi,%rbp,4), %ecx
	cmpl	%r12d, %esi
	cmovge	%esi, %r12d
	addl	108(%rsp), %esi
	movslq	%esi, %rsi
	imulq	%r13, %rsi
	subq	%rsi, %rax
	movq	%rax, %rsi
	movl	(%rdi,%rbp,4), %eax
	cmpl	%eax, (%rdi,%r10,4)
	cmovle	(%rdi,%r10,4), %eax
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	movl	112(%rsp), %edi
	addl	$1, %eax
	subl	%r8d, %edi
	movl	104(%rsp), %r8d
	subl	$1, %r8d
	cmpl	%r8d, %ecx
	je	.L54
	cmpl	%edi, %eax
	je	.L55
.L28:
	movb	$0, 16(%rsp)
.L17:
	movslq	%r12d, %rax
	imulq	%rax, %r13
	cmpl	%r15d, 76(%rsp)
	leaq	0(%r13,%rsi), %rax
	movl	28(%rsp), %esi
	cmove	%r12d, %esi
	cmpl	%edx, 68(%rsp)
	cmove	%r12d, %r9d
	movl	%esi, 28(%rsp)
	jmp	.L15
	.p2align 4,,10
	.p2align 3
.L52:
	cmpl	%edi, %r9d
	jne	.L24
	movzbl	8(%rsp), %ecx
	movzbl	127(%rsp), %edi
	movl	$0, %eax
	movl	120(%rsp), %r11d
	movl	108(%rsp), %r10d
	testb	%cl, %cl
	cmovne	%edi, %eax
	movb	%al, 8(%rsp)
	leal	(%r12,%r11), %eax
	cmpl	%eax, %r10d
	cmovge	%r10d, %eax
	movl	%eax, 108(%rsp)
	movzbl	%cl, %eax
	imull	%r11d, %eax
	addl	%eax, 36(%rsp)
	movzbl	%dil, %eax
	imull	%eax, %r12d
	addl	%r12d, 84(%rsp)
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L54:
	cmpl	%edi, %eax
	jne	.L28
	movzbl	16(%rsp), %ecx
	movzbl	127(%rsp), %r8d
	movl	$0, %eax
	movl	4(%rsp), %edi
	movl	120(%rsp), %r10d
	testb	%cl, %cl
	cmovne	%r8d, %eax
	movb	%al, 16(%rsp)
	movl	%edi, %eax
	addl	%r10d, %eax
	cmpl	%eax, %r12d
	cmovl	%eax, %r12d
	movzbl	%cl, %eax
	imull	%r10d, %eax
	addl	%eax, 32(%rsp)
	movzbl	%r8b, %eax
	imull	%edi, %eax
	addl	%eax, 72(%rsp)
	jmp	.L17
	.p2align 4,,10
	.p2align 3
.L53:
	movl	108(%rsp), %eax
	addl	$1, %r12d
	cmpl	%r12d, %eax
	cmovge	%eax, %r12d
	movzbl	8(%rsp), %eax
	movb	$0, 8(%rsp)
	addl	%eax, 36(%rsp)
	movl	%r12d, 108(%rsp)
	jmp	.L11
	.p2align 4,,10
	.p2align 3
.L55:
	movl	4(%rsp), %eax
	addl	$1, %eax
	cmpl	%eax, %r12d
	cmovl	%eax, %r12d
	movzbl	16(%rsp), %eax
	movb	$0, 16(%rsp)
	addl	%eax, 32(%rsp)
	jmp	.L17
	.cfi_endproc
.LFE4260:
	.size	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0, .-_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	.align 2
	.p2align 4
	.type	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0, @function
_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0:
.LFB4261:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movslq	%ecx, %rax
	addl	%ecx, %ecx
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movl	%edx, %r14d
	movl	%ecx, %edx
	movslq	%ecx, %r15
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	orl	$1, %edx
	movl	%r9d, %r13d
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movslq	%edx, %r10
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	(%rax,%rax,2), %rbx
	salq	$5, %rbx
	addq	%rdi, %rbx
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	movl	4(%rbx), %edi
	movl	%edx, 4(%rsp)
	cmpl	24(%rbx), %edi
	je	.L102
.L57:
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movl	44(%rax), %edi
	cmpl	64(%rax), %edi
	je	.L103
.L58:
	leal	(%rsi,%r14), %r12d
	sarl	%r12d
	cmpl	%r13d, %esi
	jg	.L59
	cmpl	%r8d, %r12d
	jl	.L59
	cmpl	%r8d, %esi
	jl	.L60
	cmpl	%r13d, %r12d
	jg	.L60
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	192(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	200(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
.L59:
	leal	1(%r12), %esi
	cmpl	%esi, %r13d
	jl	.L61
	cmpl	%r8d, %r14d
	jl	.L61
	cmpl	%esi, %r8d
	jg	.L62
	cmpl	%r13d, %r14d
	jg	.L62
	leaq	(%r10,%r10,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	192(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	200(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
.L61:
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movl	4(%rax), %esi
	movl	8(%rax), %ecx
	movl	12(%rax), %edi
	movl	20(%rax), %r11d
	movl	24(%rax), %edx
	movl	28(%rax), %r9d
	movl	%esi, 72(%rsp)
	movq	(%rax), %rsi
	movl	32(%rax), %r12d
	movl	%ecx, 24(%rsp)
	movl	44(%rax), %ecx
	movslq	36(%rax), %r14
	movl	%edi, 36(%rsp)
	movq	40(%rax), %rdi
	movl	60(%rax), %r8d
	movq	%rsi, 40(%rsp)
	movl	16(%rax), %esi
	movl	64(%rax), %r15d
	movl	%ecx, 76(%rsp)
	movl	52(%rax), %ecx
	movslq	76(%rax), %r13
	movq	%rdi, 48(%rsp)
	movl	56(%rax), %edi
	movl	%esi, 56(%rsp)
	movl	%ecx, 32(%rsp)
	movl	48(%rax), %esi
	movl	72(%rax), %ecx
	movl	%edi, 60(%rsp)
	movzbl	80(%rax), %edi
	movl	%esi, 28(%rsp)
	movl	%ecx, 4(%rsp)
	movl	68(%rax), %esi
	movb	%dil, 8(%rsp)
	leaq	(%r10,%r10,2), %rdi
	movzbl	81(%rax), %ecx
	salq	$5, %rdi
	movq	88(%rax), %rax
	addq	%rdi, %rbp
	movb	%cl, 16(%rsp)
	movl	0(%rbp), %edi
	testl	%edi, %edi
	je	.L63
	movl	24(%rbp), %r10d
	movl	4(%rbp), %ecx
	addq	88(%rbp), %rax
	movl	%r10d, 80(%rsp)
	movl	28(%rbp), %r10d
	movl	%ecx, 104(%rsp)
	movl	%r10d, 64(%rsp)
	movl	32(%rbp), %r10d
	movq	%rax, 96(%rsp)
	movl	%r10d, 84(%rsp)
	movl	44(%rbp), %r10d
	movl	%r10d, 68(%rsp)
	cmpl	%ecx, %edx
	je	.L104
	movb	$0, 8(%rsp)
.L64:
	movl	60(%rbp), %edi
	movl	20(%rbp), %r11d
	movl	36(%rbp), %r14d
	movl	64(%rbp), %edx
	movl	%edi, 88(%rsp)
	movl	72(%rbp), %edi
	movl	68(%rbp), %r9d
	movl	%edi, 72(%rsp)
	movl	76(%rbp), %edi
	movl	%edi, 96(%rsp)
	cmpl	68(%rsp), %r15d
	je	.L105
	movb	$0, 16(%rsp)
.L70:
	movl	72(%rsp), %esi
	movl	%edx, %r15d
	movl	96(%rsp), %r13d
	movl	88(%rsp), %r8d
	movl	84(%rsp), %r12d
	movl	%esi, 4(%rsp)
	movl	80(%rsp), %edx
	movl	%r9d, %esi
	movl	64(%rsp), %r9d
.L63:
	movq	40(%rsp), %rdi
	movl	24(%rsp), %ecx
	movl	%esi, 68(%rbx)
	movl	4(%rsp), %esi
	movl	%edx, 24(%rbx)
	movq	%rdi, (%rbx)
	movq	48(%rsp), %rdx
	movl	%ecx, 8(%rbx)
	movl	36(%rsp), %edi
	movl	%esi, 72(%rbx)
	movl	56(%rsp), %ecx
	movzbl	8(%rsp), %esi
	movl	%edi, 12(%rbx)
	movl	%ecx, 16(%rbx)
	movl	28(%rsp), %edi
	movq	%rdx, 40(%rbx)
	movl	32(%rsp), %ecx
	movb	%sil, 80(%rbx)
	movl	60(%rsp), %edx
	movzbl	16(%rsp), %esi
	movl	%r12d, 32(%rbx)
	movl	%r14d, 36(%rbx)
	movl	%r15d, 64(%rbx)
	movl	%r13d, 76(%rbx)
	movl	%r11d, 20(%rbx)
	movl	%r9d, 28(%rbx)
	movl	%edi, 48(%rbx)
	movl	%ecx, 52(%rbx)
	movl	%edx, 56(%rbx)
	movl	%r8d, 60(%rbx)
	movb	%sil, 81(%rbx)
	movq	%rax, 88(%rbx)
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L62:
	.cfi_restore_state
	movl	200(%rsp), %eax
	movl	%r14d, %edx
	movl	%r13d, %r9d
	movq	%rbp, %rdi
	movq	%r10, 8(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 200
	movl	200(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	20(%rsp), %ecx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 200
	popq	%rdx
	.cfi_def_cfa_offset 192
	movq	8(%rsp), %r10
	jmp	.L61
	.p2align 4,,10
	.p2align 3
.L60:
	movl	200(%rsp), %eax
	movl	%r13d, %r9d
	movl	%r12d, %edx
	movq	%rbp, %rdi
	movq	%r10, 16(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 200
	movl	200(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	%r8d, 24(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 200
	popq	%rsi
	.cfi_def_cfa_offset 192
	movq	16(%rsp), %r10
	movl	8(%rsp), %r8d
	jmp	.L59
	.p2align 4,,10
	.p2align 3
.L103:
	leaq	(%r15,%r15,2), %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	cmpl	44(%rdx), %edi
	je	.L58
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %r12
	movslq	56(%rax), %r11
	movl	%edi, 64(%rdx)
	imulq	%r9, %r12
	movq	%r9, 8(%rsp)
	movq	88(%rdx), %r9
	movl	%r11d, 76(%rdx)
	movl	%r11d, 56(%rdx)
	imulq	8(%rsp), %r11
	subq	%r12, %r9
	movl	%edi, 44(%rdx)
	movslq	56(%rax), %rdi
	addq	%r9, %r11
	movq	%r11, 88(%rdx)
	movl	44(%rax), %r11d
	leaq	(%r10,%r10,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%edi, 76(%rax)
	movq	88(%rax), %r12
	movl	%edi, 56(%rax)
	imulq	%rdx, %r9
	movl	%r11d, 64(%rax)
	imulq	%rdx, %rdi
	movl	%r11d, 44(%rax)
	subq	%r9, %r12
	movq	%r12, %r9
	addq	%rdi, %r9
	movq	%r9, 88(%rax)
	jmp	.L58
	.p2align 4,,10
	.p2align 3
.L102:
	leaq	(%r15,%r15,2), %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	cmpl	4(%rdx), %edi
	je	.L57
	movslq	8(%rdx), %r9
	movslq	16(%rdx), %r12
	movslq	16(%rbx), %r11
	movl	%edi, 24(%rdx)
	imulq	%r9, %r12
	movq	%r9, 8(%rsp)
	movq	88(%rdx), %r9
	movl	%r11d, 16(%rdx)
	movl	%r11d, 36(%rdx)
	imulq	8(%rsp), %r11
	subq	%r12, %r9
	movl	%edi, 4(%rdx)
	addq	%r9, %r11
	movslq	16(%rbx), %r9
	movq	%r11, 88(%rdx)
	leaq	(%r10,%r10,2), %rdx
	movl	4(%rbx), %r12d
	salq	$5, %rdx
	addq	%rbp, %rdx
	movslq	8(%rdx), %rdi
	movslq	16(%rdx), %r11
	movl	%r9d, 36(%rdx)
	movl	%r9d, 16(%rdx)
	imulq	%rdi, %r11
	movq	%rdi, 8(%rsp)
	movq	88(%rdx), %rdi
	imulq	8(%rsp), %r9
	movl	%r12d, 24(%rdx)
	movl	%r12d, 4(%rdx)
	subq	%r11, %rdi
	addq	%rdi, %r9
	movq	%r9, 88(%rdx)
	jmp	.L57
	.p2align 4,,10
	.p2align 3
.L104:
	movl	12(%rbp), %eax
	leaq	_ZN11Solve_merge6SparseE(%rip), %r10
	movl	%eax, 120(%rsp)
	movzbl	80(%rbp), %eax
	movb	%al, 127(%rsp)
	movl	%edi, %eax
	subl	%r11d, %eax
	cltq
	movl	100001000(%r10,%rax,4), %ecx
	movl	$1, %eax
	movl	%ecx, 88(%rsp)
	sall	%cl, %eax
	movl	%edi, %ecx
	subl	%eax, %ecx
	movslq	%ecx, %rax
	movslq	88(%rsp), %rcx
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rcx, %rax
	movq	%rax, 88(%rsp)
	movslq	%r11d, %rax
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rax, %rcx
	movl	(%r10,%rcx,4), %eax
	movq	%rcx, 112(%rsp)
	movq	88(%rsp), %rcx
	cmpl	%eax, (%r10,%rcx,4)
	cmovle	(%r10,%rcx,4), %eax
	movl	%r9d, %ecx
	cmpl	8(%rbp), %r9d
	cmovl	8(%rbp), %ecx
	addl	8(%rbp), %r9d
	movslq	%r9d, %r9
	movl	%ecx, 108(%rsp)
	movq	96(%rsp), %rcx
	imulq	%r14, %r9
	subq	%r9, %rcx
	movq	%rcx, 96(%rsp)
	movq	88(%rsp), %rcx
	movl	50000500(%r10,%rcx,4), %r9d
	movq	112(%rsp), %rcx
	cmpl	%r9d, 50000500(%r10,%rcx,4)
	cmovge	50000500(%r10,%rcx,4), %r9d
	subl	%r11d, %edi
	movl	68(%rsp), %ecx
	subl	%eax, %r9d
	addl	$1, %ecx
	addl	$1, %r9d
	cmpl	%eax, %ecx
	je	.L106
	cmpl	%edi, %r9d
	je	.L107
.L79:
	movb	$0, 8(%rsp)
.L66:
	movslq	108(%rsp), %rax
	movl	80(%rsp), %ecx
	movq	%rax, %rdi
	imulq	%r14, %rax
	addq	96(%rsp), %rax
	cmpl	%edx, 72(%rsp)
	movl	24(%rsp), %edx
	cmove	%edi, %edx
	cmpl	%ecx, 104(%rsp)
	cmovne	64(%rsp), %edi
	movl	%edx, 24(%rsp)
	movl	%edi, 64(%rsp)
	jmp	.L64
	.p2align 4,,10
	.p2align 3
.L105:
	movl	40(%rbp), %r10d
	movl	48(%rbp), %ecx
	movl	52(%rbp), %edi
	movl	%ecx, 108(%rsp)
	movl	%r10d, %ecx
	movl	%r10d, %r12d
	movl	%edi, 120(%rsp)
	movzbl	81(%rbp), %edi
	subl	%r8d, %ecx
	movl	$1, %ebp
	movslq	%ecx, %rcx
	movl	%r10d, 112(%rsp)
	movslq	%r8d, %r10
	movb	%dil, 127(%rsp)
	leaq	_ZN11Solve_merge6SparseE(%rip), %rdi
	leaq	(%r10,%r10,4), %r10
	movslq	100001000(%rdi,%rcx,4), %rcx
	sall	%cl, %ebp
	subl	%ebp, %r12d
	leaq	(%r10,%r10,4), %rbp
	movslq	%r12d, %r10
	movl	108(%rsp), %r12d
	addq	%rcx, %rbp
	leaq	(%r10,%r10,4), %r10
	leaq	(%r10,%r10,4), %r10
	addq	%rcx, %r10
	movl	50000500(%rdi,%r10,4), %ecx
	cmpl	%ecx, 50000500(%rdi,%rbp,4)
	cmovge	50000500(%rdi,%rbp,4), %ecx
	cmpl	%r12d, %esi
	cmovge	%esi, %r12d
	addl	108(%rsp), %esi
	movslq	%esi, %rsi
	imulq	%r13, %rsi
	subq	%rsi, %rax
	movq	%rax, %rsi
	movl	(%rdi,%rbp,4), %eax
	cmpl	%eax, (%rdi,%r10,4)
	cmovle	(%rdi,%r10,4), %eax
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	movl	112(%rsp), %edi
	addl	$1, %eax
	subl	%r8d, %edi
	movl	104(%rsp), %r8d
	subl	$1, %r8d
	cmpl	%r8d, %ecx
	je	.L108
	cmpl	%edi, %eax
	je	.L109
.L83:
	movb	$0, 16(%rsp)
.L72:
	movslq	%r12d, %rax
	imulq	%rax, %r13
	cmpl	%r15d, 76(%rsp)
	leaq	0(%r13,%rsi), %rax
	movl	28(%rsp), %esi
	cmove	%r12d, %esi
	cmpl	%edx, 68(%rsp)
	cmove	%r12d, %r9d
	movl	%esi, 28(%rsp)
	jmp	.L70
	.p2align 4,,10
	.p2align 3
.L106:
	cmpl	%edi, %r9d
	jne	.L79
	movzbl	8(%rsp), %ecx
	movzbl	127(%rsp), %edi
	movl	$0, %eax
	movl	120(%rsp), %r11d
	movl	108(%rsp), %r10d
	testb	%cl, %cl
	cmovne	%edi, %eax
	movb	%al, 8(%rsp)
	leal	(%r12,%r11), %eax
	cmpl	%eax, %r10d
	cmovge	%r10d, %eax
	movl	%eax, 108(%rsp)
	movzbl	%cl, %eax
	imull	%r11d, %eax
	addl	%eax, 36(%rsp)
	movzbl	%dil, %eax
	imull	%eax, %r12d
	addl	%r12d, 84(%rsp)
	jmp	.L66
	.p2align 4,,10
	.p2align 3
.L108:
	cmpl	%edi, %eax
	jne	.L83
	movzbl	16(%rsp), %ecx
	movzbl	127(%rsp), %r8d
	movl	$0, %eax
	movl	4(%rsp), %edi
	movl	120(%rsp), %r10d
	testb	%cl, %cl
	cmovne	%r8d, %eax
	movb	%al, 16(%rsp)
	movl	%edi, %eax
	addl	%r10d, %eax
	cmpl	%eax, %r12d
	cmovl	%eax, %r12d
	movzbl	%cl, %eax
	imull	%r10d, %eax
	addl	%eax, 32(%rsp)
	movzbl	%r8b, %eax
	imull	%edi, %eax
	addl	%eax, 72(%rsp)
	jmp	.L72
	.p2align 4,,10
	.p2align 3
.L107:
	movl	108(%rsp), %eax
	addl	$1, %r12d
	cmpl	%r12d, %eax
	cmovge	%eax, %r12d
	movzbl	8(%rsp), %eax
	movb	$0, 8(%rsp)
	addl	%eax, 36(%rsp)
	movl	%r12d, 108(%rsp)
	jmp	.L66
	.p2align 4,,10
	.p2align 3
.L109:
	movl	4(%rsp), %eax
	addl	$1, %eax
	cmpl	%eax, %r12d
	cmovl	%eax, %r12d
	movzbl	16(%rsp), %eax
	movb	$0, 16(%rsp)
	addl	%eax, 32(%rsp)
	jmp	.L72
	.cfi_endproc
.LFE4261:
	.size	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0, .-_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	.p2align 4
	.globl	_Z5powerii
	.type	_Z5powerii, @function
_Z5powerii:
.LFB3521:
	.cfi_startproc
	endbr64
	movl	$1, %eax
	testl	%esi, %esi
	je	.L114
	.p2align 4,,10
	.p2align 3
.L113:
	testb	$1, %sil
	je	.L112
	imull	%edi, %eax
	movl	%eax, %edx
	cltq
	imulq	$288737297, %rax, %rax
	movl	%edx, %ecx
	sarl	$31, %ecx
	sarq	$58, %rax
	subl	%ecx, %eax
	imull	$998244353, %eax, %eax
	subl	%eax, %edx
	movl	%edx, %eax
.L112:
	movl	%edi, %edx
	imull	%edi, %edx
	movslq	%edx, %rdi
	movl	%edx, %ecx
	imulq	$288737297, %rdi, %rdi
	sarl	$31, %ecx
	sarq	$58, %rdi
	subl	%ecx, %edi
	imull	$998244353, %edi, %edi
	subl	%edi, %edx
	sarl	%esi
	movl	%edx, %edi
	jne	.L113
	ret
	.p2align 4,,10
	.p2align 3
.L114:
	ret
	.cfi_endproc
.LFE3521:
	.size	_Z5powerii, .-_Z5powerii
	.section	.text._ZN10Solve_left2ST6changeEiiii,"axG",@progbits,_ZN10Solve_left2ST6changeEiiii,comdat
	.align 2
	.p2align 4
	.weak	_ZN10Solve_left2ST6changeEiiii
	.type	_ZN10Solve_left2ST6changeEiiii, @function
_ZN10Solve_left2ST6changeEiiii:
.LFB3529:
	.cfi_startproc
	endbr64
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movslq	%ecx, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	cmpl	%edx, %esi
	je	.L128
	leal	(%rsi,%rdx), %r9d
	leal	(%rbx,%rbx), %r12d
	movl	%r12d, %r13d
	sarl	%r9d
	orl	$1, %r13d
	cmpl	%r8d, %r9d
	jge	.L129
	leal	1(%r9), %esi
	movl	%r13d, %ecx
	call	_ZN10Solve_left2ST6changeEiiii
.L123:
	movslq	%r12d, %r12
	leaq	(%r12,%r12,2), %rax
	leaq	0(%rbp,%rax,4), %rax
	movl	(%rax), %edx
	movl	4(%rax), %ecx
	movslq	%r13d, %rax
	leaq	(%rax,%rax,2), %rax
	leaq	0(%rbp,%rax,4), %rax
	movl	(%rax), %esi
	movl	4(%rax), %eax
	cmpl	%esi, %edx
	jg	.L124
	jne	.L125
	addl	%eax, %ecx
.L126:
	leaq	(%rbx,%rbx,2), %rax
	leaq	0(%rbp,%rax,4), %rax
	movl	%edx, (%rax)
	movl	%ecx, 4(%rax)
	movl	$0, 8(%rax)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L129:
	.cfi_restore_state
	movl	%r12d, %ecx
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L123
	.p2align 4,,10
	.p2align 3
.L125:
	jl	.L126
	movl	%edx, %esi
	.p2align 4,,10
	.p2align 3
.L124:
	movl	%esi, %edx
	movl	%eax, %ecx
	jmp	.L126
	.p2align 4,,10
	.p2align 3
.L128:
	leaq	(%rbx,%rbx,2), %rax
	movl	$1, 4(%rdi,%rax,4)
	addq	$8, %rsp
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3529:
	.size	_ZN10Solve_left2ST6changeEiiii, .-_ZN10Solve_left2ST6changeEiiii
	.section	.text._ZN10Solve_left2ST6updateEiiiiii,"axG",@progbits,_ZN10Solve_left2ST6updateEiiiiii,comdat
	.align 2
	.p2align 4
	.weak	_ZN10Solve_left2ST6updateEiiiiii
	.type	_ZN10Solve_left2ST6updateEiiiiii, @function
_ZN10Solve_left2ST6updateEiiiiii:
.LFB3530:
	.cfi_startproc
	endbr64
	cmpl	%r8d, %edx
	jl	.L147
	cmpl	%esi, %r9d
	jl	.L147
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movl	%edx, %r12d
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	cmpl	%esi, %r8d
	jg	.L132
	cmpl	%r9d, %edx
	jg	.L132
	movslq	%ecx, %rcx
	movl	80(%rsp), %ebx
	leaq	(%rcx,%rcx,2), %rax
	leaq	(%rdi,%rax,4), %rax
	addl	%ebx, (%rax)
	addl	%ebx, 8(%rax)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L132:
	.cfi_restore_state
	movslq	%ecx, %rax
	addl	%ecx, %ecx
	leaq	(%rax,%rax,2), %rax
	movl	%ecx, %ebp
	movslq	%ecx, %r15
	leaq	(%rbx,%rax,4), %r13
	orl	$1, %ebp
	movl	8(%r13), %eax
	movslq	%ebp, %r14
	testl	%eax, %eax
	je	.L133
	leaq	(%r15,%r15,2), %rdx
	movslq	%ebp, %r14
	leaq	(%rbx,%rdx,4), %rdx
	addl	%eax, (%rdx)
	addl	%eax, 8(%rdx)
	leaq	(%r14,%r14,2), %rax
	movl	8(%r13), %edx
	leaq	(%rbx,%rax,4), %rax
	addl	%edx, (%rax)
	addl	%edx, 8(%rax)
	movl	$0, 8(%r13)
.L133:
	subq	$8, %rsp
	.cfi_def_cfa_offset 88
	leal	(%r12,%rsi), %eax
	movl	88(%rsp), %edi
	sarl	%eax
	movl	%eax, %edx
	pushq	%rdi
	.cfi_def_cfa_offset 96
	movq	%rbx, %rdi
	movl	%r9d, 28(%rsp)
	movl	%r8d, 24(%rsp)
	movl	%eax, 20(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	20(%rsp), %eax
	movl	28(%rsp), %r9d
	movl	%ebp, %ecx
	movl	24(%rsp), %r8d
	movl	%r12d, %edx
	movq	%rbx, %rdi
	leal	1(%rax), %esi
	movl	96(%rsp), %eax
	movl	%eax, (%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	leaq	(%r15,%r15,2), %rax
	leaq	(%r14,%r14,2), %rcx
	popq	%rdi
	.cfi_def_cfa_offset 88
	leaq	(%rbx,%rax,4), %rdx
	leaq	(%rbx,%rcx,4), %rcx
	popq	%r8
	.cfi_def_cfa_offset 80
	movl	(%rdx), %eax
	movl	(%rcx), %esi
	movl	4(%rdx), %edx
	movl	4(%rcx), %ecx
	cmpl	%esi, %eax
	jg	.L134
	jne	.L135
	addl	%ecx, %edx
.L136:
	movl	%eax, 0(%r13)
	movl	%edx, 4(%r13)
	movl	$0, 8(%r13)
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L147:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	ret
	.p2align 4,,10
	.p2align 3
.L135:
	.cfi_def_cfa_offset 80
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	jl	.L136
	movl	%eax, %esi
	.p2align 4,,10
	.p2align 3
.L134:
	movl	%esi, %eax
	movl	%ecx, %edx
	jmp	.L136
	.cfi_endproc
.LFE3530:
	.size	_ZN10Solve_left2ST6updateEiiiiii, .-_ZN10Solve_left2ST6updateEiiiiii
	.section	.text._ZN11Solve_right3DSU7findparEi,"axG",@progbits,_ZN11Solve_right3DSU7findparEi,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_right3DSU7findparEi
	.type	_ZN11Solve_right3DSU7findparEi, @function
_ZN11Solve_right3DSU7findparEi:
.LFB3545:
	.cfi_startproc
	endbr64
	movslq	%esi, %rdx
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	leaq	(%rdi,%rdx,4), %rbx
	movq	%rdx, %rax
	movl	(%rbx), %esi
	cmpl	%edx, %esi
	jne	.L154
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L154:
	.cfi_restore_state
	call	_ZN11Solve_right3DSU7findparEi
	movl	%eax, (%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3545:
	.size	_ZN11Solve_right3DSU7findparEi, .-_ZN11Solve_right3DSU7findparEi
	.text
	.p2align 4
	.globl	_ZN11Solve_right5solveEv
	.type	_ZN11Solve_right5solveEv, @function
_ZN11Solve_right5solveEv:
.LFB3551:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	_ZN11Solve_right3dsuE(%rip), %rbx
	subq	$72, %rsp
	.cfi_def_cfa_offset 128
	movl	n(%rip), %ecx
	movq	$0, 4000040+_ZN11Solve_right3dsuE(%rip)
	cmpl	$-1, %ecx
	jl	.L156
	leal	1(%rcx), %esi
	leaq	4(%rbx), %rdx
	movq	%rbx, %rax
	leaq	(%rdx,%rsi,4), %rdx
	.p2align 4,,10
	.p2align 3
.L158:
	movl	$0, 2000020(%rax)
	addq	$4, %rax
	movl	$0, -4(%rax)
	cmpq	%rax, %rdx
	jne	.L158
	leaq	_ZN11Solve_right3resE(%rip), %rax
	leaq	8(%rax), %rdx
	leaq	(%rdx,%rsi,8), %rdx
	.p2align 4,,10
	.p2align 3
.L160:
	movq	$0, (%rax)
	addq	$8, %rax
	cmpq	%rax, %rdx
	jne	.L160
.L156:
	movslq	%ecx, %r12
	xorl	%eax, %eax
	leaq	_ZN11Solve_right3resE(%rip), %r15
	leaq	p(%rip), %r14
	leaq	_ZN11Solve_right3dsuE(%rip), %r11
	testl	%ecx, %ecx
	jg	.L193
	jmp	.L155
	.p2align 4,,10
	.p2align 3
.L208:
	leal	-1(%rbp), %edx
	movslq	%edx, %r13
	movl	(%rbx,%r13,4), %esi
	testl	%esi, %esi
	jne	.L207
	leal	1(%rbp), %r13d
	movslq	%r13d, %rdx
	movl	(%rbx,%rdx,4), %esi
	testl	%esi, %esi
	jne	.L175
.L194:
	movq	4000040+_ZN11Solve_right3dsuE(%rip), %rax
	movq	%rax, (%r15,%r12,8)
	subq	$1, %r12
	testl	%r12d, %r12d
	jle	.L155
.L193:
	movslq	(%r14,%r12,4), %rbp
	addq	$1, %rax
	movq	%rax, 4000040+_ZN11Solve_right3dsuE(%rip)
	movl	%ebp, (%rbx,%rbp,4)
	movq	%rbp, %rcx
	movl	$1, 2000020(%rbx,%rbp,4)
	testl	%ebp, %ebp
	jne	.L208
	movl	(%rbx,%rbp,4), %eax
	testl	%eax, %eax
	je	.L194
.L172:
	leal	1(%rcx), %r13d
	movslq	%r13d, %rdx
	movl	(%rbx,%rdx,4), %esi
	testl	%esi, %esi
	je	.L194
	cmpl	%eax, %ecx
	je	.L175
	movslq	%eax, %rcx
	movl	(%rbx,%rcx,4), %edi
	cmpl	%edi, %eax
	jne	.L209
.L176:
	movl	%edi, (%rbx,%rbp,4)
	movslq	%edi, %rbp
	movl	(%rbx,%rdx,4), %esi
	movq	%rbp, %rcx
.L175:
	movslq	%esi, %r8
	cmpl	%esi, %r13d
	je	.L183
	movl	(%rbx,%r8,4), %eax
	cmpl	%esi, %eax
	jne	.L210
.L184:
	movl	%esi, (%rbx,%rdx,4)
.L183:
	movl	2000020(%rbx,%rbp,4), %edi
	movl	2000020(%rbx,%r8,4), %edx
	cmpl	%edx, %edi
	jl	.L191
	movl	%edx, %eax
	movslq	%ecx, %r8
	movl	%edi, %edx
	movslq	%esi, %rbp
	movl	%eax, %edi
	movq	%r8, %rsi
.L191:
	movslq	%edx, %rax
	movslq	%edi, %rcx
	addl	%edi, %edx
	movl	%esi, (%rbx,%rbp,4)
	imulq	%rcx, %rax
	addq	4000040+_ZN11Solve_right3dsuE(%rip), %rax
	movl	%edx, 2000020(%rbx,%r8,4)
	movq	%rax, (%r15,%r12,8)
	subq	$1, %r12
	movq	%rax, 4000040+_ZN11Solve_right3dsuE(%rip)
	testl	%r12d, %r12d
	jg	.L193
.L155:
	addq	$72, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L207:
	.cfi_restore_state
	cmpl	%esi, %edx
	je	.L163
	movslq	%esi, %rdx
	movl	(%rbx,%rdx,4), %edi
	cmpl	%edi, %esi
	jne	.L211
.L164:
	movl	%edi, (%rbx,%r13,4)
	movl	%edi, %esi
.L163:
	movslq	%esi, %rdx
	movl	2000020(%rbx,%rbp,4), %r9d
	movslq	%ecx, %r10
	movl	2000020(%rbx,%rdx,4), %edi
	cmpl	%edi, %r9d
	jl	.L171
	movl	%edi, %edx
	movslq	%esi, %r10
	movl	%r9d, %edi
	movl	%ecx, %esi
	movl	%edx, %r9d
	movslq	%ecx, %rdx
.L171:
	movslq	%edi, %r8
	movslq	%r9d, %r13
	movl	%esi, (%rbx,%r10,4)
	addl	%r9d, %edi
	imulq	%r13, %r8
	movl	%edi, 2000020(%rbx,%rdx,4)
	addq	%r8, %rax
	movq	%rax, 4000040+_ZN11Solve_right3dsuE(%rip)
	movl	(%rbx,%rbp,4), %eax
	testl	%eax, %eax
	je	.L194
	jmp	.L172
	.p2align 4,,10
	.p2align 3
.L211:
	movslq	%edi, %r8
	movl	(%rbx,%r8,4), %esi
	cmpl	%esi, %edi
	jne	.L212
	movl	%esi, (%rbx,%rdx,4)
	movl	%esi, %edi
	jmp	.L164
	.p2align 4,,10
	.p2align 3
.L210:
	movslq	%eax, %r13
	movl	(%rbx,%r13,4), %esi
	cmpl	%esi, %eax
	jne	.L213
	movl	%esi, (%rbx,%r8,4)
	movslq	%esi, %r8
	jmp	.L184
	.p2align 4,,10
	.p2align 3
.L209:
	movslq	%edi, %r8
	movl	(%rbx,%r8,4), %eax
	cmpl	%eax, %edi
	jne	.L214
	movl	%eax, (%rbx,%rcx,4)
	movl	%eax, %edi
	jmp	.L176
	.p2align 4,,10
	.p2align 3
.L214:
	movslq	%eax, %r9
	movl	(%rbx,%r9,4), %esi
	cmpl	%esi, %eax
	je	.L178
	movslq	%esi, %r10
	movl	(%rbx,%r10,4), %eax
	cmpl	%eax, %esi
	jne	.L215
.L179:
	movl	%eax, (%rbx,%r9,4)
	movl	%eax, %esi
.L178:
	movl	%esi, %eax
	movl	%esi, (%rbx,%r8,4)
	movl	%eax, %edi
	movl	%eax, (%rbx,%rcx,4)
	jmp	.L176
	.p2align 4,,10
	.p2align 3
.L213:
	movslq	%esi, %r9
	movl	(%rbx,%r9,4), %eax
	cmpl	%eax, %esi
	je	.L186
	movslq	%eax, %r10
	movl	(%rbx,%r10,4), %esi
	cmpl	%esi, %eax
	jne	.L216
.L187:
	movl	%esi, (%rbx,%r9,4)
	movl	%esi, %eax
.L186:
	movl	%eax, %esi
	movl	%eax, (%rbx,%r13,4)
	movl	%esi, (%rbx,%r8,4)
	movslq	%esi, %r8
	jmp	.L184
	.p2align 4,,10
	.p2align 3
.L212:
	movslq	%esi, %r9
	movl	(%rbx,%r9,4), %edi
	cmpl	%edi, %esi
	je	.L166
	movslq	%edi, %r10
	movl	(%rbx,%r10,4), %esi
	cmpl	%esi, %edi
	jne	.L217
.L167:
	movl	%esi, (%rbx,%r9,4)
	movl	%esi, %edi
.L166:
	movl	%edi, %esi
	movl	%edi, (%rbx,%r8,4)
	movl	%esi, (%rbx,%rdx,4)
	movl	%esi, %edi
	jmp	.L164
.L217:
	movslq	%esi, %rdi
	movq	%rdi, (%rsp)
	movl	(%rbx,%rdi,4), %edi
	cmpl	%edi, %esi
	je	.L168
	movslq	%edi, %rsi
	movq	%rsi, 8(%rsp)
	movl	(%rbx,%rsi,4), %esi
	cmpl	%esi, %edi
	je	.L169
	movslq	%esi, %rdi
	movq	%rdi, 16(%rsp)
	movl	(%rbx,%rdi,4), %edi
	cmpl	%edi, %esi
	je	.L170
	movl	%edi, %esi
	movq	%r11, %rdi
	movq	%r10, 56(%rsp)
	movq	%r9, 48(%rsp)
	movq	%r8, 40(%rsp)
	movq	%rdx, 32(%rsp)
	movl	%ebp, 24(%rsp)
	call	_ZN11Solve_right3DSU7findparEi
	movq	56(%rsp), %r10
	movq	48(%rsp), %r9
	leaq	_ZN11Solve_right3dsuE(%rip), %r11
	movl	%eax, %edi
	movq	16(%rsp), %rax
	movq	40(%rsp), %r8
	movq	32(%rsp), %rdx
	movl	24(%rsp), %ecx
	movl	%edi, (%rbx,%rax,4)
	movq	4000040+_ZN11Solve_right3dsuE(%rip), %rax
.L170:
	movq	8(%rsp), %rsi
	movl	%edi, (%rbx,%rsi,4)
.L169:
	movq	(%rsp), %rsi
	movl	%edi, (%rbx,%rsi,4)
.L168:
	movl	%edi, (%rbx,%r10,4)
	movl	%edi, %esi
	jmp	.L167
.L216:
	movslq	%esi, %rax
	movq	%rax, (%rsp)
	movl	(%rbx,%rax,4), %eax
	cmpl	%eax, %esi
	je	.L188
	movslq	%eax, %rdi
	movq	%rdi, 8(%rsp)
	movl	(%rbx,%rdi,4), %edi
	cmpl	%edi, %eax
	je	.L189
	movslq	%edi, %rax
	movl	(%rbx,%rax,4), %esi
	movq	%rax, 16(%rsp)
	cmpl	%esi, %edi
	je	.L190
	movq	%r11, %rdi
	movq	%r10, 56(%rsp)
	movq	%r9, 48(%rsp)
	movq	%r8, 40(%rsp)
	movq	%rdx, 32(%rsp)
	movl	%ecx, 24(%rsp)
	call	_ZN11Solve_right3DSU7findparEi
	movq	56(%rsp), %r10
	movq	48(%rsp), %r9
	leaq	_ZN11Solve_right3dsuE(%rip), %r11
	movl	%eax, %esi
	movq	16(%rsp), %rax
	movq	40(%rsp), %r8
	movq	32(%rsp), %rdx
	movl	24(%rsp), %ecx
	movl	%esi, (%rbx,%rax,4)
.L190:
	movq	8(%rsp), %rax
	movl	%esi, (%rbx,%rax,4)
	movl	%esi, %eax
.L189:
	movq	(%rsp), %rdi
	movl	%eax, (%rbx,%rdi,4)
.L188:
	movl	%eax, (%rbx,%r10,4)
	movl	%eax, %esi
	jmp	.L187
.L215:
	movslq	%eax, %rdi
	movl	(%rbx,%rdi,4), %esi
	movq	%rdi, (%rsp)
	cmpl	%esi, %eax
	je	.L180
	movslq	%esi, %rax
	movq	%rax, 8(%rsp)
	movl	(%rbx,%rax,4), %eax
	cmpl	%eax, %esi
	je	.L181
	movslq	%eax, %rdi
	movl	(%rbx,%rdi,4), %esi
	movq	%rdi, 16(%rsp)
	cmpl	%esi, %eax
	je	.L182
	movq	%r11, %rdi
	movq	%r10, 56(%rsp)
	movq	%r9, 48(%rsp)
	movq	%r8, 40(%rsp)
	movq	%rcx, 32(%rsp)
	movq	%rdx, 24(%rsp)
	call	_ZN11Solve_right3DSU7findparEi
	movq	16(%rsp), %rdi
	movq	56(%rsp), %r10
	leaq	_ZN11Solve_right3dsuE(%rip), %r11
	movq	48(%rsp), %r9
	movq	40(%rsp), %r8
	movl	%eax, %esi
	movq	32(%rsp), %rcx
	movq	24(%rsp), %rdx
	movl	%eax, (%rbx,%rdi,4)
.L182:
	movq	8(%rsp), %rax
	movl	%esi, (%rbx,%rax,4)
.L181:
	movq	(%rsp), %rax
	movl	%esi, (%rbx,%rax,4)
.L180:
	movl	%esi, (%rbx,%r10,4)
	movl	%esi, %eax
	jmp	.L179
	.cfi_endproc
.LFE3551:
	.size	_ZN11Solve_right5solveEv, .-_ZN11Solve_right5solveEv
	.section	.text._ZN11Solve_mergeplENS_4nodeES0_,"axG",@progbits,_ZN11Solve_mergeplENS_4nodeES0_,comdat
	.p2align 4
	.weak	_ZN11Solve_mergeplENS_4nodeES0_
	.type	_ZN11Solve_mergeplENS_4nodeES0_, @function
_ZN11Solve_mergeplENS_4nodeES0_:
.LFB3567:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	movq	%rdi, %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$16, %rsp
	.cfi_def_cfa_offset 72
	movl	168(%rsp), %esi
	testl	%esi, %esi
	jne	.L219
	movdqu	72(%rsp), %xmm0
	movdqu	88(%rsp), %xmm1
	movdqu	104(%rsp), %xmm2
	movdqu	120(%rsp), %xmm3
	movdqu	136(%rsp), %xmm4
	movups	%xmm0, (%rdi)
	movdqu	152(%rsp), %xmm5
	movups	%xmm1, 16(%rdi)
	movups	%xmm2, 32(%rdi)
	movups	%xmm3, 48(%rdi)
	movups	%xmm4, 64(%rdi)
	movups	%xmm5, 80(%rdi)
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L219:
	.cfi_restore_state
	movl	212(%rsp), %edi
	movq	72(%rsp), %rbx
	movl	116(%rsp), %ecx
	movl	120(%rsp), %edx
	movl	%edi, -108(%rsp)
	movl	76(%rsp), %edi
	movq	%rbx, -88(%rsp)
	movl	88(%rsp), %ebx
	movl	%edi, -40(%rsp)
	movl	84(%rsp), %edi
	movl	%ebx, -52(%rsp)
	movl	128(%rsp), %ebx
	movl	%edi, -100(%rsp)
	movq	112(%rsp), %rdi
	movl	%ecx, -28(%rsp)
	movl	192(%rsp), %ecx
	movl	%edx, -112(%rsp)
	movl	124(%rsp), %edx
	movq	%rdi, -64(%rsp)
	movq	188(%rsp), %rdi
	movl	%edx, -104(%rsp)
	movl	200(%rsp), %edx
	movl	%ebx, -48(%rsp)
	movl	204(%rsp), %ebx
	movl	%ecx, -24(%rsp)
	movl	232(%rsp), %ecx
	movl	%edx, -96(%rsp)
	movl	80(%rsp), %r10d
	movl	%ebx, -44(%rsp)
	movl	196(%rsp), %r14d
	movq	%rdi, -80(%rsp)
	movl	%ecx, -20(%rsp)
	movq	228(%rsp), %rdi
	movl	240(%rsp), %edx
	movl	96(%rsp), %r11d
	movb	$0, -53(%rsp)
	movq	%rdi, -72(%rsp)
	movl	244(%rsp), %ebx
	movl	172(%rsp), %edi
	movl	%edx, -92(%rsp)
	movl	%ebx, -32(%rsp)
	movq	256(%rsp), %rdx
	movl	236(%rsp), %r15d
	addq	160(%rsp), %rdx
	cmpl	%edi, %r11d
	je	.L242
.L221:
	movl	136(%rsp), %r8d
	xorl	%r11d, %r11d
	cmpl	-108(%rsp), %r8d
	je	.L243
.L227:
	movq	-88(%rsp), %rsi
	movl	-112(%rsp), %edi
	movl	%r14d, 28(%rax)
	movl	-44(%rsp), %ecx
	movl	-48(%rsp), %ebx
	movl	%r15d, 68(%rax)
	movq	%rsi, (%rax)
	movl	-100(%rsp), %esi
	movl	%edi, 48(%rax)
	movl	-104(%rsp), %edi
	movl	%esi, 12(%rax)
	movl	-52(%rsp), %esi
	movl	%ecx, 36(%rax)
	movq	-72(%rsp), %rcx
	movl	%esi, 16(%rax)
	movq	-80(%rsp), %rsi
	movl	%edi, 52(%rax)
	movl	-32(%rsp), %edi
	movq	%rsi, 20(%rax)
	movl	-96(%rsp), %esi
	movl	%ebx, 56(%rax)
	movzbl	-53(%rsp), %ebx
	movl	%esi, 32(%rax)
	movq	-64(%rsp), %rsi
	movb	%bl, 80(%rax)
	movq	%rsi, 40(%rax)
	movl	-92(%rsp), %esi
	movl	%r10d, 8(%rax)
	movq	%rcx, 60(%rax)
	movl	%esi, 72(%rax)
	movl	%edi, 76(%rax)
	movb	%r11b, 81(%rax)
	movq	%rdx, 88(%rax)
	addq	$16, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L242:
	.cfi_restore_state
	movl	104(%rsp), %ebx
	movl	%esi, %ecx
	subl	92(%rsp), %ecx
	movl	%esi, %ebp
	leaq	_ZN11Solve_merge6SparseE(%rip), %r8
	movslq	%ecx, %rcx
	movslq	108(%rsp), %r9
	movl	%ebx, 4(%rsp)
	movzbl	152(%rsp), %ebx
	movslq	100001000(%r8,%rcx,4), %rcx
	movq	%r9, -16(%rsp)
	movb	%bl, 3(%rsp)
	movl	$1, %ebx
	sall	%cl, %ebx
	subl	%ebx, %ebp
	movslq	%ebp, %rbx
	leaq	(%rbx,%rbx,4), %rbx
	leaq	(%rbx,%rbx,4), %r12
	movslq	92(%rsp), %rbx
	addq	%rcx, %r12
	leaq	(%rbx,%rbx,4), %rbx
	leaq	(%rbx,%rbx,4), %rbp
	addq	%rcx, %rbp
	movl	176(%rsp), %ecx
	movl	(%r8,%rbp,4), %ebx
	cmpl	%ebx, (%r8,%r12,4)
	movl	%ecx, %r13d
	cmovle	(%r8,%r12,4), %ebx
	cmpl	100(%rsp), %ecx
	cmovl	100(%rsp), %r13d
	addl	100(%rsp), %ecx
	movslq	%ecx, %rcx
	imulq	%r9, %rcx
	subq	%rcx, %rdx
	movl	-108(%rsp), %ecx
	movq	%rdx, -8(%rsp)
	movl	50000500(%r8,%r12,4), %edx
	cmpl	%edx, 50000500(%r8,%rbp,4)
	cmovge	50000500(%r8,%rbp,4), %edx
	addl	$1, %ecx
	subl	92(%rsp), %esi
	subl	%ebx, %edx
	addl	$1, %edx
	cmpl	%ebx, %ecx
	je	.L244
	cmpl	%esi, %edx
	jne	.L223
	movl	4(%rsp), %edx
	addl	$1, %edx
	cmpl	%edx, %r13d
	cmovl	%edx, %r13d
	movzbl	3(%rsp), %edx
	addl	%edx, -100(%rsp)
.L223:
	movslq	%r13d, %rdx
	imulq	-16(%rsp), %rdx
	addq	-8(%rsp), %rdx
	cmpl	-40(%rsp), %r11d
	cmove	%r13d, %r10d
	cmpl	-24(%rsp), %edi
	cmove	%r13d, %r14d
	jmp	.L221
	.p2align 4,,10
	.p2align 3
.L243:
	movzbl	153(%rsp), %ecx
	leaq	_ZN11Solve_merge6SparseE(%rip), %rsi
	movl	144(%rsp), %ebx
	movl	208(%rsp), %r9d
	movslq	132(%rsp), %rbp
	movb	%cl, -24(%rsp)
	movl	208(%rsp), %ecx
	subl	132(%rsp), %ecx
	movl	%ebx, -16(%rsp)
	movl	$1, %ebx
	leaq	0(%rbp,%rbp,4), %rbp
	movslq	%ecx, %rcx
	leaq	0(%rbp,%rbp,4), %r12
	movslq	100001000(%rsi,%rcx,4), %rcx
	sall	%cl, %ebx
	addq	%rcx, %r12
	subl	%ebx, %r9d
	movslq	%r9d, %rbx
	movslq	148(%rsp), %r9
	leaq	(%rbx,%rbx,4), %rbx
	leaq	(%rbx,%rbx,4), %rbp
	movq	%r9, -40(%rsp)
	addq	%rcx, %rbp
	movl	140(%rsp), %ecx
	movl	50000500(%rsi,%rbp,4), %ebx
	cmpl	%ebx, 50000500(%rsi,%r12,4)
	cmovge	50000500(%rsi,%r12,4), %ebx
	movl	%ecx, %r13d
	cmpl	216(%rsp), %ecx
	cmovl	216(%rsp), %r13d
	addl	216(%rsp), %ecx
	movslq	%ecx, %rcx
	imulq	%r9, %rcx
	subq	%rcx, %rdx
	movq	%rdx, %rcx
	movl	(%rsi,%r12,4), %edx
	cmpl	%edx, (%rsi,%rbp,4)
	cmovle	(%rsi,%rbp,4), %edx
	movl	%ebx, %esi
	subl	$1, %edi
	subl	%edx, %esi
	movl	%esi, %edx
	movl	208(%rsp), %esi
	subl	132(%rsp), %esi
	addl	$1, %edx
	cmpl	%ebx, %edi
	je	.L245
	cmpl	%edx, %esi
	jne	.L229
	movl	-16(%rsp), %edx
	addl	$1, %edx
	cmpl	%edx, %r13d
	cmovl	%edx, %r13d
	movzbl	-24(%rsp), %edx
	addl	%edx, -104(%rsp)
.L229:
	movslq	%r13d, %rdx
	movl	-112(%rsp), %edi
	movl	-20(%rsp), %esi
	imulq	-40(%rsp), %rdx
	addq	%rcx, %rdx
	cmpl	-28(%rsp), %r8d
	cmove	%r13d, %edi
	cmpl	%esi, -108(%rsp)
	cmove	%r13d, %r15d
	movl	%edi, -112(%rsp)
	jmp	.L227
	.p2align 4,,10
	.p2align 3
.L245:
	cmpl	%edx, %esi
	jne	.L229
	movzbl	-24(%rsp), %ebx
	movl	220(%rsp), %esi
	movl	-16(%rsp), %r9d
	movzbl	249(%rsp), %edi
	testb	%bl, %bl
	leal	(%rsi,%r9), %edx
	cmovne	%edi, %r11d
	cmpl	%edx, %r13d
	cmovl	%edx, %r13d
	movzbl	%bl, %edx
	imull	%esi, %edx
	addl	%edx, -104(%rsp)
	movzbl	%dil, %edx
	imull	%r9d, %edx
	addl	%edx, -92(%rsp)
	jmp	.L229
	.p2align 4,,10
	.p2align 3
.L244:
	cmpl	%esi, %edx
	jne	.L223
	movzbl	3(%rsp), %ebx
	movzbl	248(%rsp), %esi
	movl	$0, %edx
	movl	180(%rsp), %ecx
	movl	4(%rsp), %r9d
	testb	%bl, %bl
	cmovne	%esi, %edx
	movb	%dl, -53(%rsp)
	leal	(%rcx,%r9), %edx
	cmpl	%edx, %r13d
	cmovl	%edx, %r13d
	movzbl	%bl, %edx
	imull	%ecx, %edx
	addl	%edx, -100(%rsp)
	movzbl	%sil, %edx
	imull	%r9d, %edx
	addl	%edx, -96(%rsp)
	jmp	.L223
	.cfi_endproc
.LFE3567:
	.size	_ZN11Solve_mergeplENS_4nodeES0_, .-_ZN11Solve_mergeplENS_4nodeES0_
	.section	.text._ZN11Solve_merge2ST8pushdownEi,"axG",@progbits,_ZN11Solve_merge2ST8pushdownEi,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_merge2ST8pushdownEi
	.type	_ZN11Solve_merge2ST8pushdownEi, @function
_ZN11Solve_merge2ST8pushdownEi:
.LFB3571:
	.cfi_startproc
	endbr64
	movslq	%esi, %rdx
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	leaq	(%rdx,%rdx,2), %rax
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	salq	$5, %rax
	addq	%rdi, %rax
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L250
.L247:
	leaq	(%rdx,%rdx,2), %rax
	salq	$5, %rax
	addq	%rdi, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L251
.L246:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L250:
	.cfi_restore_state
	leal	(%rsi,%rsi), %r9d
	movslq	%r9d, %rcx
	leaq	(%rcx,%rcx,2), %rcx
	salq	$5, %rcx
	addq	%rdi, %rcx
	cmpl	4(%rcx), %r8d
	je	.L247
	movslq	8(%rcx), %r10
	movslq	16(%rcx), %rbx
	orl	$1, %r9d
	movslq	16(%rax), %r11
	movq	88(%rcx), %r14
	movslq	%r9d, %r9
	movl	%r8d, 4(%rcx)
	imulq	%r10, %rbx
	movl	%r8d, 24(%rcx)
	imulq	%r11, %r10
	movl	%r11d, 36(%rcx)
	movl	%r11d, 16(%rcx)
	movslq	16(%rax), %r8
	subq	%rbx, %r14
	addq	%r14, %r10
	movq	%r10, 88(%rcx)
	movl	4(%rax), %r10d
	leaq	(%r9,%r9,2), %rax
	salq	$5, %rax
	addq	%rdi, %rax
	movslq	8(%rax), %rcx
	movslq	16(%rax), %r9
	movl	%r10d, 24(%rax)
	movq	88(%rax), %rbx
	movl	%r10d, 4(%rax)
	imulq	%rcx, %r9
	movl	%r8d, 36(%rax)
	imulq	%r8, %rcx
	movl	%r8d, 16(%rax)
	subq	%r9, %rbx
	addq	%rbx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L247
	.p2align 4,,10
	.p2align 3
.L251:
	addl	%esi, %esi
	movslq	%esi, %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rdi, %rdx
	cmpl	44(%rdx), %ecx
	je	.L246
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %r10
	orl	$1, %esi
	movslq	56(%rax), %r9
	movq	88(%rdx), %rbx
	movslq	%esi, %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %r10
	movl	%ecx, 44(%rdx)
	imulq	%r9, %r8
	movl	%r9d, 76(%rdx)
	movl	%r9d, 56(%rdx)
	subq	%r10, %rbx
	addq	%rbx, %r8
	movq	%r8, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %r8d
	leaq	(%rsi,%rsi,2), %rax
	salq	$5, %rax
	addq	%rax, %rdi
	movslq	48(%rdi), %rax
	movslq	56(%rdi), %rcx
	movl	%r8d, 64(%rdi)
	movq	88(%rdi), %rbx
	movl	%r8d, 44(%rdi)
	imulq	%rax, %rcx
	movl	%edx, 76(%rdi)
	imulq	%rdx, %rax
	movl	%edx, 56(%rdi)
	subq	%rcx, %rbx
	addq	%rbx, %rax
	movq	%rax, 88(%rdi)
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE3571:
	.size	_ZN11Solve_merge2ST8pushdownEi, .-_ZN11Solve_merge2ST8pushdownEi
	.section	.text._ZN11Solve_merge2ST10update_MaxEiiiiiii,"axG",@progbits,_ZN11Solve_merge2ST10update_MaxEiiiiiii,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	.type	_ZN11Solve_merge2ST10update_MaxEiiiiiii, @function
_ZN11Solve_merge2ST10update_MaxEiiiiiii:
.LFB3572:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$344, %rsp
	.cfi_def_cfa_offset 400
	movq	%fs:40, %rax
	movq	%rax, 328(%rsp)
	xorl	%eax, %eax
	cmpl	%esi, %r9d
	jl	.L252
	movl	%edx, %r13d
	movl	%r8d, %r12d
	cmpl	%r8d, %edx
	jl	.L252
	cmpl	%r8d, %esi
	movq	%rdi, %rbx
	movl	%r9d, %ebp
	setge	%dil
	cmpl	%edx, %r9d
	setge	8(%rsp)
	movzbl	8(%rsp), %eax
	testb	%dil, %dil
	je	.L254
	testb	%al, %al
	je	.L254
	movslq	%ecx, %rcx
	leaq	(%rcx,%rcx,2), %rdi
	salq	$5, %rdi
	addq	%rdi, %rbx
	movl	400(%rsp), %edi
	movslq	48(%rbx), %rax
	movslq	56(%rbx), %rdx
	movl	%edi, 64(%rbx)
	movq	88(%rbx), %rsi
	movl	%edi, 44(%rbx)
	movl	408(%rsp), %edi
	imulq	%rax, %rdx
	movslq	%edi, %rcx
	movl	%edi, 76(%rbx)
	imulq	%rcx, %rax
	subq	%rdx, %rsi
	movl	%ecx, 56(%rbx)
	addq	%rsi, %rax
	movq	%rax, 88(%rbx)
.L252:
	movq	328(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L741
	addq	$344, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L254:
	.cfi_restore_state
	leal	(%rcx,%rcx), %r14d
	movslq	%ecx, %r15
	movl	%r14d, %edx
	leaq	(%r15,%r15,2), %rax
	movslq	%r14d, %r14
	orl	$1, %edx
	salq	$5, %rax
	movl	%edx, 40(%rsp)
	addq	%rbx, %rax
	movslq	%edx, %rdx
	movq	%rdx, 16(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L742
.L255:
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L743
.L256:
	leal	(%rsi,%r13), %eax
	leaq	224(%rsp), %r10
	sarl	%eax
	movl	%eax, %r11d
	leal	1(%rax), %eax
	movl	%eax, 24(%rsp)
	cmpl	%r11d, %r12d
	jg	.L257
	cmpl	%r11d, %ebp
	setge	32(%rsp)
	movzbl	32(%rsp), %eax
	testb	%dil, %dil
	je	.L258
	testb	%al, %al
	je	.L258
	leaq	(%r14,%r14,2), %rax
	leaq	224(%rsp), %r10
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	24(%rsp), %ebp
	jl	.L260
	cmpl	24(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%r9b
.L336:
	movl	40(%rsp), %esi
	movq	16(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 32(%rsp)
	movl	%edi, 64(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 48(%rsp)
	cmpl	24(%rax), %ecx
	je	.L744
.L337:
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L745
.L338:
	movl	24(%rsp), %eax
	leal	0(%r13,%rax), %r11d
	sarl	%r11d
	leal	1(%r11), %edi
	movl	%edi, 56(%rsp)
	cmpl	%r11d, %r12d
	jg	.L339
	cmpl	%r11d, %ebp
	setge	88(%rsp)
	jl	.L340
	testb	%r9b, %r9b
	je	.L340
	movq	32(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L342
.L396:
	movl	64(%rsp), %edi
	movq	48(%rsp), %rax
	leal	(%rdi,%rdi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 24(%rsp)
	movl	%edi, 80(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 40(%rsp)
	cmpl	24(%rax), %ecx
	je	.L746
.L397:
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L747
.L398:
	movl	56(%rsp), %eax
	leal	0(%r13,%rax), %r11d
	sarl	%r11d
	leal	1(%r11), %edi
	movl	%edi, 72(%rsp)
	cmpl	%r11d, %r12d
	jg	.L399
	cmpl	%r11d, %ebp
	setge	96(%rsp)
	jl	.L400
	testb	%r9b, %r9b
	je	.L400
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L402
.L411:
	movl	80(%rsp), %edi
	movq	40(%rsp), %rax
	addl	%edi, %edi
	leaq	(%rax,%rax,2), %rax
	movl	%edi, %esi
	salq	$5, %rax
	movl	%edi, 80(%rsp)
	movslq	%edi, %r11
	orl	$1, %esi
	addq	%rbx, %rax
	movslq	%esi, %rdi
	movl	%esi, 88(%rsp)
	movl	4(%rax), %ecx
	movq	%rdi, 56(%rsp)
	cmpl	24(%rax), %ecx
	je	.L748
.L412:
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L749
.L413:
	movl	72(%rsp), %eax
	leal	0(%r13,%rax), %edx
	sarl	%edx
	leal	1(%rdx), %edi
	movl	%edi, 64(%rsp)
	cmpl	%edx, %r12d
	jg	.L414
	cmpl	%edx, %ebp
	jl	.L415
	testb	%r9b, %r9b
	je	.L415
	leaq	(%r11,%r11,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%edi, %ebp
	jl	.L417
.L416:
	movl	408(%rsp), %eax
	movl	%r13d, %edx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 72(%rsp)
	movq	%rbx, %rdi
	movq	%r11, 8(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	104(%rsp), %ecx
	movl	80(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movq	8(%rsp), %r11
.L417:
	movq	40(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	56(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	leaq	(%r11,%r11,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, 0(%rbp)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rbp)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rbp)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rbp)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rbp)
	movdqu	496(%rsp), %xmm1
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rbp)
.L402:
	movq	48(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	40(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, 0(%rbp)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rbp)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rbp)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rbp)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rbp)
	movdqu	496(%rsp), %xmm7
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rbp)
.L342:
	movq	16(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	48(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, 0(%rbp)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rbp)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rbp)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rbp)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rbp)
	movdqu	496(%rsp), %xmm3
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm3, 80(%rbp)
.L260:
	movq	16(%rsp), %rax
	leaq	(%r15,%r15,2), %rbp
	leaq	(%r14,%r14,2), %rdi
	salq	$5, %rdi
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	addq	%rdi, %rbx
	movq	%r10, %rdi
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	pushq	88(%rbx)
	.cfi_def_cfa_offset 504
	pushq	80(%rbx)
	.cfi_def_cfa_offset 512
	pushq	72(%rbx)
	.cfi_def_cfa_offset 520
	pushq	64(%rbx)
	.cfi_def_cfa_offset 528
	pushq	56(%rbx)
	.cfi_def_cfa_offset 536
	pushq	48(%rbx)
	.cfi_def_cfa_offset 544
	pushq	40(%rbx)
	.cfi_def_cfa_offset 552
	pushq	32(%rbx)
	.cfi_def_cfa_offset 560
	pushq	24(%rbx)
	.cfi_def_cfa_offset 568
	pushq	16(%rbx)
	.cfi_def_cfa_offset 576
	pushq	8(%rbx)
	.cfi_def_cfa_offset 584
	pushq	(%rbx)
	.cfi_def_cfa_offset 592
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, 0(%rbp)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rbp)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rbp)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rbp)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rbp)
	movdqu	496(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm5, 80(%rbp)
	jmp	.L252
	.p2align 4,,10
	.p2align 3
.L258:
	leal	0(,%rcx,4), %edx
	leaq	(%r14,%r14,2), %rax
	movl	%edx, %r10d
	salq	$5, %rax
	movslq	%edx, %rdx
	orl	$1, %r10d
	movq	%rdx, 48(%rsp)
	addq	%rbx, %rax
	movslq	%r10d, %rdx
	movl	%r10d, 88(%rsp)
	movl	4(%rax), %r8d
	movq	%rdx, 56(%rsp)
	cmpl	24(%rax), %r8d
	je	.L750
.L261:
	leaq	(%r14,%r14,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L751
.L262:
	leal	(%rsi,%r11), %eax
	leaq	224(%rsp), %r10
	sarl	%eax
	leal	1(%rax), %edx
	movl	%eax, 80(%rsp)
	movl	%edx, 64(%rsp)
	cmpl	%eax, %r12d
	jg	.L263
	cmpl	80(%rsp), %ebp
	setge	72(%rsp)
	movzbl	72(%rsp), %eax
	testb	%dil, %dil
	je	.L264
	testb	%al, %al
	je	.L264
	movq	48(%rsp), %rax
	leaq	224(%rsp), %r10
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	64(%rsp), %ebp
	jl	.L266
	cmpl	64(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%r9b
.L305:
	movl	88(%rsp), %esi
	movq	56(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 72(%rsp)
	movl	%edi, 112(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 80(%rsp)
	cmpl	24(%rax), %ecx
	je	.L752
.L306:
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L753
.L307:
	movl	64(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 104(%rsp)
	movl	%edi, 96(%rsp)
	cmpl	%eax, %r12d
	jg	.L308
	cmpl	%eax, %ebp
	setge	128(%rsp)
	jl	.L309
	testb	%r9b, %r9b
	je	.L309
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L311
.L320:
	movl	112(%rsp), %esi
	movq	80(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 64(%rsp)
	movl	%edi, 120(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 88(%rsp)
	cmpl	24(%rax), %ecx
	je	.L754
.L321:
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L755
.L322:
	movl	96(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%edi, 104(%rsp)
	cmpl	%eax, %r12d
	jg	.L323
	cmpl	%eax, %ebp
	setge	136(%rsp)
	jl	.L324
	testb	%r9b, %r9b
	je	.L324
	movq	64(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%edi, %ebp
	jl	.L326
.L325:
	movl	408(%rsp), %eax
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%r10, 32(%rsp)
	movl	%r11d, %edx
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	136(%rsp), %ecx
	movl	120(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	32(%rsp), %r10
.L326:
	movq	80(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 96(%rsp)
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	160(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	288(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rax)
.L311:
	movq	56(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 64(%rsp)
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	168(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rax)
.L266:
	leaq	(%r14,%r14,2), %rax
	movq	%r10, %rdi
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 64(%rsp)
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rax)
.L257:
	movl	24(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L260
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %r9d
	je	.L336
	testb	%al, %al
	je	.L336
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L260
	.p2align 4,,10
	.p2align 3
.L743:
	leaq	(%r14,%r14,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L256
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %r11
	movslq	56(%rax), %r10
	movl	%r8d, 64(%rdx)
	imulq	%r9, %r11
	movq	%r9, 24(%rsp)
	movq	88(%rdx), %r9
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	24(%rsp), %r10
	subq	%r11, %r9
	movl	%r8d, 44(%rdx)
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movq	88(%rax), %r11
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movl	%r10d, 64(%rax)
	imulq	%rdx, %r8
	movl	%r10d, 44(%rax)
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rax)
	jmp	.L256
	.p2align 4,,10
	.p2align 3
.L742:
	leaq	(%r14,%r14,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L255
	movslq	8(%rdx), %r9
	movslq	16(%rdx), %r11
	movslq	16(%rax), %r10
	movl	%r8d, 4(%rdx)
	imulq	%r9, %r11
	movq	%r9, 24(%rsp)
	movq	88(%rdx), %r9
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	24(%rsp), %r10
	subq	%r11, %r9
	movl	%r8d, 24(%rdx)
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movq	88(%rax), %r11
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movl	%r10d, 24(%rax)
	imulq	%rdx, %r8
	movl	%r10d, 4(%rax)
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rax)
	jmp	.L255
	.p2align 4,,10
	.p2align 3
.L264:
	movq	48(%rsp), %rax
	leal	0(,%rcx,8), %edx
	movl	%edx, %r9d
	movslq	%edx, %rdx
	leaq	(%rax,%rax,2), %rax
	orl	$1, %r9d
	movq	%rdx, 96(%rsp)
	salq	$5, %rax
	movslq	%r9d, %rdx
	movl	%r9d, 128(%rsp)
	addq	%rbx, %rax
	movq	%rdx, 104(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L756
.L267:
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L757
.L268:
	movl	80(%rsp), %eax
	leal	(%rsi,%rax), %r10d
	sarl	%r10d
	leal	1(%r10), %eax
	movl	%eax, 112(%rsp)
	cmpl	%r10d, %r12d
	jg	.L758
	cmpl	%r10d, %ebp
	setge	120(%rsp)
	movzbl	120(%rsp), %eax
	testb	%dil, %dil
	je	.L270
	testb	%al, %al
	je	.L270
	movq	96(%rsp), %rax
	leaq	224(%rsp), %r10
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	112(%rsp), %ebp
	jl	.L272
	cmpl	112(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%r9b
.L281:
	movl	128(%rsp), %edi
	movq	104(%rsp), %rax
	leal	(%rdi,%rdi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 120(%rsp)
	movl	%esi, 152(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 136(%rsp)
	cmpl	24(%rax), %ecx
	je	.L759
.L282:
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L760
.L283:
	movl	80(%rsp), %eax
	addl	112(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%edi, 144(%rsp)
	cmpl	%eax, %r12d
	jg	.L284
	cmpl	%eax, %ebp
	setge	168(%rsp)
	jl	.L285
	testb	%r9b, %r9b
	je	.L285
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	128(%rsp)
	cmpl	%edi, %ebp
	jl	.L287
.L296:
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	152(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %edi
	movl	%eax, 168(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %edi
	movl	%edi, 160(%rsp)
	movslq	%edi, %rdi
	movq	%rdi, 112(%rsp)
	cmpl	24(%r8), %ecx
	je	.L761
.L297:
	movq	136(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L762
.L298:
	movl	80(%rsp), %edx
	addl	144(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 152(%rsp)
	cmpl	%edx, %r12d
	jg	.L299
	cmpl	%edx, %ebp
	jl	.L300
	cmpb	$0, 128(%rsp)
	je	.L300
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L302
.L301:
	movl	%r11d, 72(%rsp)
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%rax, 128(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 144(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	96(%rsp), %edx
	movl	168(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	144(%rsp), %r10
	movq	128(%rsp), %rax
	movl	72(%rsp), %r11d
.L302:
	movq	136(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movl	%r11d, 128(%rsp)
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	112(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 80(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rdx
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rdx)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rdx)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rdx)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rdx)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rdx)
	movdqu	496(%rsp), %xmm7
	movl	320(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm7, 80(%rdx)
.L287:
	movq	104(%rsp), %rax
	movl	%r11d, 112(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 80(%rsp)
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	216(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	304(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L272:
	movq	48(%rsp), %rax
	movl	%r11d, 112(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 80(%rsp)
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	192(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movl	304(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm5, 80(%rax)
.L263:
	movl	64(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L266
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 32(%rsp)
	movl	%eax, %r9d
	je	.L305
	testb	%al, %al
	je	.L305
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L266
	.p2align 4,,10
	.p2align 3
.L340:
	movl	40(%rsp), %esi
	movq	32(%rsp), %rax
	leal	0(,%rsi,4), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 72(%rsp)
	movl	%esi, 112(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 80(%rsp)
	cmpl	24(%rax), %ecx
	je	.L763
.L343:
	movq	32(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L764
.L344:
	movl	24(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 104(%rsp)
	movl	%edi, 96(%rsp)
	cmpl	%eax, %r12d
	jg	.L345
	cmpl	%eax, %ebp
	setge	136(%rsp)
	jl	.L346
	testb	%r9b, %r9b
	je	.L346
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L348
.L372:
	movl	112(%rsp), %esi
	movq	80(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 24(%rsp)
	movl	%edi, 120(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 40(%rsp)
	cmpl	24(%rax), %ecx
	je	.L765
.L373:
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L766
.L374:
	movl	96(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%edi, 104(%rsp)
	cmpl	%eax, %r12d
	jg	.L375
	cmpl	%eax, %ebp
	setge	136(%rsp)
	jl	.L376
	testb	%r9b, %r9b
	je	.L376
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	112(%rsp)
	cmpl	%edi, %ebp
	jl	.L378
.L387:
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	120(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %edi
	movl	%eax, 128(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %edi
	movslq	%edi, %rsi
	movl	%edi, 136(%rsp)
	movq	%rsi, 96(%rsp)
	cmpl	24(%r8), %ecx
	je	.L767
.L388:
	movq	40(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L768
.L389:
	movl	104(%rsp), %ecx
	leal	(%r11,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 120(%rsp)
	cmpl	%edx, %r12d
	jg	.L390
	cmpl	%edx, %ebp
	jl	.L391
	cmpb	$0, 112(%rsp)
	je	.L391
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L393
.L392:
	movq	%rax, 88(%rsp)
	movl	%r11d, %edx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	408(%rsp), %eax
	movq	%r10, 104(%rsp)
	movq	%rbx, %rdi
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	152(%rsp), %ecx
	movl	136(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	104(%rsp), %r10
	movq	88(%rsp), %rax
.L393:
	movq	40(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	96(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 104(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 280(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	296(%rsp), %rdx
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rdx)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rdx)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rdx)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rdx)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rdx)
	movdqu	496(%rsp), %xmm7
	movq	280(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rdx)
.L378:
	movq	80(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 88(%rsp)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	280(%rsp), %rax
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, (%rax)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movq	216(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rax)
.L348:
	movq	32(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 40(%rsp)
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	168(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	232(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movq	216(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm5, 80(%rax)
.L339:
	movl	56(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L342
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %r9d
	je	.L396
	testb	%al, %al
	je	.L396
	movq	48(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L342
	.p2align 4,,10
	.p2align 3
.L745:
	movq	32(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L338
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 44(%rdx)
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	%rsi, %rdi
	movslq	56(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L338
	.p2align 4,,10
	.p2align 3
.L744:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L337
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 24(%rdx)
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	%rsi, %rdi
	movslq	16(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L337
	.p2align 4,,10
	.p2align 3
.L751:
	movq	48(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L262
	movl	56(%rax), %r10d
	movslq	48(%rdx), %r9
	movl	%r8d, 64(%rdx)
	movl	%r8d, 44(%rdx)
	movl	%r10d, 64(%rsp)
	movq	%r9, %r10
	movslq	56(%rdx), %r9
	movq	%r10, 72(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	64(%rsp), %r10
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	72(%rsp), %r10
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 64(%rsp)
	movq	88(%rax), %rdx
	imulq	64(%rsp), %r8
	movl	%r10d, 64(%rax)
	movl	%r10d, 44(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L262
	.p2align 4,,10
	.p2align 3
.L750:
	movq	48(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L261
	movl	16(%rax), %r10d
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%r10d, 64(%rsp)
	movq	%r9, %r10
	movslq	16(%rdx), %r9
	movq	%r10, 72(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	64(%rsp), %r10
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	72(%rsp), %r10
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 64(%rsp)
	movq	88(%rax), %rdx
	imulq	64(%rsp), %r8
	movl	%r10d, 24(%rax)
	movl	%r10d, 4(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L261
	.p2align 4,,10
	.p2align 3
.L346:
	movl	40(%rsp), %edi
	movq	72(%rsp), %rax
	leal	0(,%rdi,8), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 120(%rsp)
	movl	%esi, 160(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 128(%rsp)
	cmpl	24(%rax), %ecx
	je	.L769
.L349:
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L770
.L350:
	movl	104(%rsp), %eax
	addl	24(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 152(%rsp)
	movl	%edi, 144(%rsp)
	cmpl	%eax, %r12d
	jg	.L351
	cmpl	%eax, %ebp
	movq	120(%rsp), %rax
	setge	176(%rsp)
	jl	.L352
	testb	%r9b, %r9b
	je	.L352
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	40(%rsp)
	cmpl	%edi, %ebp
	jl	.L354
.L363:
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	160(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %esi
	movl	%eax, 160(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %esi
	movslq	%esi, %rdi
	movl	%esi, 168(%rsp)
	movq	%rdi, 24(%rsp)
	cmpl	24(%r8), %ecx
	je	.L771
.L364:
	movq	128(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L772
.L365:
	movl	104(%rsp), %edx
	addl	144(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 152(%rsp)
	cmpl	%edx, %r12d
	jg	.L366
	cmpl	%edx, %ebp
	jl	.L367
	cmpb	$0, 40(%rsp)
	je	.L367
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L369
.L368:
	movl	%r11d, 40(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%rax, 136(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 144(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	184(%rsp), %ecx
	movl	120(%rsp), %edx
	movl	168(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	144(%rsp), %r10
	movq	136(%rsp), %rax
	movl	40(%rsp), %r11d
.L369:
	movq	128(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movl	%r11d, 104(%rsp)
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	24(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 40(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	232(%rsp), %rdx
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rdx)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rdx)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rdx)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rdx)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rdx)
	movdqu	496(%rsp), %xmm5
	movl	296(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	24(%rsp), %r10
	movups	%xmm5, 80(%rdx)
.L354:
	movq	72(%rsp), %rax
	movl	%r11d, 104(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 40(%rsp)
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	216(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	232(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movl	296(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	24(%rsp), %r10
	movups	%xmm5, 80(%rax)
.L345:
	movl	96(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L348
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 88(%rsp)
	movl	%eax, %r9d
	je	.L372
	testb	%al, %al
	je	.L372
	movq	80(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L348
	.p2align 4,,10
	.p2align 3
.L309:
	movl	88(%rsp), %edi
	movq	72(%rsp), %rax
	sall	$2, %edi
	leaq	(%rax,%rax,2), %rax
	movl	%edi, %esi
	salq	$5, %rax
	movl	%edi, 136(%rsp)
	movslq	%edi, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 88(%rsp)
	movl	%esi, 144(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 120(%rsp)
	cmpl	24(%rax), %ecx
	je	.L773
.L312:
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L774
.L313:
	movl	104(%rsp), %edx
	addl	64(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L314
	cmpl	%edx, %ebp
	jl	.L315
	testb	%r9b, %r9b
	je	.L315
	movq	88(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L317
.L316:
	movl	408(%rsp), %ecx
	movl	%eax, %esi
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 128(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 64(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	160(%rsp), %ecx
	movl	120(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	128(%rsp), %r10
	movl	64(%rsp), %r11d
.L317:
	movq	72(%rsp), %rax
	movl	%r11d, 128(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 104(%rsp)
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	184(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 256(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	296(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	320(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	64(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L308:
	movl	96(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L311
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 32(%rsp)
	movl	%eax, %r9d
	je	.L320
	testb	%al, %al
	je	.L320
	movq	80(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L311
	.p2align 4,,10
	.p2align 3
.L400:
	movl	64(%rsp), %edi
	movq	24(%rsp), %rax
	sall	$2, %edi
	leaq	(%rax,%rax,2), %rax
	movl	%edi, %esi
	salq	$5, %rax
	movl	%edi, 104(%rsp)
	movslq	%edi, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 64(%rsp)
	movl	%esi, 112(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 88(%rsp)
	cmpl	24(%rax), %ecx
	je	.L775
.L403:
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L776
.L404:
	movl	56(%rsp), %eax
	leal	(%rax,%r11), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L405
	cmpl	%edx, %ebp
	jl	.L406
	testb	%r9b, %r9b
	je	.L406
	movq	64(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L408
.L407:
	movl	408(%rsp), %ecx
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%r10, 56(%rsp)
	movl	%r11d, %edx
	movl	%eax, %esi
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	128(%rsp), %ecx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	56(%rsp), %r10
.L408:
	movq	24(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 96(%rsp)
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	160(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 248(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	288(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movq	248(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm3, 80(%rax)
.L399:
	movl	72(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L402
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %r9d
	je	.L411
	testb	%al, %al
	je	.L411
	movq	40(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L402
	.p2align 4,,10
	.p2align 3
.L746:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L397
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 24(%rdx)
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	%rsi, %rdi
	movslq	16(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L397
	.p2align 4,,10
	.p2align 3
.L752:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L306
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L306
	.p2align 4,,10
	.p2align 3
.L753:
	movq	72(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L307
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 44(%rdx)
	movslq	56(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L307
	.p2align 4,,10
	.p2align 3
.L747:
	movq	24(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L398
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 44(%rdx)
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	%rsi, %rdi
	movslq	56(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L398
	.p2align 4,,10
	.p2align 3
.L757:
	movq	96(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L268
	movl	56(%rax), %r10d
	movslq	48(%rdx), %r9
	movl	%r8d, 64(%rdx)
	movl	%r8d, 44(%rdx)
	movl	%r10d, 112(%rsp)
	movq	%r9, %r10
	movslq	56(%rdx), %r9
	movq	%r10, 120(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	112(%rsp), %r10
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	120(%rsp), %r10
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 112(%rsp)
	movq	88(%rax), %rdx
	imulq	112(%rsp), %r8
	movl	%r10d, 64(%rax)
	movl	%r10d, 44(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L268
	.p2align 4,,10
	.p2align 3
.L756:
	movq	96(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L267
	movl	16(%rax), %r10d
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%r10d, 112(%rsp)
	movq	%r9, %r10
	movslq	16(%rdx), %r9
	movq	%r10, 120(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	112(%rsp), %r10
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	120(%rsp), %r10
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 112(%rsp)
	movq	88(%rax), %rdx
	imulq	112(%rsp), %r8
	movl	%r10d, 24(%rax)
	movl	%r10d, 4(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L267
	.p2align 4,,10
	.p2align 3
.L758:
	leaq	224(%rsp), %r10
.L269:
	movl	112(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L272
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 72(%rsp)
	movl	%eax, %r9d
	je	.L281
	testb	%al, %al
	je	.L281
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L272
	.p2align 4,,10
	.p2align 3
.L764:
	movq	72(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L344
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 44(%rdx)
	movslq	56(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L344
	.p2align 4,,10
	.p2align 3
.L763:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L343
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L343
	.p2align 4,,10
	.p2align 3
.L270:
	movq	96(%rsp), %rax
	sall	$4, %ecx
	movslq	%ecx, %rdx
	orl	$1, %ecx
	leaq	(%rax,%rax,2), %rax
	movl	%ecx, 160(%rsp)
	movslq	%ecx, %rcx
	salq	$5, %rax
	movl	%edx, 168(%rsp)
	addq	%rbx, %rax
	movq	%rdx, 136(%rsp)
	movq	%rcx, 144(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L777
.L273:
	movq	96(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L778
.L274:
	leal	(%rsi,%r10), %edx
	sarl	%edx
	leal	1(%rdx), %r9d
	movl	%r9d, 152(%rsp)
	cmpl	%edx, %r12d
	jg	.L275
	cmpl	%edx, %ebp
	jl	.L276
	testb	%dil, %dil
	je	.L276
	movq	136(%rsp), %rax
	movl	408(%rsp), %edi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%edi, 76(%rax)
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	%edi, %rsi
	imulq	%rsi, %rdx
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%r9d, %ebp
	jl	.L278
.L277:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%r10d, %edx
	movl	%r11d, 120(%rsp)
	movq	%rbx, %rdi
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	168(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movl	120(%rsp), %r11d
.L278:
	movq	96(%rsp), %rax
	leaq	224(%rsp), %r10
	movl	%r11d, 160(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 152(%rsp)
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	232(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 312(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	344(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movl	160(%rsp), %r11d
	movq	120(%rsp), %r10
	movups	%xmm3, 80(%rax)
	jmp	.L269
.L406:
	movl	%eax, 120(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movl	%r11d, 128(%rsp)
	movq	%r10, 136(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	120(%rsp), %ecx
	movl	72(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	136(%rsp), %r10
	movl	128(%rsp), %r11d
	movl	120(%rsp), %eax
.L405:
	cmpl	%eax, %ebp
	jl	.L408
	cmpl	%eax, %r12d
	jg	.L407
	cmpb	$0, 96(%rsp)
	je	.L407
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L408
.L276:
	movl	408(%rsp), %eax
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movl	%r10d, 184(%rsp)
	movl	%r11d, 176(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	184(%rsp), %ecx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movl	184(%rsp), %r10d
	movl	176(%rsp), %r11d
.L275:
	movl	152(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L278
	cmpl	%eax, %r12d
	jg	.L277
	cmpb	$0, 120(%rsp)
	je	.L277
	movq	144(%rsp), %rax
	movl	400(%rsp), %edi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%edi, 64(%rax)
	movq	88(%rax), %rsi
	movl	%edi, 44(%rax)
	imulq	%rdx, %rcx
	movl	408(%rsp), %edi
	movl	%edi, 76(%rax)
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movslq	%edi, %rsi
	imulq	%rsi, %rdx
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L278
.L315:
	movl	%eax, 160(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movl	%r11d, 152(%rsp)
	movq	%r10, 168(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	152(%rsp), %ecx
	movl	80(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	168(%rsp), %r10
	movl	160(%rsp), %eax
	movl	152(%rsp), %r11d
.L314:
	cmpl	%eax, %ebp
	jl	.L317
	cmpl	%eax, %r12d
	jg	.L316
	cmpb	$0, 128(%rsp)
	je	.L316
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L317
.L285:
	movq	120(%rsp), %rcx
	movl	128(%rsp), %esi
	leaq	(%rcx,%rcx,2), %r8
	sall	$2, %esi
	movslq	%esi, %rdi
	salq	$5, %r8
	orl	$1, %esi
	movl	%edi, 196(%rsp)
	addq	%rbx, %r8
	movq	%rdi, 160(%rsp)
	movslq	%esi, %rdi
	movl	4(%r8), %ecx
	movl	%esi, 184(%rsp)
	movq	%rdi, 128(%rsp)
	cmpl	24(%r8), %ecx
	je	.L779
.L288:
	movq	120(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L780
.L289:
	movl	112(%rsp), %ecx
	leal	(%rax,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 176(%rsp)
	cmpl	%edx, %r12d
	jg	.L290
	cmpl	%edx, %ebp
	jl	.L291
	testb	%r9b, %r9b
	je	.L291
	movq	160(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L293
.L292:
	movl	408(%rsp), %ecx
	movl	%eax, %edx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 168(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 112(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	200(%rsp), %ecx
	movl	192(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	168(%rsp), %r10
	movl	112(%rsp), %r11d
.L293:
	movq	120(%rsp), %rax
	movl	%r11d, 176(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 168(%rsp)
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	256(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 304(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	360(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movl	368(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	112(%rsp), %r10
	movups	%xmm7, 80(%rax)
.L284:
	movl	144(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L287
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 72(%rsp)
	movb	%al, 128(%rsp)
	je	.L296
	testb	%al, %al
	je	.L296
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movq	88(%rax), %rdi
	imulq	%rdx, %rcx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movl	408(%rsp), %edi
	movslq	%edi, %rsi
	movl	%edi, 76(%rax)
	imulq	%rsi, %rdx
	movl	%esi, 56(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L287
.L376:
	movq	24(%rsp), %rcx
	movl	112(%rsp), %esi
	leaq	(%rcx,%rcx,2), %r8
	sall	$2, %esi
	movslq	%esi, %rdi
	salq	$5, %r8
	orl	$1, %esi
	movl	%edi, 152(%rsp)
	addq	%rbx, %r8
	movq	%rdi, 112(%rsp)
	movslq	%esi, %rdi
	movl	4(%r8), %ecx
	movl	%esi, 160(%rsp)
	movq	%rdi, 128(%rsp)
	cmpl	24(%r8), %ecx
	je	.L781
.L379:
	movq	24(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L782
.L380:
	movl	96(%rsp), %ecx
	leal	(%rax,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 144(%rsp)
	cmpl	%edx, %r12d
	jg	.L381
	cmpl	%edx, %ebp
	jl	.L382
	testb	%r9b, %r9b
	je	.L382
	movq	112(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L384
.L383:
	movl	408(%rsp), %ecx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%eax, %edx
	movq	%r10, 136(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 96(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	136(%rsp), %r10
	movl	96(%rsp), %r11d
.L384:
	movq	24(%rsp), %rax
	movl	%r11d, 144(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 136(%rsp)
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	208(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 288(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	328(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movl	336(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	96(%rsp), %r10
	movups	%xmm1, 80(%rax)
.L375:
	movl	104(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L378
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 88(%rsp)
	movb	%al, 112(%rsp)
	je	.L387
	testb	%al, %al
	je	.L387
	movq	40(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L378
.L352:
	movl	40(%rsp), %edi
	leaq	(%rax,%rax,2), %r8
	salq	$5, %r8
	sall	$4, %edi
	addq	%rbx, %r8
	movl	%edi, %ecx
	movslq	%edi, %rsi
	movl	%edi, 196(%rsp)
	movl	4(%r8), %eax
	orl	$1, %ecx
	movq	%rsi, 168(%rsp)
	movl	%ecx, 184(%rsp)
	movslq	%ecx, %rcx
	movq	%rcx, 40(%rsp)
	cmpl	24(%r8), %eax
	je	.L783
.L355:
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %edx
	cmpl	64(%rax), %edx
	je	.L784
.L356:
	movl	152(%rsp), %edx
	addl	24(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L357
	cmpl	%edx, %ebp
	jl	.L358
	testb	%r9b, %r9b
	je	.L358
	movq	168(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L360
.L359:
	movl	408(%rsp), %ecx
	movl	%eax, %esi
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 176(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 24(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	200(%rsp), %ecx
	movl	168(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	176(%rsp), %r10
	movl	24(%rsp), %r11d
.L360:
	movq	120(%rsp), %rax
	movl	%r11d, 176(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 152(%rsp)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	264(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	344(%rsp), %rax
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, (%rax)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	368(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	24(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L351:
	movl	144(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L354
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 136(%rsp)
	movb	%al, 40(%rsp)
	je	.L363
	testb	%al, %al
	je	.L363
	movq	128(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L354
.L324:
	movq	64(%rsp), %rcx
	movl	112(%rsp), %edi
	leaq	(%rcx,%rcx,2), %r8
	sall	$2, %edi
	movslq	%edi, %rsi
	salq	$5, %r8
	orl	$1, %edi
	movl	%edi, 160(%rsp)
	addq	%rbx, %r8
	movslq	%edi, %rdi
	movl	%esi, 152(%rsp)
	movl	4(%r8), %ecx
	movq	%rsi, 128(%rsp)
	movq	%rdi, 112(%rsp)
	cmpl	24(%r8), %ecx
	je	.L785
.L327:
	movq	64(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L786
.L328:
	movl	96(%rsp), %ecx
	leal	(%rax,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 144(%rsp)
	cmpl	%edx, %r12d
	jg	.L329
	cmpl	%edx, %ebp
	jl	.L330
	testb	%r9b, %r9b
	je	.L330
	movq	128(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L332
.L331:
	movl	408(%rsp), %ecx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%eax, %edx
	movl	%r11d, 96(%rsp)
	movq	%rbx, %rdi
	movq	%r10, 136(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	136(%rsp), %r10
	movl	96(%rsp), %r11d
.L332:
	movq	64(%rsp), %rax
	movl	%r11d, 144(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 136(%rsp)
	movq	112(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	224(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 288(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	328(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movl	336(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	96(%rsp), %r10
	movups	%xmm7, 80(%rax)
.L323:
	movl	104(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L326
	cmpl	%eax, %r12d
	jg	.L325
	cmpb	$0, 32(%rsp)
	je	.L325
	movq	88(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L326
.L415:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%r11, 96(%rsp)
	movq	%r10, 104(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	96(%rsp), %ecx
	movl	88(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	104(%rsp), %r10
	movq	96(%rsp), %r11
.L414:
	movl	64(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L417
	cmpl	%eax, %r12d
	jg	.L416
	cmpb	$0, 8(%rsp)
	je	.L416
	movq	56(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L417
.L770:
	movq	120(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L350
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L350
.L769:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L349
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L349
.L749:
	leaq	(%r11,%r11,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L413
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 64(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	64(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L413
.L748:
	leaq	(%r11,%r11,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L412
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 64(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	64(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L412
.L755:
	movq	64(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L322
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L322
.L754:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L321
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L321
.L776:
	movq	64(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L404
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 120(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	120(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L404
.L775:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L403
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 120(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	120(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L403
.L777:
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L273
	movl	16(%rax), %ecx
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%ecx, 152(%rsp)
	movq	%r9, %rcx
	movslq	16(%rdx), %r9
	movq	%rcx, 176(%rsp)
	imulq	%rcx, %r9
	movq	88(%rdx), %rcx
	subq	%r9, %rcx
	movq	%rcx, %r9
	movslq	152(%rsp), %rcx
	movl	%ecx, 36(%rdx)
	movl	%ecx, 16(%rdx)
	imulq	176(%rsp), %rcx
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	movslq	16(%rax), %rcx
	movl	4(%rax), %r8d
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	movl	%r8d, 152(%rsp)
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %r9
	movslq	16(%rax), %rdx
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%r9, %rdx
	imulq	%r9, %rcx
	subq	%rdx, %r8
	movq	%r8, %rdx
	movl	152(%rsp), %r8d
	addq	%rdx, %rcx
	movl	%r8d, 24(%rax)
	movl	%r8d, 4(%rax)
	movq	%rcx, 88(%rax)
	jmp	.L273
.L759:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L282
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L282
.L760:
	movq	120(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L283
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L283
.L766:
	movq	24(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L374
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	104(%rsp), %rsi
	movl	%ecx, 44(%rdx)
	subq	%rdi, %r8
	movslq	56(%rax), %rcx
	movl	44(%rax), %edi
	movq	40(%rsp), %rax
	addq	%r8, %rsi
	leaq	(%rax,%rax,2), %rax
	movq	%rsi, 88(%rdx)
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L374
.L765:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L373
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movl	4(%rax), %edi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L373
.L774:
	movq	88(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L313
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 152(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	152(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L313
.L773:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L312
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 152(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	152(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L312
.L778:
	movq	136(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L274
	movl	56(%rax), %r9d
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%r9d, 152(%rsp)
	movslq	48(%rdx), %r9
	movslq	152(%rsp), %rcx
	movq	%r9, %r8
	movslq	56(%rdx), %r9
	movl	%ecx, 76(%rdx)
	imulq	%r8, %r9
	movl	%ecx, 56(%rdx)
	movq	%r8, 176(%rsp)
	movq	88(%rdx), %r8
	imulq	176(%rsp), %rcx
	subq	%r9, %r8
	addq	%r8, %rcx
	movl	44(%rax), %r8d
	movq	%rcx, 88(%rdx)
	movslq	56(%rax), %rcx
	movq	144(%rsp), %rax
	movl	%r8d, 152(%rsp)
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r9
	movslq	56(%rax), %rdx
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%r9, %rdx
	imulq	%r9, %rcx
	subq	%rdx, %r8
	movq	%r8, %rdx
	movl	152(%rsp), %r8d
	addq	%rdx, %rcx
	movl	%r8d, 64(%rax)
	movl	%r8d, 44(%rax)
	movq	%rcx, 88(%rax)
	jmp	.L274
.L382:
	movl	%eax, 176(%rsp)
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movl	408(%rsp), %eax
	movl	%r11d, 168(%rsp)
	movq	%r10, 184(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	168(%rsp), %ecx
	movl	112(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movl	176(%rsp), %eax
	movl	168(%rsp), %r11d
.L381:
	movl	144(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L384
	cmpl	%ecx, %r12d
	jg	.L383
	cmpb	$0, 136(%rsp)
	je	.L383
	movq	128(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 64(%rax)
	movl	%esi, 44(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rdx, %rcx
	movq	88(%rax), %rdi
	imulq	%rsi, %rdx
	movl	%esi, 76(%rax)
	movl	%esi, 56(%rax)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L384
.L291:
	movl	%eax, 208(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 216(%rsp)
	movl	%r11d, 200(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	212(%rsp), %ecx
	movl	128(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	216(%rsp), %r10
	movl	208(%rsp), %eax
	movl	200(%rsp), %r11d
.L290:
	movl	176(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L293
	cmpl	%ecx, %r12d
	jg	.L292
	cmpb	$0, 168(%rsp)
	je	.L292
	movq	128(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L293
.L391:
	movl	%r11d, 112(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%rax, 144(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 152(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	144(%rsp), %ecx
	movl	120(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	152(%rsp), %r10
	movq	144(%rsp), %rax
	movl	112(%rsp), %r11d
.L390:
	movl	120(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L393
	cmpl	%ecx, %r12d
	jg	.L392
	cmpb	$0, 88(%rsp)
	je	.L392
	movq	96(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L393
.L330:
	movl	%eax, 176(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 184(%rsp)
	movl	%r11d, 168(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	168(%rsp), %ecx
	movl	112(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movl	176(%rsp), %eax
	movl	168(%rsp), %r11d
.L329:
	movl	144(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L332
	cmpl	%ecx, %r12d
	jg	.L331
	cmpb	$0, 136(%rsp)
	je	.L331
	movq	112(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L332
.L358:
	movl	%eax, 208(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 216(%rsp)
	movl	%r11d, 200(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	212(%rsp), %ecx
	movl	40(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	216(%rsp), %r10
	movl	208(%rsp), %eax
	movl	200(%rsp), %r11d
.L357:
	cmpl	%eax, %ebp
	jl	.L360
	cmpl	%eax, %r12d
	jg	.L359
	cmpb	$0, 176(%rsp)
	je	.L359
	movq	40(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rcx
	movl	%esi, 76(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 56(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 64(%rax)
	movl	%edi, 44(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L360
.L367:
	movl	%r11d, 40(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%rax, 176(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 184(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movq	176(%rsp), %rax
	movl	40(%rsp), %r11d
.L366:
	movl	152(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L369
	cmpl	%ecx, %r12d
	jg	.L368
	cmpb	$0, 136(%rsp)
	je	.L368
	movq	24(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L369
.L300:
	movq	%rax, 176(%rsp)
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 184(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 128(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	184(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movq	176(%rsp), %rax
	movl	128(%rsp), %r11d
.L299:
	movl	152(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L302
	cmpl	%ecx, %r12d
	jg	.L301
	cmpb	$0, 72(%rsp)
	je	.L301
	movq	112(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %rcx
	movslq	56(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L302
.L771:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L364
	imulq	$96, 128(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 176(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 152(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	152(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 24(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L364
.L772:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L365
	imulq	$96, %rax, %rdx
	imulq	$96, 128(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 152(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	152(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 24(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L365
.L762:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L298
	imulq	$96, %rax, %rdx
	imulq	$96, 136(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 152(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	152(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L298
.L761:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L297
	imulq	$96, 136(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 176(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 152(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	152(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L297
.L768:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L389
	imulq	$96, %rax, %rdx
	imulq	$96, 40(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 120(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	120(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 96(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L389
.L780:
	movq	160(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L289
	imulq	$96, %rsi, %rdx
	imulq	$96, 120(%rsp), %r8
	addq	%rbx, %rdx
	addq	%rbx, %r8
	movslq	48(%rdx), %rsi
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%edi, 176(%rsp)
	movq	%rsi, %rdi
	movslq	56(%rdx), %rsi
	movslq	176(%rsp), %rcx
	movq	%rdi, 200(%rsp)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	movl	%ecx, 56(%rdx)
	movl	%ecx, 76(%rdx)
	imulq	200(%rsp), %rcx
	subq	%rsi, %rdi
	movslq	56(%r8), %rsi
	addq	%rdi, %rcx
	movl	44(%r8), %edi
	movq	%rcx, 88(%rdx)
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 176(%rsp)
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	176(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L289
.L779:
	movq	160(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 176(%rsp)
	cmpl	4(%rsi), %ecx
	je	.L288
	imulq	$96, 120(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 208(%rsp)
	imulq	$96, %rdi, %rdx
	movl	16(%rsi), %esi
	movl	%esi, 200(%rsp)
	movq	176(%rsp), %rsi
	addq	%rbx, %rdx
	movslq	8(%rsi), %rsi
	movslq	16(%rdx), %rdi
	movl	%ecx, 24(%rdx)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	subq	%rsi, %rdi
	movq	176(%rsp), %rsi
	movl	%ecx, 4(%rsi)
	movslq	200(%rsp), %rsi
	movq	176(%rsp), %rcx
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rcx), %rcx
	imulq	%rsi, %rcx
	movq	208(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rdx)
	movl	4(%r8), %edi
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 176(%rsp)
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	176(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L288
.L782:
	movq	112(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L380
	imulq	$96, %rsi, %rdx
	imulq	$96, 24(%rsp), %r8
	addq	%rbx, %rdx
	addq	%rbx, %r8
	movslq	48(%rdx), %rsi
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%edi, 144(%rsp)
	movq	%rsi, %rdi
	movslq	56(%rdx), %rsi
	movslq	144(%rsp), %rcx
	movq	%rdi, 168(%rsp)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	movl	%ecx, 56(%rdx)
	movl	%ecx, 76(%rdx)
	imulq	168(%rsp), %rcx
	subq	%rsi, %rdi
	movslq	56(%r8), %rsi
	addq	%rdi, %rcx
	movl	44(%r8), %edi
	movq	%rcx, 88(%rdx)
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 144(%rsp)
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L380
.L781:
	movq	112(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 144(%rsp)
	cmpl	4(%rsi), %ecx
	je	.L379
	imulq	$96, 24(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 176(%rsp)
	imulq	$96, %rdi, %rdx
	movl	16(%rsi), %esi
	movl	%esi, 168(%rsp)
	movq	144(%rsp), %rsi
	addq	%rbx, %rdx
	movslq	8(%rsi), %rsi
	movslq	16(%rdx), %rdi
	movl	%ecx, 24(%rdx)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	subq	%rsi, %rdi
	movq	144(%rsp), %rsi
	movl	%ecx, 4(%rsi)
	movslq	168(%rsp), %rsi
	movq	144(%rsp), %rcx
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rcx), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rdx)
	movl	4(%r8), %edi
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 144(%rsp)
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L379
.L784:
	movq	168(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rax
	salq	$5, %rax
	cmpl	44(%rbx,%rax), %edx
	je	.L356
	imulq	$96, %rcx, %rax
	imulq	$96, 120(%rsp), %r8
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	addq	%rbx, %r8
	movl	56(%r8), %esi
	movl	%edx, 64(%rax)
	imulq	%rdi, %rcx
	movl	%edx, 44(%rax)
	movq	%rdi, 200(%rsp)
	movslq	%esi, %rdx
	movq	88(%rax), %rdi
	imulq	200(%rsp), %rdx
	movl	%esi, 56(%rax)
	subq	%rcx, %rdi
	movl	%esi, 76(%rax)
	movslq	56(%r8), %rcx
	movl	44(%r8), %esi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	imulq	$96, 40(%rsp), %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r8
	movslq	56(%rax), %rdx
	movl	%ecx, 76(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 56(%rax)
	imulq	%r8, %rdx
	movl	%esi, 64(%rax)
	imulq	%r8, %rcx
	movl	%esi, 44(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L356
.L786:
	movq	128(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L328
	imulq	$96, %rsi, %rdx
	imulq	$96, 64(%rsp), %r8
	addq	%rbx, %rdx
	addq	%rbx, %r8
	movslq	48(%rdx), %rsi
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%edi, 144(%rsp)
	movq	%rsi, %rdi
	movslq	56(%rdx), %rsi
	movslq	144(%rsp), %rcx
	movq	%rdi, 168(%rsp)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	movl	%ecx, 56(%rdx)
	movl	%ecx, 76(%rdx)
	imulq	168(%rsp), %rcx
	subq	%rsi, %rdi
	movslq	56(%r8), %rsi
	addq	%rdi, %rcx
	movl	44(%r8), %edi
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	%edi, 144(%rsp)
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L328
.L785:
	leaq	(%rsi,%rsi,2), %rdx
	movq	%rsi, %rdi
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 144(%rsp)
	cmpl	4(%rsi), %ecx
	je	.L327
	imulq	$96, 64(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 176(%rsp)
	imulq	$96, %rdi, %rdx
	movl	16(%rsi), %esi
	movl	%esi, 168(%rsp)
	movq	144(%rsp), %rsi
	addq	%rbx, %rdx
	movslq	8(%rsi), %rsi
	movslq	16(%rdx), %rdi
	movl	%ecx, 24(%rdx)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	subq	%rsi, %rdi
	movq	144(%rsp), %rsi
	movl	%ecx, 4(%rsi)
	movslq	168(%rsp), %rsi
	movq	144(%rsp), %rcx
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rcx), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movl	%edi, 144(%rsp)
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L327
.L767:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L388
	imulq	$96, 40(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 144(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 120(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	120(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	144(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 96(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L388
.L783:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rcx
	cmpl	4(%rcx), %eax
	je	.L355
	imulq	$96, 120(%rsp), %rdx
	imulq	$96, %rsi, %rsi
	addq	%rbx, %rdx
	movq	%rdx, 208(%rsp)
	movl	16(%rdx), %edx
	addq	%rbx, %rsi
	movslq	16(%rsi), %rdi
	movl	%edx, 200(%rsp)
	movslq	8(%rcx), %rdx
	movl	%eax, 24(%rsi)
	imulq	%rdi, %rdx
	movq	88(%rsi), %rdi
	movl	%eax, 4(%rcx)
	subq	%rdx, %rdi
	movslq	200(%rsp), %rdx
	movl	%edx, 36(%rsi)
	movl	%edx, 16(%rsi)
	movslq	8(%rcx), %rax
	imulq	%rdx, %rax
	movq	208(%rsp), %rdx
	movslq	16(%rdx), %rcx
	addq	%rdi, %rax
	movq	%rax, 88(%rsi)
	imulq	$96, 40(%rsp), %rax
	movl	4(%r8), %esi
	addq	%rbx, %rax
	movslq	8(%rax), %r8
	movslq	16(%rax), %rdx
	movl	%ecx, 36(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 16(%rax)
	imulq	%r8, %rdx
	movl	%esi, 24(%rax)
	imulq	%r8, %rcx
	movl	%esi, 4(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L355
.L741:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE3572:
	.size	_ZN11Solve_merge2ST10update_MaxEiiiiiii, .-_ZN11Solve_merge2ST10update_MaxEiiiiiii
	.section	.text._ZN11Solve_merge2ST10update_MinEiiiiiii,"axG",@progbits,_ZN11Solve_merge2ST10update_MinEiiiiiii,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_merge2ST10update_MinEiiiiiii
	.type	_ZN11Solve_merge2ST10update_MinEiiiiiii, @function
_ZN11Solve_merge2ST10update_MinEiiiiiii:
.LFB3573:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$344, %rsp
	.cfi_def_cfa_offset 400
	movq	%fs:40, %rax
	movq	%rax, 328(%rsp)
	xorl	%eax, %eax
	cmpl	%esi, %r9d
	jl	.L787
	movl	%edx, %r13d
	movl	%r8d, %r12d
	cmpl	%r8d, %edx
	jl	.L787
	cmpl	%r8d, %esi
	movq	%rdi, %rbx
	movl	%r9d, %ebp
	setge	%dil
	cmpl	%edx, %r9d
	setge	8(%rsp)
	movzbl	8(%rsp), %eax
	testb	%dil, %dil
	je	.L789
	testb	%al, %al
	je	.L789
	movslq	%ecx, %rcx
	leaq	(%rcx,%rcx,2), %rdi
	movslq	408(%rsp), %rcx
	salq	$5, %rdi
	addq	%rdi, %rbx
	movslq	8(%rbx), %rax
	movslq	16(%rbx), %rdx
	movl	%ecx, 36(%rbx)
	movq	88(%rbx), %rsi
	movl	%ecx, 16(%rbx)
	imulq	%rax, %rdx
	imulq	%rcx, %rax
	subq	%rdx, %rsi
	movq	%rsi, %rdx
	movl	400(%rsp), %esi
	addq	%rdx, %rax
	movl	%esi, 24(%rbx)
	movl	%esi, 4(%rbx)
	movq	%rax, 88(%rbx)
.L787:
	movq	328(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L1276
	addq	$344, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L789:
	.cfi_restore_state
	leal	(%rcx,%rcx), %r14d
	movslq	%ecx, %r15
	movl	%r14d, %edx
	leaq	(%r15,%r15,2), %rax
	movslq	%r14d, %r14
	orl	$1, %edx
	salq	$5, %rax
	movl	%edx, 40(%rsp)
	addq	%rbx, %rax
	movslq	%edx, %rdx
	movq	%rdx, 16(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L1277
.L790:
	leaq	(%r15,%r15,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L1278
.L791:
	leal	(%rsi,%r13), %eax
	leaq	224(%rsp), %r10
	sarl	%eax
	movl	%eax, %r11d
	leal	1(%rax), %eax
	movl	%eax, 24(%rsp)
	cmpl	%r11d, %r12d
	jg	.L792
	cmpl	%r11d, %ebp
	setge	32(%rsp)
	movzbl	32(%rsp), %eax
	testb	%dil, %dil
	je	.L793
	testb	%al, %al
	je	.L793
	leaq	(%r14,%r14,2), %rax
	leaq	224(%rsp), %r10
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	24(%rsp), %ebp
	jl	.L795
	cmpl	24(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%sil
.L871:
	movl	40(%rsp), %edi
	movq	16(%rsp), %rax
	leal	(%rdi,%rdi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rdx
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rdx, 32(%rsp)
	movl	%edi, 64(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 48(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1279
.L872:
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1280
.L873:
	movl	24(%rsp), %eax
	addl	%r13d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, %r11d
	movl	%edi, 56(%rsp)
	cmpl	%eax, %r12d
	jg	.L874
	cmpl	%eax, %ebp
	setge	88(%rsp)
	jl	.L875
	testb	%sil, %sil
	je	.L875
	movq	32(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L877
.L916:
	movl	64(%rsp), %esi
	movq	48(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 24(%rsp)
	movl	%esi, 80(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 40(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1281
.L917:
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1282
.L918:
	movl	56(%rsp), %eax
	leal	0(%r13,%rax), %r11d
	sarl	%r11d
	leal	1(%r11), %edi
	movl	%edi, 72(%rsp)
	cmpl	%r11d, %r12d
	jg	.L919
	cmpl	%r11d, %ebp
	setge	104(%rsp)
	jl	.L920
	testb	%r9b, %r9b
	je	.L920
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L922
.L946:
	movl	80(%rsp), %esi
	movq	40(%rsp), %rax
	addl	%esi, %esi
	leaq	(%rax,%rax,2), %rax
	movl	%esi, %edi
	salq	$5, %rax
	movl	%esi, 80(%rsp)
	movslq	%esi, %r11
	orl	$1, %edi
	addq	%rbx, %rax
	movl	%edi, 88(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 56(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1283
.L947:
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1284
.L948:
	movl	72(%rsp), %eax
	leal	0(%r13,%rax), %edx
	sarl	%edx
	leal	1(%rdx), %edi
	movl	%edi, 64(%rsp)
	cmpl	%edx, %r12d
	jg	.L949
	cmpl	%edx, %ebp
	jl	.L950
	testb	%r9b, %r9b
	je	.L950
	leaq	(%r11,%r11,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%edi, %ebp
	jl	.L952
.L951:
	movl	408(%rsp), %eax
	movl	%r13d, %edx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r11, 72(%rsp)
	movq	%rbx, %rdi
	movq	%r10, 8(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	104(%rsp), %ecx
	movl	80(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r11
	movq	8(%rsp), %r10
.L952:
	movq	40(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	56(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	leaq	(%r11,%r11,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, 0(%rbp)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rbp)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rbp)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rbp)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rbp)
	movdqu	496(%rsp), %xmm1
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rbp)
.L922:
	movq	48(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	40(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, 0(%rbp)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rbp)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rbp)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rbp)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rbp)
	movdqu	496(%rsp), %xmm7
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rbp)
.L877:
	movq	16(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rbp
	movq	48(%rsp), %rax
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 200(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, 0(%rbp)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rbp)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rbp)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rbp)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rbp)
	movdqu	496(%rsp), %xmm3
	movq	200(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm3, 80(%rbp)
.L795:
	movq	16(%rsp), %rax
	leaq	(%r15,%r15,2), %rbp
	leaq	(%r14,%r14,2), %rdi
	salq	$5, %rdi
	salq	$5, %rbp
	leaq	(%rax,%rax,2), %rax
	addq	%rbx, %rbp
	salq	$5, %rax
	addq	%rbx, %rax
	addq	%rdi, %rbx
	movq	%r10, %rdi
	pushq	88(%rax)
	.cfi_def_cfa_offset 408
	pushq	80(%rax)
	.cfi_def_cfa_offset 416
	pushq	72(%rax)
	.cfi_def_cfa_offset 424
	pushq	64(%rax)
	.cfi_def_cfa_offset 432
	pushq	56(%rax)
	.cfi_def_cfa_offset 440
	pushq	48(%rax)
	.cfi_def_cfa_offset 448
	pushq	40(%rax)
	.cfi_def_cfa_offset 456
	pushq	32(%rax)
	.cfi_def_cfa_offset 464
	pushq	24(%rax)
	.cfi_def_cfa_offset 472
	pushq	16(%rax)
	.cfi_def_cfa_offset 480
	pushq	8(%rax)
	.cfi_def_cfa_offset 488
	pushq	(%rax)
	.cfi_def_cfa_offset 496
	pushq	88(%rbx)
	.cfi_def_cfa_offset 504
	pushq	80(%rbx)
	.cfi_def_cfa_offset 512
	pushq	72(%rbx)
	.cfi_def_cfa_offset 520
	pushq	64(%rbx)
	.cfi_def_cfa_offset 528
	pushq	56(%rbx)
	.cfi_def_cfa_offset 536
	pushq	48(%rbx)
	.cfi_def_cfa_offset 544
	pushq	40(%rbx)
	.cfi_def_cfa_offset 552
	pushq	32(%rbx)
	.cfi_def_cfa_offset 560
	pushq	24(%rbx)
	.cfi_def_cfa_offset 568
	pushq	16(%rbx)
	.cfi_def_cfa_offset 576
	pushq	8(%rbx)
	.cfi_def_cfa_offset 584
	pushq	(%rbx)
	.cfi_def_cfa_offset 592
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, 0(%rbp)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rbp)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rbp)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rbp)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rbp)
	movdqu	496(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm5, 80(%rbp)
	jmp	.L787
	.p2align 4,,10
	.p2align 3
.L793:
	leal	0(,%rcx,4), %edx
	leaq	(%r14,%r14,2), %rax
	movl	%edx, %r10d
	salq	$5, %rax
	movslq	%edx, %rdx
	orl	$1, %r10d
	movq	%rdx, 48(%rsp)
	addq	%rbx, %rax
	movslq	%r10d, %rdx
	movl	%r10d, 88(%rsp)
	movl	4(%rax), %r8d
	movq	%rdx, 56(%rsp)
	cmpl	24(%rax), %r8d
	je	.L1285
.L796:
	leaq	(%r14,%r14,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L1286
.L797:
	leal	(%rsi,%r11), %eax
	leaq	224(%rsp), %r10
	sarl	%eax
	leal	1(%rax), %edx
	movl	%eax, 80(%rsp)
	movl	%edx, 64(%rsp)
	cmpl	%eax, %r12d
	jg	.L798
	cmpl	80(%rsp), %ebp
	setge	72(%rsp)
	movzbl	72(%rsp), %eax
	testb	%dil, %dil
	je	.L799
	testb	%al, %al
	je	.L799
	movq	48(%rsp), %rax
	leaq	224(%rsp), %r10
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	64(%rsp), %ebp
	jl	.L801
	cmpl	64(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%r9b
.L840:
	movl	88(%rsp), %edi
	movq	56(%rsp), %rax
	leal	(%rdi,%rdi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 72(%rsp)
	movl	%esi, 112(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 80(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1287
.L841:
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1288
.L842:
	movl	64(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 104(%rsp)
	movl	%edi, 96(%rsp)
	cmpl	%eax, %r12d
	jg	.L843
	cmpl	%eax, %ebp
	setge	136(%rsp)
	jl	.L844
	testb	%r9b, %r9b
	je	.L844
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L846
.L862:
	movl	112(%rsp), %edi
	movq	80(%rsp), %rax
	addl	%edi, %edi
	leaq	(%rax,%rax,2), %rax
	movl	%edi, %esi
	salq	$5, %rax
	movl	%edi, 112(%rsp)
	movslq	%edi, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 64(%rsp)
	movl	%esi, 120(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 88(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1289
.L863:
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1290
.L864:
	movl	96(%rsp), %eax
	leal	(%r11,%rax), %edx
	sarl	%edx
	leal	1(%rdx), %edi
	movl	%edi, 104(%rsp)
	cmpl	%edx, %r12d
	jg	.L865
	cmpl	%edx, %ebp
	jl	.L866
	testb	%r9b, %r9b
	je	.L866
	movq	64(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%edi, %ebp
	jl	.L868
.L867:
	movl	408(%rsp), %eax
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%r10, 32(%rsp)
	movl	%r11d, %edx
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	136(%rsp), %ecx
	movl	120(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	32(%rsp), %r10
.L868:
	movq	80(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 96(%rsp)
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	160(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	288(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rax)
.L846:
	movq	56(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 64(%rsp)
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	168(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm1, 80(%rax)
.L801:
	leaq	(%r14,%r14,2), %rax
	movq	%r10, %rdi
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 64(%rsp)
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 224(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rax
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rax)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movq	224(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rax)
.L792:
	movl	24(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L795
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %esi
	je	.L871
	testb	%al, %al
	je	.L871
	movq	16(%rsp), %rax
	movl	408(%rsp), %edi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%edi, 36(%rax)
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	%edi, %rsi
	imulq	%rsi, %rdx
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L795
	.p2align 4,,10
	.p2align 3
.L1278:
	leaq	(%r14,%r14,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L791
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %r11
	movslq	56(%rax), %r10
	movl	%r8d, 64(%rdx)
	imulq	%r9, %r11
	movq	%r9, 24(%rsp)
	movq	88(%rdx), %r9
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	24(%rsp), %r10
	subq	%r11, %r9
	movl	%r8d, 44(%rdx)
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movq	88(%rax), %r11
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movl	%r10d, 64(%rax)
	imulq	%rdx, %r8
	movl	%r10d, 44(%rax)
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rax)
	jmp	.L791
	.p2align 4,,10
	.p2align 3
.L1277:
	leaq	(%r14,%r14,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L790
	movslq	8(%rdx), %r9
	movslq	16(%rdx), %r11
	movslq	16(%rax), %r10
	movl	%r8d, 4(%rdx)
	imulq	%r9, %r11
	movq	%r9, 24(%rsp)
	movq	88(%rdx), %r9
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	24(%rsp), %r10
	subq	%r11, %r9
	movl	%r8d, 24(%rdx)
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	16(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movq	88(%rax), %r11
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movl	%r10d, 24(%rax)
	imulq	%rdx, %r8
	movl	%r10d, 4(%rax)
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rax)
	jmp	.L790
	.p2align 4,,10
	.p2align 3
.L799:
	movq	48(%rsp), %rax
	leal	0(,%rcx,8), %edx
	movl	%edx, %r9d
	movslq	%edx, %rdx
	leaq	(%rax,%rax,2), %rax
	orl	$1, %r9d
	movq	%rdx, 96(%rsp)
	salq	$5, %rax
	movslq	%r9d, %rdx
	movl	%r9d, 128(%rsp)
	addq	%rbx, %rax
	movq	%rdx, 104(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L1291
.L802:
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %r8d
	cmpl	64(%rax), %r8d
	je	.L1292
.L803:
	movl	80(%rsp), %eax
	leal	(%rsi,%rax), %r10d
	sarl	%r10d
	leal	1(%r10), %eax
	movl	%eax, 112(%rsp)
	cmpl	%r10d, %r12d
	jg	.L1293
	cmpl	%r10d, %ebp
	setge	120(%rsp)
	movzbl	120(%rsp), %eax
	testb	%dil, %dil
	je	.L805
	testb	%al, %al
	je	.L805
	movq	96(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	224(%rsp), %r10
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rdx, %rcx
	movq	88(%rax), %rdi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	cmpl	112(%rsp), %ebp
	jl	.L807
	cmpl	112(%rsp), %r12d
	leaq	224(%rsp), %r10
	setle	%r9b
.L816:
	movl	128(%rsp), %esi
	movq	104(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 120(%rsp)
	movl	%esi, 152(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 136(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1294
.L817:
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1295
.L818:
	movl	80(%rsp), %eax
	addl	112(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%edi, 144(%rsp)
	cmpl	%eax, %r12d
	jg	.L819
	cmpl	%eax, %ebp
	setge	168(%rsp)
	jl	.L820
	testb	%r9b, %r9b
	je	.L820
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	128(%rsp)
	cmpl	%edi, %ebp
	jl	.L822
.L831:
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	152(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %esi
	movl	%eax, 168(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %esi
	movl	%esi, 160(%rsp)
	movslq	%esi, %rsi
	movq	%rsi, 112(%rsp)
	cmpl	24(%r8), %ecx
	je	.L1296
.L832:
	movq	136(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L1297
.L833:
	movl	80(%rsp), %edx
	addl	144(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 152(%rsp)
	cmpl	%edx, %r12d
	jg	.L834
	cmpl	%edx, %ebp
	jl	.L835
	cmpb	$0, 128(%rsp)
	je	.L835
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L837
.L836:
	movl	%r11d, 72(%rsp)
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%rax, 128(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 144(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	96(%rsp), %edx
	movl	168(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	144(%rsp), %r10
	movq	128(%rsp), %rax
	movl	72(%rsp), %r11d
.L837:
	movq	136(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movl	%r11d, 128(%rsp)
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	112(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 80(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rdx
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rdx)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rdx)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rdx)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rdx)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rdx)
	movdqu	496(%rsp), %xmm7
	movl	320(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm7, 80(%rdx)
.L822:
	movq	104(%rsp), %rax
	movl	%r11d, 112(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 80(%rsp)
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	216(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	304(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L807:
	movq	48(%rsp), %rax
	movl	%r11d, 112(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 80(%rsp)
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	192(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 264(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	272(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movl	304(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	72(%rsp), %r10
	movups	%xmm5, 80(%rax)
.L798:
	movl	64(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L801
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 32(%rsp)
	movl	%eax, %r9d
	je	.L840
	testb	%al, %al
	je	.L840
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L801
	.p2align 4,,10
	.p2align 3
.L875:
	movl	40(%rsp), %edi
	movq	32(%rsp), %rax
	leal	0(,%rdi,4), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rdx
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rdx, 72(%rsp)
	movl	%edi, 112(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 80(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1298
.L878:
	movq	32(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1299
.L879:
	movl	24(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 104(%rsp)
	movl	%edi, 96(%rsp)
	cmpl	%eax, %r12d
	jg	.L880
	cmpl	%eax, %ebp
	setge	128(%rsp)
	jl	.L881
	testb	%sil, %sil
	je	.L881
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	%r9b
	cmpl	%edi, %ebp
	jl	.L883
.L892:
	movl	112(%rsp), %esi
	movq	80(%rsp), %rax
	leal	(%rsi,%rsi), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movslq	%edx, %rsi
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rsi, 24(%rsp)
	movl	%edi, 120(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 40(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1300
.L893:
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1301
.L894:
	movl	96(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%edi, 104(%rsp)
	cmpl	%eax, %r12d
	jg	.L895
	cmpl	%eax, %ebp
	setge	136(%rsp)
	jl	.L896
	testb	%r9b, %r9b
	je	.L896
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	112(%rsp)
	cmpl	%edi, %ebp
	jl	.L898
.L907:
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	120(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %esi
	movl	%eax, 128(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %esi
	movslq	%esi, %rdi
	movl	%esi, 136(%rsp)
	movq	%rdi, 96(%rsp)
	cmpl	24(%r8), %ecx
	je	.L1302
.L908:
	movq	40(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L1303
.L909:
	movl	104(%rsp), %ecx
	leal	(%r11,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 120(%rsp)
	cmpl	%edx, %r12d
	jg	.L910
	cmpl	%edx, %ebp
	jl	.L911
	cmpb	$0, 112(%rsp)
	je	.L911
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L913
.L912:
	movq	%rax, 104(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%r11d, %edx
	movl	408(%rsp), %eax
	movq	%r10, 88(%rsp)
	movq	%rbx, %rdi
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	152(%rsp), %ecx
	movl	136(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	104(%rsp), %rax
	movq	88(%rsp), %r10
.L913:
	movq	40(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	96(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 104(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 280(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	296(%rsp), %rdx
	movdqu	416(%rsp), %xmm6
	movups	%xmm6, (%rdx)
	movdqu	432(%rsp), %xmm7
	movups	%xmm7, 16(%rdx)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rdx)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rdx)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rdx)
	movdqu	496(%rsp), %xmm5
	movq	280(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm5, 80(%rdx)
.L898:
	movq	80(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 88(%rsp)
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	280(%rsp), %rax
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, (%rax)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movq	216(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rax)
.L883:
	movq	32(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 40(%rsp)
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	168(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	232(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movq	216(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm5, 80(%rax)
.L874:
	movl	56(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L877
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %r9d
	je	.L916
	testb	%al, %al
	je	.L916
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rdi
	imulq	%rdx, %rcx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movl	408(%rsp), %edi
	movslq	%edi, %rsi
	movl	%edi, 36(%rax)
	imulq	%rsi, %rdx
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L877
	.p2align 4,,10
	.p2align 3
.L1280:
	movq	32(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L873
	movslq	48(%rdx), %rdi
	movslq	56(%rdx), %r9
	movslq	56(%rax), %r8
	movq	88(%rdx), %r11
	movl	%ecx, 64(%rdx)
	imulq	%rdi, %r9
	movl	%ecx, 44(%rdx)
	movl	%r8d, 76(%rdx)
	movl	%r8d, 56(%rdx)
	imulq	%rdi, %r8
	movslq	56(%rax), %rcx
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rdx)
	movl	44(%rax), %r8d
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rdi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rdi
	movl	%r8d, 64(%rax)
	imulq	%rdx, %rcx
	movl	%r8d, 44(%rax)
	subq	%rdi, %r11
	movq	%r11, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 88(%rax)
	jmp	.L873
	.p2align 4,,10
	.p2align 3
.L1279:
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L872
	movslq	8(%rdx), %rdi
	movslq	16(%rdx), %r9
	movslq	16(%rax), %r8
	movq	88(%rdx), %r11
	movl	%ecx, 4(%rdx)
	imulq	%rdi, %r9
	movl	%ecx, 24(%rdx)
	movl	%r8d, 36(%rdx)
	movl	%r8d, 16(%rdx)
	imulq	%rdi, %r8
	movslq	16(%rax), %rcx
	subq	%r9, %r11
	addq	%r11, %r8
	movq	%r8, 88(%rdx)
	movl	4(%rax), %r8d
	movq	48(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rdi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rdi
	movl	%r8d, 24(%rax)
	imulq	%rdx, %rcx
	movl	%r8d, 4(%rax)
	subq	%rdi, %r11
	movq	%r11, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 88(%rax)
	jmp	.L872
	.p2align 4,,10
	.p2align 3
.L1286:
	movq	48(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L797
	movl	56(%rax), %r10d
	movslq	48(%rdx), %r9
	movl	%r8d, 64(%rdx)
	movl	%r8d, 44(%rdx)
	movl	%r10d, 64(%rsp)
	movq	%r9, %r10
	movslq	56(%rdx), %r9
	movq	%r10, 72(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	64(%rsp), %r10
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	72(%rsp), %r10
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 64(%rsp)
	movq	88(%rax), %rdx
	imulq	64(%rsp), %r8
	movl	%r10d, 64(%rax)
	movl	%r10d, 44(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L797
	.p2align 4,,10
	.p2align 3
.L1285:
	movq	48(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L796
	movl	16(%rax), %r10d
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%r10d, 64(%rsp)
	movq	%r9, %r10
	movslq	16(%rdx), %r9
	movq	%r10, 72(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	64(%rsp), %r10
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	72(%rsp), %r10
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 64(%rsp)
	movq	88(%rax), %rdx
	imulq	64(%rsp), %r8
	movl	%r10d, 24(%rax)
	movl	%r10d, 4(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L796
	.p2align 4,,10
	.p2align 3
.L881:
	movl	40(%rsp), %edx
	movq	72(%rsp), %rax
	sall	$3, %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %edi
	salq	$5, %rax
	movl	%edx, 136(%rsp)
	movslq	%edx, %rdx
	orl	$1, %edi
	addq	%rbx, %rax
	movq	%rdx, 40(%rsp)
	movl	%edi, 144(%rsp)
	movslq	%edi, %rdi
	movl	4(%rax), %ecx
	movq	%rdi, 120(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1304
.L884:
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1305
.L885:
	movl	104(%rsp), %edx
	addl	24(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L886
	cmpl	%edx, %ebp
	jl	.L887
	testb	%sil, %sil
	je	.L887
	movq	40(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L889
.L888:
	movl	408(%rsp), %ecx
	movl	%eax, %esi
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 128(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 24(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	160(%rsp), %ecx
	movl	120(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	128(%rsp), %r10
	movl	24(%rsp), %r11d
.L889:
	movq	72(%rsp), %rax
	movl	%r11d, 128(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 104(%rsp)
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 216(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	296(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm4
	movups	%xmm4, 64(%rax)
	movdqu	496(%rsp), %xmm5
	movl	320(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	24(%rsp), %r10
	movups	%xmm5, 80(%rax)
.L880:
	movl	96(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L883
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 88(%rsp)
	movl	%eax, %r9d
	je	.L892
	testb	%al, %al
	je	.L892
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rdi
	imulq	%rdx, %rcx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movl	408(%rsp), %edi
	movslq	%edi, %rsi
	movl	%edi, 36(%rax)
	imulq	%rsi, %rdx
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L883
	.p2align 4,,10
	.p2align 3
.L844:
	movl	88(%rsp), %edi
	movq	72(%rsp), %rax
	leal	0(,%rdi,4), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 120(%rsp)
	movl	%esi, 160(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 128(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1306
.L847:
	movq	72(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1307
.L848:
	movl	104(%rsp), %eax
	addl	64(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 152(%rsp)
	movl	%edi, 144(%rsp)
	cmpl	%eax, %r12d
	jg	.L849
	cmpl	%eax, %ebp
	movq	120(%rsp), %rax
	setge	176(%rsp)
	jl	.L850
	testb	%r9b, %r9b
	je	.L850
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%edi, %ebp
	jl	.L852
.L851:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%r10, 88(%rsp)
	movl	%r11d, 64(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	120(%rsp), %edx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	88(%rsp), %r10
	movl	64(%rsp), %r11d
.L852:
	movq	72(%rsp), %rax
	movl	%r11d, 104(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 88(%rsp)
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	216(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 256(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	280(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	296(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	64(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L843:
	movl	96(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L846
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 32(%rsp)
	movl	%eax, %r9d
	je	.L862
	testb	%al, %al
	je	.L862
	movq	80(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 24(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 4(%rax)
	imulq	%rdx, %rcx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	408(%rsp), %edi
	movslq	%edi, %rsi
	movl	%edi, 36(%rax)
	imulq	%rsi, %rdx
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L846
	.p2align 4,,10
	.p2align 3
.L920:
	movl	64(%rsp), %esi
	movq	24(%rsp), %rax
	leal	0(,%rsi,4), %edx
	leaq	(%rax,%rax,2), %rax
	movl	%edx, %esi
	salq	$5, %rax
	movslq	%edx, %rdi
	orl	$1, %esi
	addq	%rbx, %rax
	movq	%rdi, 88(%rsp)
	movl	%esi, 128(%rsp)
	movslq	%esi, %rsi
	movl	4(%rax), %ecx
	movq	%rsi, 96(%rsp)
	cmpl	24(%rax), %ecx
	je	.L1308
.L923:
	movq	24(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1309
.L924:
	movl	56(%rsp), %eax
	addl	%r11d, %eax
	sarl	%eax
	leal	1(%rax), %edi
	movl	%eax, 120(%rsp)
	movl	%edi, 112(%rsp)
	cmpl	%eax, %r12d
	jg	.L925
	cmpl	%eax, %ebp
	movq	88(%rsp), %rax
	setge	144(%rsp)
	jl	.L926
	testb	%r9b, %r9b
	je	.L926
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	cmpl	%edi, %r12d
	movq	%rdx, 88(%rax)
	setle	64(%rsp)
	cmpl	%edi, %ebp
	jl	.L928
.L937:
	movq	96(%rsp), %rax
	leaq	(%rax,%rax,2), %r8
	movl	128(%rsp), %eax
	salq	$5, %r8
	addl	%eax, %eax
	addq	%rbx, %r8
	movl	%eax, %edi
	movl	%eax, 136(%rsp)
	movl	4(%r8), %ecx
	cltq
	orl	$1, %edi
	movslq	%edi, %rsi
	movl	%edi, 128(%rsp)
	movq	%rsi, 56(%rsp)
	cmpl	24(%r8), %ecx
	je	.L1310
.L938:
	movq	96(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L1311
.L939:
	movl	112(%rsp), %ecx
	leal	(%r11,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 120(%rsp)
	cmpl	%edx, %r12d
	jg	.L940
	cmpl	%edx, %ebp
	jl	.L941
	cmpb	$0, 64(%rsp)
	je	.L941
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L943
.L942:
	movq	%rax, 64(%rsp)
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movl	408(%rsp), %eax
	movq	%r10, 104(%rsp)
	movl	%r11d, %edx
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	144(%rsp), %ecx
	movl	136(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	104(%rsp), %r10
	movq	64(%rsp), %rax
.L943:
	movq	96(%rsp), %rcx
	leaq	(%rax,%rax,2), %rax
	movq	%r10, %rdi
	salq	$5, %rax
	leaq	(%rcx,%rcx,2), %rdx
	movq	56(%rsp), %rcx
	addq	%rbx, %rax
	salq	$5, %rdx
	leaq	(%rcx,%rcx,2), %rcx
	addq	%rbx, %rdx
	salq	$5, %rcx
	movq	%rdx, 64(%rsp)
	addq	%rbx, %rcx
	pushq	88(%rcx)
	.cfi_def_cfa_offset 408
	pushq	80(%rcx)
	.cfi_def_cfa_offset 416
	pushq	72(%rcx)
	.cfi_def_cfa_offset 424
	pushq	64(%rcx)
	.cfi_def_cfa_offset 432
	pushq	56(%rcx)
	.cfi_def_cfa_offset 440
	pushq	48(%rcx)
	.cfi_def_cfa_offset 448
	pushq	40(%rcx)
	.cfi_def_cfa_offset 456
	pushq	32(%rcx)
	.cfi_def_cfa_offset 464
	pushq	24(%rcx)
	.cfi_def_cfa_offset 472
	pushq	16(%rcx)
	.cfi_def_cfa_offset 480
	pushq	8(%rcx)
	.cfi_def_cfa_offset 488
	pushq	(%rcx)
	.cfi_def_cfa_offset 496
	pushq	88(%rax)
	.cfi_def_cfa_offset 504
	pushq	80(%rax)
	.cfi_def_cfa_offset 512
	pushq	72(%rax)
	.cfi_def_cfa_offset 520
	pushq	64(%rax)
	.cfi_def_cfa_offset 528
	pushq	56(%rax)
	.cfi_def_cfa_offset 536
	pushq	48(%rax)
	.cfi_def_cfa_offset 544
	pushq	40(%rax)
	.cfi_def_cfa_offset 552
	pushq	32(%rax)
	.cfi_def_cfa_offset 560
	pushq	24(%rax)
	.cfi_def_cfa_offset 568
	pushq	16(%rax)
	.cfi_def_cfa_offset 576
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	movq	%r10, 248(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rdx
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rdx)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rdx)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rdx)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rdx)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rdx)
	movdqu	496(%rsp), %xmm7
	movq	248(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm7, 80(%rdx)
.L928:
	movq	24(%rsp), %rax
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 64(%rsp)
	movq	96(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	184(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 248(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	256(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movq	248(%rsp), %r10
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movups	%xmm3, 80(%rax)
.L919:
	movl	72(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L922
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 8(%rsp)
	movl	%eax, %r9d
	je	.L946
	testb	%al, %al
	je	.L946
	movq	40(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L922
	.p2align 4,,10
	.p2align 3
.L1281:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L917
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 24(%rdx)
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	%rsi, %rdi
	movslq	16(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L917
	.p2align 4,,10
	.p2align 3
.L1287:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L841
	movslq	8(%rdx), %rsi
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movl	%ecx, 4(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	4(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L841
	.p2align 4,,10
	.p2align 3
.L1288:
	movq	72(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L842
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movq	%rsi, 96(%rsp)
	movq	88(%rdx), %rsi
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	96(%rsp), %rdi
	subq	%r8, %rsi
	movl	%ecx, 44(%rdx)
	movslq	56(%rax), %rcx
	addq	%rsi, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L842
	.p2align 4,,10
	.p2align 3
.L1282:
	movq	24(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L918
	movslq	48(%rdx), %rsi
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movq	88(%rdx), %r11
	movl	%ecx, 64(%rdx)
	imulq	%rsi, %r8
	movl	%ecx, 44(%rdx)
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	%rsi, %rdi
	movslq	56(%rax), %rcx
	subq	%r8, %r11
	addq	%r11, %rdi
	movq	%rdi, 88(%rdx)
	movl	44(%rax), %edi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r11
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r11
	movq	%r11, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L918
	.p2align 4,,10
	.p2align 3
.L1292:
	movq	96(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %r8d
	je	.L803
	movl	56(%rax), %r10d
	movslq	48(%rdx), %r9
	movl	%r8d, 64(%rdx)
	movl	%r8d, 44(%rdx)
	movl	%r10d, 112(%rsp)
	movq	%r9, %r10
	movslq	56(%rdx), %r9
	movq	%r10, 120(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	112(%rsp), %r10
	movl	%r10d, 76(%rdx)
	movl	%r10d, 56(%rdx)
	imulq	120(%rsp), %r10
	movslq	56(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	44(%rax), %r10d
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %r9
	movl	%r8d, 76(%rax)
	movl	%r8d, 56(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 112(%rsp)
	movq	88(%rax), %rdx
	imulq	112(%rsp), %r8
	movl	%r10d, 64(%rax)
	movl	%r10d, 44(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L803
	.p2align 4,,10
	.p2align 3
.L1291:
	movq	96(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L802
	movl	16(%rax), %r10d
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%r10d, 112(%rsp)
	movq	%r9, %r10
	movslq	16(%rdx), %r9
	movq	%r10, 120(%rsp)
	imulq	%r10, %r9
	movq	88(%rdx), %r10
	subq	%r9, %r10
	movq	%r10, %r9
	movslq	112(%rsp), %r10
	movl	%r10d, 36(%rdx)
	movl	%r10d, 16(%rdx)
	imulq	120(%rsp), %r10
	movslq	16(%rax), %r8
	addq	%r9, %r10
	movq	%r10, 88(%rdx)
	movl	4(%rax), %r10d
	movq	104(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %r9
	movl	%r8d, 36(%rax)
	movl	%r8d, 16(%rax)
	imulq	%rdx, %r9
	movq	%rdx, 112(%rsp)
	movq	88(%rax), %rdx
	imulq	112(%rsp), %r8
	movl	%r10d, 24(%rax)
	movl	%r10d, 4(%rax)
	subq	%r9, %rdx
	addq	%rdx, %r8
	movq	%r8, 88(%rax)
	jmp	.L802
	.p2align 4,,10
	.p2align 3
.L1293:
	leaq	224(%rsp), %r10
.L804:
	movl	112(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L807
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 72(%rsp)
	movl	%eax, %r9d
	je	.L816
	testb	%al, %al
	je	.L816
	movq	104(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rdx, %rcx
	movq	88(%rax), %rdi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L807
	.p2align 4,,10
	.p2align 3
.L1299:
	movq	72(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L879
	movslq	48(%rdx), %rdi
	movslq	56(%rdx), %r9
	movslq	56(%rax), %r8
	movl	%ecx, 64(%rdx)
	imulq	%rdi, %r9
	movq	%rdi, 96(%rsp)
	movq	88(%rdx), %rdi
	movl	%r8d, 76(%rdx)
	movl	%r8d, 56(%rdx)
	imulq	96(%rsp), %r8
	subq	%r9, %rdi
	movl	%ecx, 44(%rdx)
	movslq	56(%rax), %rcx
	addq	%rdi, %r8
	movq	%r8, 88(%rdx)
	movl	44(%rax), %r8d
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rdi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r9
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rdi
	movl	%r8d, 64(%rax)
	imulq	%rdx, %rcx
	movl	%r8d, 44(%rax)
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 88(%rax)
	jmp	.L879
	.p2align 4,,10
	.p2align 3
.L1298:
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L878
	movslq	8(%rdx), %rdi
	movslq	16(%rdx), %r9
	movslq	16(%rax), %r8
	movl	%ecx, 4(%rdx)
	imulq	%rdi, %r9
	movq	%rdi, 96(%rsp)
	movq	88(%rdx), %rdi
	movl	%r8d, 36(%rdx)
	movl	%r8d, 16(%rdx)
	imulq	96(%rsp), %r8
	subq	%r9, %rdi
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%rdi, %r8
	movq	%r8, 88(%rdx)
	movl	4(%rax), %r8d
	movq	80(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rdi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r9
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rdi
	movl	%r8d, 24(%rax)
	imulq	%rdx, %rcx
	movl	%r8d, 4(%rax)
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 88(%rax)
	jmp	.L878
	.p2align 4,,10
	.p2align 3
.L805:
	movq	96(%rsp), %rax
	sall	$4, %ecx
	movslq	%ecx, %rdx
	orl	$1, %ecx
	leaq	(%rax,%rax,2), %rax
	movl	%ecx, 160(%rsp)
	movslq	%ecx, %rcx
	salq	$5, %rax
	movl	%edx, 168(%rsp)
	addq	%rbx, %rax
	movq	%rdx, 136(%rsp)
	movq	%rcx, 144(%rsp)
	movl	4(%rax), %r8d
	cmpl	24(%rax), %r8d
	je	.L1312
.L808:
	movq	96(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %ecx
	cmpl	64(%rax), %ecx
	je	.L1313
.L809:
	leal	(%rsi,%r10), %edx
	sarl	%edx
	leal	1(%rdx), %r9d
	movl	%r9d, 152(%rsp)
	cmpl	%edx, %r12d
	jg	.L810
	cmpl	%edx, %ebp
	jl	.L811
	testb	%dil, %dil
	je	.L811
	movq	136(%rsp), %rax
	movl	400(%rsp), %edi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%edi, 24(%rax)
	movq	88(%rax), %rsi
	movl	%edi, 4(%rax)
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	cmpl	%r9d, %ebp
	jl	.L813
.L812:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%r10d, %edx
	movl	%r11d, 120(%rsp)
	movq	%rbx, %rdi
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	168(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movl	120(%rsp), %r11d
.L813:
	movq	96(%rsp), %rax
	leaq	224(%rsp), %r10
	movl	%r11d, 160(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 152(%rsp)
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	232(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 312(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	344(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm0
	movups	%xmm0, 32(%rax)
	movdqu	464(%rsp), %xmm1
	movups	%xmm1, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movl	160(%rsp), %r11d
	movq	120(%rsp), %r10
	movups	%xmm3, 80(%rax)
	jmp	.L804
.L926:
	movl	64(%rsp), %edi
	leaq	(%rax,%rax,2), %r8
	salq	$5, %r8
	sall	$3, %edi
	addq	%rbx, %r8
	movslq	%edi, %rcx
	movl	4(%r8), %edx
	movl	%ecx, %eax
	movl	%ecx, 152(%rsp)
	orl	$1, %eax
	movq	%rcx, 64(%rsp)
	movl	%eax, 160(%rsp)
	cltq
	movq	%rax, 136(%rsp)
	cmpl	24(%r8), %edx
	je	.L1314
.L929:
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %edx
	cmpl	64(%rax), %edx
	je	.L1315
.L930:
	movl	56(%rsp), %edx
	addl	120(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L931
	cmpl	%edx, %ebp
	jl	.L932
	testb	%r9b, %r9b
	je	.L932
	movq	64(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L934
.L933:
	movl	408(%rsp), %ecx
	movl	%eax, %esi
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 144(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 56(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	136(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	144(%rsp), %r10
	movl	56(%rsp), %r11d
.L934:
	movq	88(%rsp), %rax
	movl	%r11d, 144(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 120(%rsp)
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	160(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 248(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	312(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm6
	movups	%xmm6, 32(%rax)
	movdqu	464(%rsp), %xmm7
	movups	%xmm7, 48(%rax)
	movdqu	480(%rsp), %xmm0
	movups	%xmm0, 64(%rax)
	movdqu	496(%rsp), %xmm1
	movl	336(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	56(%rsp), %r10
	movups	%xmm1, 80(%rax)
.L925:
	movl	112(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L928
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 104(%rsp)
	movb	%al, 64(%rsp)
	je	.L937
	testb	%al, %al
	je	.L937
	movq	96(%rsp), %rax
	movl	400(%rsp), %edi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%edi, 24(%rax)
	movq	88(%rax), %rsi
	movl	%edi, 4(%rax)
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L928
.L811:
	movl	408(%rsp), %eax
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movl	%r10d, 184(%rsp)
	movl	%r11d, 176(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	184(%rsp), %ecx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movl	184(%rsp), %r10d
	movl	176(%rsp), %r11d
.L810:
	movl	152(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L813
	cmpl	%eax, %r12d
	jg	.L812
	cmpb	$0, 120(%rsp)
	je	.L812
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L813
.L850:
	movl	88(%rsp), %edi
	leaq	(%rax,%rax,2), %r8
	salq	$5, %r8
	sall	$3, %edi
	addq	%rbx, %r8
	movslq	%edi, %rcx
	movl	4(%r8), %edx
	movl	%ecx, %eax
	movl	%ecx, 196(%rsp)
	orl	$1, %eax
	movq	%rcx, 168(%rsp)
	movl	%eax, 184(%rsp)
	cltq
	movq	%rax, 88(%rsp)
	cmpl	24(%r8), %edx
	je	.L1316
.L853:
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movl	44(%rax), %edx
	cmpl	64(%rax), %edx
	je	.L1317
.L854:
	movl	64(%rsp), %edx
	addl	152(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %eax
	cmpl	%edx, %r12d
	jg	.L855
	cmpl	%edx, %ebp
	jl	.L856
	testb	%r9b, %r9b
	je	.L856
	movq	168(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%eax, %ebp
	jl	.L858
.L857:
	movl	408(%rsp), %ecx
	movl	%eax, %esi
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 176(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 64(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	200(%rsp), %ecx
	movl	168(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	176(%rsp), %r10
	movl	64(%rsp), %r11d
.L858:
	movq	120(%rsp), %rax
	movl	%r11d, 176(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 152(%rsp)
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	264(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 256(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	344(%rsp), %rax
	movdqu	416(%rsp), %xmm4
	movups	%xmm4, (%rax)
	movdqu	432(%rsp), %xmm5
	movups	%xmm5, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movl	368(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	64(%rsp), %r10
	movups	%xmm7, 80(%rax)
.L849:
	movl	144(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L852
	cmpl	%eax, %r12d
	jg	.L851
	cmpb	$0, 136(%rsp)
	je	.L851
	movq	128(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L852
.L820:
	movq	120(%rsp), %rcx
	movl	128(%rsp), %edi
	leaq	(%rcx,%rcx,2), %r8
	sall	$2, %edi
	movslq	%edi, %rsi
	salq	$5, %r8
	orl	$1, %edi
	movl	%edi, 184(%rsp)
	addq	%rbx, %r8
	movslq	%edi, %rdi
	movl	%esi, 196(%rsp)
	movl	4(%r8), %ecx
	movq	%rsi, 160(%rsp)
	movq	%rdi, 128(%rsp)
	cmpl	24(%r8), %ecx
	je	.L1318
.L823:
	movq	120(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L1319
.L824:
	movl	112(%rsp), %ecx
	leal	(%rcx,%rax), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 176(%rsp)
	cmpl	%edx, %r12d
	jg	.L825
	cmpl	%edx, %ebp
	jl	.L826
	testb	%r9b, %r9b
	je	.L826
	movq	160(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L828
.L827:
	movl	408(%rsp), %ecx
	movl	%eax, %edx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 168(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 112(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	200(%rsp), %ecx
	movl	192(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	168(%rsp), %r10
	movl	112(%rsp), %r11d
.L828:
	movq	120(%rsp), %rax
	movl	%r11d, 176(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 168(%rsp)
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	256(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 304(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	360(%rsp), %rax
	movdqu	416(%rsp), %xmm2
	movups	%xmm2, (%rax)
	movdqu	432(%rsp), %xmm3
	movups	%xmm3, 16(%rax)
	movdqu	448(%rsp), %xmm2
	movups	%xmm2, 32(%rax)
	movdqu	464(%rsp), %xmm3
	movups	%xmm3, 48(%rax)
	movdqu	480(%rsp), %xmm6
	movups	%xmm6, 64(%rax)
	movdqu	496(%rsp), %xmm7
	movl	368(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	112(%rsp), %r10
	movups	%xmm7, 80(%rax)
.L819:
	movl	144(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L822
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 72(%rsp)
	movb	%al, 128(%rsp)
	je	.L831
	testb	%al, %al
	je	.L831
	movq	136(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L822
.L896:
	movq	24(%rsp), %rcx
	movl	112(%rsp), %edi
	leaq	(%rcx,%rcx,2), %r8
	sall	$2, %edi
	movslq	%edi, %rsi
	salq	$5, %r8
	orl	$1, %edi
	movl	%edi, 152(%rsp)
	addq	%rbx, %r8
	movslq	%edi, %rdi
	movl	%esi, 160(%rsp)
	movl	4(%r8), %ecx
	movq	%rsi, 128(%rsp)
	movq	%rdi, 112(%rsp)
	cmpl	24(%r8), %ecx
	je	.L1320
.L899:
	movq	24(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movl	44(%rdx), %ecx
	cmpl	64(%rdx), %ecx
	je	.L1321
.L900:
	movl	96(%rsp), %ecx
	leal	(%rax,%rcx), %edx
	sarl	%edx
	leal	1(%rdx), %r8d
	movl	%r8d, 144(%rsp)
	cmpl	%edx, %r12d
	jg	.L901
	cmpl	%edx, %ebp
	jl	.L902
	testb	%r9b, %r9b
	je	.L902
	movq	128(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	cmpl	%r8d, %ebp
	jl	.L904
.L903:
	movl	408(%rsp), %ecx
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movl	%eax, %edx
	movl	%r11d, 96(%rsp)
	movq	%rbx, %rdi
	movq	%r10, 136(%rsp)
	pushq	%rcx
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %ecx
	pushq	%rcx
	.cfi_def_cfa_offset 416
	movl	168(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	136(%rsp), %r10
	movl	96(%rsp), %r11d
.L904:
	movq	24(%rsp), %rax
	movl	%r11d, 144(%rsp)
	movq	%r10, %rdi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movq	%rax, 136(%rsp)
	movq	112(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 408
	pushq	80(%rdx)
	.cfi_def_cfa_offset 416
	pushq	72(%rdx)
	.cfi_def_cfa_offset 424
	pushq	64(%rdx)
	.cfi_def_cfa_offset 432
	pushq	56(%rdx)
	.cfi_def_cfa_offset 440
	pushq	48(%rdx)
	.cfi_def_cfa_offset 448
	pushq	40(%rdx)
	.cfi_def_cfa_offset 456
	pushq	32(%rdx)
	.cfi_def_cfa_offset 464
	pushq	24(%rdx)
	.cfi_def_cfa_offset 472
	pushq	16(%rdx)
	.cfi_def_cfa_offset 480
	pushq	8(%rdx)
	.cfi_def_cfa_offset 488
	pushq	(%rdx)
	.cfi_def_cfa_offset 496
	movq	224(%rsp), %rax
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	pushq	88(%rdx)
	.cfi_def_cfa_offset 504
	pushq	80(%rdx)
	.cfi_def_cfa_offset 512
	pushq	72(%rdx)
	.cfi_def_cfa_offset 520
	pushq	64(%rdx)
	.cfi_def_cfa_offset 528
	pushq	56(%rdx)
	.cfi_def_cfa_offset 536
	pushq	48(%rdx)
	.cfi_def_cfa_offset 544
	pushq	40(%rdx)
	.cfi_def_cfa_offset 552
	pushq	32(%rdx)
	.cfi_def_cfa_offset 560
	pushq	24(%rdx)
	.cfi_def_cfa_offset 568
	pushq	16(%rdx)
	.cfi_def_cfa_offset 576
	pushq	8(%rdx)
	.cfi_def_cfa_offset 584
	pushq	(%rdx)
	.cfi_def_cfa_offset 592
	movq	%r10, 288(%rsp)
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	328(%rsp), %rax
	movdqu	416(%rsp), %xmm0
	movups	%xmm0, (%rax)
	movdqu	432(%rsp), %xmm1
	movups	%xmm1, 16(%rax)
	movdqu	448(%rsp), %xmm4
	movups	%xmm4, 32(%rax)
	movdqu	464(%rsp), %xmm5
	movups	%xmm5, 48(%rax)
	movdqu	480(%rsp), %xmm2
	movups	%xmm2, 64(%rax)
	movdqu	496(%rsp), %xmm3
	movl	336(%rsp), %r11d
	addq	$192, %rsp
	.cfi_def_cfa_offset 400
	movq	96(%rsp), %r10
	movups	%xmm3, 80(%rax)
.L895:
	movl	104(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L898
	cmpl	%eax, %r12d
	setle	%al
	cmpb	$0, 88(%rsp)
	movb	%al, 112(%rsp)
	je	.L907
	testb	%al, %al
	je	.L907
	movq	40(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L898
.L887:
	movl	%eax, 152(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 168(%rsp)
	movl	%r11d, 160(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	152(%rsp), %ecx
	movl	40(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	168(%rsp), %r10
	movl	160(%rsp), %r11d
	movl	152(%rsp), %eax
.L886:
	cmpl	%eax, %ebp
	jl	.L889
	cmpl	%eax, %r12d
	jg	.L888
	cmpb	$0, 128(%rsp)
	je	.L888
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movq	88(%rax), %rsi
	imulq	%rdx, %rcx
	subq	%rcx, %rsi
	movq	%rsi, %rcx
	movl	400(%rsp), %esi
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	addq	%rcx, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L889
.L866:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%r11d, 128(%rsp)
	movq	%r10, 136(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	128(%rsp), %ecx
	movl	112(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	136(%rsp), %r10
	movl	128(%rsp), %r11d
.L865:
	movl	104(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L868
	cmpl	%eax, %r12d
	jg	.L867
	cmpb	$0, 32(%rsp)
	je	.L867
	movq	88(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L868
.L950:
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%r10, 96(%rsp)
	movq	%r11, 104(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	96(%rsp), %ecx
	movl	88(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	104(%rsp), %r11
	movq	96(%rsp), %r10
.L949:
	movl	64(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L952
	cmpl	%eax, %r12d
	jg	.L951
	cmpb	$0, 8(%rsp)
	je	.L951
	movq	56(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L952
.L1305:
	movq	40(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L885
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %r8
	movslq	56(%rax), %rdi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %r8
	movq	%r9, 152(%rsp)
	movq	88(%rdx), %r9
	movl	%edi, 76(%rdx)
	movl	%edi, 56(%rdx)
	imulq	152(%rsp), %rdi
	subq	%r8, %r9
	movl	%ecx, 44(%rdx)
	addq	%r9, %rdi
	movq	%rdi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %edi
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r8
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r9
	movl	%edx, 56(%rax)
	imulq	%r8, %rcx
	movl	%edi, 64(%rax)
	imulq	%r8, %rdx
	movl	%edi, 44(%rax)
	subq	%rcx, %r9
	addq	%r9, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L885
.L1304:
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L884
	movslq	8(%rdx), %r9
	movslq	16(%rdx), %r8
	movslq	16(%rax), %rdi
	movl	%ecx, 4(%rdx)
	imulq	%r9, %r8
	movq	%r9, 152(%rsp)
	movq	88(%rdx), %r9
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	imulq	152(%rsp), %rdi
	subq	%r8, %r9
	movl	%ecx, 24(%rdx)
	addq	%r9, %rdi
	movq	%rdi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %edi
	movq	120(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %r8
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r9
	movl	%edx, 16(%rax)
	imulq	%r8, %rcx
	movl	%edi, 24(%rax)
	imulq	%r8, %rdx
	movl	%edi, 4(%rax)
	subq	%rcx, %r9
	addq	%r9, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L884
.L1284:
	leaq	(%r11,%r11,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L948
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 64(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	64(%rsp), %rsi
	movl	%ecx, 44(%rdx)
	subq	%rdi, %r8
	movslq	56(%rax), %rcx
	movl	44(%rax), %edi
	movq	56(%rsp), %rax
	addq	%r8, %rsi
	leaq	(%rax,%rax,2), %rax
	movq	%rsi, 88(%rdx)
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	addq	%r8, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L948
.L1283:
	leaq	(%r11,%r11,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L947
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 64(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	64(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movl	4(%rax), %edi
	movq	56(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	addq	%r8, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L947
.L1290:
	movq	64(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L864
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L864
.L1289:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L863
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	88(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	addq	%r8, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L863
.L1309:
	movq	88(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L924
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 112(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	112(%rsp), %rsi
	movl	%ecx, 44(%rdx)
	subq	%rdi, %r8
	movslq	56(%rax), %rcx
	movl	44(%rax), %edi
	movq	96(%rsp), %rax
	addq	%r8, %rsi
	leaq	(%rax,%rax,2), %rax
	movq	%rsi, 88(%rdx)
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdx
	movslq	56(%rax), %rsi
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 64(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 44(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L924
.L1308:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L923
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 112(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	112(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	movslq	16(%rax), %rcx
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movl	4(%rax), %edi
	movq	96(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rsi
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%rdx, %rsi
	movl	%edi, 24(%rax)
	imulq	%rdx, %rcx
	movl	%edi, 4(%rax)
	subq	%rsi, %r8
	movq	%r8, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 88(%rax)
	jmp	.L923
.L1295:
	movq	120(%rsp), %rdi
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L818
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L818
.L1301:
	movq	24(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L894
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L894
.L1300:
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L893
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 104(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	104(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	40(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L893
.L1307:
	movq	120(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L848
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rdi
	movslq	56(%rax), %rsi
	movl	%ecx, 64(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 76(%rdx)
	movl	%esi, 56(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 44(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	56(%rax), %rdx
	movl	44(%rax), %esi
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	movl	%edx, 76(%rax)
	movq	88(%rax), %r8
	movl	%edx, 56(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 64(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 44(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L848
.L1306:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L847
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	128(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L847
.L1313:
	movq	136(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	44(%rdx), %ecx
	je	.L809
	movl	56(%rax), %r9d
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%r9d, 152(%rsp)
	movslq	48(%rdx), %r9
	movslq	152(%rsp), %rcx
	movq	%r9, %r8
	movslq	56(%rdx), %r9
	movl	%ecx, 76(%rdx)
	imulq	%r8, %r9
	movl	%ecx, 56(%rdx)
	movq	%r8, 176(%rsp)
	movq	88(%rdx), %r8
	imulq	176(%rsp), %rcx
	subq	%r9, %r8
	addq	%r8, %rcx
	movl	44(%rax), %r8d
	movq	%rcx, 88(%rdx)
	movslq	56(%rax), %rcx
	movq	144(%rsp), %rax
	movl	%r8d, 152(%rsp)
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r9
	movslq	56(%rax), %rdx
	movl	%ecx, 76(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 56(%rax)
	imulq	%r9, %rdx
	imulq	%r9, %rcx
	subq	%rdx, %r8
	movq	%r8, %rdx
	movl	152(%rsp), %r8d
	addq	%rdx, %rcx
	movl	%r8d, 64(%rax)
	movl	%r8d, 44(%rax)
	movq	%rcx, 88(%rax)
	jmp	.L809
.L1312:
	leaq	(%rdx,%rdx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %r8d
	je	.L808
	movl	16(%rax), %ecx
	movslq	8(%rdx), %r9
	movl	%r8d, 4(%rdx)
	movl	%r8d, 24(%rdx)
	movl	%ecx, 152(%rsp)
	movq	%r9, %rcx
	movslq	16(%rdx), %r9
	movq	%rcx, 176(%rsp)
	imulq	%rcx, %r9
	movq	88(%rdx), %rcx
	subq	%r9, %rcx
	movq	%rcx, %r9
	movslq	152(%rsp), %rcx
	movl	%ecx, 36(%rdx)
	movl	%ecx, 16(%rdx)
	imulq	176(%rsp), %rcx
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	movslq	16(%rax), %rcx
	movl	4(%rax), %r8d
	movq	144(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	movl	%r8d, 152(%rsp)
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %r9
	movslq	16(%rax), %rdx
	movl	%ecx, 36(%rax)
	movq	88(%rax), %r8
	movl	%ecx, 16(%rax)
	imulq	%r9, %rdx
	imulq	%r9, %rcx
	subq	%rdx, %r8
	movq	%r8, %rdx
	movl	152(%rsp), %r8d
	addq	%rdx, %rcx
	movl	%r8d, 24(%rax)
	movl	%r8d, 4(%rax)
	movq	%rcx, 88(%rax)
	jmp	.L808
.L1294:
	leaq	(%rdi,%rdi,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	cmpl	4(%rdx), %ecx
	je	.L817
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rdi
	movslq	16(%rax), %rsi
	movl	%ecx, 4(%rdx)
	imulq	%r8, %rdi
	movq	%r8, 144(%rsp)
	movq	88(%rdx), %r8
	movl	%esi, 36(%rdx)
	movl	%esi, 16(%rdx)
	imulq	144(%rsp), %rsi
	subq	%rdi, %r8
	movl	%ecx, 24(%rdx)
	addq	%r8, %rsi
	movq	%rsi, 88(%rdx)
	movslq	16(%rax), %rdx
	movl	4(%rax), %esi
	movq	136(%rsp), %rax
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdi
	movslq	16(%rax), %rcx
	movl	%edx, 36(%rax)
	movq	88(%rax), %r8
	movl	%edx, 16(%rax)
	imulq	%rdi, %rcx
	movl	%esi, 24(%rax)
	imulq	%rdi, %rdx
	movl	%esi, 4(%rax)
	subq	%rcx, %r8
	movq	%r8, %rcx
	addq	%rdx, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L817
.L902:
	movl	%eax, 176(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 184(%rsp)
	movl	%r11d, 168(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	176(%rsp), %ecx
	movl	112(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 408
	popq	%rax
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movl	176(%rsp), %eax
	movl	168(%rsp), %r11d
.L901:
	movl	144(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L904
	cmpl	%ecx, %r12d
	jg	.L903
	cmpb	$0, 136(%rsp)
	je	.L903
	movq	112(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rdx, %rcx
	movq	88(%rax), %rdi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L904
.L856:
	movl	%eax, 208(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 216(%rsp)
	movl	%r11d, 200(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	212(%rsp), %ecx
	movl	80(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 408
	popq	%rsi
	.cfi_def_cfa_offset 400
	movq	216(%rsp), %r10
	movl	208(%rsp), %eax
	movl	200(%rsp), %r11d
.L855:
	cmpl	%eax, %ebp
	jl	.L858
	cmpl	%eax, %r12d
	jg	.L857
	cmpb	$0, 176(%rsp)
	je	.L857
	movq	88(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L858
.L941:
	movl	%r11d, 64(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movq	%rax, 144(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 152(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	152(%rsp), %ecx
	movl	128(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	152(%rsp), %r10
	movq	144(%rsp), %rax
	movl	64(%rsp), %r11d
.L940:
	movl	120(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L943
	cmpl	%ecx, %r12d
	jg	.L942
	cmpb	$0, 104(%rsp)
	je	.L942
	movq	56(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L943
.L932:
	movl	%eax, 176(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movl	%r11d, 168(%rsp)
	movq	%r10, 184(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	168(%rsp), %ecx
	movl	72(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movl	176(%rsp), %eax
	movl	168(%rsp), %r11d
.L931:
	cmpl	%eax, %ebp
	jl	.L934
	cmpl	%eax, %r12d
	jg	.L933
	cmpb	$0, 144(%rsp)
	je	.L933
	movq	136(%rsp), %rax
	movl	400(%rsp), %esi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 24(%rax)
	movl	%esi, 4(%rax)
	movslq	408(%rsp), %rsi
	imulq	%rdx, %rcx
	movq	88(%rax), %rdi
	imulq	%rsi, %rdx
	movl	%esi, 36(%rax)
	movl	%esi, 16(%rax)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	jmp	.L934
.L835:
	movq	%rax, 176(%rsp)
	movl	408(%rsp), %eax
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%r10, 184(%rsp)
	movq	%rbx, %rdi
	movl	%r11d, 128(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	184(%rsp), %ecx
	movl	160(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 408
	popq	%r10
	.cfi_def_cfa_offset 400
	movq	184(%rsp), %r10
	movq	176(%rsp), %rax
	movl	128(%rsp), %r11d
.L834:
	movl	152(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L837
	cmpl	%ecx, %r12d
	jg	.L836
	cmpb	$0, 72(%rsp)
	je	.L836
	movq	112(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L837
.L911:
	movl	%r11d, 112(%rsp)
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	%ebp, %r9d
	movq	%rax, 152(%rsp)
	movl	408(%rsp), %eax
	movq	%r10, 144(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	144(%rsp), %ecx
	movl	120(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 408
	popq	%r8
	.cfi_def_cfa_offset 400
	movq	152(%rsp), %rax
	movq	144(%rsp), %r10
	movl	112(%rsp), %r11d
.L910:
	movl	120(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L913
	cmpl	%ecx, %r12d
	jg	.L912
	cmpb	$0, 88(%rsp)
	je	.L912
	movq	96(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rdx
	salq	$5, %rdx
	addq	%rbx, %rdx
	movslq	8(%rdx), %rcx
	movslq	16(%rdx), %rsi
	movq	88(%rdx), %rdi
	imulq	%rcx, %rsi
	subq	%rsi, %rdi
	movq	%rdi, %rsi
	movl	400(%rsp), %edi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movslq	408(%rsp), %rdi
	imulq	%rdi, %rcx
	movl	%edi, 36(%rdx)
	movl	%edi, 16(%rdx)
	addq	%rsi, %rcx
	movq	%rcx, 88(%rdx)
	jmp	.L913
.L826:
	movl	%eax, 208(%rsp)
	movl	%ebp, %r9d
	movl	%r12d, %r8d
	movq	%rbx, %rdi
	movl	408(%rsp), %eax
	movq	%r10, 216(%rsp)
	movl	%r11d, 200(%rsp)
	pushq	%rax
	.cfi_def_cfa_offset 408
	movl	408(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 416
	movl	212(%rsp), %ecx
	movl	128(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 408
	popq	%rdx
	.cfi_def_cfa_offset 400
	movq	216(%rsp), %r10
	movl	208(%rsp), %eax
	movl	200(%rsp), %r11d
.L825:
	movl	176(%rsp), %ecx
	cmpl	%ecx, %ebp
	jl	.L828
	cmpl	%ecx, %r12d
	jg	.L827
	cmpb	$0, 168(%rsp)
	je	.L827
	movq	128(%rsp), %rax
	movslq	408(%rsp), %rsi
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbx, %rax
	movslq	8(%rax), %rdx
	movslq	16(%rax), %rcx
	movl	%esi, 36(%rax)
	movq	88(%rax), %rdi
	movl	%esi, 16(%rax)
	imulq	%rdx, %rcx
	imulq	%rsi, %rdx
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	400(%rsp), %edi
	addq	%rcx, %rdx
	movl	%edi, 24(%rax)
	movl	%edi, 4(%rax)
	movq	%rdx, 88(%rax)
	jmp	.L828
.L1316:
	leaq	(%rcx,%rcx,2), %rax
	movq	%rcx, %rdi
	salq	$5, %rax
	leaq	(%rbx,%rax), %rsi
	cmpl	4(%rsi), %edx
	je	.L853
	imulq	$96, 120(%rsp), %rax
	leaq	(%rbx,%rax), %rcx
	imulq	$96, %rdi, %rax
	movq	%rcx, 208(%rsp)
	movl	16(%rcx), %ecx
	movl	%ecx, 200(%rsp)
	movslq	8(%rsi), %rcx
	addq	%rbx, %rax
	movslq	16(%rax), %rdi
	movl	%edx, 24(%rax)
	imulq	%rdi, %rcx
	movq	88(%rax), %rdi
	movl	%edx, 4(%rsi)
	subq	%rcx, %rdi
	movslq	200(%rsp), %rcx
	movl	%ecx, 16(%rax)
	movl	%ecx, 36(%rax)
	movslq	8(%rsi), %rdx
	imulq	%rcx, %rdx
	movq	208(%rsp), %rcx
	movslq	16(%rcx), %rcx
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	imulq	$96, 88(%rsp), %rax
	movl	4(%r8), %esi
	addq	%rbx, %rax
	movslq	8(%rax), %r8
	movslq	16(%rax), %rdx
	movl	%ecx, 36(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 16(%rax)
	imulq	%r8, %rdx
	movl	%esi, 24(%rax)
	imulq	%r8, %rcx
	movl	%esi, 4(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L853
.L1303:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L909
	imulq	$96, %rax, %rdx
	imulq	$96, 40(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 120(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	120(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 96(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L909
.L1319:
	movq	160(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L824
	imulq	$96, %rsi, %rdx
	imulq	$96, 120(%rsp), %r8
	addq	%rbx, %rdx
	addq	%rbx, %r8
	movslq	48(%rdx), %rsi
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%edi, 176(%rsp)
	movq	%rsi, %rdi
	movslq	56(%rdx), %rsi
	movslq	176(%rsp), %rcx
	movq	%rdi, 200(%rsp)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	movl	%ecx, 56(%rdx)
	movl	%ecx, 76(%rdx)
	imulq	200(%rsp), %rcx
	subq	%rsi, %rdi
	movslq	56(%r8), %rsi
	addq	%rdi, %rcx
	movl	44(%r8), %edi
	movq	%rcx, 88(%rdx)
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 176(%rsp)
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	176(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L824
.L1318:
	leaq	(%rsi,%rsi,2), %rdx
	movq	%rsi, %rdi
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 176(%rsp)
	cmpl	4(%rsi), %ecx
	je	.L823
	imulq	$96, 120(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 208(%rsp)
	imulq	$96, %rdi, %rdx
	movl	16(%rsi), %esi
	movl	%esi, 200(%rsp)
	movq	176(%rsp), %rsi
	addq	%rbx, %rdx
	movslq	8(%rsi), %rsi
	movslq	16(%rdx), %rdi
	movl	%ecx, 24(%rdx)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	subq	%rsi, %rdi
	movq	176(%rsp), %rsi
	movl	%ecx, 4(%rsi)
	movslq	200(%rsp), %rsi
	movq	176(%rsp), %rcx
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rcx), %rcx
	imulq	%rsi, %rcx
	movq	208(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rdx)
	movl	4(%r8), %edi
	imulq	$96, 128(%rsp), %rdx
	movl	%edi, 176(%rsp)
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	176(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L823
.L1317:
	movq	168(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rax
	salq	$5, %rax
	cmpl	44(%rbx,%rax), %edx
	je	.L854
	imulq	$96, %rcx, %rax
	imulq	$96, 120(%rsp), %r8
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	addq	%rbx, %r8
	movl	56(%r8), %esi
	movl	%edx, 64(%rax)
	imulq	%rdi, %rcx
	movl	%edx, 44(%rax)
	movq	%rdi, 200(%rsp)
	movslq	%esi, %rdx
	movq	88(%rax), %rdi
	imulq	200(%rsp), %rdx
	movl	%esi, 56(%rax)
	subq	%rcx, %rdi
	movl	%esi, 76(%rax)
	movslq	56(%r8), %rcx
	movl	44(%r8), %esi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	imulq	$96, 88(%rsp), %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r8
	movslq	56(%rax), %rdx
	movl	%ecx, 76(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 56(%rax)
	imulq	%r8, %rdx
	movl	%esi, 64(%rax)
	imulq	%r8, %rcx
	movl	%esi, 44(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L854
.L1311:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L939
	imulq	$96, %rax, %rdx
	imulq	$96, 96(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 120(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	120(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 56(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L939
.L1310:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L938
	imulq	$96, 96(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 144(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 120(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	120(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	144(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 56(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L938
.L1321:
	movq	128(%rsp), %rsi
	leaq	(%rsi,%rsi,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L900
	imulq	$96, %rsi, %rdx
	imulq	$96, 24(%rsp), %r8
	addq	%rbx, %rdx
	addq	%rbx, %r8
	movslq	48(%rdx), %rsi
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	movl	%ecx, 44(%rdx)
	movl	%edi, 144(%rsp)
	movq	%rsi, %rdi
	movslq	56(%rdx), %rsi
	movslq	144(%rsp), %rcx
	movq	%rdi, 168(%rsp)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	movl	%ecx, 56(%rdx)
	movl	%ecx, 76(%rdx)
	imulq	168(%rsp), %rcx
	subq	%rsi, %rdi
	movslq	56(%r8), %rsi
	addq	%rdi, %rcx
	movl	44(%r8), %edi
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	%edi, 144(%rsp)
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 64(%rdx)
	movl	%edi, 44(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L900
.L1320:
	leaq	(%rsi,%rsi,2), %rdx
	movq	%rsi, %rdi
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 144(%rsp)
	cmpl	4(%rsi), %ecx
	je	.L899
	imulq	$96, 24(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	movq	%rsi, 176(%rsp)
	imulq	$96, %rdi, %rdx
	movl	16(%rsi), %esi
	movl	%esi, 168(%rsp)
	movq	144(%rsp), %rsi
	addq	%rbx, %rdx
	movslq	8(%rsi), %rsi
	movslq	16(%rdx), %rdi
	movl	%ecx, 24(%rdx)
	imulq	%rdi, %rsi
	movq	88(%rdx), %rdi
	subq	%rsi, %rdi
	movq	144(%rsp), %rsi
	movl	%ecx, 4(%rsi)
	movslq	168(%rsp), %rsi
	movq	144(%rsp), %rcx
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rcx), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movl	%edi, 144(%rsp)
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %rdi
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	imulq	%r8, %rsi
	subq	%rcx, %rdi
	movq	%rdi, %rcx
	movl	144(%rsp), %edi
	addq	%rcx, %rsi
	movl	%edi, 24(%rdx)
	movl	%edi, 4(%rdx)
	movq	%rsi, 88(%rdx)
	jmp	.L899
.L1297:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	cmpl	44(%rbx,%rdx), %ecx
	je	.L833
	imulq	$96, %rax, %rdx
	imulq	$96, 136(%rsp), %r8
	addq	%rbx, %rdx
	movslq	48(%rdx), %r9
	movslq	56(%rdx), %rsi
	addq	%rbx, %r8
	movl	56(%r8), %edi
	movl	%ecx, 64(%rdx)
	imulq	%r9, %rsi
	movl	%ecx, 44(%rdx)
	movq	%r9, 152(%rsp)
	movslq	%edi, %rcx
	movq	88(%rdx), %r9
	imulq	152(%rsp), %rcx
	movl	%edi, 56(%rdx)
	subq	%rsi, %r9
	movl	%edi, 76(%rdx)
	movslq	56(%r8), %rsi
	movl	44(%r8), %edi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	addq	%rbx, %rdx
	movslq	48(%rdx), %r8
	movslq	56(%rdx), %rcx
	movl	%esi, 76(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 56(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 64(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 44(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L833
.L1296:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L832
	imulq	$96, 136(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 176(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 152(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	152(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	176(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 112(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L832
.L1315:
	movq	64(%rsp), %rcx
	leaq	(%rcx,%rcx,2), %rax
	salq	$5, %rax
	cmpl	44(%rbx,%rax), %edx
	je	.L930
	imulq	$96, %rcx, %rax
	imulq	$96, 88(%rsp), %r8
	addq	%rbx, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %rcx
	addq	%rbx, %r8
	movl	56(%r8), %esi
	movl	%edx, 64(%rax)
	imulq	%rdi, %rcx
	movl	%edx, 44(%rax)
	movq	%rdi, 168(%rsp)
	movslq	%esi, %rdx
	movq	88(%rax), %rdi
	imulq	168(%rsp), %rdx
	movl	%esi, 56(%rax)
	subq	%rcx, %rdi
	movl	%esi, 76(%rax)
	movslq	56(%r8), %rcx
	movl	44(%r8), %esi
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	imulq	$96, 136(%rsp), %rax
	addq	%rbx, %rax
	movslq	48(%rax), %r8
	movslq	56(%rax), %rdx
	movl	%ecx, 76(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 56(%rax)
	imulq	%r8, %rdx
	movl	%esi, 64(%rax)
	imulq	%r8, %rcx
	movl	%esi, 44(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L930
.L1314:
	leaq	(%rcx,%rcx,2), %rax
	movq	%rcx, %rdi
	salq	$5, %rax
	leaq	(%rbx,%rax), %rsi
	cmpl	4(%rsi), %edx
	je	.L929
	imulq	$96, 88(%rsp), %rax
	leaq	(%rbx,%rax), %rcx
	imulq	$96, %rdi, %rax
	movq	%rcx, 176(%rsp)
	movl	16(%rcx), %ecx
	movl	%ecx, 168(%rsp)
	movslq	8(%rsi), %rcx
	addq	%rbx, %rax
	movslq	16(%rax), %rdi
	movl	%edx, 24(%rax)
	imulq	%rdi, %rcx
	movq	88(%rax), %rdi
	movl	%edx, 4(%rsi)
	subq	%rcx, %rdi
	movslq	168(%rsp), %rcx
	movl	%ecx, 16(%rax)
	movl	%ecx, 36(%rax)
	movslq	8(%rsi), %rdx
	imulq	%rcx, %rdx
	movq	176(%rsp), %rcx
	movslq	16(%rcx), %rcx
	addq	%rdi, %rdx
	movq	%rdx, 88(%rax)
	movl	4(%r8), %esi
	imulq	$96, 136(%rsp), %rax
	addq	%rbx, %rax
	movslq	8(%rax), %r8
	movslq	16(%rax), %rdx
	movl	%ecx, 36(%rax)
	movq	88(%rax), %rdi
	movl	%ecx, 16(%rax)
	imulq	%r8, %rdx
	movl	%esi, 24(%rax)
	imulq	%r8, %rcx
	movl	%esi, 4(%rax)
	subq	%rdx, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 88(%rax)
	jmp	.L929
.L1302:
	leaq	(%rax,%rax,2), %rdx
	salq	$5, %rdx
	leaq	(%rbx,%rdx), %rdi
	cmpl	4(%rdi), %ecx
	je	.L908
	imulq	$96, 40(%rsp), %rdx
	leaq	(%rbx,%rdx), %rsi
	imulq	$96, %rax, %rdx
	movq	%rsi, 144(%rsp)
	movl	16(%rsi), %esi
	movl	%esi, 120(%rsp)
	movslq	8(%rdi), %rsi
	addq	%rbx, %rdx
	movslq	16(%rdx), %r9
	movl	%ecx, 24(%rdx)
	imulq	%r9, %rsi
	movq	88(%rdx), %r9
	movl	%ecx, 4(%rdi)
	subq	%rsi, %r9
	movslq	120(%rsp), %rsi
	movl	%esi, 16(%rdx)
	movl	%esi, 36(%rdx)
	movslq	8(%rdi), %rcx
	imulq	%rsi, %rcx
	movq	144(%rsp), %rsi
	movslq	16(%rsi), %rsi
	addq	%r9, %rcx
	movq	%rcx, 88(%rdx)
	imulq	$96, 96(%rsp), %rdx
	movl	4(%r8), %edi
	addq	%rbx, %rdx
	movslq	8(%rdx), %r8
	movslq	16(%rdx), %rcx
	movl	%esi, 36(%rdx)
	movq	88(%rdx), %r9
	movl	%esi, 16(%rdx)
	imulq	%r8, %rcx
	movl	%edi, 24(%rdx)
	imulq	%r8, %rsi
	movl	%edi, 4(%rdx)
	subq	%rcx, %r9
	addq	%r9, %rsi
	movq	%rsi, 88(%rdx)
	jmp	.L908
.L1276:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE3573:
	.size	_ZN11Solve_merge2ST10update_MinEiiiiiii, .-_ZN11Solve_merge2ST10update_MinEiiiiiii
	.section	.text._ZN11Solve_merge2ST6changeEiiiiiiii,"axG",@progbits,_ZN11Solve_merge2ST6changeEiiiiiiii,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_merge2ST6changeEiiiiiiii
	.type	_ZN11Solve_merge2ST6changeEiiiiiiii, @function
_ZN11Solve_merge2ST6changeEiiiiiiii:
.LFB3574:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	movq	%rdi, %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$136, %rsp
	.cfi_def_cfa_offset 192
	cmpl	%edx, %esi
	je	.L1357
	movslq	%ecx, %rax
	addl	%ecx, %ecx
	leaq	(%rax,%rax,2), %rbx
	movslq	%ecx, %r12
	salq	$5, %rbx
	addq	%rdi, %rbx
	movl	%ecx, %edi
	orl	$1, %edi
	movl	4(%rbx), %r10d
	movl	%edi, 12(%rsp)
	movslq	%edi, %r13
	cmpl	24(%rbx), %r10d
	je	.L1358
.L1326:
	leaq	(%rax,%rax,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movl	44(%rax), %r10d
	cmpl	64(%rax), %r10d
	je	.L1359
.L1327:
	leal	(%rsi,%rdx), %r10d
	sarl	%r10d
	cmpl	%r8d, %r10d
	jge	.L1360
.L1328:
	subq	$8, %rsp
	.cfi_def_cfa_offset 200
	leal	1(%r10), %esi
	movq	%rbp, %rdi
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 216
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 224
	movl	44(%rsp), %ecx
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 192
.L1329:
	leaq	(%r12,%r12,2), %rax
	leaq	0(%r13,%r13,2), %rdi
	salq	$5, %rax
	salq	$5, %rdi
	addq	%rbp, %rax
	addq	%rdi, %rbp
	movl	44(%rax), %ecx
	movq	(%rax), %rsi
	movl	4(%rax), %edx
	movl	20(%rax), %r10d
	movl	28(%rax), %r9d
	movl	32(%rax), %r11d
	movl	%ecx, 80(%rsp)
	movl	48(%rax), %ecx
	movslq	36(%rax), %r14
	movq	%rsi, 48(%rsp)
	movl	12(%rax), %esi
	movl	60(%rax), %r8d
	movl	%edx, 76(%rsp)
	movl	8(%rax), %edx
	movl	64(%rax), %r15d
	movl	%ecx, 28(%rsp)
	movl	56(%rax), %ecx
	movslq	76(%rax), %r12
	movl	%esi, 32(%rsp)
	movq	40(%rax), %rsi
	movl	%edx, 24(%rsp)
	movl	%ecx, 60(%rsp)
	movl	72(%rax), %ecx
	movl	16(%rax), %edx
	movq	%rsi, 40(%rsp)
	movl	%ecx, 12(%rsp)
	movl	52(%rax), %esi
	movzbl	80(%rax), %ecx
	movl	%edx, 56(%rsp)
	movl	%esi, 36(%rsp)
	movl	24(%rax), %edx
	movl	68(%rax), %esi
	movb	%cl, 126(%rsp)
	movzbl	81(%rax), %ecx
	movl	0(%rbp), %edi
	movq	88(%rax), %rax
	movb	%cl, 16(%rsp)
	testl	%edi, %edi
	je	.L1330
	movl	24(%rbp), %r13d
	movl	4(%rbp), %ecx
	addq	88(%rbp), %rax
	movl	%r13d, 72(%rsp)
	movl	28(%rbp), %r13d
	movl	%ecx, 104(%rsp)
	movl	%r13d, 64(%rsp)
	movl	32(%rbp), %r13d
	movq	%rax, 96(%rsp)
	movl	%r13d, 84(%rsp)
	movl	44(%rbp), %r13d
	movl	%r13d, 68(%rsp)
	cmpl	%ecx, %edx
	je	.L1361
	movb	$0, 126(%rsp)
.L1331:
	movl	72(%rbp), %edi
	movl	60(%rbp), %edx
	movl	20(%rbp), %r10d
	movl	36(%rbp), %r14d
	movl	%edi, 76(%rsp)
	movl	76(%rbp), %edi
	movl	%edx, 88(%rsp)
	movl	68(%rbp), %r9d
	movl	%edi, 96(%rsp)
	movl	64(%rbp), %edx
	cmpl	68(%rsp), %r15d
	je	.L1362
	movb	$0, 16(%rsp)
.L1337:
	movl	76(%rsp), %esi
	movl	%edx, %r15d
	movl	96(%rsp), %r12d
	movl	88(%rsp), %r8d
	movl	84(%rsp), %r11d
	movl	%esi, 12(%rsp)
	movl	72(%rsp), %edx
	movl	%r9d, %esi
	movl	64(%rsp), %r9d
.L1330:
	movq	48(%rsp), %rcx
	movl	56(%rsp), %edi
	movl	%edx, 24(%rbx)
	movq	40(%rsp), %rdx
	movl	%esi, 68(%rbx)
	movl	12(%rsp), %esi
	movq	%rcx, (%rbx)
	movq	%rdx, 40(%rbx)
	movl	28(%rsp), %edx
	movl	24(%rsp), %ecx
	movl	%esi, 72(%rbx)
	movl	%edx, 48(%rbx)
	movzbl	126(%rsp), %esi
	movl	36(%rsp), %edx
	movl	%ecx, 8(%rbx)
	movb	%sil, 80(%rbx)
	movl	32(%rsp), %ecx
	movl	%edx, 52(%rbx)
	movzbl	16(%rsp), %esi
	movl	60(%rsp), %edx
	movl	%ecx, 12(%rbx)
	movl	%edi, 16(%rbx)
	movl	%r10d, 20(%rbx)
	movl	%r9d, 28(%rbx)
	movl	%r11d, 32(%rbx)
	movl	%r14d, 36(%rbx)
	movl	%edx, 56(%rbx)
	movl	%r8d, 60(%rbx)
	movl	%r15d, 64(%rbx)
	movl	%r12d, 76(%rbx)
	movb	%sil, 81(%rbx)
	movq	%rax, 88(%rbx)
.L1322:
	addq	$136, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L1360:
	.cfi_restore_state
	subq	$8, %rsp
	.cfi_def_cfa_offset 200
	movl	%r10d, %edx
	movq	%rbp, %rdi
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 208
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 216
	movl	216(%rsp), %eax
	pushq	%rax
	.cfi_def_cfa_offset 224
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 192
	jmp	.L1329
	.p2align 4,,10
	.p2align 3
.L1359:
	leaq	(%r12,%r12,2), %rdi
	salq	$5, %rdi
	addq	%rbp, %rdi
	cmpl	44(%rdi), %r10d
	je	.L1327
	movslq	48(%rdi), %r11
	movslq	56(%rdi), %r15
	movslq	56(%rax), %r14
	movl	%r10d, 64(%rdi)
	imulq	%r11, %r15
	movq	%r11, 16(%rsp)
	movq	88(%rdi), %r11
	movl	%r14d, 76(%rdi)
	movl	%r14d, 56(%rdi)
	imulq	16(%rsp), %r14
	subq	%r15, %r11
	movl	%r10d, 44(%rdi)
	movslq	56(%rax), %r10
	addq	%r11, %r14
	movq	%r14, 88(%rdi)
	movl	44(%rax), %r14d
	leaq	0(%r13,%r13,2), %rax
	salq	$5, %rax
	addq	%rbp, %rax
	movslq	48(%rax), %rdi
	movslq	56(%rax), %r11
	movl	%r10d, 76(%rax)
	movq	88(%rax), %r15
	movl	%r10d, 56(%rax)
	imulq	%rdi, %r11
	movl	%r14d, 64(%rax)
	imulq	%rdi, %r10
	movl	%r14d, 44(%rax)
	subq	%r11, %r15
	addq	%r15, %r10
	movq	%r10, 88(%rax)
	leal	(%rsi,%rdx), %r10d
	sarl	%r10d
	cmpl	%r8d, %r10d
	jl	.L1328
	jmp	.L1360
	.p2align 4,,10
	.p2align 3
.L1358:
	leaq	(%r12,%r12,2), %rdi
	salq	$5, %rdi
	addq	%rbp, %rdi
	cmpl	4(%rdi), %r10d
	je	.L1326
	movslq	8(%rdi), %r11
	movslq	16(%rdi), %r15
	movslq	16(%rbx), %r14
	movl	%r10d, 24(%rdi)
	imulq	%r11, %r15
	movq	%r11, 16(%rsp)
	movq	88(%rdi), %r11
	movl	%r14d, 16(%rdi)
	movl	%r14d, 36(%rdi)
	imulq	16(%rsp), %r14
	subq	%r15, %r11
	movl	%r10d, 4(%rdi)
	addq	%r11, %r14
	movslq	16(%rbx), %r11
	movq	%r14, 88(%rdi)
	leaq	0(%r13,%r13,2), %rdi
	movl	4(%rbx), %r15d
	salq	$5, %rdi
	addq	%rbp, %rdi
	movslq	8(%rdi), %r10
	movslq	16(%rdi), %r14
	movl	%r11d, 36(%rdi)
	movl	%r11d, 16(%rdi)
	imulq	%r10, %r14
	movq	%r10, 16(%rsp)
	movq	88(%rdi), %r10
	imulq	16(%rsp), %r11
	movl	%r15d, 24(%rdi)
	movl	%r15d, 4(%rdi)
	subq	%r14, %r10
	addq	%r10, %r11
	movq	%r11, 88(%rdi)
	jmp	.L1326
	.p2align 4,,10
	.p2align 3
.L1357:
	movslq	%ecx, %rcx
	movl	192(%rsp), %edx
	leaq	(%rcx,%rcx,2), %rdi
	salq	$5, %rdi
	addq	%rdi, %rbp
	testl	%edx, %edx
	jne	.L1324
	movl	$257, %eax
	movq	$0, 0(%rbp)
	movq	$0, 8(%rbp)
	movq	$0, 16(%rbp)
	movq	$0, 24(%rbp)
	movq	$0, 32(%rbp)
	movq	$0, 40(%rbp)
	movq	$0, 48(%rbp)
	movq	$0, 56(%rbp)
	movq	$0, 64(%rbp)
	movq	$0, 72(%rbp)
	movw	%ax, 80(%rbp)
	movq	$0, 88(%rbp)
	jmp	.L1322
	.p2align 4,,10
	.p2align 3
.L1324:
	movl	192(%rsp), %eax
	movl	200(%rsp), %ebx
	movl	%r9d, 40(%rbp)
	movl	%r9d, 0(%rbp)
	movl	%eax, 44(%rbp)
	movl	%eax, 4(%rbp)
	movl	200(%rsp), %eax
	movl	$1, 52(%rbp)
	movl	%eax, 16(%rbp)
	movl	208(%rsp), %eax
	movl	$1, 12(%rbp)
	movl	%eax, 56(%rbp)
	movl	200(%rsp), %eax
	movl	$1, 48(%rbp)
	addl	208(%rsp), %eax
	movl	$1, 8(%rbp)
	movdqu	40(%rbp), %xmm1
	cltq
	movl	%ebx, 36(%rbp)
	movdqu	0(%rbp), %xmm0
	movl	208(%rsp), %ebx
	movq	%rax, 88(%rbp)
	movups	%xmm0, 20(%rbp)
	movl	%ebx, 76(%rbp)
	movups	%xmm1, 60(%rbp)
	jmp	.L1322
	.p2align 4,,10
	.p2align 3
.L1362:
	movl	40(%rbp), %r11d
	movl	48(%rbp), %ecx
	movl	52(%rbp), %edi
	movl	%ecx, 108(%rsp)
	movl	%r11d, %ecx
	movl	%r11d, %r13d
	movl	%edi, 120(%rsp)
	movzbl	81(%rbp), %edi
	subl	%r8d, %ecx
	movl	$1, %ebp
	movslq	%ecx, %rcx
	movl	%r11d, 112(%rsp)
	movslq	%r8d, %r11
	movb	%dil, 127(%rsp)
	leaq	_ZN11Solve_merge6SparseE(%rip), %rdi
	leaq	(%r11,%r11,4), %r11
	movslq	100001000(%rdi,%rcx,4), %rcx
	sall	%cl, %ebp
	subl	%ebp, %r13d
	leaq	(%r11,%r11,4), %rbp
	movslq	%r13d, %r11
	movl	108(%rsp), %r13d
	addq	%rcx, %rbp
	leaq	(%r11,%r11,4), %r11
	leaq	(%r11,%r11,4), %r11
	addq	%rcx, %r11
	movl	50000500(%rdi,%r11,4), %ecx
	cmpl	%ecx, 50000500(%rdi,%rbp,4)
	cmovge	50000500(%rdi,%rbp,4), %ecx
	cmpl	%r13d, %esi
	cmovge	%esi, %r13d
	addl	108(%rsp), %esi
	movslq	%esi, %rsi
	imulq	%r12, %rsi
	subq	%rsi, %rax
	movq	%rax, %rsi
	movl	(%rdi,%rbp,4), %eax
	cmpl	%eax, (%rdi,%r11,4)
	cmovle	(%rdi,%r11,4), %eax
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	movl	112(%rsp), %edi
	addl	$1, %eax
	subl	%r8d, %edi
	movl	104(%rsp), %r8d
	subl	$1, %r8d
	cmpl	%r8d, %ecx
	je	.L1363
	cmpl	%edi, %eax
	je	.L1364
.L1350:
	movb	$0, 16(%rsp)
.L1339:
	movslq	%r13d, %rax
	imulq	%rax, %r12
	cmpl	%r15d, 80(%rsp)
	leaq	(%r12,%rsi), %rax
	movl	28(%rsp), %esi
	cmove	%r13d, %esi
	cmpl	%edx, 68(%rsp)
	cmove	%r13d, %r9d
	movl	%esi, 28(%rsp)
	jmp	.L1337
	.p2align 4,,10
	.p2align 3
.L1361:
	movl	12(%rbp), %eax
	leaq	_ZN11Solve_merge6SparseE(%rip), %r13
	movl	%eax, 120(%rsp)
	movzbl	80(%rbp), %eax
	movb	%al, 127(%rsp)
	movl	%edi, %eax
	subl	%r10d, %eax
	cltq
	movl	100001000(%r13,%rax,4), %ecx
	movl	$1, %eax
	movl	%ecx, 88(%rsp)
	sall	%cl, %eax
	movl	%edi, %ecx
	subl	%eax, %ecx
	movslq	%ecx, %rax
	movslq	88(%rsp), %rcx
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rcx, %rax
	movq	%rax, 88(%rsp)
	movslq	%r10d, %rax
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rax
	addq	%rax, %rcx
	movl	0(%r13,%rcx,4), %eax
	movq	%rcx, 112(%rsp)
	movq	88(%rsp), %rcx
	cmpl	%eax, 0(%r13,%rcx,4)
	cmovle	0(%r13,%rcx,4), %eax
	movl	%r9d, %ecx
	cmpl	8(%rbp), %r9d
	cmovl	8(%rbp), %ecx
	addl	8(%rbp), %r9d
	movslq	%r9d, %r9
	movl	%ecx, 108(%rsp)
	movq	96(%rsp), %rcx
	imulq	%r14, %r9
	subq	%r9, %rcx
	movq	%rcx, 96(%rsp)
	movq	88(%rsp), %rcx
	movl	50000500(%r13,%rcx,4), %r9d
	movq	112(%rsp), %rcx
	cmpl	%r9d, 50000500(%r13,%rcx,4)
	cmovge	50000500(%r13,%rcx,4), %r9d
	subl	%r10d, %edi
	movl	68(%rsp), %ecx
	subl	%eax, %r9d
	addl	$1, %ecx
	addl	$1, %r9d
	cmpl	%eax, %ecx
	je	.L1365
	cmpl	%edi, %r9d
	je	.L1366
.L1346:
	movb	$0, 126(%rsp)
.L1333:
	movslq	108(%rsp), %rax
	movl	72(%rsp), %ecx
	movq	%rax, %rdi
	imulq	%r14, %rax
	addq	96(%rsp), %rax
	cmpl	%edx, 76(%rsp)
	movl	24(%rsp), %edx
	cmove	%edi, %edx
	cmpl	%ecx, 104(%rsp)
	cmovne	64(%rsp), %edi
	movl	%edx, 24(%rsp)
	movl	%edi, 64(%rsp)
	jmp	.L1331
	.p2align 4,,10
	.p2align 3
.L1366:
	movl	108(%rsp), %eax
	addl	$1, %r11d
	cmpl	%r11d, %eax
	cmovge	%eax, %r11d
	movzbl	126(%rsp), %eax
	movb	$0, 126(%rsp)
	addl	%eax, 32(%rsp)
	movl	%r11d, 108(%rsp)
	jmp	.L1333
	.p2align 4,,10
	.p2align 3
.L1364:
	movl	12(%rsp), %eax
	addl	$1, %eax
	cmpl	%eax, %r13d
	cmovl	%eax, %r13d
	movzbl	16(%rsp), %eax
	movb	$0, 16(%rsp)
	addl	%eax, 36(%rsp)
	jmp	.L1339
	.p2align 4,,10
	.p2align 3
.L1365:
	cmpl	%edi, %r9d
	jne	.L1346
	movzbl	126(%rsp), %ecx
	movzbl	127(%rsp), %edi
	movl	$0, %eax
	movl	120(%rsp), %r9d
	movl	108(%rsp), %r10d
	testb	%cl, %cl
	cmovne	%edi, %eax
	movb	%al, 126(%rsp)
	leal	(%r11,%r9), %eax
	cmpl	%eax, %r10d
	cmovge	%r10d, %eax
	movl	%eax, 108(%rsp)
	movzbl	%cl, %eax
	imull	%r9d, %eax
	addl	%eax, 32(%rsp)
	movzbl	%dil, %eax
	imull	%eax, %r11d
	addl	%r11d, 84(%rsp)
	jmp	.L1333
	.p2align 4,,10
	.p2align 3
.L1363:
	cmpl	%edi, %eax
	jne	.L1350
	movzbl	16(%rsp), %ecx
	movzbl	127(%rsp), %r11d
	movl	$0, %eax
	movl	12(%rsp), %edi
	movl	120(%rsp), %r8d
	testb	%cl, %cl
	cmovne	%r11d, %eax
	movb	%al, 16(%rsp)
	movl	%edi, %eax
	addl	%r8d, %eax
	cmpl	%eax, %r13d
	cmovl	%eax, %r13d
	movzbl	%cl, %eax
	imull	%r8d, %eax
	addl	%eax, 36(%rsp)
	movzbl	%r11b, %eax
	imull	%edi, %eax
	addl	%eax, 76(%rsp)
	jmp	.L1339
	.cfi_endproc
.LFE3574:
	.size	_ZN11Solve_merge2ST6changeEiiiiiiii, .-_ZN11Solve_merge2ST6changeEiiiiiiii
	.section	.text._ZN11Solve_merge2STC2Ev,"axG",@progbits,_ZN11Solve_merge2STC5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN11Solve_merge2STC2Ev
	.type	_ZN11Solve_merge2STC2Ev, @function
_ZN11Solve_merge2STC2Ev:
.LFB3576:
	.cfi_startproc
	endbr64
	leaq	192001920(%rdi), %rax
	.p2align 4,,10
	.p2align 3
.L1368:
	movl	$0, (%rdi)
	addq	$96, %rdi
	movl	$0, -92(%rdi)
	movl	$0, -88(%rdi)
	movl	$0, -84(%rdi)
	movl	$0, -80(%rdi)
	movl	$0, -76(%rdi)
	movl	$0, -72(%rdi)
	movl	$0, -68(%rdi)
	movl	$0, -64(%rdi)
	movl	$0, -60(%rdi)
	movl	$0, -56(%rdi)
	movl	$0, -52(%rdi)
	movl	$0, -48(%rdi)
	movl	$0, -44(%rdi)
	movl	$0, -40(%rdi)
	movl	$0, -36(%rdi)
	movl	$0, -32(%rdi)
	movl	$0, -28(%rdi)
	movl	$0, -24(%rdi)
	movl	$0, -20(%rdi)
	movb	$1, -16(%rdi)
	movb	$1, -15(%rdi)
	movq	$0, -8(%rdi)
	cmpq	%rax, %rdi
	jne	.L1368
	ret
	.cfi_endproc
.LFE3576:
	.size	_ZN11Solve_merge2STC2Ev, .-_ZN11Solve_merge2STC2Ev
	.weak	_ZN11Solve_merge2STC1Ev
	.set	_ZN11Solve_merge2STC1Ev,_ZN11Solve_merge2STC2Ev
	.section	.rodata._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_.str1.1,"aMS",@progbits,1
.LC0:
	.string	"vector::_M_realloc_insert"
	.section	.text._ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.type	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, @function
_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_:
.LFB3987:
	.cfi_startproc
	endbr64
	movabsq	$2305843009213693951, %rcx
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	8(%rdi), %r12
	movq	(%rdi), %r8
	movq	%r12, %rax
	subq	%r8, %rax
	sarq	$2, %rax
	cmpq	%rcx, %rax
	je	.L1384
	movq	%rdx, %r15
	movq	%rsi, %rdx
	movq	%rdi, %rbx
	movq	%rsi, %r13
	subq	%r8, %rdx
	testq	%rax, %rax
	je	.L1380
	movabsq	$9223372036854775804, %r14
	leaq	(%rax,%rax), %rsi
	cmpq	%rsi, %rax
	jbe	.L1385
.L1372:
	movq	%r14, %rdi
	movq	%rdx, 8(%rsp)
	movq	%r8, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %r8
	movq	8(%rsp), %rdx
	movq	%rax, %rbp
	addq	%rax, %r14
.L1379:
	movl	(%r15), %eax
	leaq	4(%rbp,%rdx), %r9
	subq	%r13, %r12
	leaq	(%r9,%r12), %r15
	movl	%eax, 0(%rbp,%rdx)
	testq	%rdx, %rdx
	jg	.L1386
	testq	%r12, %r12
	jg	.L1375
	testq	%r8, %r8
	jne	.L1378
.L1376:
	movq	%rbp, (%rbx)
	movq	%r15, 8(%rbx)
	movq	%r14, 16(%rbx)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L1386:
	.cfi_restore_state
	movq	%r8, %rsi
	movq	%rbp, %rdi
	movq	%r9, 8(%rsp)
	movq	%r8, (%rsp)
	call	memmove@PLT
	testq	%r12, %r12
	movq	(%rsp), %r8
	movq	8(%rsp), %r9
	jg	.L1375
.L1378:
	movq	%r8, %rdi
	call	_ZdlPv@PLT
	jmp	.L1376
	.p2align 4,,10
	.p2align 3
.L1385:
	testq	%rsi, %rsi
	jne	.L1373
	xorl	%r14d, %r14d
	xorl	%ebp, %ebp
	jmp	.L1379
	.p2align 4,,10
	.p2align 3
.L1375:
	movq	%r12, %rdx
	movq	%r13, %rsi
	movq	%r9, %rdi
	movq	%r8, (%rsp)
	call	memcpy@PLT
	movq	(%rsp), %r8
	testq	%r8, %r8
	je	.L1376
	jmp	.L1378
	.p2align 4,,10
	.p2align 3
.L1380:
	movl	$4, %r14d
	jmp	.L1372
.L1384:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
.L1373:
	cmpq	%rcx, %rsi
	cmovbe	%rsi, %rcx
	movq	%rcx, %r14
	salq	$2, %r14
	jmp	.L1372
	.cfi_endproc
.LFE3987:
	.size	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_, .-_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	.section	.text.unlikely,"ax",@progbits
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4
	.globl	_ZN10Solve_left5solveEv
	.type	_ZN10Solve_left5solveEv, @function
_ZN10Solve_left5solveEv:
.LFB3534:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3534
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$168, %rsp
	.cfi_def_cfa_offset 224
	movl	n(%rip), %ecx
	movq	%fs:40, %rax
	movq	%rax, 152(%rsp)
	xorl	%eax, %eax
	leal	0(,%rcx,4), %edx
	testl	%edx, %edx
	jle	.L1391
	subl	$1, %edx
	leaq	12+_ZN10Solve_left7SegtreeE(%rip), %rax
	leaq	(%rdx,%rdx,2), %rsi
	leaq	12(%rax), %rdx
	leaq	(%rdx,%rsi,4), %rdx
	.p2align 4,,10
	.p2align 3
.L1392:
	movl	$0, (%rax)
	addq	$12, %rax
	movl	$0, -8(%rax)
	movl	$0, -4(%rax)
	cmpq	%rax, %rdx
	jne	.L1392
.L1391:
	leaq	92(%rsp), %rax
	leaq	p(%rip), %r15
	movq	$0, 96(%rsp)
	movq	%rax, 48(%rsp)
	leaq	96(%rsp), %rax
	movq	$0, 104(%rsp)
	movq	$0, 112(%rsp)
	movq	$0, 128(%rsp)
	movq	$0, 136(%rsp)
	movq	$0, 144(%rsp)
	movl	$1, 92(%rsp)
	movq	%rax, 64(%rsp)
	testl	%ecx, %ecx
	jle	.L1390
	.p2align 4,,10
	.p2align 3
.L1389:
	movq	104(%rsp), %rsi
	cmpq	112(%rsp), %rsi
	je	.L1961
	movl	92(%rsp), %eax
	addq	$4, %rsi
	movl	%eax, -4(%rsi)
	movq	%rsi, 104(%rsp)
.L1488:
	movq	136(%rsp), %rsi
	cmpq	144(%rsp), %rsi
	je	.L1962
	movl	92(%rsp), %eax
	addq	$4, %rsi
	movl	%eax, -4(%rsi)
	movq	%rsi, 136(%rsp)
.L1578:
	movl	92(%rsp), %r8d
	movl	n(%rip), %r12d
	cmpl	$1, %r8d
	jg	.L1963
.L1579:
	cmpl	$1, %r12d
	je	.L1964
.L1580:
	leal	1(%r12), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1587
	cmpl	$1, %edx
	je	.L1965
	leal	1(%rdx), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1590
	cmpl	$1, %r9d
	je	.L1966
	leal	1(%r9), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1593
	cmpl	$1, %edx
	je	.L1967
	leal	1(%rdx), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jge	.L1968
	leal	1(%r9), %esi
	cmpl	%esi, %edx
	je	.L1969
	leal	(%rdx,%rsi), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1617
	movl	$34, %ecx
	movl	%r9d, %edx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1618:
	movl	408+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	420+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	412+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	424+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%eax, %ecx
	jg	.L1619
	jne	.L1620
	addl	%edx, %esi
.L1621:
	movl	%ecx, 204+_ZN10Solve_left7SegtreeE(%rip)
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%esi, 208+_ZN10Solve_left7SegtreeE(%rip)
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 212+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1598:
	cmpl	%eax, %ecx
	jl	.L1622
	jne	.L1623
	addl	%esi, %edx
.L1624:
	movl	%eax, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1595:
	cmpl	%ecx, %eax
	jg	.L1631
.L2027:
	jne	.L1632
	addl	%esi, %edx
.L1633:
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%eax, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%ecx, %eax
	jle	.L1970
.L1658:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1660
	.p2align 4,,10
	.p2align 3
.L1963:
	testl	%r12d, %r12d
	jle	.L1580
	leal	-1(%r8), %ebp
	movl	20+_ZN10Solve_left7SegtreeE(%rip), %eax
	cmpl	%r12d, %ebp
	jge	.L1971
	testl	%eax, %eax
	je	.L1582
	addl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 32+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 44+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1582:
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	leal	1(%r12), %ebx
	movl	%ebp, %r9d
	movl	$1, %r8d
	pushq	$-1
	.cfi_def_cfa_offset 240
	sarl	%ebx
	movl	$2, %ecx
	movl	$1, %esi
	movl	%ebx, %edx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6updateEiiiiii
	leal	1(%rbx), %esi
	movl	$3, %ecx
	movl	%r12d, %edx
	movl	$1, %r8d
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%ebp, %r9d
	movl	$-1, (%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%rdi
	.cfi_def_cfa_offset 232
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r8
	.cfi_def_cfa_offset 224
	cmpl	%eax, %ecx
	jl	.L1583
	jne	.L1584
	addl	%esi, %edx
.L1585:
	movl	n(%rip), %r12d
	movl	%eax, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movl	92(%rsp), %r8d
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	$1, %r12d
	jne	.L1580
.L1964:
	movl	$1, 16+_ZN10Solve_left7SegtreeE(%rip)
	movl	$1, %edx
.L1586:
	leal	-1(%r8), %eax
	leaq	_ZN10Solve_left3resE(%rip), %rbx
	movslq	%r8d, %rcx
	addl	$1, %r8d
	cltq
	movl	%r8d, 92(%rsp)
	addq	(%rbx,%rax,8), %rdx
	movq	%rdx, (%rbx,%rcx,8)
	cmpl	%r12d, %r8d
	jg	.L1972
	movq	104(%rsp), %rdi
	movq	96(%rsp), %rdx
	movslq	%r8d, %r8
	movl	(%r15,%r8,4), %r11d
	cmpq	%rdi, %rdx
	je	.L1396
	leaq	_ZN10Solve_left7SegtreeE(%rip), %r14
	jmp	.L1393
	.p2align 4,,10
	.p2align 3
.L1400:
	movl	-8(%rdi), %r10d
	leal	1(%r10), %r13d
	cmpl	%r12d, %r13d
	jg	.L1737
	testb	%al, %al
	jne	.L1737
	cmpl	$1, %r13d
	movl	20+_ZN10Solve_left7SegtreeE(%rip), %eax
	setle	%sil
	cmpl	%r12d, %ebp
	setge	12(%rsp)
	movzbl	12(%rsp), %edi
	testb	%sil, %sil
	je	.L1428
	testb	%dil, %dil
	je	.L1428
	addl	%ebx, 12+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, %ebx
	movq	%rcx, %rdi
	movl	%ebx, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1401:
	cmpq	%rdi, %rdx
	je	.L1396
.L1393:
	movslq	-4(%rdi), %rax
	movl	(%r15,%rax,4), %ebx
	movq	%rax, %rbp
	cmpl	%r11d, %ebx
	jle	.L1396
	leaq	-4(%rdi), %rcx
	subl	%r11d, %ebx
	testl	%eax, %eax
	movl	n(%rip), %r12d
	movq	%rcx, 104(%rsp)
	setle	%al
	cmpq	%rdx, %rcx
	jne	.L1400
	testl	%r12d, %r12d
	jle	.L1737
	testb	%al, %al
	jne	.L1737
	movl	20+_ZN10Solve_left7SegtreeE(%rip), %eax
	cmpl	%r12d, %ebp
	jge	.L1973
	movl	32+_ZN10Solve_left7SegtreeE(%rip), %edx
	testl	%eax, %eax
	je	.L1403
	addl	%eax, %edx
	addl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 44+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 32+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1403:
	leal	1(%r12), %r13d
	sarl	%r13d
	leal	1(%r13), %r10d
	cmpl	%r13d, %ebp
	jge	.L1974
	movl	56+_ZN10Solve_left7SegtreeE(%rip), %ecx
	testl	%edx, %edx
	je	.L1405
	addl	%edx, %ecx
	addl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 60+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1405:
	movl	%r10d, %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%esi, 20(%rsp)
	cmpl	%eax, %ebp
	jge	.L1975
	movl	104+_ZN10Solve_left7SegtreeE(%rip), %edx
	testl	%ecx, %ecx
	je	.L1407
	addl	%ecx, %edx
	addl	%ecx, 96+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 108+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 116+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1407:
	leal	1(%rax), %esi
	sarl	%esi
	leal	1(%rsi), %ecx
	movl	%esi, 16(%rsp)
	movl	%ecx, 12(%rsp)
	cmpl	%esi, %ebp
	jge	.L1976
	testl	%edx, %edx
	je	.L1409
	addl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 204+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 212+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1409:
	movl	12(%rsp), %edx
	movl	%r11d, 36(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %r9d
	movl	%eax, 40(%rsp)
	movl	$1, %r8d
	movl	$16, %ecx
	movq	%r14, %rdi
	movl	%r10d, 36(%rsp)
	sarl	%edx
	movl	$1, %esi
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	%edx, 40(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	40(%rsp), %edx
	movq	%r14, %rdi
	movl	%ebp, %r9d
	movl	$17, %ecx
	movl	$1, %r8d
	movl	%ebx, (%rsp)
	leal	1(%rdx), %esi
	movl	32(%rsp), %edx
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r10
	.cfi_def_cfa_offset 232
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r11
	.cfi_def_cfa_offset 224
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	28(%rsp), %r10d
	movl	32(%rsp), %eax
	movl	36(%rsp), %r11d
	jl	.L1410
	jne	.L1411
	addl	%edi, %ecx
.L1412:
	movl	%edx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1408:
	movl	%r11d, 24(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%eax, %edx
	movl	%ebp, %r9d
	movl	%r10d, 24(%rsp)
	movl	$1, %r8d
	movl	$9, %ecx
	movq	%r14, %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	28(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%r8
	.cfi_def_cfa_offset 232
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %ecx
	popq	%r9
	.cfi_def_cfa_offset 224
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	movl	16(%rsp), %r10d
	movl	24(%rsp), %r11d
	jl	.L1413
	jne	.L1414
	addl	%esi, %edx
.L1415:
	movl	%eax, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1406
	.p2align 4,,10
	.p2align 3
.L1587:
	leal	1(%rdx), %esi
	cmpl	%r12d, %esi
	je	.L1977
	leal	(%rsi,%r12), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1662
	cmpl	%edx, %esi
	je	.L1978
	leal	(%rsi,%rdx), %r10d
	sarl	%r10d
	cmpl	%r8d, %r10d
	jl	.L1665
	cmpl	%r10d, %esi
	je	.L1979
	leal	(%rsi,%r10), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jge	.L1980
	leal	1(%rdx), %esi
	movl	$25, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r10d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
.L1669:
	movl	288+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	300+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	292+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	304+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%eax, %ecx
	jg	.L1670
	jne	.L1671
	addl	%edx, %esi
.L1672:
	movl	%ecx, 144+_ZN10Solve_left7SegtreeE(%rip)
	movl	156+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%esi, 148+_ZN10Solve_left7SegtreeE(%rip)
	movl	160+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 152+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1667:
	cmpl	%eax, %ecx
	jg	.L1691
.L2024:
	jne	.L1692
	addl	%edx, %esi
.L1693:
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 72+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 76+_ZN10Solve_left7SegtreeE(%rip)
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 80+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%eax, %ecx
	jle	.L1981
.L1712:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1714
	.p2align 4,,10
	.p2align 3
.L1737:
	movq	%rcx, %rdi
	cmpq	%rdi, %rdx
	jne	.L1393
	.p2align 4,,10
	.p2align 3
.L1396:
	movq	136(%rsp), %rdi
	movq	128(%rsp), %rdx
	cmpq	%rdi, %rdx
	je	.L1389
	leaq	_ZN10Solve_left7SegtreeE(%rip), %r14
	jmp	.L1394
	.p2align 4,,10
	.p2align 3
.L1491:
	movl	-8(%rdi), %eax
	leal	1(%rax), %ebp
	cmpl	%r12d, %ebp
	jg	.L1739
	testb	%sil, %sil
	jne	.L1739
	cmpl	$1, %ebp
	movl	20+_ZN10Solve_left7SegtreeE(%rip), %edi
	setle	%sil
	cmpl	%r12d, %ebx
	setge	12(%rsp)
	movzbl	12(%rsp), %r9d
	testb	%sil, %sil
	je	.L1519
	testb	%r9b, %r9b
	je	.L1519
	addl	%r13d, 12+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, %r13d
	movq	%rcx, %rdi
	movl	%r13d, 20+_ZN10Solve_left7SegtreeE(%rip)
	.p2align 4,,10
	.p2align 3
.L1492:
	cmpq	%rdi, %rdx
	je	.L1389
.L1394:
	movslq	-4(%rdi), %rax
	movq	%rax, %rbx
	movl	(%r15,%rax,4), %eax
	cmpl	%r11d, %eax
	jge	.L1389
	movl	%r11d, %r13d
	leaq	-4(%rdi), %rcx
	movl	n(%rip), %r12d
	subl	%eax, %r13d
	testl	%ebx, %ebx
	movq	%rcx, 136(%rsp)
	setle	%sil
	cmpq	%rdx, %rcx
	jne	.L1491
	testl	%r12d, %r12d
	jle	.L1739
	testb	%sil, %sil
	jne	.L1739
	movl	20+_ZN10Solve_left7SegtreeE(%rip), %eax
	cmpl	%r12d, %ebx
	jge	.L1982
	movl	32+_ZN10Solve_left7SegtreeE(%rip), %edx
	testl	%eax, %eax
	je	.L1494
	addl	%eax, %edx
	addl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 44+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 32+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1494:
	leal	1(%r12), %ebp
	sarl	%ebp
	leal	1(%rbp), %r10d
	cmpl	%ebp, %ebx
	jge	.L1983
	movl	56+_ZN10Solve_left7SegtreeE(%rip), %ecx
	testl	%edx, %edx
	je	.L1496
	addl	%edx, %ecx
	addl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 60+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1496:
	movl	%r10d, %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%esi, 20(%rsp)
	cmpl	%eax, %ebx
	jge	.L1984
	movl	104+_ZN10Solve_left7SegtreeE(%rip), %edx
	testl	%ecx, %ecx
	je	.L1498
	addl	%ecx, %edx
	addl	%ecx, 96+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 108+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 116+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1498:
	leal	1(%rax), %esi
	sarl	%esi
	leal	1(%rsi), %ecx
	movl	%esi, 16(%rsp)
	movl	%ecx, 12(%rsp)
	cmpl	%esi, %ebx
	jge	.L1985
	testl	%edx, %edx
	je	.L1500
	addl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 204+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 212+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1500:
	movl	12(%rsp), %edx
	movl	%r11d, 36(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	movl	%eax, 40(%rsp)
	movl	$1, %r8d
	movl	$16, %ecx
	movq	%r14, %rdi
	movl	%r10d, 36(%rsp)
	sarl	%edx
	movl	$1, %esi
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	%edx, 40(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	40(%rsp), %edx
	movl	%ebx, %r9d
	movq	%r14, %rdi
	movl	$17, %ecx
	movl	$1, %r8d
	movl	%r13d, (%rsp)
	leal	1(%rdx), %esi
	movl	32(%rsp), %edx
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%esi, %edx
	movl	28(%rsp), %r10d
	movl	32(%rsp), %eax
	movl	36(%rsp), %r11d
	jg	.L1501
	jne	.L1502
	addl	%edi, %ecx
.L1503:
	movl	%edx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1499:
	movl	%r11d, 24(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%eax, %edx
	movl	$9, %ecx
	movl	%r10d, 24(%rsp)
	movl	$1, %r8d
	movq	%r14, %rdi
	movl	%ebx, %r9d
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	28(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%rax
	.cfi_def_cfa_offset 232
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r8
	.cfi_def_cfa_offset 224
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	16(%rsp), %r10d
	movl	24(%rsp), %r11d
	jl	.L1504
	jne	.L1505
	addl	%edi, %ecx
.L1506:
	movl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1497
	.p2align 4,,10
	.p2align 3
.L1428:
	testl	%eax, %eax
	je	.L1429
	addl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 32+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 44+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1429:
	leal	1(%r12), %eax
	sarl	%eax
	leal	1(%rax), %r9d
	movl	%r9d, 16(%rsp)
	cmpl	%eax, %r13d
	jg	.L1430
	cmpl	%eax, %ebp
	movl	32+_ZN10Solve_left7SegtreeE(%rip), %edi
	setge	20(%rsp)
	movzbl	20(%rsp), %r8d
	testb	%sil, %sil
	je	.L1431
	testb	%r8b, %r8b
	je	.L1431
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	addl	%ebx, %edi
	movl	%edi, 32+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ebx, %esi
	movl	%esi, 24+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%r9d, %ebp
	jl	.L1986
	cmpl	%eax, %r10d
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %edx
	setle	%cl
.L1465:
	testl	%edx, %edx
	je	.L1466
	addl	%edx, 72+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 92+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
.L1466:
	movl	16(%rsp), %eax
	addl	%r12d, %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%esi, 20(%rsp)
	cmpl	%eax, %r13d
	jg	.L1467
	movl	80+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%eax, %ebp
	jl	.L1468
	testb	%cl, %cl
	je	.L1468
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	addl	%ebx, %edx
	movl	92+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ebx, %eax
	movl	%eax, 72+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%esi, %ebp
	jl	.L1987
.L1476:
	testl	%ecx, %ecx
	je	.L1477
	addl	%ecx, 168+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 176+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 180+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 188+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 92+_ZN10Solve_left7SegtreeE(%rip)
.L1477:
	movl	20(%rsp), %esi
	movl	%r11d, 16(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %r9d
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	%r13d, %r8d
	movl	$14, %ecx
	movq	%r14, %rdi
	leal	(%r12,%rsi), %eax
	sarl	%eax
	movl	%eax, %edx
	movl	%eax, 28(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	28(%rsp), %eax
	movl	%r12d, %edx
	movl	%ebp, %r9d
	movl	$15, %ecx
	movl	%r13d, %r8d
	movq	%r14, %rdi
	movl	%ebx, (%rsp)
	leal	1(%rax), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	168+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	180+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%rbx
	.cfi_def_cfa_offset 224
	movl	172+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	184+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%edx, %eax
	movl	16(%rsp), %r11d
	jl	.L1478
	jne	.L1479
	addl	%esi, %ecx
.L1480:
	movl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 88+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 92+_ZN10Solve_left7SegtreeE(%rip)
.L1470:
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %r8d
	cmpl	%edx, %eax
	jg	.L1481
.L2003:
	jne	.L1482
	addl	%ecx, %r8d
.L1483:
	movl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%r8d, 40+_ZN10Solve_left7SegtreeE(%rip)
	movq	104(%rsp), %rdi
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
	movq	96(%rsp), %rdx
.L1433:
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%esi, %eax
	jl	.L1484
.L1990:
	jne	.L1485
	addl	%r8d, %ecx
.L1486:
	movl	%esi, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1401
	.p2align 4,,10
	.p2align 3
.L1431:
	testl	%edi, %edi
	je	.L1434
	addl	%edi, 48+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 56+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 60+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1434:
	movl	16(%rsp), %ecx
	sarl	%ecx
	leal	1(%rcx), %r9d
	movl	%ecx, 28(%rsp)
	movl	%ecx, %edi
	movl	%r9d, 24(%rsp)
	cmpl	%ecx, %r13d
	jg	.L1435
	movl	56+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%edi, %ebp
	jl	.L1436
	testb	%sil, %sil
	je	.L1436
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	addl	%ebx, %ecx
	movl	68+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ebx, %edx
	movl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%r9d, %ebp
	jl	.L1988
.L1456:
	testl	%esi, %esi
	je	.L1457
	addl	%esi, 120+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 128+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 132+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 140+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 68+_ZN10Solve_left7SegtreeE(%rip)
.L1457:
	movl	24(%rsp), %esi
	movl	%r11d, 32(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %r9d
	movl	%r10d, 36(%rsp)
	movl	%r13d, %r8d
	movl	$10, %ecx
	movq	%r14, %rdi
	movl	%eax, 32(%rsp)
	leal	(%rax,%rsi), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 240
	sarl	%edx
	movl	%edx, 36(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	36(%rsp), %edx
	movl	40(%rsp), %eax
	movl	%ebp, %r9d
	movl	$11, %ecx
	movq	%r14, %rdi
	movl	%r13d, %r8d
	movl	%ebx, (%rsp)
	leal	1(%rdx), %esi
	movl	%eax, %edx
	movl	%eax, 36(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	120+_ZN10Solve_left7SegtreeE(%rip), %ecx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	132+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	124+_ZN10Solve_left7SegtreeE(%rip), %edi
	movl	136+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%edx, %ecx
	movl	20(%rsp), %eax
	movl	28(%rsp), %r10d
	movl	32(%rsp), %r11d
	jg	.L1458
	jne	.L1459
	addl	%esi, %edi
.L1460:
	movl	%ecx, 60+_ZN10Solve_left7SegtreeE(%rip)
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	%edi, 64+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 68+_ZN10Solve_left7SegtreeE(%rip)
.L1438:
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%edx, %ecx
	jl	.L1461
.L2001:
	jne	.L1462
	addl	%edi, %esi
.L1463:
	movl	%edx, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1430:
	cmpl	16(%rsp), %ebp
	jl	.L1989
	cmpl	%eax, %r10d
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %edx
	setle	%al
	cmpb	$0, 12(%rsp)
	movl	%eax, %ecx
	je	.L1465
	testb	%al, %al
	je	.L1465
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movq	104(%rsp), %rdi
	addl	%ebx, %eax
	addl	%edx, %ebx
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movq	96(%rsp), %rdx
	movl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ebx, 44+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%esi, %eax
	jge	.L1990
.L1484:
	movl	%eax, %esi
	movl	%r8d, %ecx
	jmp	.L1486
	.p2align 4,,10
	.p2align 3
.L1739:
	movq	%rcx, %rdi
	jmp	.L1492
	.p2align 4,,10
	.p2align 3
.L1519:
	testl	%edi, %edi
	je	.L1520
	addl	%edi, 24+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 32+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 36+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 44+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
.L1520:
	leal	1(%r12), %r10d
	sarl	%r10d
	leal	1(%r10), %r8d
	movl	%r8d, 16(%rsp)
	cmpl	%r10d, %ebp
	jg	.L1521
	cmpl	%r10d, %ebx
	movl	32+_ZN10Solve_left7SegtreeE(%rip), %edi
	setge	20(%rsp)
	movzbl	20(%rsp), %r9d
	testb	%sil, %sil
	je	.L1522
	testb	%r9b, %r9b
	je	.L1522
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	addl	%r13d, %edi
	movl	%edi, 32+_ZN10Solve_left7SegtreeE(%rip)
	addl	%r13d, %esi
	movl	%esi, 24+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%r8d, %ebx
	jl	.L1991
	cmpl	%r10d, %eax
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %edx
	setle	%sil
.L1556:
	testl	%edx, %edx
	je	.L1557
	addl	%edx, 72+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 92+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
.L1557:
	movl	16(%rsp), %ecx
	leal	(%rcx,%r12), %r10d
	sarl	%r10d
	leal	1(%r10), %edi
	movl	%edi, 20(%rsp)
	cmpl	%r10d, %ebp
	jg	.L1558
	movl	80+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%r10d, %ebx
	jl	.L1559
	testb	%sil, %sil
	je	.L1559
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	addl	%r13d, %edx
	movl	92+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%r13d, %eax
	movl	%eax, 72+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edi, %ebx
	jl	.L1992
.L1567:
	testl	%ecx, %ecx
	je	.L1568
	addl	%ecx, 168+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 176+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 180+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 188+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 92+_ZN10Solve_left7SegtreeE(%rip)
.L1568:
	movl	20(%rsp), %esi
	movl	%r11d, 16(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	%ebp, %r8d
	movl	$14, %ecx
	movq	%r14, %rdi
	leal	(%rsi,%r12), %eax
	sarl	%eax
	movl	%eax, %edx
	movl	%eax, 28(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	28(%rsp), %eax
	movl	%ebx, %r9d
	movl	%r12d, %edx
	movl	$15, %ecx
	movl	%ebp, %r8d
	movq	%r14, %rdi
	movl	%r13d, (%rsp)
	leal	1(%rax), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	168+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	180+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	172+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	184+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%edx, %eax
	movl	16(%rsp), %r11d
	jl	.L1569
	jne	.L1570
	addl	%esi, %ecx
.L1571:
	movl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 88+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 92+_ZN10Solve_left7SegtreeE(%rip)
.L1561:
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %r8d
	cmpl	%eax, %edx
	jl	.L1572
.L1999:
	jne	.L1573
	addl	%ecx, %r8d
.L1574:
	movl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%r8d, 40+_ZN10Solve_left7SegtreeE(%rip)
	movq	136(%rsp), %rdi
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
	movq	128(%rsp), %rdx
.L1524:
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%esi, %eax
	jl	.L1575
.L1995:
	jne	.L1576
	addl	%r8d, %ecx
.L1577:
	movl	%esi, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1492
	.p2align 4,,10
	.p2align 3
.L1522:
	testl	%edi, %edi
	je	.L1525
	addl	%edi, 48+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 56+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 60+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edi, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1525:
	movl	16(%rsp), %ecx
	sarl	%ecx
	leal	1(%rcx), %edi
	movl	%ecx, 28(%rsp)
	movl	%ecx, %edx
	movl	%edi, 24(%rsp)
	cmpl	%ecx, %ebp
	jg	.L1526
	movl	56+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%edx, %ebx
	jl	.L1527
	testb	%sil, %sil
	je	.L1527
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	addl	%r13d, %ecx
	movl	68+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
	addl	%r13d, %edx
	movl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edi, %ebx
	jl	.L1993
.L1547:
	testl	%esi, %esi
	je	.L1548
	addl	%esi, 120+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 128+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 132+_ZN10Solve_left7SegtreeE(%rip)
	addl	%esi, 140+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 68+_ZN10Solve_left7SegtreeE(%rip)
.L1548:
	movl	24(%rsp), %esi
	movl	%r11d, 32(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	movl	%eax, 36(%rsp)
	movl	%ebp, %r8d
	movl	$10, %ecx
	movq	%r14, %rdi
	movl	%r10d, 32(%rsp)
	leal	(%r10,%rsi), %edx
	pushq	%r13
	.cfi_def_cfa_offset 240
	sarl	%edx
	movl	%edx, 36(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	36(%rsp), %edx
	movl	%ebp, %r8d
	movq	%r14, %rdi
	movl	40(%rsp), %r10d
	movl	$11, %ecx
	movl	%ebx, %r9d
	movl	%r13d, (%rsp)
	leal	1(%rdx), %esi
	movl	%r10d, %edx
	movl	%r10d, 36(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	120+_ZN10Solve_left7SegtreeE(%rip), %ecx
	popq	%rax
	.cfi_def_cfa_offset 232
	movl	132+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r8
	.cfi_def_cfa_offset 224
	movl	124+_ZN10Solve_left7SegtreeE(%rip), %edi
	movl	136+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %edx
	movl	20(%rsp), %r10d
	movl	28(%rsp), %eax
	movl	32(%rsp), %r11d
	jl	.L1549
	jne	.L1550
	addl	%esi, %edi
.L1551:
	movl	%ecx, 60+_ZN10Solve_left7SegtreeE(%rip)
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	%edi, 64+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 68+_ZN10Solve_left7SegtreeE(%rip)
.L1529:
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%edx, %ecx
	jl	.L1552
.L1997:
	jne	.L1553
	addl	%edi, %esi
.L1554:
	movl	%edx, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1521:
	cmpl	16(%rsp), %ebx
	jl	.L1994
	cmpl	%r10d, %eax
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %edx
	setle	%cl
	cmpb	$0, 12(%rsp)
	movl	%ecx, %esi
	je	.L1556
	testb	%cl, %cl
	je	.L1556
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movq	136(%rsp), %rdi
	addl	%r13d, %eax
	addl	%edx, %r13d
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movq	128(%rsp), %rdx
	movl	%eax, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	%r13d, 44+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%esi, %eax
	jge	.L1995
.L1575:
	movl	%eax, %esi
	movl	%r8d, %ecx
	jmp	.L1577
	.p2align 4,,10
	.p2align 3
.L1527:
	testl	%ecx, %ecx
	je	.L1530
	addl	%ecx, 96+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 104+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 108+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 116+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1530:
	movl	24(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %ecx
	movl	%edx, 36(%rsp)
	movl	%edx, %edi
	movl	%ecx, 32(%rsp)
	cmpl	%edx, %ebp
	jg	.L1531
	movl	104+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%edi, %ebx
	jl	.L1532
	testb	%sil, %sil
	je	.L1532
	addl	%r13d, %edx
	addl	%r13d, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1531:
	movl	%r11d, 44(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	movq	%r14, %rdi
	movl	%r10d, 48(%rsp)
	movl	$9, %ecx
	movl	%ebp, %r8d
	movl	%eax, 44(%rsp)
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	44(%rsp), %edx
	movl	48(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	36(%rsp), %eax
	movl	40(%rsp), %r10d
	movl	44(%rsp), %r11d
	jl	.L1543
	jne	.L1544
	addl	%edi, %ecx
.L1545:
	movl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1526:
	cmpl	24(%rsp), %ebx
	jl	.L1996
	movl	68+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	28(%rsp), %eax
	jg	.L1547
	cmpb	$0, 20(%rsp)
	je	.L1547
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	addl	%r13d, %esi
	movl	%esi, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	addl	%r13d, %ecx
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%ecx, 60+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edx, %ecx
	jge	.L1997
.L1552:
	movl	%ecx, %edx
	movl	%edi, %esi
	jmp	.L1554
	.p2align 4,,10
	.p2align 3
.L1559:
	testl	%edx, %edx
	je	.L1562
	addl	%edx, 144+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 152+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 156+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 164+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 80+_ZN10Solve_left7SegtreeE(%rip)
.L1562:
	movl	16(%rsp), %esi
	movl	%r11d, 32(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	movl	%eax, 36(%rsp)
	movl	%ebp, %r8d
	movl	$12, %ecx
	movq	%r14, %rdi
	movl	%r10d, 32(%rsp)
	leal	(%r10,%rsi), %edx
	pushq	%r13
	.cfi_def_cfa_offset 240
	sarl	%edx
	movl	%edx, 32(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	32(%rsp), %edx
	movq	%r14, %rdi
	movl	%ebx, %r9d
	movl	40(%rsp), %r10d
	movl	$13, %ecx
	movl	%ebp, %r8d
	movl	%r13d, (%rsp)
	leal	1(%rdx), %esi
	movl	%r10d, %edx
	movl	%r10d, 32(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	144+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	156+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%rax
	.cfi_def_cfa_offset 224
	movl	148+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	160+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	16(%rsp), %r10d
	movl	28(%rsp), %eax
	movl	32(%rsp), %r11d
	jl	.L1563
	jne	.L1564
	addl	%edi, %ecx
.L1565:
	movl	%edx, 72+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 76+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 80+_ZN10Solve_left7SegtreeE(%rip)
.L1558:
	cmpl	20(%rsp), %ebx
	jl	.L1998
	movl	92+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%r10d, %eax
	jg	.L1567
	cmpb	$0, 12(%rsp)
	je	.L1567
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %r8d
	addl	%r13d, %edx
	addl	%ecx, %r13d
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	movl	%r13d, 92+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%eax, %edx
	jge	.L1999
.L1572:
	movl	%edx, %eax
	movl	%ecx, %r8d
	jmp	.L1574
	.p2align 4,,10
	.p2align 3
.L1436:
	testl	%ecx, %ecx
	je	.L1439
	addl	%ecx, 96+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 104+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 108+_ZN10Solve_left7SegtreeE(%rip)
	addl	%ecx, 116+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1439:
	movl	24(%rsp), %ecx
	sarl	%ecx
	leal	1(%rcx), %edx
	movl	%ecx, 36(%rsp)
	movl	%edx, 32(%rsp)
	cmpl	%ecx, %r13d
	jg	.L1440
	movl	104+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %ebp
	jl	.L1441
	testb	%sil, %sil
	je	.L1441
	addl	%ebx, %edx
	addl	%ebx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1440:
	movl	%r11d, 44(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movq	%r14, %rdi
	movl	%ebp, %r9d
	movl	%eax, 48(%rsp)
	movl	$9, %ecx
	movl	%r13d, %r8d
	movl	%r10d, 44(%rsp)
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	44(%rsp), %edx
	movl	48(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%rax
	.cfi_def_cfa_offset 224
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%esi, %edx
	movl	36(%rsp), %r10d
	movl	40(%rsp), %eax
	movl	44(%rsp), %r11d
	jg	.L1452
	jne	.L1453
	addl	%edi, %ecx
.L1454:
	movl	%edx, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1435:
	cmpl	24(%rsp), %ebp
	jl	.L2000
	movl	68+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	28(%rsp), %r10d
	jg	.L1456
	cmpb	$0, 20(%rsp)
	je	.L1456
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	addl	%ebx, %esi
	movl	%esi, 68+_ZN10Solve_left7SegtreeE(%rip)
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	addl	%ebx, %ecx
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	%ecx, 60+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edx, %ecx
	jge	.L2001
.L1461:
	movl	%ecx, %edx
	movl	%edi, %esi
	jmp	.L1463
	.p2align 4,,10
	.p2align 3
.L1468:
	testl	%edx, %edx
	je	.L1471
	addl	%edx, 144+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 152+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 156+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 164+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 80+_ZN10Solve_left7SegtreeE(%rip)
.L1471:
	movl	16(%rsp), %esi
	movl	%r11d, 32(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %r9d
	movl	%r10d, 36(%rsp)
	movl	%r13d, %r8d
	movl	$12, %ecx
	movq	%r14, %rdi
	movl	%eax, 32(%rsp)
	leal	(%rax,%rsi), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 240
	sarl	%edx
	movl	%edx, 32(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	32(%rsp), %edx
	movl	40(%rsp), %eax
	movl	%r13d, %r8d
	movl	$13, %ecx
	movq	%r14, %rdi
	movl	%ebp, %r9d
	movl	%ebx, (%rsp)
	leal	1(%rdx), %esi
	movl	%eax, %edx
	movl	%eax, 32(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	144+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%rax
	.cfi_def_cfa_offset 232
	movl	156+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r8
	.cfi_def_cfa_offset 224
	movl	148+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	160+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	16(%rsp), %eax
	movl	28(%rsp), %r10d
	movl	32(%rsp), %r11d
	jl	.L1472
	jne	.L1473
	addl	%edi, %ecx
.L1474:
	movl	%edx, 72+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 76+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 80+_ZN10Solve_left7SegtreeE(%rip)
.L1467:
	cmpl	20(%rsp), %ebp
	jl	.L2002
	movl	92+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%eax, %r10d
	jg	.L1476
	cmpb	$0, 12(%rsp)
	je	.L1476
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %r8d
	addl	%ebx, %edx
	addl	%ecx, %ebx
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 84+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ebx, 92+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edx, %eax
	jle	.L2003
.L1481:
	movl	%edx, %eax
	movl	%ecx, %r8d
	jmp	.L1483
	.p2align 4,,10
	.p2align 3
.L1576:
	jg	.L1577
	movl	%esi, %eax
	jmp	.L1575
	.p2align 4,,10
	.p2align 3
.L1485:
	jg	.L1486
	movl	%esi, %eax
	jmp	.L1484
	.p2align 4,,10
	.p2align 3
.L1989:
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movq	104(%rsp), %rdi
	movq	96(%rsp), %rdx
	jmp	.L1433
	.p2align 4,,10
	.p2align 3
.L1994:
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movq	136(%rsp), %rdi
	movq	128(%rsp), %rdx
	jmp	.L1524
	.p2align 4,,10
	.p2align 3
.L1973:
	addl	%ebx, 12+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, %ebx
	movq	%rdx, %rdi
	movl	%ebx, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1401
	.p2align 4,,10
	.p2align 3
.L1982:
	addl	%r13d, 12+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, %r13d
	movq	%rdx, %rdi
	movl	%r13d, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1492
	.p2align 4,,10
	.p2align 3
.L1482:
	jl	.L1483
	movl	%eax, %edx
	jmp	.L1481
	.p2align 4,,10
	.p2align 3
.L1573:
	jg	.L1574
	movl	%eax, %edx
	jmp	.L1572
	.p2align 4,,10
	.p2align 3
.L1553:
	jg	.L1554
	movl	%edx, %ecx
	jmp	.L1552
	.p2align 4,,10
	.p2align 3
.L1462:
	jg	.L1463
	movl	%edx, %ecx
	jmp	.L1461
	.p2align 4,,10
	.p2align 3
.L1996:
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	jmp	.L1529
	.p2align 4,,10
	.p2align 3
.L1998:
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1561
	.p2align 4,,10
	.p2align 3
.L2000:
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1438
	.p2align 4,,10
	.p2align 3
.L2002:
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1470
	.p2align 4,,10
	.p2align 3
.L1983:
	addl	%r13d, %edx
	addl	%r13d, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1495:
	cmpl	%r10d, %ebx
	jl	.L2004
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %eax
	testl	%eax, %eax
	je	.L1512
	addl	%eax, 72+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 84+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 92+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
.L1512:
	movl	%r11d, 12(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	leal	(%r10,%r12), %ebp
	movl	%r10d, %esi
	pushq	%r13
	.cfi_def_cfa_offset 240
	sarl	%ebp
	movl	%ebx, %r9d
	movl	$1, %r8d
	movl	$6, %ecx
	movl	%ebp, %edx
	movq	%r14, %rdi
	call	_ZN10Solve_left2ST6updateEiiiiii
	leal	1(%rbp), %esi
	movl	%ebx, %r9d
	movl	$7, %ecx
	movl	%r12d, %edx
	movl	$1, %r8d
	movq	%r14, %rdi
	movl	%r13d, (%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%eax, %edx
	movl	12(%rsp), %r11d
	jg	.L1513
	jne	.L1514
	addl	%ecx, %esi
.L1515:
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%edx, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 40+_ZN10Solve_left7SegtreeE(%rip)
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%edx, %eax
	jg	.L1516
.L2005:
	jne	.L1517
	addl	%esi, %ecx
	movl	%edx, %eax
.L1518:
	movl	%eax, 12+_ZN10Solve_left7SegtreeE(%rip)
	movq	136(%rsp), %rdi
	movl	%ecx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movq	128(%rsp), %rdx
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1492
	.p2align 4,,10
	.p2align 3
.L2004:
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%edx, %eax
	jle	.L2005
.L1516:
	movl	%edx, %eax
	movl	%esi, %ecx
	jmp	.L1518
	.p2align 4,,10
	.p2align 3
.L1517:
	jl	.L1518
	movl	%eax, %edx
	jmp	.L1516
	.p2align 4,,10
	.p2align 3
.L1974:
	addl	%ebx, %edx
	addl	%ebx, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 32+_ZN10Solve_left7SegtreeE(%rip)
.L1404:
	cmpl	%r10d, %ebp
	jl	.L2006
	movl	44+_ZN10Solve_left7SegtreeE(%rip), %eax
	testl	%eax, %eax
	je	.L1421
	addl	%eax, 72+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 80+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 84+_ZN10Solve_left7SegtreeE(%rip)
	addl	%eax, 92+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
.L1421:
	movl	%r11d, 12(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	leal	(%r12,%r10), %r13d
	movl	%r10d, %esi
	pushq	%rbx
	.cfi_def_cfa_offset 240
	sarl	%r13d
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$6, %ecx
	movl	%r13d, %edx
	movq	%r14, %rdi
	call	_ZN10Solve_left2ST6updateEiiiiii
	leal	1(%r13), %esi
	movl	%r12d, %edx
	movl	%ebp, %r9d
	movl	$7, %ecx
	movl	$1, %r8d
	movq	%r14, %rdi
	movl	%ebx, (%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%rbx
	.cfi_def_cfa_offset 224
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%edx, %eax
	movl	12(%rsp), %r11d
	jl	.L1422
	jne	.L1423
	addl	%ecx, %esi
.L1424:
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%edx, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 40+_ZN10Solve_left7SegtreeE(%rip)
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%eax, %edx
	jl	.L1425
.L2007:
	jne	.L1426
	addl	%esi, %ecx
.L1427:
	movq	104(%rsp), %rdi
	movq	96(%rsp), %rdx
	movl	%eax, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1401
	.p2align 4,,10
	.p2align 3
.L2006:
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %ecx
	cmpl	%eax, %edx
	jge	.L2007
.L1425:
	movl	%edx, %eax
	movl	%esi, %ecx
	jmp	.L1427
	.p2align 4,,10
	.p2align 3
.L1426:
	jg	.L1427
	movl	%eax, %edx
	jmp	.L1425
	.p2align 4,,10
	.p2align 3
.L1441:
	testl	%edx, %edx
	je	.L1442
	addl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 204+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 212+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1442:
	movl	32(%rsp), %edx
	sarl	%edx
	leal	1(%rdx), %ecx
	movl	%edx, 44(%rsp)
	movl	%ecx, 40(%rsp)
	movl	%edx, %ecx
	cmpl	%edx, %r13d
	jg	.L1443
	movl	200+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %ebp
	jl	.L1444
	testb	%sil, %sil
	je	.L1444
	addl	%ebx, %edx
	addl	%ebx, 192+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
.L1443:
	movl	%r11d, 60(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%r13d, %r8d
	movq	%r14, %rdi
	movl	%eax, 64(%rsp)
	movl	$17, %ecx
	movl	%ebp, %r9d
	movl	%r10d, 52(%rsp)
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	52(%rsp), %edx
	movl	56(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%rax
	.cfi_def_cfa_offset 232
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r8
	.cfi_def_cfa_offset 224
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	44(%rsp), %r10d
	movl	56(%rsp), %eax
	movl	60(%rsp), %r11d
	jl	.L1449
	jne	.L1450
	addl	%edi, %ecx
.L1451:
	movl	%edx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1440
.L1444:
	testl	%edx, %edx
	je	.L1445
	addl	%edx, 384+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 392+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 396+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 404+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 200+_ZN10Solve_left7SegtreeE(%rip)
.L1445:
	movl	40(%rsp), %edx
	movl	%r11d, 76(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %r9d
	movl	%eax, 80(%rsp)
	movl	%r13d, %r8d
	movl	$32, %ecx
	movq	%r14, %rdi
	movl	%r10d, 68(%rsp)
	sarl	%edx
	movl	$1, %esi
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	%edx, 72(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	72(%rsp), %edx
	movl	%ebp, %r9d
	movq	%r14, %rdi
	movl	$33, %ecx
	movl	%r13d, %r8d
	movl	%ebx, (%rsp)
	leal	1(%rdx), %esi
	movl	60(%rsp), %edx
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	384+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r9
	.cfi_def_cfa_offset 232
	movl	396+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r10
	.cfi_def_cfa_offset 224
	movl	388+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	400+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	60(%rsp), %r10d
	movl	72(%rsp), %eax
	movl	76(%rsp), %r11d
	jl	.L1446
	jne	.L1447
	addl	%edi, %ecx
.L1448:
	movl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 196+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 200+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1443
	.p2align 4,,10
	.p2align 3
.L1532:
	testl	%edx, %edx
	je	.L1533
	addl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 204+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 212+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
.L1533:
	movl	32(%rsp), %ecx
	sarl	%ecx
	leal	1(%rcx), %edx
	movl	%ecx, 44(%rsp)
	movl	%edx, 40(%rsp)
	cmpl	%ecx, %ebp
	jg	.L1534
	movl	200+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %ebx
	jl	.L1535
	testb	%sil, %sil
	je	.L1535
	addl	%r13d, %edx
	addl	%r13d, 192+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 200+_ZN10Solve_left7SegtreeE(%rip)
.L1534:
	movl	%r11d, 60(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movq	%r14, %rdi
	movl	%ebx, %r9d
	movl	%r10d, 64(%rsp)
	movl	$17, %ecx
	movl	%ebp, %r8d
	movl	%eax, 52(%rsp)
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	52(%rsp), %edx
	movl	56(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%rax
	.cfi_def_cfa_offset 224
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%edx, %esi
	movl	44(%rsp), %eax
	movl	56(%rsp), %r10d
	movl	60(%rsp), %r11d
	jl	.L1540
	jne	.L1541
	addl	%edi, %ecx
.L1542:
	movl	%edx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 104+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1531
.L1535:
	testl	%edx, %edx
	je	.L1536
	addl	%edx, 384+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 392+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 396+_ZN10Solve_left7SegtreeE(%rip)
	addl	%edx, 404+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 200+_ZN10Solve_left7SegtreeE(%rip)
.L1536:
	movl	40(%rsp), %edx
	movl	%r11d, 76(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebx, %r9d
	movl	%r10d, 80(%rsp)
	movl	%ebp, %r8d
	movl	$32, %ecx
	movq	%r14, %rdi
	movl	%eax, 68(%rsp)
	sarl	%edx
	movl	$1, %esi
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	%edx, 72(%rsp)
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	72(%rsp), %edx
	movl	%ebp, %r8d
	movq	%r14, %rdi
	movl	$33, %ecx
	movl	%ebx, %r9d
	movl	%r13d, (%rsp)
	leal	1(%rdx), %esi
	movl	60(%rsp), %edx
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	384+_ZN10Solve_left7SegtreeE(%rip), %edx
	popq	%rax
	.cfi_def_cfa_offset 232
	movl	396+_ZN10Solve_left7SegtreeE(%rip), %esi
	popq	%r8
	.cfi_def_cfa_offset 224
	movl	388+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	400+_ZN10Solve_left7SegtreeE(%rip), %edi
	cmpl	%esi, %edx
	movl	60(%rsp), %eax
	movl	72(%rsp), %r10d
	movl	76(%rsp), %r11d
	jg	.L1537
	jne	.L1538
	addl	%edi, %ecx
.L1539:
	movl	%edx, 192+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 196+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 200+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1534
	.p2align 4,,10
	.p2align 3
.L1991:
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movq	%rcx, %rdi
	jmp	.L1524
	.p2align 4,,10
	.p2align 3
.L1986:
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %r8d
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %eax
	movq	%rcx, %rdi
	jmp	.L1433
	.p2align 4,,10
	.p2align 3
.L1962:
	movq	48(%rsp), %rdx
	leaq	128(%rsp), %rdi
.LEHB0:
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
	jmp	.L1578
	.p2align 4,,10
	.p2align 3
.L1961:
	movq	48(%rsp), %rdx
	movq	64(%rsp), %rdi
	call	_ZNSt6vectorIiSaIiEE17_M_realloc_insertIJRKiEEEvN9__gnu_cxx17__normal_iteratorIPiS1_EEDpOT_
.LEHE0:
	jmp	.L1488
	.p2align 4,,10
	.p2align 3
.L1544:
	jg	.L1545
	movl	%edx, %esi
	.p2align 4,,10
	.p2align 3
.L1543:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1545
	.p2align 4,,10
	.p2align 3
.L1570:
	jg	.L1571
	movl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L1569:
	movl	%eax, %edx
	movl	%esi, %ecx
	jmp	.L1571
	.p2align 4,,10
	.p2align 3
.L1473:
	jg	.L1474
	movl	%edx, %esi
	.p2align 4,,10
	.p2align 3
.L1472:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1474
	.p2align 4,,10
	.p2align 3
.L1479:
	jg	.L1480
	movl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L1478:
	movl	%eax, %edx
	movl	%esi, %ecx
	jmp	.L1480
	.p2align 4,,10
	.p2align 3
.L1564:
	jg	.L1565
	movl	%edx, %esi
	.p2align 4,,10
	.p2align 3
.L1563:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1565
	.p2align 4,,10
	.p2align 3
.L1550:
	jg	.L1551
	movl	%ecx, %edx
	.p2align 4,,10
	.p2align 3
.L1549:
	movl	%edx, %ecx
	movl	%esi, %edi
	jmp	.L1551
	.p2align 4,,10
	.p2align 3
.L1459:
	jl	.L1460
	movl	%ecx, %edx
	.p2align 4,,10
	.p2align 3
.L1458:
	movl	%edx, %ecx
	movl	%esi, %edi
	jmp	.L1460
	.p2align 4,,10
	.p2align 3
.L1453:
	jl	.L1454
	movl	%edx, %esi
	.p2align 4,,10
	.p2align 3
.L1452:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1454
	.p2align 4,,10
	.p2align 3
.L1423:
	jg	.L1424
	movl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L1422:
	movl	%eax, %edx
	movl	%ecx, %esi
	jmp	.L1424
	.p2align 4,,10
	.p2align 3
.L1514:
	jl	.L1515
	movl	%edx, %eax
	.p2align 4,,10
	.p2align 3
.L1513:
	movl	%eax, %edx
	movl	%ecx, %esi
	jmp	.L1515
	.p2align 4,,10
	.p2align 3
.L1662:
	leal	1(%rdx), %esi
	cmpl	%r12d, %esi
	je	.L2008
	leal	(%rsi,%r12), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1695
	cmpl	%edx, %esi
	je	.L2009
	leal	(%rsi,%rdx), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jge	.L2010
	leal	1(%r9), %esi
	movl	$29, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1699:
	movl	336+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	348+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	340+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	352+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jg	.L1700
	jne	.L1701
	addl	%esi, %edx
.L1702:
	movl	%eax, 168+_ZN10Solve_left7SegtreeE(%rip)
	movl	180+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 172+_ZN10Solve_left7SegtreeE(%rip)
	movl	184+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 176+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1697:
	cmpl	%ecx, %eax
	jg	.L1709
.L2021:
	jne	.L1710
	addl	%esi, %edx
.L1711:
	movl	%eax, 84+_ZN10Solve_left7SegtreeE(%rip)
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 88+_ZN10Solve_left7SegtreeE(%rip)
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 92+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1664
	.p2align 4,,10
	.p2align 3
.L1590:
	leal	1(%r9), %esi
	cmpl	%esi, %edx
	je	.L2011
	leal	(%rdx,%rsi), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1635
	cmpl	%r9d, %esi
	je	.L2012
	leal	(%rsi,%r9), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jge	.L2013
	leal	1(%rdx), %esi
	cmpl	%esi, %r9d
	je	.L2014
	leal	(%r9,%rsi), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1641
	movl	$42, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1642:
	movl	504+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	516+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	508+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	520+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	jl	.L1643
	jne	.L1644
	addl	%esi, %edx
.L1645:
	movl	%eax, 252+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	%edx, 256+_ZN10Solve_left7SegtreeE(%rip)
	movl	92(%rsp), %r8d
	movl	$0, 260+_ZN10Solve_left7SegtreeE(%rip)
.L1639:
	movl	240+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	244+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jl	.L1646
.L2033:
	jne	.L1647
	addl	%edx, %esi
.L1648:
	movl	%ecx, 120+_ZN10Solve_left7SegtreeE(%rip)
	movl	136+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	%esi, 124+_ZN10Solve_left7SegtreeE(%rip)
	movl	132+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$0, 128+_ZN10Solve_left7SegtreeE(%rip)
.L1637:
	cmpl	%ecx, %eax
	jl	.L1655
.L2018:
	jne	.L1656
	addl	%edx, %esi
.L1657:
	movl	%ecx, 60+_ZN10Solve_left7SegtreeE(%rip)
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%esi, 64+_ZN10Solve_left7SegtreeE(%rip)
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 68+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1592
	.p2align 4,,10
	.p2align 3
.L1972:
	movq	128(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1390
	call	_ZdlPv@PLT
.L1390:
	movq	96(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1387
	call	_ZdlPv@PLT
.L1387:
	movq	152(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L2015
	addq	$168, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L1975:
	.cfi_restore_state
	addl	%ebx, %ecx
	addl	%ebx, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1406:
	movl	%r11d, 16(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%r13d, %edx
	movq	%r14, %rdi
	movl	%r10d, 20(%rsp)
	movl	$5, %ecx
	movl	%ebp, %r9d
	movl	$1, %r8d
	pushq	%rbx
	.cfi_def_cfa_offset 240
	movl	36(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%r13
	.cfi_def_cfa_offset 232
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	popq	%rdi
	.cfi_def_cfa_offset 224
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	movl	12(%rsp), %r10d
	movl	16(%rsp), %r11d
	jl	.L1416
	jne	.L1417
	addl	%esi, %edx
.L1418:
	movl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1404
	.p2align 4,,10
	.p2align 3
.L1417:
	jg	.L1418
	movl	%eax, %ecx
	.p2align 4,,10
	.p2align 3
.L1416:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1418
	.p2align 4,,10
	.p2align 3
.L1984:
	addl	%r13d, %ecx
	addl	%r13d, 48+_ZN10Solve_left7SegtreeE(%rip)
	movl	%ecx, 56+_ZN10Solve_left7SegtreeE(%rip)
.L1497:
	movl	%r11d, 16(%rsp)
	subq	$8, %rsp
	.cfi_def_cfa_offset 232
	movl	%ebp, %edx
	movl	$5, %ecx
	movl	%r10d, 20(%rsp)
	movl	%ebx, %r9d
	movl	$1, %r8d
	movq	%r14, %rdi
	pushq	%r13
	.cfi_def_cfa_offset 240
	movl	36(%rsp), %esi
	call	_ZN10Solve_left2ST6updateEiiiiii
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %eax
	popq	%r11
	.cfi_def_cfa_offset 232
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	popq	%rbp
	.cfi_def_cfa_offset 224
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	movl	12(%rsp), %r10d
	movl	16(%rsp), %r11d
	jl	.L1507
	jne	.L1508
	addl	%esi, %edx
.L1509:
	movl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1495
	.p2align 4,,10
	.p2align 3
.L1508:
	jg	.L1509
	movl	%eax, %ecx
	.p2align 4,,10
	.p2align 3
.L1507:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1509
.L1971:
	subl	$1, %eax
	subl	$1, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	%eax, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1579
.L1992:
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1561
.L1993:
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	jmp	.L1529
.L1988:
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %edi
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1438
.L1987:
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %ecx
	jmp	.L1470
.L1965:
	movl	$1, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %esi
	.p2align 4,,10
	.p2align 3
.L1589:
	cmpl	%ecx, %eax
	jg	.L1715
	jne	.L1716
	addl	%esi, %edx
.L1717:
	movl	%edx, 16+_ZN10Solve_left7SegtreeE(%rip)
	movslq	%edx, %rdx
	movl	%eax, 12+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 20+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1586
	.p2align 4,,10
	.p2align 3
.L1716:
	jl	.L1717
	movl	%eax, %ecx
	.p2align 4,,10
	.p2align 3
.L1715:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1717
.L1977:
	movl	$1, 40+_ZN10Solve_left7SegtreeE(%rip)
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %esi
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1589
.L1541:
	jg	.L1542
	movl	%edx, %esi
.L1540:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1542
.L1450:
	jg	.L1451
	movl	%edx, %esi
.L1449:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1451
.L1635:
	leal	1(%r9), %esi
	cmpl	%esi, %edx
	je	.L2016
	leal	(%rdx,%rsi), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jge	.L2017
	leal	1(%r9), %esi
	movl	$23, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1651:
	movl	264+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	276+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	268+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	280+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	jl	.L1652
	jne	.L1653
	addl	%esi, %edx
.L1654:
	movl	120+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%eax, 132+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 136+_ZN10Solve_left7SegtreeE(%rip)
	movl	124+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 140+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
	cmpl	%ecx, %eax
	jge	.L2018
.L1655:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1657
.L1695:
	leal	1(%rdx), %esi
	cmpl	%r12d, %esi
	je	.L2019
	leal	(%rsi,%r12), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jge	.L2020
	leal	1(%rdx), %esi
	movl	$31, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r12d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
.L1705:
	movl	360+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	372+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	364+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	376+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %eax
	jl	.L1706
	jne	.L1707
	addl	%edx, %esi
.L1708:
	movl	168+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 180+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 184+_ZN10Solve_left7SegtreeE(%rip)
	movl	172+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 188+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
	cmpl	%ecx, %eax
	jle	.L2021
.L1709:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1711
.L1665:
	leal	1(%r10), %esi
	cmpl	%esi, %edx
	je	.L2022
	leal	(%rdx,%rsi), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1674
	cmpl	%r9d, %esi
	je	.L2023
	leal	(%rsi,%r9), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1677
	movl	$52, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1678:
	movl	624+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	636+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	628+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	640+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%eax, %ecx
	jl	.L1679
	jne	.L1680
	addl	%esi, %edx
.L1681:
	movl	%eax, 312+_ZN10Solve_left7SegtreeE(%rip)
	movl	324+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 316+_ZN10Solve_left7SegtreeE(%rip)
	movl	328+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 320+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1676:
	cmpl	%eax, %ecx
	jl	.L1688
.L2032:
	jne	.L1689
	addl	%esi, %edx
.L1690:
	movl	144+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%eax, 156+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 160+_ZN10Solve_left7SegtreeE(%rip)
	movl	148+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 164+_ZN10Solve_left7SegtreeE(%rip)
	cmpl	%eax, %ecx
	jle	.L2024
.L1691:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1693
.L1593:
	leal	1(%rdx), %esi
	cmpl	%esi, %r9d
	je	.L2025
	leal	(%r9,%rsi), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jge	.L2026
	leal	1(%rdx), %esi
	movl	$19, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
.L1627:
	movl	216+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	228+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	220+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	232+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %eax
	jl	.L1628
	jne	.L1629
	addl	%edx, %esi
.L1630:
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 108+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 112+_ZN10Solve_left7SegtreeE(%rip)
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 116+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
	cmpl	%ecx, %eax
	jle	.L2027
.L1631:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1633
.L1584:
	jg	.L1585
	movl	%eax, %ecx
.L1583:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1585
.L1447:
	jg	.L1448
	movl	%edx, %esi
.L1446:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1448
.L1538:
	jl	.L1539
	movl	%edx, %esi
.L1537:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1539
.L1411:
	jg	.L1412
	movl	%edx, %esi
.L1410:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1412
.L1502:
	jl	.L1503
	movl	%edx, %esi
.L1501:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1503
.L1505:
	jg	.L1506
	movl	%edx, %esi
.L1504:
	movl	%esi, %edx
	movl	%edi, %ecx
	jmp	.L1506
.L1414:
	jg	.L1415
	movl	%eax, %ecx
.L1413:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1415
.L1985:
	addl	%r13d, %edx
	addl	%r13d, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1499
.L1976:
	addl	%ebx, %edx
	addl	%ebx, 96+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 104+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1408
.L1978:
	movl	$1, 76+_ZN10Solve_left7SegtreeE(%rip)
	movl	88+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$1, %esi
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %eax
	.p2align 4,,10
	.p2align 3
.L1664:
	cmpl	%eax, %ecx
	jg	.L1712
.L1981:
	jne	.L1713
	addl	%edx, %esi
.L1714:
	movl	%ecx, 36+_ZN10Solve_left7SegtreeE(%rip)
	movl	24+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%esi, 40+_ZN10Solve_left7SegtreeE(%rip)
	movl	28+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 44+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1589
	.p2align 4,,10
	.p2align 3
.L1713:
	jl	.L1714
	movl	%ecx, %eax
	jmp	.L1712
	.p2align 4,,10
	.p2align 3
.L1966:
	movl	$1, 52+_ZN10Solve_left7SegtreeE(%rip)
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %edx
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	64+_ZN10Solve_left7SegtreeE(%rip), %esi
	.p2align 4,,10
	.p2align 3
.L1592:
	cmpl	%ecx, %eax
	jg	.L1658
.L1970:
	jne	.L1659
	addl	%esi, %edx
.L1660:
	movl	%eax, 24+_ZN10Solve_left7SegtreeE(%rip)
	movl	36+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 28+_ZN10Solve_left7SegtreeE(%rip)
	movl	40+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 32+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1589
	.p2align 4,,10
	.p2align 3
.L1659:
	jl	.L1660
	movl	%eax, %ecx
	jmp	.L1658
	.p2align 4,,10
	.p2align 3
.L2011:
	movl	$1, 64+_ZN10Solve_left7SegtreeE(%rip)
	movl	60+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %esi
	movl	48+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	52+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1592
.L2008:
	movl	$1, 88+_ZN10Solve_left7SegtreeE(%rip)
	movl	72+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %edx
	movl	84+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	76+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1664
.L1968:
	cmpl	$1, %r9d
	je	.L2028
	leal	1(%r9), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1599
	cmpl	$1, %edx
	je	.L2029
	leal	1(%rdx), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1602
	cmpl	$1, %r9d
	je	.L2030
	leal	1(%r9), %edx
	sarl	%edx
	cmpl	%r8d, %edx
	jl	.L1605
	movl	$128, %ecx
	movl	$1, %esi
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1606:
	movl	1536+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	1548+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	1540+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	1552+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jg	.L1607
	jne	.L1608
	addl	%esi, %edx
.L1609:
	movl	%eax, 768+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	%edx, 772+_ZN10Solve_left7SegtreeE(%rip)
	movl	92(%rsp), %r8d
	movl	$0, 776+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1604
.L1980:
	movl	$24, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1669
.L2020:
	movl	$30, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1705
.L2026:
	movl	$18, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1627
.L1674:
	leal	1(%r9), %esi
	cmpl	%esi, %edx
	je	.L2031
	leal	(%rdx,%rsi), %r9d
	sarl	%r9d
	cmpl	%r8d, %r9d
	jl	.L1683
	movl	$54, %ecx
	movl	%r9d, %edx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
.L1684:
	movl	648+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	660+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	652+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	664+_ZN10Solve_left7SegtreeE(%rip), %edx
	cmpl	%ecx, %eax
	jl	.L1685
	jne	.L1686
	addl	%edx, %esi
.L1687:
	movl	312+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	%ecx, 324+_ZN10Solve_left7SegtreeE(%rip)
	movl	%esi, 328+_ZN10Solve_left7SegtreeE(%rip)
	movl	316+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$0, 332+_ZN10Solve_left7SegtreeE(%rip)
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
	cmpl	%eax, %ecx
	jge	.L2032
.L1688:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1690
.L2010:
	movl	$28, %ecx
	movl	%r9d, %edx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1699
.L2017:
	movl	$22, %ecx
	movl	%r9d, %edx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1651
.L2013:
	movl	$20, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	movl	252+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	240+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	256+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
	movl	244+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jge	.L2033
.L1646:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1648
.L1632:
	jl	.L1633
	movl	%eax, %ecx
	jmp	.L1631
	.p2align 4,,10
	.p2align 3
.L1656:
	jg	.L1657
	movl	%ecx, %eax
	jmp	.L1655
	.p2align 4,,10
	.p2align 3
.L1710:
	jl	.L1711
	movl	%eax, %ecx
	jmp	.L1709
	.p2align 4,,10
	.p2align 3
.L1692:
	jl	.L1693
	movl	%ecx, %eax
	jmp	.L1691
	.p2align 4,,10
	.p2align 3
.L1623:
	jg	.L1624
	movl	%eax, %ecx
.L1622:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1624
.L1671:
	jl	.L1672
	movl	%ecx, %eax
.L1670:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1672
.L1653:
	jg	.L1654
	movl	%eax, %ecx
.L1652:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1654
.L1629:
	jg	.L1630
	movl	%ecx, %eax
.L1628:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1630
.L1701:
	jl	.L1702
	movl	%eax, %ecx
.L1700:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1702
.L1707:
	jg	.L1708
	movl	%ecx, %eax
.L1706:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1708
.L1689:
	jg	.L1690
	movl	%eax, %ecx
	jmp	.L1688
	.p2align 4,,10
	.p2align 3
.L1647:
	jg	.L1648
	movl	%ecx, %eax
	jmp	.L1646
	.p2align 4,,10
	.p2align 3
.L2016:
	movl	$1, 136+_ZN10Solve_left7SegtreeE(%rip)
	movl	120+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %edx
	movl	132+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	124+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1637
.L2012:
	movl	$1, 124+_ZN10Solve_left7SegtreeE(%rip)
	movl	136+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	$1, %esi
	movl	120+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	132+_ZN10Solve_left7SegtreeE(%rip), %eax
	jmp	.L1637
.L2022:
	movl	$1, 160+_ZN10Solve_left7SegtreeE(%rip)
	movl	156+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	movl	144+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	148+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1667
.L2025:
	movl	$1, 112+_ZN10Solve_left7SegtreeE(%rip)
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	$1, %esi
	movl	100+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %eax
	jmp	.L1595
.L1979:
	movl	$1, 148+_ZN10Solve_left7SegtreeE(%rip)
	movl	156+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %esi
	movl	144+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	160+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1667
.L2009:
	movl	$1, 172+_ZN10Solve_left7SegtreeE(%rip)
	movl	168+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	movl	180+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	184+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1697
.L2019:
	movl	$1, 184+_ZN10Solve_left7SegtreeE(%rip)
	movl	168+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %esi
	movl	180+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	172+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1697
.L1967:
	movl	$1, 100+_ZN10Solve_left7SegtreeE(%rip)
	movl	108+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	112+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	96+_ZN10Solve_left7SegtreeE(%rip), %eax
	jmp	.L1595
.L1599:
	leal	1(%rdx), %esi
	movl	$33, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
	movl	384+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	388+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1601:
	movl	396+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	400+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jg	.L1613
	jne	.L1614
	addl	%esi, %edx
.L1615:
	movl	%eax, 192+_ZN10Solve_left7SegtreeE(%rip)
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	%edx, 196+_ZN10Solve_left7SegtreeE(%rip)
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %esi
	movl	$0, 200+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1598
.L1641:
	leal	1(%rdx), %esi
	movl	$43, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1642
.L1683:
	leal	1(%r9), %esi
	movl	$55, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1684
.L1617:
	leal	1(%r9), %esi
	movl	$35, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1618
.L1677:
	leal	1(%rdx), %esi
	movl	$53, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1678
.L1644:
	jg	.L1645
	movl	%eax, %ecx
.L1643:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1645
.L1686:
	jg	.L1687
	movl	%ecx, %eax
.L1685:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1687
.L1614:
	jl	.L1615
	movl	%eax, %ecx
.L1613:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1615
.L1620:
	jl	.L1621
	movl	%ecx, %eax
.L1619:
	movl	%eax, %ecx
	movl	%edx, %esi
	jmp	.L1621
.L1680:
	jg	.L1681
	movl	%eax, %ecx
.L1679:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1681
.L1602:
	leal	1(%r9), %esi
	movl	$65, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	call	_ZN10Solve_left2ST6changeEiiii
	movl	768+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	772+_ZN10Solve_left7SegtreeE(%rip), %edx
	movl	n(%rip), %r12d
	movl	92(%rsp), %r8d
.L1604:
	movl	780+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	784+_ZN10Solve_left7SegtreeE(%rip), %esi
	cmpl	%ecx, %eax
	jg	.L1610
	jne	.L1611
	addl	%esi, %edx
.L1612:
	movl	%eax, 384+_ZN10Solve_left7SegtreeE(%rip)
	movl	%edx, 388+_ZN10Solve_left7SegtreeE(%rip)
	movl	$0, 392+_ZN10Solve_left7SegtreeE(%rip)
	jmp	.L1601
.L2028:
	movl	$1, 196+_ZN10Solve_left7SegtreeE(%rip)
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	208+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1598
.L1969:
	movl	$1, 208+_ZN10Solve_left7SegtreeE(%rip)
	movl	192+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %esi
	movl	204+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	196+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1598
.L2014:
	movl	$1, 256+_ZN10Solve_left7SegtreeE(%rip)
	movl	252+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	jmp	.L1639
.L2031:
	movl	$1, 328+_ZN10Solve_left7SegtreeE(%rip)
	movl	312+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %esi
	movl	324+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	316+_ZN10Solve_left7SegtreeE(%rip), %edx
	jmp	.L1676
.L2023:
	movl	$1, 316+_ZN10Solve_left7SegtreeE(%rip)
	movl	312+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	movl	324+_ZN10Solve_left7SegtreeE(%rip), %ecx
	movl	328+_ZN10Solve_left7SegtreeE(%rip), %esi
	jmp	.L1676
.L1611:
	jl	.L1612
	movl	%eax, %ecx
.L1610:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1612
.L1605:
	leal	1(%rdx), %esi
	movl	$129, %ecx
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rdi
	movl	%r9d, %edx
	call	_ZN10Solve_left2ST6changeEiiii
	jmp	.L1606
.L2029:
	movl	$1, 388+_ZN10Solve_left7SegtreeE(%rip)
	movl	384+_ZN10Solve_left7SegtreeE(%rip), %eax
	jmp	.L1601
.L1608:
	jl	.L1609
	movl	%eax, %ecx
.L1607:
	movl	%ecx, %eax
	movl	%esi, %edx
	jmp	.L1609
.L2030:
	movl	$1, 772+_ZN10Solve_left7SegtreeE(%rip)
	movl	768+_ZN10Solve_left7SegtreeE(%rip), %eax
	movl	$1, %edx
	jmp	.L1604
.L2015:
	call	__stack_chk_fail@PLT
.L1740:
	endbr64
	movq	%rax, %rbp
	jmp	.L1720
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA3534:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3534-.LLSDACSB3534
.LLSDACSB3534:
	.uleb128 .LEHB0-.LFB3534
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L1740-.LFB3534
	.uleb128 0
.LLSDACSE3534:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC3534
	.type	_ZN10Solve_left5solveEv.cold, @function
_ZN10Solve_left5solveEv.cold:
.LFSB3534:
.L1720:
	.cfi_def_cfa_offset 224
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	128(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1721
	call	_ZdlPv@PLT
.L1721:
	movq	96(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L1722
	call	_ZdlPv@PLT
.L1722:
	movq	%rbp, %rdi
.LEHB1:
	call	_Unwind_Resume@PLT
.LEHE1:
	.cfi_endproc
.LFE3534:
	.section	.gcc_except_table
.LLSDAC3534:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC3534-.LLSDACSBC3534
.LLSDACSBC3534:
	.uleb128 .LEHB1-.LCOLDB1
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSEC3534:
	.section	.text.unlikely
	.text
	.size	_ZN10Solve_left5solveEv, .-_ZN10Solve_left5solveEv
	.section	.text.unlikely
	.size	_ZN10Solve_left5solveEv.cold, .-_ZN10Solve_left5solveEv.cold
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text._ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,"axG",@progbits,_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.type	_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_, @function
_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_:
.LFB4100:
	.cfi_startproc
	endbr64
	movabsq	$1152921504606846975, %rcx
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	8(%rdi), %rbp
	movq	(%rdi), %r14
	movq	%rbp, %rax
	subq	%r14, %rax
	sarq	$3, %rax
	cmpq	%rcx, %rax
	je	.L2053
	movq	%rsi, %rbx
	movq	%rdi, %r12
	subq	%r14, %rsi
	testq	%rax, %rax
	je	.L2044
	movabsq	$9223372036854775800, %r15
	leaq	(%rax,%rax), %rdi
	cmpq	%rdi, %rax
	jbe	.L2054
.L2036:
	movq	%r15, %rdi
	movq	%rdx, 8(%rsp)
	movq	%rsi, (%rsp)
	call	_Znwm@PLT
	movq	(%rsp), %rsi
	movq	8(%rsp), %rdx
	movq	%rax, %r13
	addq	%rax, %r15
	leaq	8(%rax), %rax
.L2043:
	movq	(%rdx), %rdx
	movq	%rdx, 0(%r13,%rsi)
	cmpq	%r14, %rbx
	je	.L2038
	movq	%r13, %rcx
	movq	%r14, %rdx
	.p2align 4,,10
	.p2align 3
.L2039:
	movl	(%rdx), %eax
	movl	4(%rdx), %esi
	addq	$8, %rdx
	addq	$8, %rcx
	movl	%eax, -8(%rcx)
	movl	%esi, -4(%rcx)
	cmpq	%rdx, %rbx
	jne	.L2039
	movq	%rbx, %rax
	subq	%r14, %rax
	leaq	8(%r13,%rax), %rax
.L2038:
	cmpq	%rbp, %rbx
	je	.L2040
	movq	%rbx, %rdx
	movq	%rax, %rcx
	.p2align 4,,10
	.p2align 3
.L2041:
	movl	4(%rdx), %esi
	movl	(%rdx), %edi
	addq	$8, %rdx
	addq	$8, %rcx
	movl	%edi, -8(%rcx)
	movl	%esi, -4(%rcx)
	cmpq	%rbp, %rdx
	jne	.L2041
	subq	%rbx, %rdx
	addq	%rdx, %rax
.L2040:
	testq	%r14, %r14
	je	.L2042
	movq	%r14, %rdi
	movq	%rax, (%rsp)
	call	_ZdlPv@PLT
	movq	(%rsp), %rax
.L2042:
	movq	%r13, (%r12)
	movq	%rax, 8(%r12)
	movq	%r15, 16(%r12)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L2054:
	.cfi_restore_state
	testq	%rdi, %rdi
	jne	.L2037
	movl	$8, %eax
	xorl	%r15d, %r15d
	xorl	%r13d, %r13d
	jmp	.L2043
	.p2align 4,,10
	.p2align 3
.L2044:
	movl	$8, %r15d
	jmp	.L2036
.L2037:
	cmpq	%rcx, %rdi
	cmovbe	%rdi, %rcx
	movq	%rcx, %r15
	salq	$3, %r15
	jmp	.L2036
.L2053:
	leaq	.LC0(%rip), %rdi
	call	_ZSt20__throw_length_errorPKc@PLT
	.cfi_endproc
.LFE4100:
	.size	_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_, .-_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	.section	.text._ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_,"axG",@progbits,_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_
	.type	_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_, @function
_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_:
.LFB4009:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	8(%rdi), %rax
	movq	%rdi, %rbx
	cmpq	16(%rdi), %rax
	je	.L2056
	movq	(%rsi), %rdx
	movq	%rdx, (%rax)
	leaq	8(%rax), %rdx
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	movq	%rdx, 8(%rdi)
	ret
	.p2align 4,,10
	.p2align 3
.L2056:
	.cfi_restore_state
	movq	%rsi, %rdx
	movq	%rax, %rsi
	call	_ZNSt6vectorISt4pairIiiESaIS1_EE17_M_realloc_insertIJS1_EEEvN9__gnu_cxx17__normal_iteratorIPS1_S3_EEDpOT_
	movq	8(%rbx), %rax
	popq	%rbx
	.cfi_def_cfa_offset 8
	subq	$8, %rax
	ret
	.cfi_endproc
.LFE4009:
	.size	_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_, .-_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4
	.globl	_ZN11Solve_merge5solveEv
	.type	_ZN11Solve_merge5solveEv, @function
_ZN11Solve_merge5solveEv:
.LFB3578:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA3578
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$328, %rsp
	.cfi_def_cfa_offset 384
	movl	n(%rip), %r15d
	movq	%fs:40, %rax
	movq	%rax, 312(%rsp)
	xorl	%eax, %eax
	movl	$0, _ZN11Solve_merge2szE(%rip)
	leal	0(,%r15,4), %edx
	testl	%edx, %edx
	jle	.L2063
	subl	$1, %edx
	leaq	96+_ZN11Solve_merge7SegtreeE(%rip), %rax
	leaq	(%rdx,%rdx,2), %rdx
	movq	%rdx, %rcx
	leaq	96(%rax), %rdx
	salq	$5, %rcx
	addq	%rcx, %rdx
	.p2align 4,,10
	.p2align 3
.L2064:
	movl	$0, (%rax)
	addq	$96, %rax
	movl	$0, -92(%rax)
	movl	$0, -88(%rax)
	movl	$0, -84(%rax)
	movl	$0, -80(%rax)
	movl	$0, -76(%rax)
	movl	$0, -72(%rax)
	movl	$0, -68(%rax)
	movl	$0, -64(%rax)
	movl	$0, -60(%rax)
	movl	$0, -56(%rax)
	movl	$0, -52(%rax)
	movl	$0, -48(%rax)
	movl	$0, -44(%rax)
	movl	$0, -40(%rax)
	movl	$0, -36(%rax)
	movl	$0, -32(%rax)
	movl	$0, -28(%rax)
	movl	$0, -24(%rax)
	movl	$0, -20(%rax)
	movb	$1, -16(%rax)
	movb	$1, -15(%rax)
	movq	$0, -8(%rax)
	cmpq	%rax, %rdx
	jne	.L2064
.L2063:
	testl	%r15d, %r15d
	jle	.L2061
	leaq	4+_ZN11Solve_merge3BitE(%rip), %rax
	leal	-1(%r15), %edx
	leaq	4(%rax), %rsi
	leal	1(%r15), %ecx
	leaq	(%rsi,%rdx,4), %rdx
	.p2align 4,,10
	.p2align 3
.L2066:
	movl	%ecx, (%rax)
	addq	$4, %rax
	movl	$0, 2000016(%rax)
	movl	$0, 4000036(%rax)
	cmpq	%rax, %rdx
	jne	.L2066
	cmpl	$1, %r15d
	je	.L2234
	movl	$2, %eax
	leaq	_ZN11Solve_merge6SparseE(%rip), %r14
	.p2align 4,,10
	.p2align 3
.L2067:
	movl	%eax, %edx
	sarl	%edx
	movslq	%edx, %rdx
	movl	100001000(%r14,%rdx,4), %edx
	addl	$1, %edx
	movl	%edx, 100001000(%r14,%rax,4)
	addq	$1, %rax
	cmpl	%eax, %r15d
	jge	.L2067
.L2234:
	leaq	100+_ZN11Solve_merge6SparseE(%rip), %rdx
	movl	$1, %eax
	leaq	p(%rip), %rsi
	.p2align 4,,10
	.p2align 3
.L2068:
	movl	(%rsi,%rax,4), %ecx
	addq	$1, %rax
	addq	$100, %rdx
	movl	%ecx, -100(%rdx)
	movl	%ecx, 50000400(%rdx)
	cmpl	%eax, %r15d
	jge	.L2068
.L2061:
	leaq	_ZN11Solve_merge6SparseE(%rip), %r14
	movl	$1, %edi
	xorl	%r8d, %r8d
	movl	$1, %r10d
	movq	%r14, %r9
	leaq	100(%r14), %r11
	.p2align 4,,10
	.p2align 3
.L2071:
	movl	%r10d, %eax
	movl	%edi, %ecx
	movl	%r15d, %ebx
	sall	%cl, %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	js	.L2072
	leaq	(%rax,%rax,4), %rax
	movl	%r8d, %ecx
	movq	%rdi, %rbx
	leaq	(%rax,%rax,4), %rax
	subq	%r8, %rbx
	addq	%r8, %rax
	leaq	(%r11,%rax,4), %rsi
	movl	%r10d, %eax
	sall	%cl, %eax
	cltq
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rcx
	movq	%r9, %rax
	salq	$2, %rcx
	.p2align 4,,10
	.p2align 3
.L2073:
	movl	50000600(%rax,%rcx), %edx
	cmpl	%edx, 50000600(%rax)
	cmovge	50000600(%rax), %edx
	movl	%edx, 50000600(%rax,%rbx,4)
	movl	100(%rax), %edx
	cmpl	%edx, 100(%rax,%rcx)
	cmovle	100(%rax,%rcx), %edx
	movl	%edx, 100(%rax,%rbx,4)
	addq	$100, %rax
	cmpq	%rax, %rsi
	jne	.L2073
.L2072:
	addq	$1, %rdi
	addq	$1, %r8
	addq	$4, %r9
	cmpq	$21, %rdi
	jne	.L2071
	movq	$0, 256(%rsp)
	movq	$0, 264(%rsp)
	movq	$0, 272(%rsp)
	movq	$0, 288(%rsp)
	movq	$0, 296(%rsp)
	movq	$0, 304(%rsp)
	testl	%r15d, %r15d
	jle	.L2059
	leaq	4+p(%rip), %rax
	xorl	%r8d, %r8d
	movq	$1, 56(%rsp)
	leaq	_ZN11Solve_merge3BitE(%rip), %r13
	movq	%rax, 32(%rsp)
	leaq	248(%rsp), %rax
	movq	%rax, 64(%rsp)
	leaq	256(%rsp), %rax
	movq	%rax, 112(%rsp)
	.p2align 4,,10
	.p2align 3
.L2216:
	movl	56(%rsp), %eax
	leal	1(%r15), %edx
	movl	%eax, 96(%rsp)
	movq	32(%rsp), %rax
	movl	(%rax), %r12d
	movl	%r15d, %eax
	subl	%r12d, %eax
	testl	%eax, %eax
	jle	.L2075
	.p2align 4,,10
	.p2align 3
.L2076:
	movslq	%eax, %rcx
	movl	0(%r13,%rcx,4), %ecx
	cmpl	%ecx, %edx
	cmovg	%ecx, %edx
	leal	-1(%rax), %ecx
	andl	%ecx, %eax
	jne	.L2076
.L2075:
	subl	%r12d, %edx
	leal	-1(%r12), %ebx
	leal	-1(%rdx), %eax
	movl	%eax, 44(%rsp)
	testl	%ebx, %ebx
	jle	.L2077
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L2078:
	movslq	%ebx, %rdx
	movl	2000020(%r13,%rdx,4), %edx
	cmpl	%edx, %eax
	cmovl	%edx, %eax
	leal	-1(%rbx), %edx
	andl	%edx, %ebx
	jne	.L2078
	movl	%r12d, %ebx
	subl	%eax, %ebx
	leal	-1(%rbx), %ebx
.L2077:
	testl	%r8d, %r8d
	je	.L2080
	movl	%ebx, 8(%rsp)
	movl	96(%rsp), %ebp
	.p2align 4,,10
	.p2align 3
.L2079:
	leaq	_ZN11Solve_merge2stE(%rip), %rbx
	movslq	%r8d, %rax
	movl	%ebp, %esi
	movslq	(%rbx,%rax,4), %rax
	movl	%ebp, %ebx
	subl	%eax, %esi
	leaq	(%rax,%rax,4), %rax
	leal	1(%rsi), %edx
	leaq	(%rax,%rax,4), %rdi
	movslq	%edx, %rdx
	movslq	100001000(%r14,%rdx,4), %r9
	movl	$1, %edx
	movq	%r9, %rcx
	addq	%r9, %rdi
	sall	%cl, %edx
	subl	%edx, %ebx
	movl	%ebx, %edx
	addl	$1, %edx
	movslq	%edx, %rax
	leaq	(%rax,%rax,4), %rax
	leaq	(%rax,%rax,4), %rcx
	movl	(%r14,%rdi,4), %eax
	addq	%r9, %rcx
	movl	50000500(%r14,%rcx,4), %edx
	cmpl	%edx, 50000500(%r14,%rdi,4)
	cmovge	50000500(%r14,%rdi,4), %edx
	cmpl	%eax, (%r14,%rcx,4)
	cmovle	(%r14,%rcx,4), %eax
	xorl	%edi, %edi
	testl	%edx, %edx
	jle	.L2083
	.p2align 4,,10
	.p2align 3
.L2084:
	movslq	%edx, %rcx
	addl	4000040(%r13,%rcx,4), %edi
	leal	-1(%rdx), %ecx
	andl	%ecx, %edx
	jne	.L2084
.L2083:
	subl	$1, %eax
	testl	%eax, %eax
	jle	.L2085
	xorl	%ecx, %ecx
	.p2align 4,,10
	.p2align 3
.L2086:
	movslq	%eax, %rdx
	addl	4000040(%r13,%rdx,4), %ecx
	leal	-1(%rax), %edx
	andl	%edx, %eax
	jne	.L2086
	subl	%ecx, %edi
.L2085:
	cmpl	%edi, %esi
	je	.L2398
	leal	-1(%r8), %eax
	movl	%eax, _ZN11Solve_merge2szE(%rip)
	cmpl	$1, %r15d
	je	.L2410
	movl	100+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	120+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2411
.L2089:
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2412
.L2090:
	leal	1(%r15), %edx
	sarl	%edx
	cmpl	%edx, %r8d
	jg	.L2091
	cmpl	$1, %edx
	je	.L2413
	movl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	216+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2414
.L2094:
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2415
.L2095:
	leal	1(%rdx), %r10d
	sarl	%r10d
	cmpl	%r10d, %r8d
	jg	.L2096
	subq	$8, %rsp
	.cfi_def_cfa_offset 392
	xorl	%r9d, %r9d
	movl	$4, %ecx
	movl	%r10d, %edx
	pushq	$0
	.cfi_def_cfa_offset 400
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	$0
	.cfi_def_cfa_offset 408
	pushq	$0
	.cfi_def_cfa_offset 416
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
.L2097:
	leaq	144(%rsp), %r15
	pushq	568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	movq	%r15, %rdi
	pushq	552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	392+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	384+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	336(%rsp), %xmm6
	leaq	96(%rax), %rbx
	movaps	%xmm6, (%rax)
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movdqu	416(%rsp), %xmm3
	movaps	%xmm7, 208+_ZN11Solve_merge7SegtreeE(%rip)
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm0, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 272+_ZN11Solve_merge7SegtreeE(%rip)
.L2093:
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	pushq	376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	movq	%r15, %rdi
	pushq	368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rbx)
	.cfi_def_cfa_offset 472
	pushq	(%rbx)
	.cfi_def_cfa_offset 480
	pushq	280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movl	_ZN11Solve_merge2szE(%rip), %r8d
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movl	n(%rip), %r15d
	movdqu	368(%rsp), %xmm2
	movaps	%xmm0, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm1, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm2, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 144+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 176+_ZN11Solve_merge7SegtreeE(%rip)
.L2088:
	testl	%r8d, %r8d
	jne	.L2079
.L2398:
	movl	8(%rsp), %ebx
.L2080:
	movq	264(%rsp), %rsi
	movq	256(%rsp), %rcx
	xorl	%edi, %edi
	movq	%rsi, %r9
	movq	%rsi, %rdx
	subq	%rcx, %r9
	sarq	$3, %r9
	movl	%r9d, %eax
	cmpl	$1, %r9d
	jg	.L2081
	jmp	.L2082
	.p2align 4,,10
	.p2align 3
.L2103:
	subq	$8, %rdx
	movl	$1, %edi
	movq	%rdx, %r9
	subq	%rcx, %r9
	sarq	$3, %r9
	movl	%r9d, %eax
	cmpl	$1, %r9d
	jle	.L2405
.L2081:
	subl	$2, %eax
	cltq
	cmpl	%r8d, 4(%rcx,%rax,8)
	jge	.L2103
	testb	%dil, %dil
	je	.L2082
.L2405:
	movq	%rdx, 264(%rsp)
	movq	%rdx, %rsi
.L2082:
	cmpq	%rcx, %rdx
	je	.L2106
	cmpl	%r8d, -4(%rdx)
	jl	.L2106
	movl	%r8d, -4(%rdx)
.L2106:
	movq	296(%rsp), %r9
	movq	288(%rsp), %rax
	movq	%r9, %rdi
	subq	%rax, %rdi
	sarq	$3, %rdi
	movl	%edi, %edx
	cmpl	$1, %edi
	jle	.L2107
	xorl	%r10d, %r10d
	jmp	.L2112
	.p2align 4,,10
	.p2align 3
.L2108:
	subq	$8, %r9
	movl	$1, %r10d
	movq	%r9, %rdi
	subq	%rax, %rdi
	sarq	$3, %rdi
	movl	%edi, %edx
	cmpl	$1, %edi
	jle	.L2406
.L2112:
	subl	$2, %edx
	movslq	%edx, %rdx
	cmpl	%r8d, 4(%rax,%rdx,8)
	jge	.L2108
	testb	%r10b, %r10b
	je	.L2107
.L2406:
	movq	%r9, 296(%rsp)
.L2107:
	cmpq	%rax, %r9
	je	.L2111
	cmpl	%r8d, -4(%r9)
	jl	.L2111
	movl	%r8d, -4(%r9)
.L2111:
	movslq	%ebx, %rdi
	movq	%rdi, 8(%rsp)
	leaq	144(%rsp), %rdi
	cmpq	%rcx, %rsi
	je	.L2114
	movq	%r14, 48(%rsp)
	movq	%rdi, %r14
	jmp	.L2113
	.p2align 4,,10
	.p2align 3
.L2116:
	movl	-12(%rsi), %eax
	leal	1(%rax), %r8d
	cmpl	%r15d, %r8d
	jg	.L2239
	testb	%dl, %dl
	jne	.L2239
	cmpl	$1, %r8d
	setle	%dl
	cmpl	%r15d, %ebp
	setge	%r11b
	testb	%dl, %dl
	je	.L2151
	testb	%r11b, %r11b
	je	.L2151
	movslq	104+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	112+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 120+_ZN11Solve_merge7SegtreeE(%rip)
	movq	184+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 100+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 132+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 112+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rdi, %rsi
	movq	%rax, 184+_ZN11Solve_merge7SegtreeE(%rip)
.L2117:
	cmpq	%rsi, %rcx
	je	.L2408
.L2113:
	cmpl	%r12d, -8(%rsi)
	jle	.L2408
	movl	-4(%rsi), %ebp
	leaq	-8(%rsi), %rdi
	movq	%rdi, 264(%rsp)
	testl	%ebp, %ebp
	setle	%dl
	cmpq	%rcx, %rdi
	jne	.L2116
	testl	%r15d, %r15d
	jle	.L2239
	testb	%dl, %dl
	jne	.L2239
	cmpl	%r15d, %ebp
	jl	.L2118
	movslq	104+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	112+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 120+_ZN11Solve_merge7SegtreeE(%rip)
	movq	184+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 100+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 132+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 112+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rcx, %rsi
	movq	%rax, 184+_ZN11Solve_merge7SegtreeE(%rip)
	cmpq	%rsi, %rcx
	jne	.L2113
	.p2align 4,,10
	.p2align 3
.L2408:
	movq	48(%rsp), %r14
	movq	288(%rsp), %rax
.L2114:
	movslq	44(%rsp), %rsi
	movq	296(%rsp), %rdx
	movq	%rsi, 16(%rsp)
	cmpq	%rdx, %rax
	je	.L2175
	movq	%r14, 80(%rsp)
	movl	44(%rsp), %r14d
	movl	%ebx, 72(%rsp)
	jmp	.L2174
	.p2align 4,,10
	.p2align 3
.L2178:
	movl	-12(%rdx), %r10d
	leal	1(%r10), %ebp
	cmpl	%r15d, %ebp
	jg	.L2241
	testb	%sil, %sil
	jne	.L2241
	cmpl	$1, %ebp
	setle	%dl
	cmpl	%r15d, %ebx
	setge	%r11b
	testb	%dl, %dl
	je	.L2188
	testb	%r11b, %r11b
	je	.L2188
	movslq	144+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	152+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movq	184+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%r12d, 140+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rsi
	movl	%r14d, 172+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rdx
	movl	%r14d, 152+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rsi, %rbx
	addq	%rbx, %rdx
	movq	%rdx, 184+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%rcx, %rdx
.L2179:
	cmpq	%rdx, %rax
	je	.L2401
.L2174:
	cmpl	%r12d, -8(%rdx)
	jge	.L2401
	movl	-4(%rdx), %ebx
	leaq	-8(%rdx), %rcx
	movq	%rcx, 296(%rsp)
	testl	%ebx, %ebx
	setle	%sil
	cmpq	%rax, %rcx
	jne	.L2178
	testl	%r15d, %r15d
	jle	.L2241
	testb	%sil, %sil
	jne	.L2241
	cmpl	%r15d, %ebx
	jl	.L2180
	movslq	144+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	152+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movq	184+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%r12d, 140+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%r14d, 172+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rdx
	movl	%r14d, 152+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rbx
	addq	%rbx, %rdx
	movq	%rdx, 184+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%rax, %rdx
	cmpq	%rdx, %rax
	jne	.L2174
	.p2align 4,,10
	.p2align 3
.L2401:
	movl	72(%rsp), %ebx
	movq	80(%rsp), %r14
.L2175:
	movl	_ZN11Solve_merge2szE(%rip), %eax
	subq	$8, %rsp
	.cfi_def_cfa_offset 392
	movl	%r15d, %edx
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	$1, %ecx
	leal	1(%rax), %r8d
	movl	52(%rsp), %eax
	movl	%r8d, _ZN11Solve_merge2szE(%rip)
	pushq	%rax
	.cfi_def_cfa_offset 400
	pushq	%rbx
	.cfi_def_cfa_offset 408
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	128(%rsp), %ebx
	movl	%ebx, %r9d
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	movslq	_ZN11Solve_merge2szE(%rip), %rdx
	leaq	_ZN11Solve_merge2stE(%rip), %rsi
	movl	%ebx, (%rsi,%rdx,4)
	movq	64(%rsp), %rbx
	movq	%rdx, %rax
	movl	%eax, 284(%rsp)
	movl	(%rbx), %edx
	movl	%edx, 280(%rsp)
	movq	96(%rsp), %rsi
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	movq	112(%rsp), %rdi
.LEHB2:
	call	_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_
	movq	32(%rsp), %rax
	movq	64(%rsp), %rsi
	leaq	288(%rsp), %rdi
	movl	(%rax), %eax
	movl	%eax, 248(%rsp)
	movl	_ZN11Solve_merge2szE(%rip), %eax
	movl	%eax, 252(%rsp)
	call	_ZNSt6vectorISt4pairIiiESaIS1_EE12emplace_backIJS1_EEERS1_DpOT_
.LEHE2:
	movl	n(%rip), %r15d
	movl	%r12d, %eax
	cmpl	%r15d, %r12d
	jg	.L2214
	.p2align 4,,10
	.p2align 3
.L2211:
	movslq	%eax, %rdx
	movl	%r12d, %ecx
	cmpl	%r12d, 2000020(%r13,%rdx,4)
	cmovge	2000020(%r13,%rdx,4), %ecx
	addl	$1, 4000040(%r13,%rdx,4)
	movl	%ecx, 2000020(%r13,%rdx,4)
	movl	%eax, %edx
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %eax
	cmpl	%r15d, %eax
	jle	.L2211
.L2214:
	movl	%r15d, %eax
	subl	%r12d, %eax
	addl	$1, %eax
	cmpl	%r15d, %eax
	jg	.L2212
	.p2align 4,,10
	.p2align 3
.L2213:
	movslq	%eax, %rdx
	movl	%r12d, %ecx
	cmpl	%r12d, 0(%r13,%rdx,4)
	cmovle	0(%r13,%rdx,4), %ecx
	movl	%ecx, 0(%r13,%rdx,4)
	movl	%eax, %edx
	negl	%edx
	andl	%eax, %edx
	addl	%edx, %eax
	cmpl	%r15d, %eax
	jle	.L2213
.L2212:
	movslq	_ZN11Solve_merge2szE(%rip), %rax
	movq	56(%rsp), %rbx
	leaq	_ZN11Solve_merge3resE(%rip), %rdx
	addq	$4, 32(%rsp)
	movq	%rax, %r8
	addq	184+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, (%rdx,%rbx,8)
	movq	%rbx, %rax
	addq	$1, %rax
	movq	%rax, 56(%rsp)
	cmpl	%eax, %r15d
	jge	.L2216
	movq	288(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L2409
	call	_ZdlPv@PLT
.L2409:
	movq	256(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L2059
	call	_ZdlPv@PLT
.L2059:
	movq	312(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L2416
	addq	$328, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L2410:
	.cfi_restore_state
	movl	$257, %edi
	movl	%eax, %r8d
	movq	$0, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 104+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 120+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 136+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 144+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 152+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 168+_ZN11Solve_merge7SegtreeE(%rip)
	movw	%di, 176+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 184+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2088
	.p2align 4,,10
	.p2align 3
.L2239:
	movq	%rdi, %rsi
	jmp	.L2117
	.p2align 4,,10
	.p2align 3
.L2091:
	leal	1(%rdx), %esi
	cmpl	%r15d, %esi
	je	.L2417
	movl	292+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	312+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2418
.L2099:
	movl	332+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	352+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2419
.L2100:
	leal	(%rsi,%r15), %edx
	sarl	%edx
	cmpl	%edx, %r8d
	jg	.L2101
	subq	$8, %rsp
	.cfi_def_cfa_offset 392
	xorl	%r9d, %r9d
	movl	$6, %ecx
	pushq	$0
	.cfi_def_cfa_offset 400
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	$0
	.cfi_def_cfa_offset 408
	pushq	$0
	.cfi_def_cfa_offset 416
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
.L2102:
	leaq	144(%rsp), %r15
	pushq	760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	pushq	752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	movq	%r15, %rdi
	pushq	744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm4
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movaps	%xmm4, 288+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm1
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm5, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 368+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2093
	.p2align 4,,10
	.p2align 3
.L2151:
	movl	100+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	120+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2420
.L2152:
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2421
.L2153:
	leal	1(%r15), %r10d
	sarl	%r10d
	leal	1(%r10), %esi
	movl	%esi, 16(%rsp)
	cmpl	%r10d, %r8d
	jg	.L2154
	cmpl	%r10d, %ebp
	setge	24(%rsp)
	movzbl	24(%rsp), %edi
	testb	%dl, %dl
	je	.L2155
	testb	%dil, %dil
	je	.L2155
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r12d, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 228+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 208+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rdi
	addq	%rdi, %rdx
	cmpl	%r10d, %eax
	movq	%rdx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	setle	%cl
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	cmpl	%esi, %ebp
	jl	.L2157
.L2168:
	movl	$3, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movb	%r11b, 100(%rsp)
	movb	%cl, 88(%rsp)
	movl	%r8d, 80(%rsp)
	movl	%eax, 72(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	16(%rsp), %eax
	movl	80(%rsp), %r8d
	movzbl	88(%rsp), %ecx
	movzbl	100(%rsp), %r11d
	leal	(%rax,%r15), %r10d
	sarl	%r10d
	leal	1(%r10), %eax
	cmpl	%r10d, %r8d
	movl	%eax, 24(%rsp)
	movl	72(%rsp), %eax
	jg	.L2422
	cmpl	%r10d, %ebp
	jl	.L2170
	testb	%cl, %cl
	je	.L2170
	movslq	584+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	592+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 600+_ZN11Solve_merge7SegtreeE(%rip)
	movq	664+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 580+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 612+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 592+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 664+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 72(%rsp)
	leaq	96(%rax), %rcx
	cmpl	24(%rsp), %ebp
	jl	.L2172
.L2171:
	movl	$7, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r8d, 16(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	24(%rsp), %esi
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	32(%rsp), %r8d
	movl	$14, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	leal	(%r15,%rsi), %eax
	sarl	%eax
	movl	%eax, %edx
	movl	%r8d, 40(%rsp)
	movl	%eax, 32(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	movl	32(%rsp), %eax
	pushq	%rbx
	.cfi_def_cfa_offset 408
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	56(%rsp), %r8d
	movl	$15, %ecx
	movl	%r15d, %edx
	leal	1(%rax), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	leaq	672+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movq	%r14, %rdi
	movq	%rcx, 48(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1392+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1384+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	1352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	1344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 672+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movq	16(%rsp), %rcx
	movaps	%xmm1, 688+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 704+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 720+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 736+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 752+_ZN11Solve_merge7SegtreeE(%rip)
.L2172:
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movq	%r14, %rdi
	movq	%rdx, 16(%rsp)
	pushq	760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rcx)
	.cfi_def_cfa_offset 472
	pushq	(%rcx)
	.cfi_def_cfa_offset 480
	pushq	664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	248(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 288+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movq	16(%rsp), %rdx
	movaps	%xmm1, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 368+_ZN11Solve_merge7SegtreeE(%rip)
.L2157:
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	pushq	376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	movq	%r14, %rdi
	pushq	368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rdx)
	.cfi_def_cfa_offset 472
	pushq	(%rdx)
	.cfi_def_cfa_offset 480
	pushq	280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm6
	movdqu	352(%rsp), %xmm7
	movaps	%xmm6, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	368(%rsp), %xmm6
	movaps	%xmm7, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	384(%rsp), %xmm7
	movaps	%xmm6, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 144+_ZN11Solve_merge7SegtreeE(%rip)
.L2407:
	movdqu	400(%rsp), %xmm6
	movq	456(%rsp), %rsi
	movdqu	416(%rsp), %xmm7
	movl	n(%rip), %r15d
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm6, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movq	256(%rsp), %rcx
	movaps	%xmm7, 176+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2117
	.p2align 4,,10
	.p2align 3
.L2411:
	cmpl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2089
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movl	112+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 292+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 228+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 208+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 324+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 304+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %rbx
	leaq	(%rdx,%rbx), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	jne	.L2090
.L2412:
	cmpl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2090
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movl	152+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 332+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 268+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 248+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 364+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 344+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %rbx
	leaq	(%rdx,%rbx), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2090
.L2155:
	movl	196+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	216+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2423
.L2158:
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2424
.L2159:
	movl	16(%rsp), %esi
	sarl	%esi
	leal	1(%rsi), %edi
	movl	%esi, 88(%rsp)
	movl	%edi, 72(%rsp)
	cmpl	%esi, %r8d
	jg	.L2425
	cmpl	88(%rsp), %ebp
	jl	.L2161
	testb	%dl, %dl
	je	.L2161
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 420+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 400+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rdx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	96(%rsi), %rdx
	movq	%rsi, 80(%rsp)
	cmpl	72(%rsp), %ebp
	jl	.L2163
.L2162:
	movl	$5, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 104(%rsp)
	movb	%r11b, 136(%rsp)
	movl	%r10d, 88(%rsp)
	movl	%r8d, 24(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	88(%rsp), %r10d
	movl	72(%rsp), %esi
	movl	%ebp, %r9d
	movl	$10, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 100(%rsp)
	leal	(%rsi,%r10), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 392
	sarl	%edx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	40(%rsp), %r8d
	movl	%edx, 40(%rsp)
	movl	%r8d, 88(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	movl	40(%rsp), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 408
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	132(%rsp), %r10d
	movl	$11, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	104(%rsp), %r8d
	leal	1(%rdx), %esi
	movl	%r10d, %edx
	movl	%r8d, 120(%rsp)
	movl	%r10d, 104(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	leaq	480+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movq	%r14, %rdi
	movq	%rdx, 56(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1144+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1136+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1128+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1120+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1112+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1104+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1096+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1088+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1080+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1072+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1064+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1056+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1048+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1040+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1032+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1024+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1016+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1008+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1000+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	992+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	984+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	976+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	968+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	960+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm4
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movaps	%xmm4, 480+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm1
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movl	104(%rsp), %eax
	movl	88(%rsp), %r8d
	movaps	%xmm5, 496+_ZN11Solve_merge7SegtreeE(%rip)
	movzbl	136(%rsp), %r11d
	movl	72(%rsp), %r10d
	movaps	%xmm6, 512+_ZN11Solve_merge7SegtreeE(%rip)
	movq	24(%rsp), %rdx
	movaps	%xmm7, 528+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 560+_ZN11Solve_merge7SegtreeE(%rip)
.L2163:
	movb	%r11b, 100(%rsp)
	movq	%r14, %rdi
	movl	%r10d, 88(%rsp)
	movl	%r8d, 72(%rsp)
	movl	%eax, 24(%rsp)
	pushq	568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rdx)
	.cfi_def_cfa_offset 472
	pushq	(%rdx)
	.cfi_def_cfa_offset 480
	pushq	472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	256(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	336(%rsp), %xmm2
	movaps	%xmm2, (%rax)
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movdqu	416(%rsp), %xmm7
	movl	280(%rsp), %r10d
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 208+_ZN11Solve_merge7SegtreeE(%rip)
	movl	72(%rsp), %r8d
	movzbl	100(%rsp), %r11d
	movaps	%xmm4, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movl	24(%rsp), %eax
	movaps	%xmm5, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 272+_ZN11Solve_merge7SegtreeE(%rip)
.L2154:
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	cmpl	16(%rsp), %ebp
	jl	.L2157
	cmpl	%r10d, %eax
	setle	%sil
	movl	%esi, %ecx
	testb	%r11b, %r11b
	je	.L2168
	testb	%sil, %sil
	je	.L2168
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 292+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rcx
	movl	%ebx, 324+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 304+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2157
	.p2align 4,,10
	.p2align 3
.L2241:
	movq	%rcx, %rdx
	jmp	.L2179
	.p2align 4,,10
	.p2align 3
.L2188:
	movl	100+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	120+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2426
.L2189:
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2427
.L2190:
	leal	1(%r15), %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%esi, 24(%rsp)
	cmpl	%eax, %ebp
	jg	.L2428
	cmpl	%eax, %ebx
	setge	48(%rsp)
	movzbl	48(%rsp), %esi
	testb	%dl, %dl
	je	.L2192
	testb	%sil, %sil
	je	.L2192
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%r14d, 268+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rdx
	movl	%r14d, 248+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	cmpl	24(%rsp), %ebx
	jl	.L2429
	cmpl	%eax, %r10d
	leaq	144(%rsp), %rax
	movq	%rax, 8(%rsp)
	setle	%cl
.L2205:
	movl	$3, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movb	%r11b, 104(%rsp)
	movb	%cl, 100(%rsp)
	movl	%r10d, 88(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	24(%rsp), %eax
	movl	88(%rsp), %r10d
	movzbl	100(%rsp), %ecx
	movzbl	104(%rsp), %r11d
	addl	%r15d, %eax
	sarl	%eax
	leal	1(%rax), %esi
	cmpl	%eax, %ebp
	movl	%esi, 48(%rsp)
	jg	.L2430
	cmpl	%eax, %ebx
	jl	.L2207
	testb	%cl, %cl
	je	.L2207
	movslq	624+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	632+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 640+_ZN11Solve_merge7SegtreeE(%rip)
	movq	664+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 620+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%r14d, 652+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rax
	movl	%r14d, 632+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 664+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 88(%rsp)
	leaq	96(%rax), %rcx
	cmpl	48(%rsp), %ebx
	jl	.L2209
.L2208:
	movl	$7, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	48(%rsp), %esi
	pushq	%r14
	.cfi_def_cfa_offset 392
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%ebp, %r8d
	movl	$14, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	leal	(%r15,%rsi), %eax
	sarl	%eax
	movl	%eax, %edx
	movl	%eax, 40(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	movl	40(%rsp), %eax
	pushq	%r14
	.cfi_def_cfa_offset 408
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	%ebp, %r8d
	movl	$15, %ecx
	movl	%r15d, %edx
	leal	1(%rax), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	leaq	672+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movq	%rcx, 56(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1392+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1384+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	1352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	1344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 672+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movq	24(%rsp), %rcx
	movaps	%xmm1, 688+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 704+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 720+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 736+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 752+_ZN11Solve_merge7SegtreeE(%rip)
.L2209:
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movq	%rdx, 24(%rsp)
	pushq	760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rcx)
	.cfi_def_cfa_offset 472
	pushq	(%rcx)
	.cfi_def_cfa_offset 480
	pushq	664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	264(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm4
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movaps	%xmm4, 288+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm1
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movq	24(%rsp), %rdx
	movaps	%xmm5, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 368+_ZN11Solve_merge7SegtreeE(%rip)
.L2194:
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	pushq	376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rdx)
	.cfi_def_cfa_offset 472
	pushq	(%rdx)
	.cfi_def_cfa_offset 480
	pushq	280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	488(%rsp), %rdx
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movl	n(%rip), %r15d
	movdqu	368(%rsp), %xmm2
	movaps	%xmm0, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm1, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm2, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movq	288(%rsp), %rax
	movaps	%xmm3, 144+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 176+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2179
	.p2align 4,,10
	.p2align 3
.L2413:
	movl	$257, %esi
	movq	$0, 192+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	144(%rsp), %r15
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movq	$0, 200+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 208+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 232+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 248+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 264+_ZN11Solve_merge7SegtreeE(%rip)
	movw	%si, 272+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 280+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2093
	.p2align 4,,10
	.p2align 3
.L2417:
	movl	$257, %ecx
	movq	$0, 288+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	144(%rsp), %r15
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movq	$0, 296+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 328+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 344+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 360+_ZN11Solve_merge7SegtreeE(%rip)
	movw	%cx, 368+_ZN11Solve_merge7SegtreeE(%rip)
	movq	$0, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2093
	.p2align 4,,10
	.p2align 3
.L2101:
	subq	$8, %rsp
	.cfi_def_cfa_offset 392
	leal	1(%rdx), %esi
	xorl	%r9d, %r9d
	movl	$7, %ecx
	pushq	$0
	.cfi_def_cfa_offset 400
	movl	%r15d, %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	$0
	.cfi_def_cfa_offset 408
	pushq	$0
	.cfi_def_cfa_offset 416
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	jmp	.L2102
	.p2align 4,,10
	.p2align 3
.L2096:
	subq	$8, %rsp
	.cfi_def_cfa_offset 392
	leal	1(%r10), %esi
	xorl	%r9d, %r9d
	movl	$5, %ecx
	pushq	$0
	.cfi_def_cfa_offset 400
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	$0
	.cfi_def_cfa_offset 408
	pushq	$0
	.cfi_def_cfa_offset 416
	call	_ZN11Solve_merge2ST6changeEiiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	jmp	.L2097
	.p2align 4,,10
	.p2align 3
.L2118:
	movl	100+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	120+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2431
.L2119:
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2432
.L2120:
	leal	1(%r15), %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%eax, 24(%rsp)
	movl	%esi, 16(%rsp)
	cmpl	%eax, %ebp
	jl	.L2433
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 228+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 208+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 280+_ZN11Solve_merge7SegtreeE(%rip)
.L2121:
	cmpl	16(%rsp), %ebp
	jl	.L2150
	movl	$3, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	16(%rsp), %esi
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	$1, %r8d
	movl	$6, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	leal	(%rsi,%r15), %eax
	sarl	%eax
	movl	%eax, %edx
	movl	%eax, 32(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	movl	32(%rsp), %eax
	pushq	%rbx
	.cfi_def_cfa_offset 408
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	$1, %r8d
	movl	$7, %ecx
	movl	%r15d, %edx
	leal	1(%rax), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	movq	%r14, %rdi
	pushq	752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm2, 288+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 368+_ZN11Solve_merge7SegtreeE(%rip)
.L2150:
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	pushq	376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_remember_state
	.cfi_def_cfa_offset 392
	movq	%r14, %rdi
	pushq	368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movaps	%xmm2, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 144+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2407
	.p2align 4,,10
	.p2align 3
.L2180:
	.cfi_restore_state
	movl	100+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	120+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2434
.L2181:
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2435
.L2182:
	leal	1(%r15), %r10d
	sarl	%r10d
	leal	1(%r10), %ebp
	cmpl	%r10d, %ebx
	jl	.L2436
.L2232:
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%r14d, 268+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rax
	movl	%r14d, 248+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 280+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	144(%rsp), %rax
	movq	%rax, 8(%rsp)
.L2183:
	cmpl	%ebp, %ebx
	jl	.L2187
	movl	$3, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	pushq	%r14
	.cfi_def_cfa_offset 392
	leal	(%r15,%rbp), %eax
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 400
	sarl	%eax
	movl	$1, %r8d
	movl	$6, %ecx
	movl	%eax, %edx
	movl	%ebp, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 40(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	movl	40(%rsp), %eax
	pushq	%r14
	.cfi_def_cfa_offset 408
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	$1, %r8d
	movl	$7, %ecx
	movl	%r15d, %edx
	leal	1(%rax), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 288+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm1, 304+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 320+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 336+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 368+_ZN11Solve_merge7SegtreeE(%rip)
.L2187:
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	pushq	376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movq	488(%rsp), %rdx
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movl	n(%rip), %r15d
	movdqu	368(%rsp), %xmm4
	movaps	%xmm2, 96+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm3, 112+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm4, 128+_ZN11Solve_merge7SegtreeE(%rip)
	movq	288(%rsp), %rax
	movaps	%xmm5, 144+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 160+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 176+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2179
.L2426:
	cmpl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2189
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%eax, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movl	112+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movl	%eax, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rcx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 292+_ZN11Solve_merge7SegtreeE(%rip)
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	movl	%edi, 228+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r8
	movslq	%edi, %rcx
	movl	%edi, 208+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%edi, 324+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r8, %rsi
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movq	%rsi, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	imulq	%r8, %rcx
	movl	%edi, 304+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rsi
	subq	%rsi, %r9
	movq	%r9, %rsi
	addq	%rcx, %rsi
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	movq	%rsi, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jne	.L2190
.L2427:
	cmpl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2190
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%eax, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movl	152+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movl	%eax, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rcx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 268+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 248+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r8
	movslq	%edi, %rcx
	movl	%eax, 332+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%edi, 364+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r8, %rsi
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movq	%rsi, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	imulq	%r8, %rcx
	movl	%edi, 344+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rsi
	subq	%rsi, %r9
	movq	%r9, %rsi
	addq	%rcx, %rsi
	movq	%rsi, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2190
.L2428:
	leaq	144(%rsp), %rsi
	movq	%rsi, 8(%rsp)
.L2191:
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	cmpl	24(%rsp), %ebx
	jl	.L2194
	cmpl	%eax, %r10d
	setle	%al
	movl	%eax, %ecx
	testb	%r11b, %r11b
	je	.L2205
	testb	%al, %al
	je	.L2205
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%r12d, 332+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rcx
	movl	%r14d, 364+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rax
	movl	%r14d, 344+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rbx
	addq	%rbx, %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2194
.L2421:
	cmpl	236+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2153
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%ecx, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movl	152+_ZN11Solve_merge7SegtreeE(%rip), %r9d
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %r10
	movl	%ecx, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rsi
	movl	%ecx, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%r9d, 268+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%r9d, 248+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rsi, %r10
	movslq	%r9d, %rsi
	movl	%ecx, 332+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rdi
	movq	%rsi, 16(%rsp)
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r9d, 364+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r10, %rdi
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %r10
	movq	%rdi, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r9d, 344+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r10, %rdi
	subq	%rdi, %rsi
	movq	%rsi, %rdi
	movq	16(%rsp), %rsi
	imulq	%r10, %rsi
	addq	%rsi, %rdi
	movq	%rdi, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2153
.L2420:
	cmpl	196+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2152
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%ecx, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movl	112+_ZN11Solve_merge7SegtreeE(%rip), %r9d
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %r10
	movl	%ecx, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rsi
	movl	%ecx, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%r9d, 228+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%r9d, 208+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rsi, %r10
	movslq	%r9d, %rsi
	movl	%ecx, 292+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rdi
	movq	%rsi, 16(%rsp)
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r9d, 324+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r10, %rdi
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %r10
	movq	%rdi, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r9d, 304+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r10, %rdi
	subq	%rdi, %rsi
	movq	%rsi, %rdi
	movq	16(%rsp), %rsi
	imulq	%r10, %rsi
	addq	%rsi, %rdi
	movq	%rdi, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2152
.L2192:
	movl	196+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	216+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2437
.L2195:
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2438
.L2196:
	leal	1(%rax), %esi
	sarl	%esi
	leal	1(%rsi), %edi
	movl	%esi, 100(%rsp)
	movl	%edi, 88(%rsp)
	cmpl	%esi, %ebp
	jg	.L2439
	cmpl	100(%rsp), %ebx
	jl	.L2198
	testb	%dl, %dl
	je	.L2198
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%r14d, 460+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rdx
	movl	%r14d, 440+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	leaq	144(%rsp), %rsi
	movq	%rsi, 8(%rsp)
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rdx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	96(%rsi), %rdx
	movq	%rsi, 104(%rsp)
	cmpl	88(%rsp), %ebx
	jl	.L2200
.L2199:
	movl	$5, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 100(%rsp)
	movb	%r11b, 136(%rsp)
	movl	%eax, 48(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	48(%rsp), %eax
	movl	88(%rsp), %esi
	movl	%ebx, %r9d
	movl	%ebp, %r8d
	movl	$10, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 88(%rsp)
	leal	(%rsi,%rax), %edx
	pushq	%r14
	.cfi_def_cfa_offset 392
	sarl	%edx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%edx, 64(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	movl	64(%rsp), %edx
	pushq	%r14
	.cfi_def_cfa_offset 408
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	120(%rsp), %eax
	movl	%ebp, %r8d
	movl	$11, %ecx
	leal	1(%rdx), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, %edx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	leaq	480+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movq	%rdx, 80(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1144+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1136+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1128+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1120+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1112+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1104+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1096+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1088+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1080+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1072+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1064+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1056+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1048+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1040+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1032+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1024+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1016+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1008+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1000+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	992+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	984+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	976+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	968+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	960+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm4
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movaps	%xmm4, 480+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm1
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movl	100(%rsp), %r10d
	movl	88(%rsp), %eax
	movaps	%xmm5, 496+_ZN11Solve_merge7SegtreeE(%rip)
	movzbl	136(%rsp), %r11d
	movq	48(%rsp), %rdx
	movaps	%xmm6, 512+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 528+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 560+_ZN11Solve_merge7SegtreeE(%rip)
.L2200:
	movb	%r11b, 100(%rsp)
	movl	%eax, 88(%rsp)
	movl	%r10d, 48(%rsp)
	pushq	568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rdx)
	.cfi_def_cfa_offset 472
	pushq	(%rdx)
	.cfi_def_cfa_offset 480
	pushq	472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	280(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	336(%rsp), %xmm6
	movaps	%xmm6, (%rax)
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movdqu	416(%rsp), %xmm3
	movaps	%xmm7, 208+_ZN11Solve_merge7SegtreeE(%rip)
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movzbl	100(%rsp), %r11d
	movaps	%xmm0, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movl	88(%rsp), %eax
	movl	48(%rsp), %r10d
	movaps	%xmm1, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 272+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2191
.L2414:
	cmpl	388+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2094
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%eax, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movl	208+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rcx
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 484+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 420+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r9
	movslq	%edi, %rcx
	movl	%edi, 400+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%edi, 516+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rsi
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rsi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	imulq	%r9, %rcx
	movl	%edi, 496+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rsi
	subq	%rsi, %rbx
	leaq	(%rcx,%rbx), %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %eax
	jne	.L2095
.L2415:
	cmpl	428+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2095
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%eax, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movl	248+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rsi, %rcx
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 524+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 460+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r9
	movslq	%edi, %rcx
	movl	%edi, 440+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%edi, 556+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rsi
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rsi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	imulq	%r9, %rcx
	movl	%edi, 536+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rsi
	subq	%rsi, %rbx
	leaq	(%rcx,%rbx), %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2095
.L2418:
	cmpl	580+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2099
	movslq	584+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	592+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 600+_ZN11Solve_merge7SegtreeE(%rip)
	movl	304+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	664+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 580+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	760+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 696+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 676+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 612+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %r9
	movslq	%edi, %rdx
	movl	%edi, 592+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%edi, 708+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rcx
	movslq	680+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rcx, 664+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	688+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%r9, %rdx
	movl	%edi, 688+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rcx
	subq	%rcx, %rbx
	leaq	(%rdx,%rbx), %rax
	movq	%rax, 760+_ZN11Solve_merge7SegtreeE(%rip)
	movl	332+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	352+_ZN11Solve_merge7SegtreeE(%rip), %eax
	jne	.L2100
.L2419:
	cmpl	620+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2100
	movslq	624+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	632+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 640+_ZN11Solve_merge7SegtreeE(%rip)
	movl	344+_ZN11Solve_merge7SegtreeE(%rip), %edi
	movq	664+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%eax, 620+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	760+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%eax, 736+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 716+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 652+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %r9
	movslq	%edi, %rdx
	movl	%edi, 632+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%edi, 748+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rcx
	movslq	720+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rcx, 664+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	728+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%r9, %rdx
	movl	%edi, 728+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rcx
	subq	%rcx, %rbx
	leaq	(%rdx,%rbx), %rax
	movq	%rax, 760+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2100
.L2431:
	cmpl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2119
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movl	112+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 292+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 228+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 208+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 324+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 304+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	leaq	(%rdx,%r11), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	jne	.L2120
.L2432:
	cmpl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2120
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movl	152+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 352+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 332+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 268+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 248+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 364+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 344+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	leaq	(%rdx,%r11), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2120
.L2434:
	cmpl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2181
	movslq	200+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 216+_ZN11Solve_merge7SegtreeE(%rip)
	movl	112+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 196+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 312+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%eax, 292+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 228+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 208+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 324+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	296+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	304+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 304+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	leaq	(%rdx,%r11), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	movl	140+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	160+_ZN11Solve_merge7SegtreeE(%rip), %eax
	jne	.L2182
.L2435:
	cmpl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2182
	movslq	240+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	leal	1(%r15), %r10d
	movl	%eax, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movl	152+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	280+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	sarl	%r10d
	movl	%eax, 236+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movl	%eax, 352+_ZN11Solve_merge7SegtreeE(%rip)
	leal	1(%r10), %ebp
	movq	376+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 332+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 268+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 248+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%esi, 364+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	336+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 280+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	344+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rdx
	movl	%esi, 344+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	leaq	(%rdx,%r11), %rax
	movq	%rax, 376+_ZN11Solve_merge7SegtreeE(%rip)
	cmpl	%r10d, %ebx
	jge	.L2232
.L2436:
	movl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	216+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2440
.L2184:
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2441
.L2185:
	movl	%ebp, %eax
	sarl	%eax
	cmpl	%eax, %ebx
	jl	.L2442
.L2230:
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%r14d, 460+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rdx
	movl	%r14d, 440+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 472+_ZN11Solve_merge7SegtreeE(%rip)
.L2186:
	pushq	%r14
	.cfi_def_cfa_offset 392
	leal	1(%rax), %esi
	movl	%ebx, %r9d
	movl	$1, %r8d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	$5, %ecx
	movl	%r10d, %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	leaq	160(%rsp), %rax
	movq	%rax, 24(%rsp)
	movq	%rax, %rdi
	pushq	568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	pushq	392+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 584
	pushq	384+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 592
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	352(%rsp), %xmm0
	movaps	%xmm0, (%rax)
	movdqu	368(%rsp), %xmm1
	movdqu	384(%rsp), %xmm2
	movdqu	400(%rsp), %xmm3
	movdqu	416(%rsp), %xmm4
	movdqu	432(%rsp), %xmm5
	movaps	%xmm1, 208+_ZN11Solve_merge7SegtreeE(%rip)
	addq	$208, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm2, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 272+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2183
.L2433:
	movl	196+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	216+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2443
.L2122:
	movl	236+_ZN11Solve_merge7SegtreeE(%rip), %eax
	cmpl	256+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2444
.L2123:
	movl	16(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%eax, 100(%rsp)
	movl	%esi, 72(%rsp)
	cmpl	%eax, %ebp
	jl	.L2445
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 420+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 400+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 472+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 80(%rsp)
.L2124:
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$5, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	40(%rsp), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	88(%rsp), %esi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	pushq	568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	movq	%r14, %rdi
	pushq	560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	movq	272(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 584
	pushq	(%rax)
	.cfi_def_cfa_offset 592
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	192+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	352(%rsp), %xmm6
	movaps	%xmm6, (%rax)
	movdqu	368(%rsp), %xmm7
	movdqu	384(%rsp), %xmm0
	movdqu	400(%rsp), %xmm1
	movdqu	416(%rsp), %xmm6
	movaps	%xmm7, 208+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	432(%rsp), %xmm7
	addq	$208, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm0, 224+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 240+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 256+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 272+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2121
.L2429:
	leaq	144(%rsp), %rax
	leaq	288+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movq	%rax, 8(%rsp)
	jmp	.L2194
.L2439:
	leaq	144(%rsp), %rsi
	movq	%rsi, 8(%rsp)
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rsi, 104(%rsp)
.L2197:
	leaq	480+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	cmpl	88(%rsp), %ebx
	jl	.L2200
	cmpl	100(%rsp), %r10d
	jg	.L2199
	cmpb	$0, 48(%rsp)
	je	.L2199
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r12d, 524+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%r14d, 556+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rcx
	movl	%r14d, 536+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rsi, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2200
.L2438:
	cmpl	428+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2196
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movl	248+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%ecx, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	movl	%ecx, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 460+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 440+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdi, %r9
	movslq	%esi, %rdi
	movl	%ecx, 524+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%rdi, 8(%rsp)
	movq	8(%rsp), %rdi
	movl	%esi, 556+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %r8
	addq	%r9, %rdi
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rdi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%esi, 536+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	imulq	8(%rsp), %r8
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%r8, %rdi
	movq	%rdi, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2196
.L2437:
	cmpl	388+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2195
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movl	208+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%ecx, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	movl	%ecx, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 420+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 400+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdi, %r9
	movslq	%esi, %rdi
	movl	%ecx, 484+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%rdi, 8(%rsp)
	movq	8(%rsp), %rdi
	movl	%esi, 516+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %r8
	addq	%r9, %rdi
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rdi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%esi, 496+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	imulq	8(%rsp), %r8
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%r8, %rdi
	movq	%rdi, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2195
.L2430:
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rsi, 88(%rsp)
.L2206:
	leaq	672+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	cmpl	48(%rsp), %ebx
	jl	.L2209
	cmpl	%eax, %r10d
	jg	.L2208
	testb	%r11b, %r11b
	je	.L2208
	movslq	720+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	728+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 736+_ZN11Solve_merge7SegtreeE(%rip)
	movq	760+_ZN11Solve_merge7SegtreeE(%rip), %rbx
	movl	%r12d, 716+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%r14d, 748+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	16(%rsp), %rax
	movl	%r14d, 728+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rbx
	addq	%rbx, %rax
	movq	%rax, 760+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2209
.L2422:
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rsi, 72(%rsp)
.L2169:
	leaq	672+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	cmpl	24(%rsp), %ebp
	jl	.L2172
	cmpl	%r10d, %eax
	jg	.L2171
	testb	%r11b, %r11b
	je	.L2171
	movslq	680+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	688+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 696+_ZN11Solve_merge7SegtreeE(%rip)
	movq	760+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 676+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 708+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 688+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 760+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2172
.L2425:
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rsi, 80(%rsp)
.L2160:
	leaq	480+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	cmpl	72(%rsp), %ebp
	jl	.L2163
	cmpl	88(%rsp), %eax
	jg	.L2162
	cmpb	$0, 24(%rsp)
	je	.L2162
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r12d, 484+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rsi
	movl	%ebx, 516+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rcx
	movl	%ebx, 496+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rsi, %rdi
	addq	%rdi, %rcx
	movq	%rcx, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2163
.L2424:
	cmpl	428+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2159
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%ecx, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	movl	%ecx, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%ecx, 524+_ZN11Solve_merge7SegtreeE(%rip)
	movl	248+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	subq	%rdi, %rsi
	movslq	248+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 556+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %r9
	movq	%rdi, 72(%rsp)
	movl	%edi, 460+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 440+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%r9, %rdi
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %r9
	addq	%rsi, %rdi
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rdi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 536+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	imulq	72(%rsp), %r9
	subq	%rdi, %rsi
	movq	%rsi, %rdi
	addq	%r9, %rdi
	movq	%rdi, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2159
.L2423:
	cmpl	388+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	je	.L2158
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%ecx, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	movl	%ecx, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%ecx, 484+_ZN11Solve_merge7SegtreeE(%rip)
	movl	208+_ZN11Solve_merge7SegtreeE(%rip), %ecx
	subq	%rdi, %rsi
	movslq	208+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 516+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %r9
	movq	%rdi, 72(%rsp)
	movl	%edi, 420+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%edi, 400+_ZN11Solve_merge7SegtreeE(%rip)
	movq	%r9, %rdi
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %r9
	addq	%rsi, %rdi
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%rdi, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%ecx, 496+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	imulq	72(%rsp), %r9
	subq	%rdi, %rsi
	movq	%rsi, %rdi
	addq	%r9, %rdi
	movq	%rdi, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2158
.L2170:
	movl	$6, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movb	%r11b, 104(%rsp)
	movl	%eax, 100(%rsp)
	movl	%r10d, 80(%rsp)
	movl	%r8d, 72(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	80(%rsp), %r10d
	movl	16(%rsp), %esi
	movl	%ebp, %r9d
	movl	$12, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 88(%rsp)
	leal	(%rsi,%r10), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 392
	sarl	%edx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	88(%rsp), %r8d
	movl	%edx, 32(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	movl	32(%rsp), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 408
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	120(%rsp), %r10d
	movl	$13, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	104(%rsp), %r8d
	leal	1(%rdx), %esi
	movl	%r10d, %edx
	movl	%r8d, 112(%rsp)
	movl	%r10d, 48(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 104(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1200+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1192+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1184+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1176+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1168+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	1160+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	1152+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm2, 576+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 592+_ZN11Solve_merge7SegtreeE(%rip)
	movzbl	104(%rsp), %r11d
	movl	100(%rsp), %eax
	movaps	%xmm4, 608+_ZN11Solve_merge7SegtreeE(%rip)
	movl	80(%rsp), %r8d
	movl	16(%rsp), %r10d
	movaps	%xmm5, 624+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 640+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 656+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2169
.L2161:
	movl	388+_ZN11Solve_merge7SegtreeE(%rip), %edx
	cmpl	408+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2446
.L2164:
	movl	428+_ZN11Solve_merge7SegtreeE(%rip), %edx
	cmpl	448+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2447
.L2165:
	movl	%eax, 104(%rsp)
	movl	72(%rsp), %edx
	movl	%ebp, %r9d
	movl	$8, %ecx
	movb	%r11b, 120(%rsp)
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 136(%rsp)
	sarl	%edx
	pushq	%rbx
	.cfi_def_cfa_offset 392
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%r8d, 116(%rsp)
	movl	%edx, 96(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	movl	96(%rsp), %edx
	pushq	%rbx
	.cfi_def_cfa_offset 408
	movl	%ebp, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	132(%rsp), %r8d
	movl	$9, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	leal	1(%rdx), %esi
	movl	120(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 112(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	952+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	944+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	936+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	928+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	920+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	912+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	904+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	896+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	888+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	880+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	872+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	864+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	856+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	848+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	840+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	832+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	824+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	816+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	808+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	800+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	792+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	784+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	776+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	768+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm6
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movaps	%xmm6, 384+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm3
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm7, 400+_ZN11Solve_merge7SegtreeE(%rip)
	movzbl	120(%rsp), %r11d
	movl	104(%rsp), %eax
	movaps	%xmm0, 416+_ZN11Solve_merge7SegtreeE(%rip)
	movl	136(%rsp), %r10d
	movl	100(%rsp), %r8d
	movaps	%xmm1, 432+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 464+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2160
.L2198:
	movl	388+_ZN11Solve_merge7SegtreeE(%rip), %edx
	cmpl	408+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2448
.L2201:
	movl	428+_ZN11Solve_merge7SegtreeE(%rip), %edx
	cmpl	448+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2449
.L2202:
	movl	%eax, 120(%rsp)
	movl	88(%rsp), %edx
	movl	%ebx, %r9d
	movl	%ebp, %r8d
	movb	%r11b, 128(%rsp)
	movl	$8, %ecx
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 136(%rsp)
	sarl	%edx
	pushq	%r14
	.cfi_def_cfa_offset 392
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%edx, 24(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	movl	24(%rsp), %edx
	pushq	%r14
	.cfi_def_cfa_offset 408
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	%ebp, %r8d
	movl	$9, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	leal	1(%rdx), %esi
	movl	132(%rsp), %edx
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 136(%rsp)
	leaq	176(%rsp), %rax
	movq	%rax, 40(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	movq	%rax, %rdi
	pushq	952+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	944+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	936+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	928+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	920+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	912+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	904+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	896+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	888+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	880+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	872+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	864+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	856+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	848+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	840+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	832+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	824+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	816+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	808+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	800+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	792+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	784+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	776+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	768+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm6
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movaps	%xmm6, 384+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm3
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm7, 400+_ZN11Solve_merge7SegtreeE(%rip)
	movl	120(%rsp), %eax
	movzbl	128(%rsp), %r11d
	movaps	%xmm0, 416+_ZN11Solve_merge7SegtreeE(%rip)
	movl	136(%rsp), %r10d
	movaps	%xmm1, 432+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 464+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2197
.L2207:
	movl	$6, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movb	%r11b, 104(%rsp)
	movl	%r10d, 100(%rsp)
	movl	%eax, 88(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	24(%rsp), %esi
	movl	88(%rsp), %eax
	pushq	%r14
	.cfi_def_cfa_offset 392
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%ebx, %r9d
	movl	%ebp, %r8d
	movl	$12, %ecx
	leal	(%rax,%rsi), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	sarl	%edx
	movl	%edx, 40(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	movl	40(%rsp), %edx
	pushq	%r14
	.cfi_def_cfa_offset 408
	movl	%ebx, %r9d
	pushq	%r12
	.cfi_def_cfa_offset 416
	movl	120(%rsp), %eax
	movl	%ebp, %r8d
	movl	$13, %ecx
	leal	1(%rdx), %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, %edx
	movl	%eax, 56(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii
	leaq	576+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 120(%rsp)
	addq	$32, %rsp
	.cfi_def_cfa_offset 384
	pushq	1336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	1256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	1248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	1240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1200+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1192+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1184+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1176+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1168+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	1160+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	1152+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	movq	200(%rsp), %rdi
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm2, 576+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 592+_ZN11Solve_merge7SegtreeE(%rip)
	movzbl	104(%rsp), %r11d
	movl	100(%rsp), %r10d
	movaps	%xmm4, 608+_ZN11Solve_merge7SegtreeE(%rip)
	movl	24(%rsp), %eax
	movaps	%xmm5, 624+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 640+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 656+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2206
.L2444:
	cmpl	428+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2123
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movl	248+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movl	%eax, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 524+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 460+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 440+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movq	%rdx, %rax
	movl	%esi, 556+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rax
	movl	%esi, 536+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	addq	%r11, %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2123
.L2443:
	cmpl	388+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2122
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movl	208+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movl	%eax, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 484+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 420+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 400+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movq	%rdx, %rax
	movl	%esi, 516+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rax
	movl	%esi, 496+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	addq	%r11, %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2122
.L2441:
	cmpl	428+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2185
	movslq	432+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	440+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movl	248+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 428+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movl	%eax, 544+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 524+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 460+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 440+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movq	%rdx, %rax
	movl	%esi, 556+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	528+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	536+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rax
	movl	%esi, 536+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	addq	%r11, %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%ebp, %eax
	sarl	%eax
	cmpl	%eax, %ebx
	jge	.L2230
.L2442:
	movl	%r10d, 24(%rsp)
	movl	%eax, %edx
	movl	%ebx, %r9d
	movl	$1, %r8d
	pushq	%r14
	.cfi_def_cfa_offset 392
	movl	$4, %ecx
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%eax, 24(%rsp)
	call	_ZN11Solve_merge2ST10update_MaxEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 392
	popq	%rdx
	.cfi_def_cfa_offset 384
	movl	24(%rsp), %r10d
	movl	8(%rsp), %eax
	jmp	.L2186
.L2440:
	cmpl	388+_ZN11Solve_merge7SegtreeE(%rip), %eax
	je	.L2184
	movslq	392+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movslq	400+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%eax, 408+_ZN11Solve_merge7SegtreeE(%rip)
	movl	208+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	472+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 388+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdx
	movl	%eax, 504+_ZN11Solve_merge7SegtreeE(%rip)
	movq	568+_ZN11Solve_merge7SegtreeE(%rip), %r11
	movl	%eax, 484+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 420+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rdi
	movslq	%esi, %rdx
	movl	%esi, 400+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movq	%rdx, %rax
	movl	%esi, 516+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%rdi, %rcx
	movslq	488+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movq	%rcx, 472+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	496+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	imulq	%rdi, %rax
	movl	%esi, 496+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	subq	%rcx, %r11
	addq	%r11, %rax
	movq	%rax, 568+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2184
.L2445:
	movl	$4, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	72(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%eax, 136(%rsp)
	movl	%esi, 80(%rsp)
	cmpl	%eax, %ebp
	jl	.L2125
	movslq	776+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	784+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 792+_ZN11Solve_merge7SegtreeE(%rip)
	movq	856+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 772+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 804+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 784+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 856+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	768+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 104(%rsp)
.L2126:
	leaq	864+_ZN11Solve_merge7SegtreeE(%rip), %rax
	cmpl	80(%rsp), %ebp
	jl	.L2140
	leaq	-864(%rax), %rdi
	movl	$9, %esi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	80(%rsp), %eax
	addl	100(%rsp), %eax
	sarl	%eax
	movl	%eax, 88(%rsp)
	cmpl	%eax, %ebp
	jl	.L2141
	movslq	1736+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	1744+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 1752+_ZN11Solve_merge7SegtreeE(%rip)
	movq	1816+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 1732+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 1764+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 1744+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 1816+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	1728+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 80(%rsp)
.L2142:
	movl	88(%rsp), %r10d
	addl	$1, %r10d
	cmpl	%r10d, %ebp
	movl	%r10d, 88(%rsp)
	jl	.L2146
	movl	$19, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	100(%rsp), %eax
	movl	88(%rsp), %r10d
	addl	%r10d, %eax
	sarl	%eax
	cmpl	%eax, %ebp
	jl	.L2147
	movslq	3656+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	3664+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 3672+_ZN11Solve_merge7SegtreeE(%rip)
	movq	3736+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 3652+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 3684+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 3664+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 3736+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2148
	.p2align 4,,10
	.p2align 3
.L2447:
	cmpl	812+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2165
	movslq	816+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	824+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%edx, 832+_ZN11Solve_merge7SegtreeE(%rip)
	movl	440+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	856+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%edx, 812+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	movl	%edx, 928+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 844+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 824+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r9
	movslq	%esi, %rcx
	movl	%edx, 908+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdi
	movq	%rcx, 80(%rsp)
	movq	952+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%esi, 940+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rdi
	movslq	912+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rdi, 856+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	920+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%esi, 920+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	subq	%rdi, %rcx
	movq	%rcx, %rdi
	movq	80(%rsp), %rcx
	imulq	%r9, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 952+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2165
.L2446:
	cmpl	772+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2164
	movslq	776+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	784+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%edx, 792+_ZN11Solve_merge7SegtreeE(%rip)
	movl	400+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	856+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%edx, 772+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	movl	%edx, 888+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 804+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 784+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r9
	movslq	%esi, %rcx
	movl	%edx, 868+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdi
	movq	%rcx, 80(%rsp)
	movq	952+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%esi, 900+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r9, %rdi
	movslq	872+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movq	%rdi, 856+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	880+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%esi, 880+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r9, %rdi
	subq	%rdi, %rcx
	movq	%rcx, %rdi
	movq	80(%rsp), %rcx
	imulq	%r9, %rcx
	addq	%rcx, %rdi
	movq	%rdi, 952+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2164
.L2449:
	cmpl	812+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2202
	movslq	816+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	824+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%edx, 832+_ZN11Solve_merge7SegtreeE(%rip)
	movl	440+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	856+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movl	%edx, 812+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	movq	952+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%edx, 928+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 844+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 824+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r8
	movslq	%esi, %rcx
	movl	%edx, 908+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdi
	movl	%esi, 940+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r8, %rdi
	movslq	912+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movq	%rdi, 856+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	920+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	imulq	%r8, %rcx
	movl	%esi, 920+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 952+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2202
.L2448:
	cmpl	772+_ZN11Solve_merge7SegtreeE(%rip), %edx
	je	.L2201
	movslq	776+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movslq	784+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%edx, 792+_ZN11Solve_merge7SegtreeE(%rip)
	movl	400+_ZN11Solve_merge7SegtreeE(%rip), %esi
	movq	856+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movl	%edx, 772+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdi, %rcx
	movq	952+_ZN11Solve_merge7SegtreeE(%rip), %r9
	movl	%edx, 888+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 804+_ZN11Solve_merge7SegtreeE(%rip)
	movl	%esi, 784+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %r8
	movslq	%esi, %rcx
	movl	%edx, 868+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rcx, %rdi
	movl	%esi, 900+_ZN11Solve_merge7SegtreeE(%rip)
	addq	%r8, %rdi
	movslq	872+_ZN11Solve_merge7SegtreeE(%rip), %r8
	movq	%rdi, 856+_ZN11Solve_merge7SegtreeE(%rip)
	movslq	880+_ZN11Solve_merge7SegtreeE(%rip), %rdi
	imulq	%r8, %rcx
	movl	%esi, 880+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%r8, %rdi
	subq	%rdi, %r9
	movq	%r9, %rdi
	addq	%rcx, %rdi
	movq	%rdi, 952+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2201
.L2125:
	movl	$8, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	80(%rsp), %eax
	sarl	%eax
	leal	1(%rax), %esi
	movl	%eax, 120(%rsp)
	movl	%esi, 88(%rsp)
	cmpl	%eax, %ebp
	jl	.L2127
	movslq	1544+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	1552+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 1560+_ZN11Solve_merge7SegtreeE(%rip)
	movq	1624+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 1540+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 1572+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 1552+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 1624+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	1536+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 120(%rsp)
.L2128:
	cmpl	88(%rsp), %ebp
	jge	.L2450
.L2224:
	leaq	768+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 104(%rsp)
	pushq	1720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	872(%rax)
	.cfi_def_cfa_offset 472
	pushq	864(%rax)
	.cfi_def_cfa_offset 480
	pushq	1624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	296(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm2, 768+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 784+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 800+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 816+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 832+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 848+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2126
.L2147:
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	$1, %r8d
	movl	%eax, %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%ebp, %r9d
	movl	$38, %ecx
	movl	%r10d, %esi
	movl	%eax, 104(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 392
	popq	%r8
	.cfi_def_cfa_offset 384
	movl	88(%rsp), %eax
.L2148:
	leal	1(%rax), %esi
	cmpl	%esi, %ebp
	jl	.L2149
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	$39, %ecx
	movl	%ebp, %r9d
	movl	$1, %r8d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	116(%rsp), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 392
	popq	%rsi
	.cfi_def_cfa_offset 384
.L2149:
	pushq	3832+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	movq	%r14, %rdi
	pushq	3824+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	3816+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	3808+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	3800+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	3792+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	3784+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	3776+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	3768+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	3760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	3752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	3744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	3736+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	3728+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	3720+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	3712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	3704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	3696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	3688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	3680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	3672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	3664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	3656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	3648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	1824+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	336(%rsp), %xmm6
	movaps	%xmm6, (%rax)
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movdqu	416(%rsp), %xmm3
	movaps	%xmm7, 1840+_ZN11Solve_merge7SegtreeE(%rip)
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm0, 1856+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 1872+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 1888+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 1904+_ZN11Solve_merge7SegtreeE(%rip)
.L2146:
	leaq	864+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 88(%rsp)
	pushq	1912+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	1904+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	1896+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	1888+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	1880+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	1872+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	1864+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	1856+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	1848+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	1840+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	968(%rax)
	.cfi_def_cfa_offset 472
	pushq	960(%rax)
	.cfi_def_cfa_offset 480
	pushq	1816+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	1808+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	1800+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	1792+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	1784+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	1776+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	1768+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	1760+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	1752+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	1744+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	256(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm4
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movaps	%xmm4, 864+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm1
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movq	88(%rsp), %rax
	movaps	%xmm5, 880+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 896+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 912+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 928+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 944+_ZN11Solve_merge7SegtreeE(%rip)
.L2140:
	leaq	384+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movq	%r14, %rdi
	movq	%rsi, 80(%rsp)
	pushq	952+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	944+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	936+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	928+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	920+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	912+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	904+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	896+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	888+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	880+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	8(%rax)
	.cfi_def_cfa_offset 472
	pushq	(%rax)
	.cfi_def_cfa_offset 480
	pushq	856+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	848+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	840+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	832+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	824+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	816+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	808+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	800+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	792+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	784+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	280(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm2
	movdqu	352(%rsp), %xmm3
	movdqu	368(%rsp), %xmm4
	movdqu	384(%rsp), %xmm5
	movdqu	400(%rsp), %xmm6
	movaps	%xmm2, 384+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm3, 400+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 416+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 432+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 448+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 464+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2124
.L2127:
	movl	$16, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	88(%rsp), %r10d
	sarl	%r10d
	leal	1(%r10), %eax
	movl	%eax, 104(%rsp)
	cmpl	%r10d, %ebp
	jl	.L2129
	movslq	3080+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	3088+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 3096+_ZN11Solve_merge7SegtreeE(%rip)
	movq	3160+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 3076+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 3108+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 3088+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 3160+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	3072+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 128(%rsp)
	jmp	.L2130
.L2141:
	movl	$18, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	88(%rsp), %eax
	addl	80(%rsp), %eax
	sarl	%eax
	cmpl	%eax, %ebp
	jl	.L2143
	movslq	3464+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	3472+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 3480+_ZN11Solve_merge7SegtreeE(%rip)
	movq	3544+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 3460+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 3492+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 3472+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 3544+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2144
.L2450:
	movl	$17, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	136(%rsp), %eax
	addl	88(%rsp), %eax
	sarl	%eax
	movl	%eax, 104(%rsp)
	cmpl	%eax, %ebp
	jl	.L2451
	movslq	3272+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movslq	3280+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movl	%r12d, 3288+_ZN11Solve_merge7SegtreeE(%rip)
	movq	3352+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 3268+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rax, %rdx
	movl	%ebx, 3300+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rax
	movl	%ebx, 3280+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rdx, %rsi
	addq	%rsi, %rax
	movq	%rax, 3352+_ZN11Solve_merge7SegtreeE(%rip)
	leaq	3264+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%rax, 88(%rsp)
	jmp	.L2135
.L2451:
	movl	$34, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	104(%rsp), %eax
	addl	88(%rsp), %eax
	sarl	%eax
	cmpl	%eax, %ebp
	jl	.L2136
	movslq	6536+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	6544+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 6552+_ZN11Solve_merge7SegtreeE(%rip)
	movq	6616+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 6532+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 6564+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 6544+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 6616+_ZN11Solve_merge7SegtreeE(%rip)
.L2137:
	leal	1(%rax), %esi
	cmpl	%esi, %ebp
	jl	.L2138
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	$69, %ecx
	movl	%ebp, %r9d
	movl	$1, %r8d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	120(%rsp), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rcx
	.cfi_def_cfa_offset 392
	popq	%rsi
	.cfi_def_cfa_offset 384
.L2138:
	leaq	3264+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 88(%rsp)
	pushq	6712+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	6704+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	6696+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	6688+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	6680+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	6672+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	6664+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	6656+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	6648+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	6640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	6632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	6624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	6616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	6608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	6600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	6592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	6584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	6576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	6568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	6560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	6552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	6544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	6536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	6528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm6
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movdqu	400(%rsp), %xmm2
	movaps	%xmm6, 3264+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm3
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm7, 3280+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 3296+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 3312+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 3328+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 3344+_ZN11Solve_merge7SegtreeE(%rip)
.L2135:
	movl	104(%rsp), %esi
	addl	$1, %esi
	cmpl	%esi, %ebp
	jl	.L2139
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$35, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	152(%rsp), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 392
	popq	%rdx
	.cfi_def_cfa_offset 384
.L2139:
	pushq	3448+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	movq	%r14, %rdi
	pushq	3440+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	3432+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	3424+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	3416+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	3408+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	3400+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	3392+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	3384+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	3376+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	3368+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	3360+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	3352+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	3344+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	3336+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	3328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	3320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	3312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	3304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	3296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	3288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	3280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	264(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	leaq	1632+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movdqu	336(%rsp), %xmm4
	movaps	%xmm4, (%rax)
	movdqu	352(%rsp), %xmm5
	movdqu	368(%rsp), %xmm6
	movdqu	384(%rsp), %xmm7
	movdqu	400(%rsp), %xmm0
	movdqu	416(%rsp), %xmm1
	movaps	%xmm5, 1648+_ZN11Solve_merge7SegtreeE(%rip)
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm6, 1664+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 1680+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm0, 1696+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 1712+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2224
.L2143:
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%eax, %edx
	movl	%ebp, %r9d
	movl	$1, %r8d
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	96(%rsp), %esi
	movl	$36, %ecx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%eax, 152(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 392
	popq	%rax
	.cfi_def_cfa_offset 384
	movl	136(%rsp), %eax
.L2144:
	leal	1(%rax), %esi
	cmpl	%esi, %ebp
	jl	.L2145
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$37, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	104(%rsp), %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 392
	popq	%r10
	.cfi_def_cfa_offset 384
.L2145:
	leaq	1728+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 80(%rsp)
	pushq	3640+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	3632+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	3624+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	3616+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	3608+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	3600+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	3592+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	3584+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	3576+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	3568+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	3560+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	3552+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	3544+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	3536+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	3528+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	3520+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	3512+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	3504+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	3496+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	3488+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	3480+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	3472+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	3464+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	3456+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 1728+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm1, 1744+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 1760+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 1776+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 1792+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 1808+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2142
.L2129:
	movl	$32, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	movl	%r10d, 128(%rsp)
	call	_ZN11Solve_merge2ST8pushdownEi
	movl	104(%rsp), %eax
	movl	128(%rsp), %r10d
	sarl	%eax
	cmpl	%eax, %ebp
	jl	.L2131
	movslq	6152+_ZN11Solve_merge7SegtreeE(%rip), %rdx
	movslq	6160+_ZN11Solve_merge7SegtreeE(%rip), %rcx
	movl	%r12d, 6168+_ZN11Solve_merge7SegtreeE(%rip)
	movq	6232+_ZN11Solve_merge7SegtreeE(%rip), %rsi
	movl	%r12d, 6148+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	%rdx, %rcx
	movl	%ebx, 6180+_ZN11Solve_merge7SegtreeE(%rip)
	imulq	8(%rsp), %rdx
	movl	%ebx, 6160+_ZN11Solve_merge7SegtreeE(%rip)
	subq	%rcx, %rsi
	addq	%rsi, %rdx
	movq	%rdx, 6232+_ZN11Solve_merge7SegtreeE(%rip)
.L2132:
	leal	1(%rax), %esi
	cmpl	%esi, %ebp
	jl	.L2133
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$65, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%r10d, %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r11
	.cfi_def_cfa_offset 392
	popq	%rax
	.cfi_def_cfa_offset 384
.L2133:
	leaq	3072+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 128(%rsp)
	pushq	6328+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	6320+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	6312+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	6304+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	6296+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	6288+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	6280+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	6272+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	6264+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	6256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	6248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	6240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	6232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	6224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	6216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	6208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	6200+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	6192+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	6184+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	6176+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	6168+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	6160+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	pushq	6152+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 568
	pushq	6144+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm6
	movdqu	352(%rsp), %xmm7
	movdqu	368(%rsp), %xmm0
	movdqu	384(%rsp), %xmm1
	movaps	%xmm6, 3072+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	400(%rsp), %xmm6
	movaps	%xmm7, 3088+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm7
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm0, 3104+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm1, 3120+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm6, 3136+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm7, 3152+_ZN11Solve_merge7SegtreeE(%rip)
.L2130:
	movl	104(%rsp), %eax
	cmpl	%eax, %ebp
	jl	.L2134
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$33, %ecx
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	136(%rsp), %edx
	movl	%eax, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%r9
	.cfi_def_cfa_offset 392
	popq	%r10
	.cfi_def_cfa_offset 384
.L2134:
	leaq	1536+_ZN11Solve_merge7SegtreeE(%rip), %rax
	movq	%r14, %rdi
	movq	%rax, 120(%rsp)
	pushq	3256+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 392
	pushq	3248+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 400
	pushq	3240+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 408
	pushq	3232+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 416
	pushq	3224+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 424
	pushq	3216+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 432
	pushq	3208+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 440
	pushq	3200+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 448
	pushq	3192+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 456
	pushq	3184+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 464
	pushq	3176+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 472
	pushq	3168+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 480
	pushq	3160+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 488
	pushq	3152+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 496
	pushq	3144+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 504
	pushq	3136+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 512
	pushq	3128+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 520
	pushq	3120+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 528
	pushq	3112+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 536
	pushq	3104+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 544
	pushq	3096+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 552
	pushq	3088+_ZN11Solve_merge7SegtreeE(%rip)
	.cfi_def_cfa_offset 560
	movq	304(%rsp), %rax
	pushq	8(%rax)
	.cfi_def_cfa_offset 568
	pushq	(%rax)
	.cfi_def_cfa_offset 576
	call	_ZN11Solve_mergeplENS_4nodeES0_
	movdqu	336(%rsp), %xmm0
	movdqu	352(%rsp), %xmm1
	movdqu	368(%rsp), %xmm2
	movdqu	384(%rsp), %xmm3
	movdqu	400(%rsp), %xmm4
	movaps	%xmm0, 1536+_ZN11Solve_merge7SegtreeE(%rip)
	movdqu	416(%rsp), %xmm5
	addq	$192, %rsp
	.cfi_def_cfa_offset 384
	movaps	%xmm1, 1552+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm2, 1568+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm3, 1584+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm4, 1600+_ZN11Solve_merge7SegtreeE(%rip)
	movaps	%xmm5, 1616+_ZN11Solve_merge7SegtreeE(%rip)
	jmp	.L2128
.L2131:
	movl	%eax, %edx
	movl	%ebp, %r9d
	movl	$1, %r8d
	movl	$64, %ecx
	movl	%r10d, 140(%rsp)
	movl	$1, %esi
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	%rbx
	.cfi_def_cfa_offset 392
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	%eax, 144(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rax
	.cfi_def_cfa_offset 392
	popq	%rdx
	.cfi_def_cfa_offset 384
	movl	140(%rsp), %r10d
	movl	128(%rsp), %eax
	jmp	.L2132
.L2136:
	pushq	%rbx
	.cfi_def_cfa_offset 392
	movl	$1, %r8d
	movl	%eax, %edx
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	pushq	%r12
	.cfi_def_cfa_offset 400
	movl	104(%rsp), %esi
	movl	%ebp, %r9d
	movl	$68, %ecx
	movl	%eax, 144(%rsp)
	call	_ZN11Solve_merge2ST10update_MinEiiiiiii.part.0
	popq	%rdi
	.cfi_def_cfa_offset 392
	popq	%r8
	.cfi_def_cfa_offset 384
	movl	128(%rsp), %eax
	jmp	.L2137
.L2416:
	call	__stack_chk_fail@PLT
.L2243:
	endbr64
	movq	%rax, %rbp
	jmp	.L2219
	.section	.gcc_except_table
.LLSDA3578:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE3578-.LLSDACSB3578
.LLSDACSB3578:
	.uleb128 .LEHB2-.LFB3578
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L2243-.LFB3578
	.uleb128 0
.LLSDACSE3578:
	.text
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC3578
	.type	_ZN11Solve_merge5solveEv.cold, @function
_ZN11Solve_merge5solveEv.cold:
.LFSB3578:
.L2219:
	.cfi_def_cfa_offset 384
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	288(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L2220
	call	_ZdlPv@PLT
.L2220:
	movq	256(%rsp), %rdi
	testq	%rdi, %rdi
	je	.L2221
	call	_ZdlPv@PLT
.L2221:
	movq	%rbp, %rdi
.LEHB3:
	call	_Unwind_Resume@PLT
.LEHE3:
	.cfi_endproc
.LFE3578:
	.section	.gcc_except_table
.LLSDAC3578:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC3578-.LLSDACSBC3578
.LLSDACSBC3578:
	.uleb128 .LEHB3-.LCOLDB2
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSEC3578:
	.section	.text.unlikely
	.text
	.size	_ZN11Solve_merge5solveEv, .-_ZN11Solve_merge5solveEv
	.section	.text.unlikely
	.size	_ZN11Solve_merge5solveEv.cold, .-_ZN11Solve_merge5solveEv.cold
.LCOLDE2:
	.text
.LHOTE2:
	.p2align 4
	.globl	_Z5solvev
	.type	_Z5solvev, @function
_Z5solvev:
.LFB3596:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leaq	n(%rip), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	_ZNSirsERi@PLT
	movl	n(%rip), %edx
	testl	%edx, %edx
	jle	.L2453
	leaq	4+p(%rip), %rbp
	movl	$1, %ebx
	leaq	_ZSt3cin(%rip), %r12
	.p2align 4,,10
	.p2align 3
.L2454:
	movq	%rbp, %rsi
	movq	%r12, %rdi
	addl	$1, %ebx
	addq	$4, %rbp
	call	_ZNSirsERi@PLT
	cmpl	%ebx, n(%rip)
	jge	.L2454
.L2453:
	call	_ZN10Solve_left5solveEv
	leaq	7(%rsp), %rbp
	call	_ZN11Solve_right5solveEv
	call	_ZN11Solve_merge5solveEv
	movslq	n(%rip), %rax
	leaq	_ZSt4cout(%rip), %rdi
	leal	1(%rax), %esi
	movslq	%esi, %rsi
	imulq	%rax, %rsi
	movq	%rsi, %rax
	shrq	$63, %rax
	addq	%rax, %rsi
	sarq	%rsi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$32, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movl	n(%rip), %eax
	testl	%eax, %eax
	jle	.L2455
	movl	$1, %ebx
	leaq	-8+_ZN10Solve_left3resE(%rip), %r14
	leaq	8+_ZN11Solve_right3resE(%rip), %r15
	leaq	_ZN11Solve_merge3resE(%rip), %r13
	leaq	_ZSt4cout(%rip), %r12
	.p2align 4,,10
	.p2align 3
.L2456:
	movq	(%r15,%rbx,8), %rsi
	movq	%r12, %rdi
	addq	(%r14,%rbx,8), %rsi
	addq	0(%r13,%rbx,8), %rsi
	addq	$1, %rbx
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$32, 7(%rsp)
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	cmpl	%ebx, n(%rip)
	jge	.L2456
.L2455:
	movl	$1, %edx
	movq	%rbp, %rsi
	movb	$10, 7(%rsp)
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L2461
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L2461:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE3596:
	.size	_Z5solvev, .-_Z5solvev
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB3597:
	.cfi_startproc
	endbr64
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	xorl	%edi, %edi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	_ZNSt8ios_base15sync_with_stdioEb@PLT
	leaq	4(%rsp), %rsi
	leaq	_ZSt3cin(%rip), %rdi
	movl	$1, 4(%rsp)
	movq	$0, 232+_ZSt3cin(%rip)
	movq	$0, 224+_ZSt4cout(%rip)
	call	_ZNSirsERi@PLT
	jmp	.L2471
	.p2align 4,,10
	.p2align 3
.L2472:
	call	_Z5solvev
.L2471:
	movl	4(%rsp), %eax
	leal	-1(%rax), %edx
	movl	%edx, 4(%rsp)
	testl	%eax, %eax
	jne	.L2472
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L2473
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L2473:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE3597:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I__Z5powerii, @function
_GLOBAL__sub_I__Z5powerii:
.LFB4257:
	.cfi_startproc
	endbr64
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	call	__cxa_atexit@PLT
	leaq	_ZN10Solve_left7SegtreeE(%rip), %rax
	leaq	24000240(%rax), %rdx
	.p2align 4,,10
	.p2align 3
.L2475:
	movl	$0, (%rax)
	addq	$12, %rax
	movl	$0, -8(%rax)
	movl	$0, -4(%rax)
	cmpq	%rdx, %rax
	jne	.L2475
	movq	$0, 4000040+_ZN11Solve_right3dsuE(%rip)
	leaq	_ZN11Solve_merge7SegtreeE(%rip), %rdi
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	jmp	_ZN11Solve_merge2STC1Ev
	.cfi_endproc
.LFE4257:
	.size	_GLOBAL__sub_I__Z5powerii, .-_GLOBAL__sub_I__Z5powerii
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__Z5powerii
	.globl	_ZN11Solve_merge2szE
	.bss
	.align 4
	.type	_ZN11Solve_merge2szE, @object
	.size	_ZN11Solve_merge2szE, 4
_ZN11Solve_merge2szE:
	.zero	4
	.globl	_ZN11Solve_merge2stE
	.align 32
	.type	_ZN11Solve_merge2stE, @object
	.size	_ZN11Solve_merge2stE, 2000020
_ZN11Solve_merge2stE:
	.zero	2000020
	.globl	_ZN11Solve_merge3resE
	.align 32
	.type	_ZN11Solve_merge3resE, @object
	.size	_ZN11Solve_merge3resE, 4000040
_ZN11Solve_merge3resE:
	.zero	4000040
	.globl	_ZN11Solve_merge7SegtreeE
	.align 32
	.type	_ZN11Solve_merge7SegtreeE, @object
	.size	_ZN11Solve_merge7SegtreeE, 192001920
_ZN11Solve_merge7SegtreeE:
	.zero	192001920
	.globl	_ZN11Solve_merge6SparseE
	.align 32
	.type	_ZN11Solve_merge6SparseE, @object
	.size	_ZN11Solve_merge6SparseE, 102001020
_ZN11Solve_merge6SparseE:
	.zero	102001020
	.globl	_ZN11Solve_merge3BitE
	.align 32
	.type	_ZN11Solve_merge3BitE, @object
	.size	_ZN11Solve_merge3BitE, 6000060
_ZN11Solve_merge3BitE:
	.zero	6000060
	.globl	_ZN11Solve_right3resE
	.align 32
	.type	_ZN11Solve_right3resE, @object
	.size	_ZN11Solve_right3resE, 4000040
_ZN11Solve_right3resE:
	.zero	4000040
	.globl	_ZN11Solve_right3dsuE
	.align 32
	.type	_ZN11Solve_right3dsuE, @object
	.size	_ZN11Solve_right3dsuE, 4000048
_ZN11Solve_right3dsuE:
	.zero	4000048
	.globl	_ZN10Solve_left3resE
	.align 32
	.type	_ZN10Solve_left3resE, @object
	.size	_ZN10Solve_left3resE, 4000040
_ZN10Solve_left3resE:
	.zero	4000040
	.globl	_ZN10Solve_left7SegtreeE
	.align 32
	.type	_ZN10Solve_left7SegtreeE, @object
	.size	_ZN10Solve_left7SegtreeE, 24000240
_ZN10Solve_left7SegtreeE:
	.zero	24000240
	.globl	p
	.align 32
	.type	p, @object
	.size	p, 2000020
p:
	.zero	2000020
	.globl	n
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.zero	4
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:

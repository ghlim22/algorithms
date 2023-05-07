	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$544, %rsp              ## imm = 0x220
	xorl	%esi, %esi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -532(%rbp)
	leaq	-528(%rbp), %rax
	movq	%rax, %rdi
	movl	$512, %edx              ## imm = 0x200
	callq	_memset
	movl	$0, -536(%rbp)
	movl	$0, -540(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	callq	_getchar
	movl	%eax, -536(%rbp)
	cmpl	$-1, %eax
	je	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movslq	-536(%rbp), %rax
	movl	-528(%rbp,%rax,4), %ecx
	addl	$1, %ecx
	movl	%ecx, -528(%rbp,%rax,4)
	jmp	LBB0_1
LBB0_3:
	movl	$0, -544(%rbp)
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$128, -544(%rbp)
	jge	LBB0_9
## %bb.5:                               ##   in Loop: Header=BB0_4 Depth=1
	movslq	-544(%rbp), %rax
	cmpl	$0, -528(%rbp,%rax,4)
	je	LBB0_7
## %bb.6:                               ##   in Loop: Header=BB0_4 Depth=1
	movslq	-544(%rbp), %rax
	movl	-528(%rbp,%rax,4), %edi
	callq	_push
LBB0_7:                                 ##   in Loop: Header=BB0_4 Depth=1
	jmp	LBB0_8
LBB0_8:                                 ##   in Loop: Header=BB0_4 Depth=1
	movl	-544(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -544(%rbp)
	jmp	LBB0_4
LBB0_9:
	jmp	LBB0_10
LBB0_10:                                ## =>This Inner Loop Header: Depth=1
	callq	_is_empty
	cmpl	$0, %eax
	setne	%cl
	xorb	$-1, %cl
	testb	$1, %cl
	jne	LBB0_11
	jmp	LBB0_12
LBB0_11:                                ##   in Loop: Header=BB0_10 Depth=1
	callq	_pop
	movl	_rear(%rip), %edx
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	jmp	LBB0_10
LBB0_12:
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	LBB0_14
## %bb.13:
	xorl	%eax, %eax
	addq	$544, %rsp              ## imm = 0x220
	popq	%rbp
	retq
LBB0_14:
	callq	___stack_chk_fail
	ud2
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function push
_push:                                  ## @push
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	_rear(%rip), %ecx
	movl	%ecx, %edx
	addl	$1, %edx
	movl	%edx, _rear(%rip)
	movslq	%ecx, %rsi
	leaq	_min_heap(%rip), %r8
	movl	%eax, (%r8,%rsi,4)
	movl	_rear(%rip), %eax
	subl	$1, %eax
	movl	%eax, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	cmpl	$1, -8(%rbp)
	movb	%al, -9(%rbp)           ## 1-byte Spill
	jle	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	cltd
	movl	$2, %ecx
	idivl	%ecx
	movslq	%eax, %rsi
	leaq	_min_heap(%rip), %rdi
	movl	(%rdi,%rsi,4), %eax
	movslq	-8(%rbp), %rsi
	cmpl	(%rdi,%rsi,4), %eax
	setge	%r8b
	movb	%r8b, -9(%rbp)          ## 1-byte Spill
LBB1_3:                                 ##   in Loop: Header=BB1_1 Depth=1
	movb	-9(%rbp), %al           ## 1-byte Reload
	testb	$1, %al
	jne	LBB1_4
	jmp	LBB1_5
LBB1_4:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	cltd
	movl	$2, %ecx
	idivl	%ecx
	movslq	%eax, %rsi
	shlq	$2, %rsi
	leaq	_min_heap(%rip), %rdi
	movq	%rdi, %r8
	addq	%rsi, %r8
	movslq	-8(%rbp), %rsi
	shlq	$2, %rsi
	addq	%rsi, %rdi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%r8, %rdi
	movq	-24(%rbp), %rsi         ## 8-byte Reload
	callq	_swap
	movl	-8(%rbp), %eax
	cltd
	movl	$2, %ecx
	idivl	%ecx
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_5:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function is_empty
_is_empty:                              ## @is_empty
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	cmpl	$2, _rear(%rip)
	setl	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function pop
_pop:                                   ## @pop
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	cmpl	$1, _rear(%rip)
	jg	LBB3_2
## %bb.1:
	movl	$-1, -4(%rbp)
	jmp	LBB3_12
LBB3_2:
	movl	_min_heap+4(%rip), %eax
	movl	%eax, -12(%rbp)
	movl	_rear(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _rear(%rip)
	movslq	%eax, %rcx
	leaq	_min_heap(%rip), %rdx
	movl	(%rdx,%rcx,4), %eax
	movl	%eax, _min_heap+4(%rip)
	movl	$1, -8(%rbp)
LBB3_3:                                 ## =>This Inner Loop Header: Depth=1
	xorl	%eax, %eax
                                        ## kill: def $al killed $al killed $eax
	movl	-8(%rbp), %ecx
	shll	$1, %ecx
	movl	_rear(%rip), %edx
	subl	$1, %edx
	cmpl	%edx, %ecx
	movb	%al, -13(%rbp)          ## 1-byte Spill
	jge	LBB3_5
## %bb.4:                               ##   in Loop: Header=BB3_3 Depth=1
	movslq	-8(%rbp), %rax
	leaq	_min_heap(%rip), %rcx
	movl	(%rcx,%rax,4), %edx
	movl	-8(%rbp), %esi
	shll	$1, %esi
	movslq	%esi, %rax
	cmpl	(%rcx,%rax,4), %edx
	setg	%dil
	movb	%dil, -13(%rbp)         ## 1-byte Spill
LBB3_5:                                 ##   in Loop: Header=BB3_3 Depth=1
	movb	-13(%rbp), %al          ## 1-byte Reload
	testb	$1, %al
	jne	LBB3_6
	jmp	LBB3_11
LBB3_6:                                 ##   in Loop: Header=BB3_3 Depth=1
	movl	-8(%rbp), %eax
	shll	$1, %eax
	addl	$1, %eax
	movl	_rear(%rip), %ecx
	subl	$1, %ecx
	cmpl	%ecx, %eax
	jge	LBB3_9
## %bb.7:                               ##   in Loop: Header=BB3_3 Depth=1
	movl	-8(%rbp), %eax
	shll	$1, %eax
	movslq	%eax, %rcx
	leaq	_min_heap(%rip), %rdx
	movl	(%rdx,%rcx,4), %eax
	movl	-8(%rbp), %esi
	shll	$1, %esi
	addl	$1, %esi
	movslq	%esi, %rcx
	cmpl	(%rdx,%rcx,4), %eax
	jle	LBB3_9
## %bb.8:                               ##   in Loop: Header=BB3_3 Depth=1
	movslq	-8(%rbp), %rax
	shlq	$2, %rax
	leaq	_min_heap(%rip), %rcx
	movq	%rcx, %rdx
	addq	%rax, %rdx
	movl	-8(%rbp), %esi
	shll	$1, %esi
	addl	$1, %esi
	movslq	%esi, %rax
	shlq	$2, %rax
	addq	%rax, %rcx
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	callq	_swap
	movl	-8(%rbp), %r8d
	shll	$1, %r8d
	addl	$1, %r8d
	movl	%r8d, -8(%rbp)
	jmp	LBB3_10
LBB3_9:                                 ##   in Loop: Header=BB3_3 Depth=1
	movslq	-8(%rbp), %rax
	shlq	$2, %rax
	leaq	_min_heap(%rip), %rcx
	movq	%rcx, %rdx
	addq	%rax, %rdx
	movl	-8(%rbp), %esi
	shll	$1, %esi
	movslq	%esi, %rax
	shlq	$2, %rax
	addq	%rax, %rcx
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	callq	_swap
	movl	-8(%rbp), %r8d
	shll	$1, %r8d
	movl	%r8d, -8(%rbp)
LBB3_10:                                ##   in Loop: Header=BB3_3 Depth=1
	jmp	LBB3_3
LBB3_11:
	movl	-12(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB3_12:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.p2align	4, 0x90         ## -- Begin function swap
_swap:                                  ## @swap
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %ecx
	movl	%ecx, -20(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, (%rax)
	movl	-20(%rbp), %ecx
	movq	-16(%rbp), %rax
	movl	%ecx, (%rax)
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d, rear: %d\n"

	.section	__DATA,__data
	.p2align	2               ## @rear
_rear:
	.long	1                       ## 0x1

.zerofill __DATA,__bss,_min_heap,1024,4 ## @min_heap
.subsections_via_symbols

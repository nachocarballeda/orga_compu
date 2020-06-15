	.file	1 "merge_sort_c.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.rdata
	.align	2
$LC0:
	.ascii	"Error in malloc\012\000"
	.text
	.align	2
	.globl	merge_sort
	.set	nomips16
	.set	nomicromips
	.ent	merge_sort
	.type	merge_sort, @function
merge_sort:
	.frame	$fp,64,$31		# vars= 32, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.cpload	$25
	.set	nomacro
	addiu	$sp,$sp,-64
	sw	$31,60($sp)
	sw	$fp,56($sp)
	move	$fp,$sp
	.cprestore	16
	sw	$4,64($fp)
	sw	$5,68($fp)
	lw	$2,68($fp)
	sltu	$2,$2,2
	bne	$2,$0,$L17
	nop

	lw	$2,68($fp)
	srl	$2,$2,1
	sw	$2,44($fp)
	lw	$2,44($fp)
	sll	$2,$2,2
	move	$4,$2
	lw	$2,%call16(malloc)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,malloc
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,48($fp)
	lw	$2,48($fp)
	bne	$2,$0,$L3
	nop

	lw	$2,%got(stderr)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,16			# 0x10
	li	$5,1			# 0x1
	lw	$2,%got($LC0)($28)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
$L3:
	lw	$2,44($fp)
	lw	$3,68($fp)
	subu	$2,$3,$2
	sll	$2,$2,2
	move	$4,$2
	lw	$2,%call16(malloc)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,malloc
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$2,52($fp)
	lw	$2,52($fp)
	bne	$2,$0,$L4
	nop

	lw	$2,%got(stderr)($28)
	lw	$2,0($2)
	move	$7,$2
	li	$6,16			# 0x10
	li	$5,1			# 0x1
	lw	$2,%got($LC0)($28)
	addiu	$4,$2,%lo($LC0)
	lw	$2,%call16(fwrite)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,fwrite
1:	jalr	$25
	nop

	lw	$28,16($fp)
$L4:
	sw	$0,24($fp)
	b	$L5
	nop

$L6:
	lw	$2,24($fp)
	sll	$2,$2,2
	lw	$3,48($fp)
	addu	$2,$3,$2
	lw	$3,24($fp)
	sll	$3,$3,2
	lw	$4,64($fp)
	addu	$3,$4,$3
	lw	$3,0($3)
	sw	$3,0($2)
	lw	$2,24($fp)
	addiu	$2,$2,1
	sw	$2,24($fp)
$L5:
	lw	$3,24($fp)
	lw	$2,44($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L6
	nop

	lw	$2,44($fp)
	sw	$2,28($fp)
	b	$L7
	nop

$L8:
	lw	$3,28($fp)
	lw	$2,44($fp)
	subu	$2,$3,$2
	sll	$2,$2,2
	lw	$3,52($fp)
	addu	$2,$3,$2
	lw	$3,28($fp)
	sll	$3,$3,2
	lw	$4,64($fp)
	addu	$3,$4,$3
	lw	$3,0($3)
	sw	$3,0($2)
	lw	$2,28($fp)
	addiu	$2,$2,1
	sw	$2,28($fp)
$L7:
	lw	$3,28($fp)
	lw	$2,68($fp)
	sltu	$2,$3,$2
	bne	$2,$0,$L8
	nop

	lw	$2,44($fp)
	move	$5,$2
	lw	$4,48($fp)
	lw	$2,%got(merge_sort)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,merge_sort
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$2,44($fp)
	lw	$3,68($fp)
	subu	$2,$3,$2
	move	$5,$2
	lw	$4,52($fp)
	lw	$2,%got(merge_sort)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,merge_sort
1:	jalr	$25
	nop

	lw	$28,16($fp)
	sw	$0,32($fp)
	sw	$0,36($fp)
	sw	$0,40($fp)
	b	$L9
	nop

$L12:
	lw	$2,32($fp)
	sll	$2,$2,2
	lw	$3,48($fp)
	addu	$2,$3,$2
	lw	$3,0($2)
	lw	$2,36($fp)
	sll	$2,$2,2
	lw	$4,52($fp)
	addu	$2,$4,$2
	lw	$2,0($2)
	slt	$2,$3,$2
	beq	$2,$0,$L10
	nop

	lw	$2,40($fp)
	addiu	$3,$2,1
	sw	$3,40($fp)
	sll	$2,$2,2
	lw	$3,64($fp)
	addu	$3,$3,$2
	lw	$2,32($fp)
	addiu	$4,$2,1
	sw	$4,32($fp)
	sll	$2,$2,2
	lw	$4,48($fp)
	addu	$2,$4,$2
	lw	$2,0($2)
	sw	$2,0($3)
	b	$L9
	nop

$L10:
	lw	$2,40($fp)
	addiu	$3,$2,1
	sw	$3,40($fp)
	sll	$2,$2,2
	lw	$3,64($fp)
	addu	$3,$3,$2
	lw	$2,36($fp)
	addiu	$4,$2,1
	sw	$4,36($fp)
	sll	$2,$2,2
	lw	$4,52($fp)
	addu	$2,$4,$2
	lw	$2,0($2)
	sw	$2,0($3)
$L9:
	lw	$3,32($fp)
	lw	$2,44($fp)
	slt	$2,$3,$2
	beq	$2,$0,$L13
	nop

	lw	$2,44($fp)
	lw	$3,68($fp)
	subu	$3,$3,$2
	lw	$2,36($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L12
	nop

	b	$L13
	nop

$L14:
	lw	$2,40($fp)
	addiu	$3,$2,1
	sw	$3,40($fp)
	sll	$2,$2,2
	lw	$3,64($fp)
	addu	$3,$3,$2
	lw	$2,32($fp)
	addiu	$4,$2,1
	sw	$4,32($fp)
	sll	$2,$2,2
	lw	$4,48($fp)
	addu	$2,$4,$2
	lw	$2,0($2)
	sw	$2,0($3)
$L13:
	lw	$3,32($fp)
	lw	$2,44($fp)
	slt	$2,$3,$2
	bne	$2,$0,$L14
	nop

	b	$L15
	nop

$L16:
	lw	$2,40($fp)
	addiu	$3,$2,1
	sw	$3,40($fp)
	sll	$2,$2,2
	lw	$3,64($fp)
	addu	$3,$3,$2
	lw	$2,36($fp)
	addiu	$4,$2,1
	sw	$4,36($fp)
	sll	$2,$2,2
	lw	$4,52($fp)
	addu	$2,$4,$2
	lw	$2,0($2)
	sw	$2,0($3)
$L15:
	lw	$2,44($fp)
	lw	$3,68($fp)
	subu	$3,$3,$2
	lw	$2,36($fp)
	sltu	$2,$2,$3
	bne	$2,$0,$L16
	nop

	lw	$4,48($fp)
	lw	$2,%call16(free)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,free
1:	jalr	$25
	nop

	lw	$28,16($fp)
	lw	$4,52($fp)
	lw	$2,%call16(free)($28)
	move	$25,$2
	.reloc	1f,R_MIPS_JALR,free
1:	jalr	$25
	nop

	lw	$28,16($fp)
$L17:
	nop
	move	$sp,$fp
	lw	$31,60($sp)
	lw	$fp,56($sp)
	addiu	$sp,$sp,64
	jr	$31
	nop

	.set	macro
	.set	reorder
	.end	merge_sort
	.size	merge_sort, .-merge_sort
	.ident	"GCC: (Debian 6.3.0-18+deb9u1) 6.3.0 20170516"

	.file   "16_n_factorial_recursion.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.text
	.align   1
	.globl   factorial
	.type    factorial, @function
factorial:
#frame size: 48
	addi  sp, sp, -48
	sd    ra, 40(sp)
	sd    s0, 32(sp)
	addi  s0, sp, 48
	mv    t2, a0
	sw    t2, -20(s0)
	li    t2, 1
	sw    t2, -24(s0)
	lw    t0, -20(s0)
	lw    t1, -24(s0)
	subw  t2, t0, t1
	sltu  t2, zero, t2
	not   t2, t2
	andi  t2, t2, 1
	sw    t2, -28(s0)
	lw    t2, -28(s0)
	beqz  t2, label1
	lw    a0, -20(s0)
	j     func_end0
	j     label2
label1:
	li    t2, 1
	sw    t2, -32(s0)
	lw    t0, -20(s0)
	lw    t1, -32(s0)
	subw  t2, t0, t1
	sw    t2, -36(s0)
	lw    a0, -36(s0)
	call  factorial
	nop
	sw    a0, -40(s0)
	lw    t0, -20(s0)
	lw    t1, -40(s0)
	mul   t2, t0, t1
	sw    t2, -44(s0)
	lw    a0, -44(s0)
	j     func_end0
label2:
func_end0:
	ld    ra, 40(sp)
	ld    s0, 32(sp)
	addi  sp, sp, 48
	jr    ra
	.size    factorial,  .-factorial
	
	.text
	.align   1
	.globl   main
	.type    main, @function
main:
#frame size: 48
	addi  sp, sp, -48
	sd    ra, 40(sp)
	sd    s0, 32(sp)
	addi  s0, sp, 48
	call  get_int
	nop
	sw    a0, -28(s0)
	lw    t2, -28(s0)
	sw    t2, -20(s0)
	li    t2, 1
	sw    t2, -32(s0)
	lw    t0, -20(s0)
	lw    t1, -32(s0)
	slt   t2, t1, t0
	sw    t2, -36(s0)
	lw    t2, -36(s0)
	beqz  t2, label3
	lw    a0, -20(s0)
	call  factorial
	nop
	sw    a0, -40(s0)
	lw    t2, -40(s0)
	sw    t2, -24(s0)
	j     label4
label3:
	li    t2, 1
	sw    t2, -44(s0)
	lw    t2, -44(s0)
	sw    t2, -24(s0)
label4:
	lw    a0, -24(s0)
	call  print_int
	nop
	li    t2, 0
	sw    t2, -48(s0)
	lw    a0, -48(s0)
	j     func_end1
func_end1:
	ld    ra, 40(sp)
	ld    s0, 32(sp)
	addi  sp, sp, 48
	jr    ra
	.size    main,  .-main

	.file   "14_while_const.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.text
	.align   1
	.globl   main
	.type    main, @function
main:
#frame size: 64
	addi  sp, sp, -64
	sd    ra, 56(sp)
	sd    s0, 48(sp)
	addi  s0, sp, 64
	li    t2, 4
	sw    t2, -20(s0)
	li    t2, 0
	sw    t2, -24(s0)
	call  get_int
	nop
	sw    a0, -32(s0)
	lw    t2, -32(s0)
	sw    t2, -28(s0)
label1:
	lw    t0, -24(s0)
	lw    t1, -20(s0)
	slt   t2, t0, t1
	sw    t2, -36(s0)
	lw    t2, -36(s0)
	beqz  t2, label2
	li    t2, 1
	sw    t2, -40(s0)
	lw    t0, -24(s0)
	lw    t1, -40(s0)
	addw  t2, t0, t1
	sw    t2, -44(s0)
	lw    t2, -44(s0)
	sw    t2, -24(s0)
	li    t2, 1
	sw    t2, -48(s0)
	lw    t0, -28(s0)
	lw    t1, -48(s0)
	addw  t2, t0, t1
	sw    t2, -52(s0)
	lw    t2, -52(s0)
	sw    t2, -28(s0)
	lw    a0, -28(s0)
	call  print_int
	nop
	j     label1
label2:
	li    t2, 0
	sw    t2, -56(s0)
	lw    a0, -56(s0)
	j     func_end0
func_end0:
	ld    ra, 56(sp)
	ld    s0, 48(sp)
	addi  sp, sp, 64
	jr    ra
	.size    main,  .-main

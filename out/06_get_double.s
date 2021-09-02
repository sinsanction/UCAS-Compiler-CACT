	.file   "06_get_double.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
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
	call  get_double
	nop
	fsd     fa0, -32(s0)
	fld     ft2, -32(s0)
	fsd     ft2, -24(s0)
	fld     fa0, -24(s0)
	call  print_double
	nop
	li    t2, 0
	sw    t2, -36(s0)
	lw    a0, -36(s0)
	j     func_end0
func_end0:
	ld    ra, 40(sp)
	ld    s0, 32(sp)
	addi  sp, sp, 48
	jr    ra
	.size    main,  .-main

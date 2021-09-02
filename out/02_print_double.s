	.file   "02_print_double.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.text
	.align   1
	.globl   main
	.type    main, @function
main:
#frame size: 32
	addi  sp, sp, -32
	sd    ra, 24(sp)
	sd    s0, 16(sp)
	addi  s0, sp, 32
	lui   a5, %hi(.LC0)
	fld     ft2, %lo(.LC0)(a5)
	.section .rodata
	.align   3
.LC0:
	.word    858993459
	.word    1074475827
	.text
	fsd     ft2, -24(s0)
	fld     fa0, -24(s0)
	call  print_double
	nop
	li    t2, 0
	sw    t2, -28(s0)
	lw    a0, -28(s0)
	j     func_end0
func_end0:
	ld    ra, 24(sp)
	ld    s0, 16(sp)
	addi  sp, sp, 32
	jr    ra
	.size    main,  .-main

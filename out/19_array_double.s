	.file   "19_array_double.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.globl   double_array_a
	.section .sdata, "aw"
	.align   3
	.type    double_array_a, @object
	.size    double_array_a, 48
double_array_a:
	.word    858993459
	.word    1072902963
	.word    1717986918
	.word    1073899110
	.word    858993459
	.word    1074475827
	.word    0
	.word    1074921472
	.word    1717986918
	.word    1075209830
	.word    -858993459
	.word    1075498188
	
	.globl   double_array_b
	.section .sdata, "aw"
	.align   3
	.type    double_array_b, @object
	.size    double_array_b, 48
double_array_b:
	.word    858993459
	.word    1075786547
	.word    -858993459
	.word    1075956940
	.word    858993459
	.word    1075983155
	.word    1717986918
	.word    1076127334
	.word    -1717986918
	.word    1076271513
	.word    -858993459
	.word    1076415692
	
	.globl   n
	.section .srodata, "a"
	.align   2
	.type    n, @object
	.size    n, 4
n:
	.word    6
	
	.text
	.align   1
	.globl   double_array_add
	.type    double_array_add, @function
double_array_add:
#frame size: 128
	addi  sp, sp, -128
	sd    ra, 120(sp)
	sd    s0, 112(sp)
	addi  s0, sp, 128
	li    t2, 0
	sw    t2, -68(s0)
label1:
	lw    t0, -68(s0)
	lui   t5, %hi(n)
	lw    t1, %lo(n)(t5)
	slt   t2, t0, t1
	sw    t2, -72(s0)
	lw    t2, -72(s0)
	beqz  t2, label2
	lw    t1, -68(s0)
	mv    t5,t1
	slliw t5, t5, 3
	add   s2, s0, t5
	fld     ft2, -64(s2)
	fsd     ft2, -80(s0)
	lw    t1, -68(s0)
	mv    t5,t1
	slliw t5, t5, 3
	lui   s2, %hi(double_array_a)
	addi  s2, s2, %lo(double_array_a)
	add   s3, s2, t5
	fld     ft2, 0(s3)
	fsd     ft2, -88(s0)
	lw    t1, -68(s0)
	mv    t5,t1
	slliw t5, t5, 3
	lui   s2, %hi(double_array_b)
	addi  s2, s2, %lo(double_array_b)
	add   s3, s2, t5
	fld     ft2, 0(s3)
	fsd     ft2, -96(s0)
	fld     ft0, -88(s0)
	fld     ft1, -96(s0)
	fadd.d  ft2, ft0, ft1
	fsd     ft2, -104(s0)
	lw    t2, -104(s0)
	lw    t4, -68(s0)
	mv    t5,t4
	slliw t5, t5, 3
	add   s2, s0, t5
	fsd     ft2, -64(s2)
	lw    t1, -68(s0)
	mv    t5,t1
	slliw t5, t5, 3
	add   s2, s0, t5
	fld     ft2, -64(s2)
	fsd     ft2, -112(s0)
	fld     fa0, -112(s0)
	call  print_double
	nop
	li    t2, 1
	sw    t2, -116(s0)
	lw    t0, -68(s0)
	lw    t1, -116(s0)
	addw  t2, t0, t1
	sw    t2, -120(s0)
	lw    t2, -120(s0)
	sw    t2, -68(s0)
	j     label1
label2:
	j     func_end0
func_end0:
	ld    ra, 120(sp)
	ld    s0, 112(sp)
	addi  sp, sp, 128
	jr    ra
	.size    double_array_add,  .-double_array_add
	
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
	call  double_array_add
	nop
	li    t2, 0
	sw    t2, -20(s0)
	lw    a0, -20(s0)
	j     func_end1
func_end1:
	ld    ra, 24(sp)
	ld    s0, 16(sp)
	addi  sp, sp, 32
	jr    ra
	.size    main,  .-main

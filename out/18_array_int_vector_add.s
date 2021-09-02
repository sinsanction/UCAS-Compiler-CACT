	.file   "18_array_int_vector_add.cact"
	.option nopic
	.attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	
	.globl   int_array_a
	.data
	.align   3
	.type    int_array_a, @object
	.size    int_array_a, 24
int_array_a:
	.word    1
	.word    2
	.word    3
	.word    4
	.word    5
	.word    6
	
	.globl   int_array_b
	.data
	.align   3
	.type    int_array_b, @object
	.size    int_array_b, 24
int_array_b:
	.word    7
	.word    8
	.word    9
	.word    10
	.word    11
	.word    12
	
	.globl   n
	.section .srodata, "a"
	.align   2
	.type    n, @object
	.size    n, 4
n:
	.word    6
	
	.text
	.align   1
	.globl   int_array_vector_add
	.type    int_array_vector_add, @function
int_array_vector_add:
#frame size: 80
	addi  sp, sp, -80
	sd    ra, 72(sp)
	sd    s0, 64(sp)
	addi  s0, sp, 80
	li    t4, 0
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t4, 1
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t4, 2
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t4, 3
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t4, 4
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t4, 5
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_a)
	addi  s2, s2, %lo(int_array_a)
	add   s3, s2, t5
	lw    t1, 0(s3)
	mv    t5,t4
	slliw t5, t5, 2
	lui   s2, %hi(int_array_b)
	addi  s2, s2, %lo(int_array_b)
	add   s3, s2, t5
	lw    t2, 0(s3)
	addw  t3, t1, t2
	mv    t5,t4
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t3, -64(s2)
	li    t3, 0
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t3, 1
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t3, 2
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t3, 3
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t3, 4
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t3, 5
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-64(s2)
	mv    t5,t3
	slliw t5, t5, 2
	add   s2, s0, t5
	sw    t2, -40(s2)
	li    t2, 5
	sw    t2, -68(s0)
	lw    t1, -68(s0)
	mv    t5,t1
	slliw t5, t5, 2
	add   s2, s0, t5
	lw    t2,-40(s2)
	sw    t2, -72(s0)
	lw    a0, -72(s0)
	call  print_int
	nop
	j     func_end0
func_end0:
	ld    ra, 72(sp)
	ld    s0, 64(sp)
	addi  sp, sp, 80
	jr    ra
	.size    int_array_vector_add,  .-int_array_vector_add
	
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
	call  int_array_vector_add
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

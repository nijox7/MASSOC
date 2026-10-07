.global main
main:
	li a0, 5
	nop
	li a1, 10
	nop
	slli a0, a0, 1
	nop
	beq a0, a1, op_success
	nop
	j _good
op_success:
	j _bad

.global main
main:
	li a0, 5
	li a1, 10
	slli a0, a0, 1
	beq a0, a1, op_success
	j _good
op_success:
	j _bad

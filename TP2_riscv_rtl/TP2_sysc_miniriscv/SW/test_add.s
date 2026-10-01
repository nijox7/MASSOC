.global main
main:
	addi x0, x0, 1
	addi a0, a0, 1
	add  x0, a0, x0
	beq  x0, a0, fail_add
	j _good
fail_add:
	j _bad

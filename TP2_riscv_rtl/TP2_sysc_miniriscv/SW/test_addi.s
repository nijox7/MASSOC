.global main
main:
	li a0, 4
	nop
	li a1, 1
	nop
	li a2, 2
	nop
	add  a1, a1, a2
        nop
	beq  a0, a1, add_success
	nop
	j _bad
add_success:
	j _good

.global main
main:
	li a0, 4
	li a1, 1
	li a2, 2
	add  a1, a1, a2
        beq  a0, a1, add_success
	j _bad
add_success:
	j _good

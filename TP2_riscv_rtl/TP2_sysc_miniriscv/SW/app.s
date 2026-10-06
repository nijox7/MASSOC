.global main
main:
	addi a1, a1, 3  ; a1 = 3
	addi x0, x0, 1  ; x0 = 1
	addi a0, a0, 2  ; a0 = 2
	add  x0, a0, x0 ; x0 = 1 + 2 
	beq  a1, x0, add_success
	j _bad
add_success:
	j _good

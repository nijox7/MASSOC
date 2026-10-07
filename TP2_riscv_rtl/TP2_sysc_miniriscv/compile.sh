MASSOC_TP2_APP_VAR="test_addi.s"
source ./systemc-env.sh
make clean && make -j
riscv32-unknown-elf-gcc -nostdlib -c SW/reset.s -o reset.o -march=rv32imc
riscv32-unknown-elf-gcc -nostdlib -c SW/$MASSOC_TP2_APP_VAR -o app.o -march=rv32imc
riscv32-unknown-elf-gcc -nostdlib reset.o app.o -T SW/link.ld -o app -march=rv32imc
riscv32-unknown-elf-objdump -d app > app.txt

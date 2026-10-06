# MASSOC - Compte-rendu TP2

## Comprendre le Minirsicv

- *run.exe* est l'exécutable du processeur décrit en SystemC.\
- *app* est l'application compilée en assembleur.

### Mise en place

Compiler:
>>
    $ source ./systemc-env.sh
    make clean && make -j
    riscv32-unknown-elf-gcc -nostdlib -c SW/reset.s -o reset.o -march=rv32imc
    riscv32-unknown-elf-gcc -nostdlib -c SW/app.s -o app.o -march=rv32imc
    riscv32-unknown-elf-gcc -nostdlib reset.o app.o -T SW/link.ld -o app -march=rv32imc

Tester l'application:
>>
    $ ./run.exe app

Observer le contenu du programme compilé:
>>
    $ riscv32-unknown-elf-objdump -d app > app.txt

### Fichier test et observation GTK-WAVE
On compile puis on exécutre l'application:
>>
    $ ./compile.sh
    $ ./run.exe app

On observe ce résultat:
>>
    
    SystemC 2.3.4-Accellera --- Aug 16 2026 17:50:15
    Copyright (c) 1996-2022 by all Contributors,
    ALL RIGHTS RESERVED
    Receiving file app, starting parsing and reading
    Chargement du segment .text.reset adr = 0x   10050, total size : 0x18
    Chargement du segment .text adr = 0x   10068, total size : 0x4
    Found _good at : 0x   10060
    Found _bad at : 0x   10064
    Number of Instruction : 0
    Reseting...
    Info: (I702) default timescale unit used for tracing: 1 ps (tf.vcd)
    done.
    Test ended at 10084
    signature_name :
    begin_signature :6
    end_signature :0
    $

Le processeur charge les segments de texte, ne trouve aucun instruction, puis exécute le programme de *reset.s*. 

### Test de l'instruction addi

On crée l'application suivante:
>>
    .global main
    main:
            addi x0, x0, 1
            addi a0, a0, 1
            add  x0, a0, x0
            beq  x0, a0, fail_add
            j _good
    fail_add:
            j _bad
# Compte-rendu

2 + 3

 10
 11
=
101

sum = 0 ^ 1 = 1
carry = 0 & 1 = 0

sum = 1 ^ 1 = 0
carry = 1 & 1 = 1


## Adder
## Filtre FIR
Utiliser des *sc_fifo<int>* pour les signaux entre les fifos!

Problème lors de l'affichage avec "trace" pour GTKWave. L'exécution provoque un erreur:
        Error: (E519) wait() is only allowed in SC_THREADs and SC_CTHREADs: 
        in SC_METHODs use next_trigger() instead



## Shift register

## Notes
SC_THREAD -> processur qui s'exécute en continu (se relance tout seul indéfiniment)
SC_NS -> nanosecondes
SC_US -> microsecondes

sc_buffer -> comme sc_signal mais produit un évènement à chaque "write"
sc_fifo -> signal fifo
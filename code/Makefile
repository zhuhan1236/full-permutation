permutation: main.o
	g++ -o permutation.out main.o -O2  -DNDEBUG

main.o: main.cc lex_permutation.h des_permutation.h ins_permutation.h exc_permutation.h
	g++ -c main.cc -O2 -s -DNDEBUG

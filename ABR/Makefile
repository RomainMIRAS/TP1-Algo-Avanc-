all: test_abr test_pile test_file test_avl

abr.o: abr.c abr.h pile.h file.h
	gcc -Wall -c abr.c

avl.o: avl.c avl.h pile.h file.h
	gcc -Wall -c avl.c

pile.o: pile.h pile.c
	gcc -Wall -c pile.c

file.o: file.h file.c
	gcc -Wall -c file.c

test_abr.o: test_abr.c abr.h
	gcc -Wall -c test_abr.c

test_avl.o: test_avl.c avl.h
	gcc -Wall -c test_avl.c

test_pile.o: pile.h abr.h
	gcc -Wall -c test_pile.c

test_abr: test_abr.o pile.o file.o abr.o
	gcc -o test_abr abr.o pile.o file.o test_abr.o -lm

test_avl: test_avl.o pile.o file.o avl.o
	gcc -o test_avl avl.o pile.o file.o test_avl.o

test_pile: test_pile.o pile.o 
	gcc -o test_pile pile.o test_pile.o

test_file: test_file.o file.o
	gcc -o test_file file.o test_file.o

clean:
	rm -f *.o *~ test_abr test_avl



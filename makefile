countdown:main.o utility.o
	gcc -o countdown main.o utility.o
main.o: main.c utility.h
	gcc -c main.c
utility.o: utility.c utility.h
	gcc -c utility.c

all: main.o emulator.o memory.o register.o utility.o
	gcc -o main main.o emulator.o memory.o register.o utility.o
	
main.o: main.c emulator.h utility.h
	gcc -c main.c -o main.o
	
emulator.o: emulator.h emulator.c
	gcc -c emulator.c -o emulator.o
	
memory.o: memory.h memory.c
	gcc -c memory.c -o memory.o
	
register.o: register.h register.c
	gcc -c register.c -o register.o
	
utility.o: utility.h utility.c
	gcc -c utility.c -o utility.o

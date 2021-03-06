.PHONY: clean debug

all: main

# Establece la variable DEBUG en este objetivo y todos sus subobjetivos
debug: DEBUG = -ggdb
debug: main

main: main.o gol.o mundo.o
	gcc -std=c99 $(DEBUG) main.o gol.o mundo.o -o main.out

main.o: src/main.c src/gol.h
	gcc -std=c99 $(DEBUG) -c src/main.c

gol.o: src/gol.c src/gol.h
	gcc -std=c99 $(DEBUG) -c src/gol.c

mundo.o: src/mundo.c src/mundo.h
	gcc -std=c99 $(DEBUG) -c src/mundo.c

clean:
	rm -f *.o

valgrind: debug
	valgrind --leak-check=full ./main.out -t 10 -s 20

gdb: debug
	gdb ./main.out

CC=gcc
CFLAGS=-shared -Ofast -DFORTIFY_SOURCE=2 -pedantic -Wall
DCC=clang
DCFLAGS=-ggdb -shared -O0 -DFORTIFY_SOURCE=2 -pedantic -Wall

all:
	$(CC) $(CFLAGS) -c gdb_check.c
clean:
	rm gdb_check.o

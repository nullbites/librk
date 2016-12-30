CC=gcc
CFLAGS=-Ofast -DFORTIFY_SOURCE=2 -pedantic -Wall -shared 
DCC=clang
DCFLAGS=-O0 -DFORTIFY_SOURCE=2 -pedantic -Weverything -shared 
all:
	$(CC) $(CFLAGS) -c sepuku.c
clean:
	rm sepuku.o

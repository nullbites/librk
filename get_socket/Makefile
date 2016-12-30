CC=gcc
CFLAGS=-fPIC -Ofast -DFORTIFY_SOURCE=2 -pedantic -Wall -Wall
DCC=clang
DCFLAGS=-ggdb -fPIC -O0 -DFORTIFY_SOURCE=2 -pedantic -Wall -Weverything

all:
	$(CC) $(CFLAGS) -c get_socket.c
clean:
	rm get_socket.o

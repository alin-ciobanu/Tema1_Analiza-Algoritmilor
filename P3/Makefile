
CC=gcc
CFLAGS=-Wall -g

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) ./ocean.c -o ./ocean

run: build
	./ocean

clean:
	rm ./*.o
	clear


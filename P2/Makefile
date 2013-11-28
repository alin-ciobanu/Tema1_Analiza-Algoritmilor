
CC=gcc
CFLAGS=-Wall -g

.PHONY: build run examples pack clean

build:
	$(CC) $(CFLAGS) ./meteo.c -o ./meteo 

run: build
	./meteo

clean:
	rm ./*.o
	clear


CC = gcc
CFLAGS = -g -Wall

all: proiect

proiect: proiect.o
	$(CC) $(CFLAGS) -o proiect proiect.o -lm

proiect.o: proiect.c
	$(CC) $(CFLAGS) -c proiect.c

clean:
	rm -f proiect proiect.o

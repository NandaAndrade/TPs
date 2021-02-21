CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp5
TMPOUT=tp5.testresult

.PHONY: all build test clean

all: build test clean

build:
	$(CC) $(CFLAGS) -c src/matrix.cpp -o matrix.o
	$(CC) $(CFLAGS) src/main.cpp matrix.o -o $(EXEC)

clean:
	rm -rf matrix.o
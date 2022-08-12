CC=gcc
CFLAGS=-fno-tree-vectorize -fopenmp -Wall -Wextra

OBJSUM := $(patsubst %.c,%.o,$(wildcard src/*.c))
OBJSUMF := $(patsubst %.c,%.exec,$(wildcard src/*.c))

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: main.o matrix
	@echo "Compiled!"

%.exec: %.o
	$(CC) $(CFLAGS) -o $@ $< main.o

matrix: $(OBJSUMF)

clean:
	rm -rf main.o *.exec *.optrpt src/*.optrpt $(OBJSUM) $(OBJSUMF)


COMPILER = gcc
FLAGS = -lm -fopenmp -Wall -Wextra

all: 2-mandelbrot.exec
	@echo "Compiled!"

%.exec: %.o
	$(COMPILER) -o $@ $+ $(FLAGS)

%.o: %.c
	$(COMPILER) -o $@ -c $< $(FLAGS)

clean:
	rm -f *.o *.exec *.ppm

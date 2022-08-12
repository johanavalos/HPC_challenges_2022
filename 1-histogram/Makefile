#
# Makefile 
# Compila e gera os executáveis de todos os arquivos com extensão .c
# presentes no diretório
# mpirun --bind-to core:overload-allowed --oversubscribe -np 8 ./bin/mpi_omp_calpi
#
CC=mpicc
CFLAGS = -O3 -Wall -fopenmp 
LIBS=-lm -lgomp
RM=rm -vf
MV=mv
BINDIR=./
SRCDIR=./

vpath %.c ./

SRCFILES= $(wildcard *.c)
OBJFILES= $(patsubst %.c, %.o, $(SRCFILES))
_PROGS= $(patsubst %.c, %, $(SRCFILES))
PROGFILES=$(addprefix $(BINDIR),$(_PROGS))

.PHONY: all clean run 

all: $(PROGFILES)

$(BINDIR)%: $(SRCDIR)%.c
	$(CC) $(INC) $< $(CFLAGS) -o $@ $(LIBS)

clean:
	$(RM) $(OBJFILES) $(PROGFILES) *~
## eof Makefile

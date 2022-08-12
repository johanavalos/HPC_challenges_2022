#include <stdio.h>
#include <stdlib.h>
#include "mpi.h"
#include "omp.h"
#include <math.h>
#include <stdbool.h>


bool primo (int n) {
    int i;
    int max = (int)(sqrt(n) + 1);
    for (i = 3; i < max; i+=2)
         if (n%i == 0)
             return false;
    return true;
}


int main(int argc, char *argv[]) {

  int rank = 0, p_amnt = 1;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &p_amnt);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	int cont = 0, total = 0;
	long int i, n;
	int inicio, salto;

	if (argc < 2) {
        	printf("Valor inválido! Entre com um valor do maior inteiro\n");
       	 	return 0;
    } else {
        n = strtol(argv[1], (char **) NULL, 10);
    }

    inicio = 3 + rank;
    salto = p_amnt;
  
  #pragma omp parallel for reduction(+:cont)
	for (i = inicio; i <= n; i += salto) 
	{	
		if(primo(i)) cont += 1;
	}
  total = cont;
		
	MPI_Reduce(
    &cont,
    &total,
    1,
    MPI_INT,
    MPI_SUM,
    0,
    MPI_COMM_WORLD);
	
  total += 1;    /* Acrescenta o dois, que também é primo */
	if (rank == 0) printf("Quant. de primos entre 1 e n: %d \n", total);
 
  MPI_Finalize();

	return(0);
}


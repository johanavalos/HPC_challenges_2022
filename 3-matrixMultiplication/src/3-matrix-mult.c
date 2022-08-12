void matrix_mult(double *A, double *B, double *C, int N){
	int i, j, k;
	register double sum;

	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++){
			sum = 0;
			for(k = 0; k < N; k++)
				sum += A[i * N + k] * B[k * N + j];
			C[i * N + j] = sum;
		}
}
#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <stdlib.h>

#define	omp

int mmult(double *c, 
	  double *a, int aRows, int aCols, 
	  double *b, int bRows, int bCols);

int mmult_cache(double *c, 
	  double *a, int aRows, int aCols, 
	  double *b, int bRows, int bCols);

#ifdef omp
int mmult_omp(double *c,
		   double *a, int aRows, int aCols,
		   double *b, int bRows, int bCols);
#endif

double* gen_matrix(int n, int m);

void compare_matrices(double* a, double* b, int nRows, int nCols);

double deltaTime(struct timespec* start, struct timespec* end) {
  double delta = (end->tv_sec - start->tv_sec) + (end->tv_nsec - start->tv_nsec)/1e9;
  return delta;
}

int main(int argc, char* argv[]) {
  struct timespec start;
  struct timespec end;
  struct timespec res;
  double *a, *b, *c1, *c2, *c3;
  int n;
  double times1, times2, times3;
  if (argc > 1) {
    n = atoi(argv[1]);
    a = gen_matrix(n, n);
    b = gen_matrix(n, n);
    c1 = malloc(sizeof(double) * n * n);
    c2 = malloc(sizeof(double) * n * n);
    c3 = malloc(sizeof(double) * n * n);
    printf("matrix size %d x %d\n", n, n);
    clock_gettime(CLOCK_REALTIME, &start);
    mmult(c1, a, n, n, b, n, n);
    clock_gettime(CLOCK_REALTIME, &end);
    times1 = deltaTime(&start, &end);
    printf("time spent in function without optimization %f(sec)\n", times1);
    clock_gettime(CLOCK_REALTIME, &start);
    mmult_cache(c2, a, n, n, b, n, n);
    clock_gettime(CLOCK_REALTIME, &end);
    times2 = deltaTime(&start, &end);
    printf("time spent in function using locality %f(sec)\n", times2);
    compare_matrices(c1, c2, n, n); 
#ifdef	omp
    clock_gettime(CLOCK_REALTIME, &start);
    mmult_omp(c3, a, n, n, b, n, n);
    clock_gettime(CLOCK_REALTIME, &end);
    times3 = deltaTime(&start, &end);
    printf("time spent in function using OpenMP %f(sec)\n", times3);
    compare_matrices(c1, c3, n, n);
#endif
} else {
    fprintf(stderr, "Usage %s <n>\n", argv[0]);
  }
}


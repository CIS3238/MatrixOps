PGMS=mmult_timing #matrix_times_vector hello pi mxv_omp_mpi mmult_mpi_omp

all:	${PGMS}


mmult_timing:	mmult.o mmult_cache.o mmult_omp.o mmult_timing.o
	gcc -o mmult -fopenmp -O3 mmult.o mmult_cache.o mmult_omp.o mmult_timing.o -o mmult_timing

mmult.o:	mmult.c
	gcc -c -Og -pg mmult.c

mmult_cache.o:	mmult_cache.c
	gcc -c -Og -pg mmult_cache.c

mmult_omp.o:	mmult_omp.c
	gcc -c -Og -pg -fopenmp mmult_omp.c

mmult_timing.o:	mmult_timing.c
	gcc -c -Og -pg mmult_timing.c

clean:
	rm -f *.o
	rm -f ${PGMS}


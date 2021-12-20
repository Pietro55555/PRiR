#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h

double f(double x)
{
	return x*x;
}

int main(int argc, char **argv)
{
	int liczbaProcesow, nrProcesu, p=2, k=20, i=1;
	double metTrapezow=0,metProstokatow=0,h=0.0;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &liczbaProcesow);
	MPI_Comm_rank(MPI_COMM_WORLD, &liczbaProcesow);
	MPI_Status status;

	if(nrProcesu == liczbaProcesow-1)
    {
		metTrapezow= 0;
		metProstokatow= 0;
		h=(double)(k-p)/liczbaProcesow;
		metTrapezow=metTrapezow+f(p+i*h);
		metProstokatow=metProstokatow+f(p +i* h);
		i++;

		MPI_Send(&metTrapezow, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
		MPI_Send(&metProstokatow, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
		MPI_Send(&i, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);
		MPI_Send(&h, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
		MPI_Send(&p, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);
		MPI_Send(&k, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);

	}
	if(nrProcesu < liczbaProcesow-1 && nrProcesu >0)
    {
		MPI_Recv(&i, 1, MPI_INT, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&p, 1, MPI_INT, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&k, 1, MPI_INT, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&h, 1, MPI_DOUBLE, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&metTrapezow, 1, MPI_DOUBLE, nrProcesu+1,2, MPI_COMM_WORLD, &status);
		MPI_Recv(&metProstokatow, 1, MPI_DOUBLE, nrProcesu+1, 2, MPI_COMM_WORLD, &status);

		metTrapezow=metTrapezow+f(p+i*h);
		metProstokatow=metProstokatow+f(p +i* h);
        i++;

        MPI_Send(&metTrapezow, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
        MPI_Send(&metProstokatow, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
        MPI_Send(&i, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);
        MPI_Send(&h, 1, MPI_DOUBLE, nrProcesu-1, 2, MPI_COMM_WORLD);
        MPI_Send(&p, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);
        MPI_Send(&k, 1, MPI_INT, nrProcesu-1, 2, MPI_COMM_WORLD);
	}

	if(nrProcesu == 0)
    {
		MPI_Recv(&p, 1, MPI_INT, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&k, 1, MPI_INT, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&h, 1, MPI_DOUBLE, nrProcesu+1, 2, MPI_COMM_WORLD, &status);
		MPI_Recv(&metTrapezow, 1, MPI_DOUBLE,nrProcesu+1,2, MPI_COMM_WORLD, &status);
		MPI_Recv(&metProstokatow, 1, MPI_DOUBLE, nrProcesu+1, 2, MPI_COMM_WORLD, &status);

		metTrapezow=metTrapezow+f(p+i*h);
		metProstokatow=metProstokatow+f(p +i* h);

            printf("Zostalo wykonanyn %d procesow\n",i);
			printf("Wynik Metody Trapezow = %f\n", metTrapezow);
			metProstokatow= metProstokatow* h;
			printf("Wynik Metody prostokatów = %f\n", metProstokatow);
    }
	MPI_Finalize();
	return 0;
}

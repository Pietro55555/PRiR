#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

double Leibniz(int n, double proces)
{
    int i;
    double wynik=0;
	proces = proces/4;
    wynik=(pow(-1,(n-1))/(2*(n-1)));
    wynik+=proces;
    wynik*=4;
    return wynik;
}

int main(int argc, char *argv[])
{
	int liczbaProcesow, nrProcesu;
	double wynik = 0.0;
	MPI_Status status;
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &liczbaProcesow);
	MPI_Comm_rank(MPI_COMM_WORLD, &nrProcesu);

	if(nrProcesu==0)
	{
		MPI_Send(&wynik,1,MPI_DOUBLE,nrProcesu+1,20,MPI_COMM_WORLD);
	}
	if((nrProcesu>1)&&(nrProcesu<liczbaProcesow-1))
	{
		MPI_Recv(&wynik,1,MPI_DOUBLE,nrProcesu-1,20,MPI_COMM_WORLD,&status);
		wynik = Lebinz(nrProcesu, wynik);

		printf("| Proces nr= %d PI= %f |", nrProcesu,wynik);
		if(nrProcesu!=liczbaProcesow-1)
		{
			MPI_Send(&wynik, 1, MPI_DOUBLE, nrProcesu+1,20, MPI_COMM_WORLD);
		}
		else
		{
			printf("| Proces nr= %d (ostatni) PI= %f (ostateczne) |", nrProcesu, wynik);
		}
	}

	MPI_Finalize();
	return 0;
}

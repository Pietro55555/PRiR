#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include "err.h"

double funkcja(double x)
{
	return 4*x-6*x+5;
}

double Gauss(int a, int b, int n)
{
    double wynikCalki=0.0;
    double t=0.0;
	double wsp1,wsp2;
	int i;

    wsp1=(double)(b - a)/2;
    wsp2=(double)(b + a)/2;

        switch(n)
    	{
		case 2:
            double tab[][]={{1.0,-0.57735027}, {1.0,0.57735027}};
            break;
		case 4:
            double tab[][]={{0.65214515,-0.33998104}, {0.65214515,0.33998104},
            				{0.34785485,-0.86113631}, {0.34785485,0.86113631}};
            break;
		case 6:
            double tab[][]={{0.46791393,-0.23861918}, {0.46791393,0.23861918},
            				{0.36076157,-0.66120939}, {0.36076157,0.66120939},
            				{0.17132449,-0.93246951}, {0.17132449,0.93246951}};
            break;
		case 8:
            double tab[][]={{0.36268378,-0.18343464}, {0.36268378,0.18343464},
            				{0.31370665,-0.52553241}, {0.31370665,0.52553241},
				            {0.22238103,-0.79666648}, {0.22238103,0.79666648},
				            {0.10122854,-0.96028986}, {0.10122854,0.96028986}};
            break;
		case 10:
            double tab[][]={{0.29552422,-0.14887434}, {0.29552422,0.14887434},
				            {0.26926672,-0.43339539}, {0.26926672,0.43339539},
				            {0.21908636,-0.67940957}, {0.21908636,0.67940957},
				            {0.14945135,-0.86506337}, {0.14945135,0.86506337},
				            {0.06667134,-0.97390653}, {0.06667134,0.97390653}};
            break;

		default:
		double tab[][];
        }

    for(i=0;i<n;i++)
    {
        t=tab[i][1];
        wynikCalki+=tab[i][0]*funkcja(wsp1*t+wsp2);
    }

    return wynikCalki;
}

double Trapezow(int a, int b, int n)
{
	double wynikCalki = 0;
    double h = (double)(b-a)/n;

	int i;
    for(i=0;i<n;i++)
    {
    	wynikCalki+=t.funkcja(a+i*h)+t.funkcja(a+(i+1)*h);
	}

	return h/2 * wynikCalki;
}

int main ()
{
 pid_t pid;
 int i, p;
 int a, b, n, seed;
 time_t t;
 printf("Podaj p: ");
 scanf("%d", &p);

 for (i = 1; i <= p; i++)
    {
    switch (pid = fork())
        {
        case -1:
            perror("Error (something wrong in fork)\n");
        case 0:
		    seed = time(&t);
		    srand(seed + i);
		    n = rand()%50;
		    a = rand();
		    b = (a + 1) + rand();

		    printf("a = %d b = %d n = %d\n",a,b,n);
		    printf("Procesem potomnym PID: %d\n", getpid());
            printf("Wynik Metody Trapezow= %f\n", Trapezow(a,b,n));

			n = 1 + rand() % 10;
			printf("a = %d b = %d n = %d\n",a,b,n);
            printf("Wynik Kwadratury Gaussa Legendrea to: %f\n", Gauss(a,b,n));
            return 0;
        default:
        printf("Proces macierzysty PID: %d\n", getpid());
        }
    }

 return 0;
}

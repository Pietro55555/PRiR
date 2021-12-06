#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include "err.h"
#include <math.h>

double Leibniz(int n)
{
    int i;
    double wynik = 0;

    for(i=1;i<=n;i++)
    {
        wynik+=(pow(-1,i-1)/(2*i-1));
    }
    wynik=4*wynik;
    return wynik;
}

int main ()
{
 pid_t pid;
 int i,p,seed;
 time_t t;
 printf("Podaj p ");
 scanf("%d",&p);

 for (i=1;i<=p;i++)
{
    switch(pid=fork())
    {
        case -1:
            perror("Error (something wrong in fork)\n");
        case 0:
		    seed=time(&t);
		    srand(seed+i);
		    n=(rand()%4900)+100;
            printf("Proces potomny PID= %d\n",getpid());
            printf("Wynik= %f\n",Leibniz(n));
            return 0;
        default:
        printf("Proces macierzysty PID= %d\n",getpid());
    }
 }
 return 0;
}

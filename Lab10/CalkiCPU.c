%%cu
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>
#include <sys/time.h>

/////////////
////CPU//////
/////////////

double f(double x)
{
    return x+1+pow(x, 2)*2+pow(x,3)+3;
}

double Simpson(float a, float b, int n)
{
    float h = (b - a) / (float)(n);
    float x;
    float calka = 0;
    float s = 0;
    int i = 1;
    for (i = 1; i < n; i++)
    {
        x = a + i * h;
        calka += f(x - h / 2);
        s += f(x);
    }
    calka = (h / 6) * (f(a) + f(b) + 2 * calka + 4 * s);
    return calka;
}



double Trapezy(float a, float b, int n)
{
    float h = (b - a) / (float)n;
    float calka = 0;
    int i = 1;
    for (i = 1; i < n; i++)
        calka += f(a + i * h);
    calka += f(a) / 2;
    calka += f(b) / 2;
    calka *= h;
    return calka;
}

double Prostokoty(float a, float b, int n)
{
    float h = (b - a) / (float)n;
    float calka = 0;
    int i = 1;
    for (i = 1; i <= n; i++)
        calka += f(a + i*h);
    calka *= h;
    return calka;
}

int main()
{
    float a, b;
    int n = 10000;
    int i;
    a = 10;
    b = 200000;
    for(i = 0; i < 5; i++)
    {
        float wynik1, wynik2, wynik3;
        n *= 10;
        printf("ilosc przedzialow(n) = %d\n",n);
        struct timeval start, end;
        gettimeofday(&start, 0);
        wynik1 = Prostokoty(a, b, n);
        gettimeofday(&end, 0);
        long seconds = end.tv_sec - start.tv_sec;
        long microseconds = end.tv_usec - start.tv_usec;
        double elapsed = seconds + microseconds*1e-6;
        printf("Metoda Prostokatow = %.8f\n",elapsed);

        struct timeval start2, end2;
        gettimeofday(&start2, 0);
        wynik2 = Trapezy(a, b, n);
        gettimeofday(&end2, 0);
        long seconds2 = end2.tv_sec - start2.tv_sec;
        long microseconds2 = end2.tv_usec - start2.tv_usec;
        double elapsed2 = seconds2 + microseconds2*1e-6;
        printf("Metoda Trapezow = %.8f\n",elapsed);

        struct timeval start3, end3;
        gettimeofday(&start3, 0);
        wynik3 = Simpson(a, b, n);
        gettimeofday(&end3, 0);
        long seconds3 = end3.tv_sec - start3.tv_sec;
        long microseconds3 = end3.tv_usec - start3.tv_usec;
        double elapsed3 = seconds3 + microseconds3*1e-6;
        printf("Metoda Simpsona = %.8f\n",elapsed3);
    }
}

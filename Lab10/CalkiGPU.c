%%cu
#include <sys/time.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;

/////////////
////GPU//////
/////////////

__device__ float f(float x)
{
    return x+1+pow(x, 2)*2+pow(x,3)+3;
}


__global__ void Trapezy( float a, float h, int n, float* tab)
{
    int tid = blockIdx.x + 1;
    if(tid < n)
        tab[tid-1] = f(a + tid * h);
}

__global__ void Simpson( float a, float h, int n, float* tab, float* tab2 )
{
	int tid = blockIdx.x + 1;
    if(tid < n + 1)
    {
      tab2[tid - 1] = a + tid * h;
      tab[tid - 1] = f(a + tid * h);
    }
}
    __global__ void Prostokat( float a, float h, int n, float* tab)
{
    int tid = blockIdx.x + 1;
    if(tid < n)
        tab[tid - 1] = f(a + tid * h) * h;
}



float metodaProstokatow( float a, float b, int n)
{
    size_t size = n * sizeof(float);
    float* dev;
    float* host = (float*)malloc(size);
    float suma = 0;
    cudaMalloc((void**) &dev, size);
    float h = (b - a) / (float)n;
    Prostokat<<<n,1>>> (a, h, n, dev);
    cudaMemcpy(host, dev, sizeof(float) * n, cudaMemcpyDeviceToHost);
    for(int i = 0; i < n; i++)
        suma += host[i];
    free(host);
    cudaFree(dev);
    return suma;
}

 float f1(float x)
 {
     return x+1+pow(x, 2)*2+pow(x,3)+3 + 10;
 }

float metodaTrapezow( float a, float b, int n)
{
    size_t size = n * sizeof(float);
    float* dev;
    float* host = (float*)malloc(size);
    float suma = 0;
    cudaMalloc((void**) &dev, size);
    float h = (b - a) / (float)n;
    Trapezy<<<n,1>>> (a, h, n, dev);
    cudaMemcpy(host, dev, sizeof(float) * n, cudaMemcpyDeviceToHost);
    for(int i = 0; i < n; i++)
        suma += host[i];
    free(host);
    cudaFree(dev);
    return h*((f1(a) / 2) + suma + (f1(b) / 2));
}

float metodaSimpsona( float a, float b, int n)
{
    size_t size = n * sizeof(float);
    float* dev;
    float* host = (float*)malloc(size);
    float* dev2;
    float* host2 = (float*)malloc(size);
    float suma1 = 0 ,suma2 = 0;
    float t[n];
    cudaMalloc((void**) &dev, size);
    cudaMalloc((void**) &dev2, size);
    float h = (b - a) / (float)n;
    Simpson<<<n,1>>> (a, h, n, dev, dev2);
    cudaMemcpy(host, dev, sizeof(float)*n, cudaMemcpyDeviceToHost);
    cudaMemcpy(host2, dev2, sizeof(float)*n, cudaMemcpyDeviceToHost);

    for(int i = 0; i < n; i++)
        t[i] = f1((host2[i + 1] +host2[i]) / 2);

    for(int i = 0 ; i < n; i++)
            suma1 += t[i];

    suma1 *= 4;

    for(int i = 1 ; i < n; i++)
        suma2 += host[i];

    suma2 *= 2;
    free(host);
    free(host2);
    cudaFree(dev);
    cudaFree(dev2);
    return (f1(a) + host[n] + suma1 + suma2) * (h / 6);
}

int main()
{
    int n = 1000000000;
    int i;

    float a = 10;
    float b = 200000;
   for(i=0;i<5;i++)
   {
    n*=10;
    printf("ilosc przedzialow(n)= %d\n", n);

    auto start1 = chrono::steady_clock::now();
    float w1 = metodaProstokatow(a, b, n);
    auto end1 = chrono::steady_clock::now();
    auto diff1 = end1 - start1;
    cout<<"Metoda Prostokatow= "<<(chrono::duration <double, milli> (diff1).count()) / 1000 <<endl;

    auto start2 = chrono::steady_clock::now();
    float w2 = metodaTrapezow(a, b, n);
    auto end2 = chrono::steady_clock::now();
    auto diff2 = end2 - start2;
    cout<<"Metoda Trapezow= "<<(chrono::duration <double, milli> (diff2).count()) / 1000 <<endl;

    auto start3 = chrono::steady_clock::now();
    float w3 = metodaSimpsona(a, b, n);
    auto end3 = chrono::steady_clock::now();
    auto diff3 = end3 - start3;
    cout<<"Metoda Simpsona= "<<(chrono::duration <double, milli> (diff3).count()) / 1000 <<endl;
   }
    return 0;
}

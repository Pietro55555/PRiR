#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "mpi.h"
#define REZERWA 100

#define TOR 1
#define WJAZD 2
#define JAZDA 3
#define WYJAZD 4
#define WYPADEK 5
#define TANKUJ 300
int paliwo = 300;
int WYJEZDZAJ=1, NIE_WYJEZDZAJ=0;
int liczba_procesow;
int nr_procesu;
int ilosc_samochodow;
int ilosc_torow=4;
int ilosc_zajetych_torow=0;
int tag=1;
int wyslij[2];
int odbierz[2];
MPI_Status mpi_status;
void Wyslij(int nr_samochodow, int stan) //wyslij do lotniska swoj stan
{
wyslij[0]=nr_samochodow;
wyslij[1]=stan;
MPI_Send(&wyslij, 2, MPI_INT, 0, tag, MPI_COMM_WORLD);
sleep(1);
}
void Tor(int liczba_procesow)
{
int nr_samochodu,status;
ilosc_samochodow = liczba_procesow - 1;
printf("Witam serdecznie na torze wyœcigowym\n");


printf("Zyczymy Panstwu, przyjemnej jazdy\n \n");
printf("Dysponujemy %d wolnymi torami\n", ilosc_torow);
sleep(2);
    while(ilosc_torow<=ilosc_samochodow)
    {
        MPI_Recv(&odbierz,2,MPI_INT,MPI_ANY_SOURCE,tag,MPI_COMM_WORLD, &mpi_status);//odbieram od kogokolwiek
        nr_samochodow=odbierz[0];
        status=odbierz[1];
        if(status==1)
        {
            printf("Samochod stoi w gara¿u\n", nr_samochodow);
        }
        if(status==2)
        {
            printf("Samochod %d rusza na tor nr %d\n", nr_samochodow, ilosc_zajetych_torow);
            ilosc_zajetych_torow--;
        }
        if(status==3)
        {
            printf("Samochod %d mgnie\n", nr_samochodow);
        }
        if(status==4)
        {
            if(ilosc_zajetych_torow<ilosc_torow)
            {
                ilosc_zajetych_torow++;
                MPI_Send(&WYJEZDZAJ, 1, MPI_INT, nr_samochodow, tag, MPI_COMM_WORLD);
            }
            else
            {
                MPI_Send(&NIE_WYJEZDZAJ, 1, MPI_INT, nr_samochodow, tag, MPI_COMM_WORLD);
            }
        }
        if(status==5)
        {
            ilosc_samochodow--;
            printf("Ilosc samochodow %d\n", ilosc_samochodow);
        }
    } //zamykam while
printf("Program zakonczyl dzialanie:)\n");
}
void Samochod()
{
    int stan,suma,i;
    stan=JAZDA; //to chyba jedyny rozsadny stan z jakiego warto startowac
    while(1)
    {
        if(stan==1)
        {
            if(rand()%2==1)
            {
                stan=WJAZD;
                paliwo=TANKUJ;
                printf("Samochód nr %d chce wjechac na tor\n",nr_procesu);
                Wyslij(nr_procesu,stan);
            }
            else
            {
                Wyslij(nr_procesu,stan);
            }
        }
        else if(stan==2)
        {
            printf("Wystartowalem, samochodow %d\n",nr_procesu);
            stan=JAZDA;
            Wyslij(nr_procesu,stan);
        }
        else if(stan==3)
        {
            paliwo-=rand()%500; // spalilem troche paliwa
            if(paliwo<=REZERWA)
            {
                stan=WYJAZD;
                printf("Prosze o zgode na powrót do gara¿u\n");
                Wyslij(nr_procesu,stan);
            }
            else
            {
                for(i=0; rand()%10000;i++);
            }
        }
        else if(stan==4)
        {
            int temp;
            MPI_Recv(&temp, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, &mpi_status);
            if(temp==WYJEZDZAJ)
            {
                stan=TOR;
                printf("Samochod %d wrocil do garazu\n", nr_procesu);
            }
            else
            {
                paliwo-=rand()%500;
                if(paliwo>0)
                {
                    Wyslij(nr_procesu,stan);
                }
                else
                {
                    stan=WYPADEK;
                    printf("rozbilem sie\n");
                    Wyslij(nr_procesu,stan);
                    return;
                }
            }
        }
    }
}
int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&nr_procesu);
    MPI_Comm_size(MPI_COMM_WORLD,&liczba_procesow);
    srand(time(NULL));

    if(nr_procesu == 0) //Lotnisko
    Tor(liczba_procesow);
    else //samoloty (petal odpowiada ze samoloty (czyli procesy inne niz 0))
    Samochod();

    MPI_Finalize();
    return 0;
}

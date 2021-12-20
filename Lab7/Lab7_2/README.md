Program w środowisku MPI który wykonuje tak zwaną "Grę w życie" czyli symulatora komórek w których każda komórka przyjmuje pewien stan zależny od stanów sąsiadów.
Na samym początku kodu tworzone są zmienne globalne oraz funkcja mod kórej zadanie jest zwrócenie resze z dzielenia.

![image](https://user-images.githubusercontent.com/80325475/146825876-a28987f1-8fd6-41ad-af9a-60a64c9a0b12.png)
###### (Przeniosłem się z Code Block na Visual Studio Code bo strasznie bolały mnie oczy od śnieżnej bieli Code Blocka)

W mainie najpierw definujemy siatke,zmienne oraz stany

![image](https://user-images.githubusercontent.com/80325475/146826277-ecfd598e-50d8-4484-afe3-3e952c2902e1.png)

następnie alokujemy tablice Integerów w pamięci oraz wykonujemy pętle która zarządza wszystkim
`
    for (iteracja = 0; iteracja < IloscIteracji; iteracja++)
    {
        j = wymiarySiatki;
        for (int i = ID * (SzerokoscSiatki / IloscProcesow); i < (ID + 1) * (SzerokoscSiatki / IloscProcesow); i++)
        {
            tabPamieci[j] = globalnaSiatka[i];
            j++;
        }

        if (IloscProcesow != 1)
        {
            int przyjmijA[wymiarySiatki];
            int przyjmijB[wymiarySiatki];
            int wyslijA[wymiarySiatki];
            int wyslijB[wymiarySiatki];
            if (ID % 2 == 0)
            {
                for (int i = 0; i < wymiarySiatki; i++)
                {
                    wyslijA[i] = tabPamieci[i + wymiarySiatki];
                }
                MPI_Ssend(&wyslijA, wymiarySiatki, MPI_INT, mod(ID - 1, IloscProcesow), 1, MPI_COMM_WORLD);


                for (int i = 0; i < wymiarySiatki; i++)
                {
                    wyslijB[i] = tabPamieci[(wymiarySiatki * (wymiarySiatki / IloscProcesow)) + i];
 
                }

                MPI_Ssend(&wyslijB, wymiarySiatki, MPI_INT, mod(ID + 1, IloscProcesow), 1, MPI_COMM_WORLD);
            }
            else
            {
                MPI_Recv(&przyjmijB, wymiarySiatki, MPI_INT, mod(ID + 1, IloscProcesow), 1, MPI_COMM_WORLD, &stat);
                MPI_Recv(&przyjmijA, wymiarySiatki, MPI_INT, mod(ID - 1, IloscProcesow), 1, MPI_COMM_WORLD, &stat);
            }
            if (ID % 2 == 0)
            {
                MPI_Recv(&przyjmijB, wymiarySiatki, MPI_INT, mod(ID + 1, IloscProcesow), 1, MPI_COMM_WORLD, &stat);
                MPI_Recv(&przyjmijA, wymiarySiatki, MPI_INT, mod(ID - 1, IloscProcesow), 1, MPI_COMM_WORLD, &stat);
            }
            else
            {

                for (int i = 0; i < wymiarySiatki; i++)
                {
                    wyslijA[i] = tabPamieci[i + wymiarySiatki];
                }
                MPI_Ssend(&wyslijA, wymiarySiatki, MPI_INT, mod(ID - 1, IloscProcesow), 1, MPI_COMM_WORLD);

   
                for (int i = 0; i < wymiarySiatki; i++)
                {
                    wyslijB[i] = tabPamieci[(wymiarySiatki * (wymiarySiatki / IloscProcesow)) + i];
                }
                MPI_Ssend(&wyslijB, wymiarySiatki, MPI_INT, mod(ID + 1, IloscProcesow), 1, MPI_COMM_WORLD);
            }
            for (int i = 0; i < wymiarySiatki; i++)
            {
                tabPamieci[i] = przyjmijA[i];
                tabPamieci[(wymiarySiatki * ((wymiarySiatki / IloscProcesow) + 1)) + i] = przyjmijB[i];
            }
        }
        else
        {
            for (int i = 0; i < wymiarySiatki; i++)
            {
                tabPamieci[i + SzerokoscSiatki + wymiarySiatki] = globalnaSiatka[i];

            }
            for (int i = SzerokoscSiatki; i < SzerokoscSiatki + wymiarySiatki; i++)
            {
                tabPamieci[i - SzerokoscSiatki] = globalnaSiatka[i - wymiarySiatki];

            }
        }

        int * koncowa = (int *)malloc(wymiarySiatki * ((wymiarySiatki / IloscProcesow)) * sizeof(int));

        for (int k = wymiarySiatki; k < wymiarySiatki * ((wymiarySiatki / IloscProcesow) + 1); k++)
        {
            int total_rows = wymiarySiatki * (wymiarySiatki / IloscProcesow) + 2;
            int r = k / wymiarySiatki;
            int c = k % wymiarySiatki;
            int prev_r = mod(r - 1, total_rows);
            int prev_c = mod(c - 1, wymiarySiatki);
            int next_r = mod(r + 1, total_rows);
            int next_c = mod(c + 1, wymiarySiatki);

            int count = tabPamieci[prev_r * wymiarySiatki + prev_c] + tabPamieci[prev_r * wymiarySiatki + c] + tabPamieci[prev_r * wymiarySiatki + next_c] + tabPamieci[r * wymiarySiatki + prev_c] + tabPamieci[r * wymiarySiatki + next_c] + tabPamieci[next_r * wymiarySiatki + prev_c] + tabPamieci[next_r * wymiarySiatki + c] + tabPamieci[next_r * wymiarySiatki + next_c];
            if (tabPamieci[k] == 1)
            {
                if (count < 2)
                    koncowa[k - wymiarySiatki] = 0;
                else if (count > 3)
                    koncowa[k - wymiarySiatki] = 0;
                else
                    koncowa[k - wymiarySiatki] = 1;
            }
            else
            {
                if (count == 3)
                    koncowa[k - wymiarySiatki] = 1;
                else
                    koncowa[k - wymiarySiatki] = 0;
            }
        }

        j = 0;
        for (int i = ID * (SzerokoscSiatki / IloscProcesow); i < (ID + 1) * (SzerokoscSiatki / IloscProcesow); i++)
        {
            globalnaSiatka[i] = koncowa[j];
            j++;
        }
        MPI_Gather(koncowa, wymiarySiatki * (wymiarySiatki / IloscProcesow), MPI_INT, &globalnaSiatka, wymiarySiatki * (wymiarySiatki / IloscProcesow), MPI_INT, 0, MPI_COMM_WORLD);

  
        if (ID == 0)
        {
            printf("\nIteracji %d: koncowa siatka:\n", iteracja);
            for (j = 0; j < SzerokoscSiatki; j++)
            {
                if (j % wymiarySiatki == 0)
                {
                    printf("\n");
                }
                printf("%d  ", globalnaSiatka[j]);
            }
            printf("\n");
        }
    }
    `
######(Nie było mozliwe wklejenie ss przez dlugosc pętli więc wstawiłem tutaj całą pętle)

Na koniec oczyszczamy pamięc by nie zostawić za sobą bałaganu i kończymy MPI

![image](https://user-images.githubusercontent.com/80325475/146826892-00608e90-4460-4436-befd-db707247d55a.png)
    
    

Program ma za zadanie obliczyć przybliżoną liczbę PI przy użyciu wzoru Leibniza w środowisku MPI
Funkcja Leibniz wykonuje wzór lebniza który przyjmuje liczbe procesó oraz wartość aktualnego procesu

![image](https://user-images.githubusercontent.com/80325475/146811895-f326d765-0e9b-43ae-b46e-2f8c5dbf7e5e.png)

Na początku maina oprócz stworzenia zmiennych, tworzymy dane o statusie (MPI_Status), inicjalizujemy podsystem MPI (MPI_Init), Pobieramy rozmiar globalnego komunikatora (MPI_Comm_size) oraz pobieramy numer procesu w globalnym komunikatorze (MPI_Comm_rank)

![image](https://user-images.githubusercontent.com/80325475/146812512-416a3701-3095-4828-94db-2507a1ad9c39.png)

Pierwszy proces ma za zadanie wysłać zmienną wynik(MPI_Send) a pozostałe procesy mają ją odebrać i policzyć pi ze wzoru Leibnitza oraz ostatni proces ma dodatkowe zadanie czyli wypisanie którym jest procesem i jakie PI otrzymał. Na końcu zakańczamy program i środowisko MPI (MPI_Finalize)

![image](https://user-images.githubusercontent.com/80325475/146813596-be0320ca-6b3b-47c1-85cc-1a82aeeb7b27.png)


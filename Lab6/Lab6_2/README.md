Program ma za zadanie obliczyć wartość całki przy pomocy metody trapezów i prostokątów w środowisku MPI.
Funkcja f ma za zadanie policzyc funkcje x^2. Na początku maina inicjalizuje zmienne oraz elementy związane ze środowiskiem MPI (takie same jak w 6_1)

![image](https://user-images.githubusercontent.com/80325475/146816940-8b1879ff-5f61-4d8b-9bf0-cd82fbe60495.png)

Ostatni proces przypisuje wartosci zmiennym oraz wysyła je do procesu następnego (czyli o numerze o jeden mniejszy). Kolejne procesy przyjmują wysłane zmienne i liczą wartości.

![image](https://user-images.githubusercontent.com/80325475/146817333-dc562423-5e8f-4d8f-9495-2f286212dae1.png)

Jeśli dojdziemy aż do procesu o numerze 0 wtedy wykonujemy po raz ostatni obliczenia i wypisujemy ile procesów zostało wykonanych i jaką wartość osiągnęła każda z metod

![image](https://user-images.githubusercontent.com/80325475/146817546-cdc81640-3453-4631-9d4c-1dfec8c25f88.png)

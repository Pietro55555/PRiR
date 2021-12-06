Zadaniem programu jest policzenie wartości całki o wzorze wymienionym w poleceniu
> y=4*x-6*x+5

Przy pomoocy metody trapezów oraz metody kwadratury Gaussa.

Na samym początku tworze funkcje funkcja która liczy wartość y z podanego wyżej wzoru

![image](https://user-images.githubusercontent.com/80325475/144882377-2343d0c1-374f-4cbe-89a6-bcb20e4e21a9.png)

Następnie możemy zauważyć funkcje która liczy całkę przy pomocy metody Kwadratury Gaussa dla przedziałów 2, 4, 6, 8 lub 10

![image](https://user-images.githubusercontent.com/80325475/144882829-f8642e18-d6e3-4d96-96b7-44b94e478496.png)

![image](https://user-images.githubusercontent.com/80325475/144882872-6ea14335-a2c3-4632-bad3-9fcd5581ef8e.png)

![image](https://user-images.githubusercontent.com/80325475/144883107-30ae8b92-fbe0-40da-bd29-793937c40f7b.png)

Wartości dla przedziałów zaczerpnąłem z https://www.fuw.edu.pl/~jnareb/zajecia/int-gauss.pdf (strona 5)

Następnie znajduje się funkcja której zadanie jest policzenie wartości całki przy pomocy metody trapezów

![image](https://user-images.githubusercontent.com/80325475/144883877-f946873f-6d36-4f14-877c-3434e79fde17.png)

W main użytkownik jest proszony o podanie p czyli ilość procesów potomnych. Następnie w pętli sprwadzamy dla każdego procesu czy fork jest równe 0. Jeśli jest równe -1 to wtedy pętla wyrzuci komunikat o błędzie. Gdy fork jest równy 0 ustawiamy ziarno w zależności od czasu oraz losujemy końce przedziału czyli a i b oraz n. Następnie  wypisujemy wartości zmiennych które wylosowaliśmy, PID procesu oraz wynik obu metod tylko że przed gaussem znów losujemy n

![image](https://user-images.githubusercontent.com/80325475/144884884-cb37a052-62c2-4595-bb36-d9d9df04bcf1.png)



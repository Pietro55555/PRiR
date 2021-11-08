# Lab 2_2

Jest to program którego zadaniem jest obliczanie całek trzeba metodami
- metodą prostokątów
- metodą trapezów
- metodą Simpsona

Całki są liczone w każdej metodzie na wątkach. Jedynymi danymi jakie musi wprowadzić
użytkownik jest początek przedziału (a), koniec przedziału (b) oraz na ilu wątkach 
ma się wykonywać program (n). Jak funkcje użyłem tej funkcji: 
![image](https://user-images.githubusercontent.com/80325475/140799284-e754d94d-5db2-4796-a604-805fa2c5f951.png). 

Funkcja została zaczerpnięta ze strony http://wyznacznik.pl/calka-nieoznaczona-zadania (wzór 7)


1.Każdy wątek liczy w pętli całkę swoją metodą do wcześniej obliczonego odcinka np.


![image](https://user-images.githubusercontent.com/80325475/140801644-a5a43d76-a3c8-4ece-923b-57ef162a9589.png)


2.Następnie sprawdzam czy na pewno wszystkie wątki zakończyły prace przy pomocy try catch


![image](https://user-images.githubusercontent.com/80325475/140801717-5f13f9a2-ee07-4aa0-ba6b-2d7579e1170d.png)


3.Na koniec sumujemy wyniki z każdego odcinka i otrzymujemy wynik końcowy który wypisujemy na ekran


![image](https://user-images.githubusercontent.com/80325475/140802410-535d5e3a-5282-4725-a0ea-2091a158d742.png)


Podane wyżej kroki są przeprowadzane dla każej metody.

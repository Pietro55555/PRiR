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

Do każdej metody są tworzone listy obiektów adekwatnie do metody
```
ArrayList<M_prostokatow> calkaP = new ArrayList<>();
...
ArrayList<M_trapezow> calkaT = new ArrayList<>();
...
ArrayList<M_Simpsona> calkaS = new ArrayList<>();

```

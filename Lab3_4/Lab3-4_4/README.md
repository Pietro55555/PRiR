Program wykonuje algorytm Monte Carlo dzięki któremu możemy policzyć pole okręgu wpisanego w kwadra. W programie liczymy pole koła w kwadracie 2 x 2.
Sam kwadrat podzielne na dwa wątki, każdy z nich to połowa kwadrata.

![image](https://user-images.githubusercontent.com/80325475/142776491-d7493c14-d132-4012-948e-3971de0addd1.png)

Po utworzeniu obiektu MonteCarlo (wątku) uruchamiamy wątki oraz dodajemy je do kolejki

![image](https://user-images.githubusercontent.com/80325475/142776526-42c2abbf-8857-4721-a927-706a1a02c01e.png)

Następnie obliczamy i otrzymujemy pole koła

![image](https://user-images.githubusercontent.com/80325475/142776569-a94841df-fa58-492c-ba8a-33953f574f82.png)


W pliku MonteCarlo tworzymy klase o tej samej nazwie która przyjmuje punkt początkowy i punkt końcowy

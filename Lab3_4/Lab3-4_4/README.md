Program wykonuje algorytm Monte Carlo dzięki któremu możemy policzyć pole okręgu wpisanego w kwadra. W programie liczymy pole koła w kwadracie 2 x 2.
Sam kwadrat podzielne na dwa wątki, każdy z nich to połowa kwadrata.

![image](https://user-images.githubusercontent.com/80325475/142776797-43c9456e-2279-49e0-ac3a-09a42c37a758.png)

Po utworzeniu obiektu MonteCarlo (wątku) uruchamiamy wątki oraz dodajemy je do kolejki

![image](https://user-images.githubusercontent.com/80325475/142776820-cf381d0c-621a-44df-99ad-dbeed053841c.png)

Następnie obliczamy i otrzymujemy pole koła

![image](https://user-images.githubusercontent.com/80325475/142776835-234e6807-6832-4962-a7de-91100d9d5278.png)


W pliku MonteCarlo tworzymy klase o tej samej nazwie która przyjmuje punkt początkowy i punkt końcowy

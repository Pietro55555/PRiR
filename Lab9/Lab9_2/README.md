

UWAGA
Przykłady zostały wrzucone tutaj  27 grudni 2021 (można to sprawdzić w hisotrii brencha)

![image](https://user-images.githubusercontent.com/80325475/149984888-927298cd-1420-4910-b348-d87fb4e848e5.png)

Może się pokazywać dzisiejsza data (18.01.2022) przy plikach ponieważ do plików postanowiłem dodać oznaczenia dzięki którym widać który kod jest do CPU a który do GPU. Mam na myśli to (przykład z Przykładu 1):

![image](https://user-images.githubusercontent.com/80325475/149985166-3d2995f1-d2d2-4e1b-b964-8f7be46cca2e.png)
![image](https://user-images.githubusercontent.com/80325475/149985220-5328cc00-8252-47b5-a1a9-65f30069807e.png)

O opisie zapomniałem i dodaje go dzisiaj(18.01)

**PRZYKŁAD 1**

Zadaniem programu w przykładzie 1 jest zmiany zdjecia na jego negatyw. Przez ogarniczenie nałożone przez google colab nie mogłem skorzystać z zdjęcia o dużej wadze więc mój program robi negatyw 10 razy ale za każym razem wartość od której odejmujemy zmniejsza się o 15 razy numer powtórzenia negatywu czyli od 1 do 10. Dzięki takiem procesowi otrzebuje ciekawy obraz oraz czas do analizy.

Obraz który wykorzystałem:


![image](https://user-images.githubusercontent.com/80325475/149986414-414ed2ba-c146-47ea-a0bd-08fa13920226.png)


Obraz który otrzymałem:

![image](https://user-images.githubusercontent.com/80325475/149986620-ed7a5f4a-dd68-43c6-9d5e-0517f4ab0fa6.png)

Przy 6 uruchomień cpu otrzymałem takie wyniki: [28.236, 31.091, 28.522, 29.760,28.731,27.855], a przy GPU takie: [19.072, 15.190, 16.230, 15.087,14.454,14.802]

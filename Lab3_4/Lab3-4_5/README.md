Program ma za zadanie stworzyć negatyw zdjęcia przy pomocy wątków. Do programu będzie użyte te zdjęcie:

![mona](https://user-images.githubusercontent.com/80325475/144758848-fee41ce0-ea70-4a12-b1df-519d48aff3ca.jpg)

następnie dzięki programowi uzyskujemy taki efekty

![pictureNeg](https://user-images.githubusercontent.com/80325475/144758866-865a6c21-e2dc-42a1-a471-813fce6813ed.jpg)

W Main wczytujemy plik oraz pobieramy z niego jego wysokość i szerokość dzięki czemu możemy ustawić cztery wątki tak żeby każdy robił swoją ćwiartke obrazu.

![image](https://user-images.githubusercontent.com/80325475/144758919-d40e907a-7713-4a70-9f6e-a2e7d2aeb0ea.png)

następnie uruchamiamy wątki komendą run i je kolejkujemy oraz na koniec zapisujemy otrzymany negatyw jaki plik jpg

![image](https://user-images.githubusercontent.com/80325475/144758943-8197b2f7-f547-4dc1-bfd5-ee524fe22dc3.png)

Klasa Negatyw przyjmuje obraz początkowy, punkty x z którego startuje i kończy oraz punkty y z których zaczyna i kończy

![image](https://user-images.githubusercontent.com/80325475/144759019-bc426232-de56-4da4-b879-082742a2b5e4.png)

Następnie nadpisuje funkcje run tak aby po uruchomienu wątku wykonywał się negatyw piksela w ten sposób że od 255 odejmujemy wartość atrybut R , G i B pixela i następnie nadpisujemy wprowadzone zdjęcie.

![image](https://user-images.githubusercontent.com/80325475/144759135-96eff5e9-9be3-4ab4-985c-3c3ba47bba61.png)

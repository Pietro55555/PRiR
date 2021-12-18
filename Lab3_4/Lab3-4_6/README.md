Program ma za zadanie generuje fraktale julii przy pomocy wątków.
Po użyciu programu uzyskamy taki oto fraktal:

![JuliaFractal](https://user-images.githubusercontent.com/80325475/146651157-b7d63346-adee-4f18-957a-4dd6793792b9.png)

W maine program tworzy wwątki które następnie wstawia do tablicy z wątkami i rozpoczyna ich prace

![image](https://user-images.githubusercontent.com/80325475/146651056-121d6fc1-3eb3-4119-9053-e5765600878c.png)

Po zakończeniu pracy wątków generoany jest obraz fratkali zbioru Julii

![image](https://user-images.githubusercontent.com/80325475/146651078-a3f6959a-5c84-4d8a-a45a-be8924b2f6a9.png)

Konstruktor klasy JuliaSet przyjmuje numer wątka oraz liczy x i y przy pomocy stałej N która określa poziom ostrości i tym samym wielkość obrazka w main po zakoneczone pracy watkow.
Metoda Run() ustawia odpowiednie współrzędne dla odpowiedniego wątka.

![image](https://user-images.githubusercontent.com/80325475/146651334-d81e1694-2e5b-4879-90a8-8373b67b59a2.png)
![image](https://user-images.githubusercontent.com/80325475/146651342-efcff64a-5aed-43a5-8696-b95dc14a22b5.png)



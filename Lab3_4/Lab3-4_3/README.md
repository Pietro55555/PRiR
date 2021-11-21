Program jest uzupełnionym kodem. Zadaniem programu jest symulowania ruszenia,jazdy oraz tankowania samochodu przy użyciu wątków.
Plik TestSamochod zawiera w sobie main-a oraz w nim Są wywoływane obiekty klasy Samochod które symulują samochody. Do każdego obiektu jest nadawany numer rejestracyjni taki jak: BIAxx  gdzie xx to dowolny numer (dla ułatwienia widoczności numer od 1 do ilosci samochodów)

![image](https://user-images.githubusercontent.com/80325475/142775742-509241d8-055d-42e0-afaf-32f67296542a.png)

Nastepnie w pliku Samochod tworzony jest samochod z atrybutami podanymi we wzorze z wykładu  z dodatkową zmienna bool "dziala".
Przy tankowaniu samochod tankuje podaną ilość paliwa w wywołaniu funkcji (aktualnyStanPaliwa + nowePaliwo) lub do pełna czli do pojemności zbiornika.
Podczas swoje działania (run) obiekt samochod zużywa paliwo z każdą sekundą. Samochod zużywa od 1 do 6 l paliwa na sekundę. Wproawdziłem losowość by przy spadnięciu paliwa poniżej 0 lub osiagnięciu 0 samochód musiał się zatrzymać przy pomocy funkcji stopp.

![image](https://user-images.githubusercontent.com/80325475/142776046-15d178d5-5a6b-4cc0-84d7-ec0d8e6d29e9.png)


Samochod zatankuje dopiero gdy zostanie mu od 1 do 3 litrów paliwa.

![image](https://user-images.githubusercontent.com/80325475/142776082-edfea1a3-7d94-4490-b8b0-62410f412168.png)


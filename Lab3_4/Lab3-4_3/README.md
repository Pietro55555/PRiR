Program jest uzupełnionym kodem. Zadaniem programu jest symulowania ruszenia,jazdy oraz tankowania samochodu przy użyciu wątków.
Plik TestSamochod zawiera w sobie main-a oraz w nim Są wywoływane obiekty klasy Samochod które symulują samochody. Do każdego obiektu jest nadawany numer rejestracyjni taki jak: BIAxx  gdzie xx to dowolny numer (dla ułatwienia widoczności numer od 1 do ilosci samochodów)

![image](https://user-images.githubusercontent.com/80325475/142775742-509241d8-055d-42e0-afaf-32f67296542a.png)

Nastepnie w pliku Samochod tworzony jest samochod z atrybutami podanymi we wzorze z wykładu  z dodatkową zmienna bool "dziala".
Przy tankowaniu samochod tankuje podaną ilość paliwa w wywołaniu funkcji (aktualnyStanPaliwa + nowePaliwo) lub do pełna czli do pojemności zbiornika.

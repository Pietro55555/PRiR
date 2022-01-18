Program ma za zadanie obliczyć wartość całki przy pomocy metody Prostokątów, Trapezów oraz Simpsona. W tym programie skupiam się na czasie wykonania zadania.
Tak oto prezentują się pobrane dane na których będą bazować moje wnioski i wykres:

![image](https://user-images.githubusercontent.com/80325475/150026182-68d27746-29fc-43ed-91e3-3301fe26f431.png)

Oto wykres wyżej ukazanej tabeli:

![image](https://user-images.githubusercontent.com/80325475/150026399-893167fc-080a-4f52-ad4e-025b45964aa6.png)
```
LEGENDA
Czerwone - GPU
Niebieskie - CPU

```

Z powyższych danych moge wywnioskowć że wraz z liczbą procesów ( w naszym przyadku przedziałów (n) ) CPU zaczyna spowalniać bardzo szybko, w przeciwieństwie do GPU w którym wzrósł czas pracy ale bardzo mało i nie ma szansy przeciąć krzywej CPU. Lecz też trzeba zauważyć że dla mniejszej liczby przedziałów (np. n=100000) cp poradziło sobie lepiej.

**Wniosek**

Jeśli chcemy wykonywać małe procesy o małej liczbie powtórzeń(wykonań) i obliczeń to dobrze się do tego nada CPU, lecz do większych i bardziej skomplikowanych programów GPU jest niezbędne jeśli chcemy usprawnić działanie kolosalnych programów obliczeniowych i nie tylko.

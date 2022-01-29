Scikit-learn jest darmową biblioteką algorytmów z dziedziny uczenia maszynowego, napisaną w języku Python i zbudowaną na bazie modułu SciPy.
Jednym z kluczowych argumentów za używaniem Scikit-Learn jest jego efektywność finansowa. Moduł jest po prostu darmowy.


Oprócz bycia darmowym moduł Scikit-Learn jest wydany na licencji New BSD License, co pozwala go również używać w oprogramowaniu z zamkniętym kodem źródłowym.


Wnętrze tego modułu jest napisane w językach, które są „szybkie”. Szybkość ta wynika między innymi z tego,
że te kluczowe elementy są już skompilowane wcześniej, a nie interpretowane „na żywo” jak z Pythonem bywa.
Moduł ten powstał w roku 2007 jest ciagle rozwijany. Cały czas do kodu dokładane są nowe funkcjonalności,
testy, naprawiany są bug-i, a cały moduł jest jeszcze dodatkowo optymalizowany.


Jeżeli przejrzymy sobie dokumentację Scikit-Learn, zauważymy, że oferuje on zaskakująco dużo funkcjonalności związanej z uczeniem maszynowym.
 Mamy tutaj gotowe funkcje pomagające w ewaluacji modeli i transformacji danych, wbudowane zbioray danych i funkcje pozwalające je generować. Scikit-Learn jest więc potężne i bogate w wiele możliwości.


Scikit-Learn posiada również funkcje związane z sieciami neuronowymi, przetwarzaniem obrazu i dźwięku oraz praca z tekstem. Mimo tych możliwości i tak częściej wykorzystywana jest "konkurencja" w tych dziedzinach (np.PyTorch) ,lecz ten moduł jest często wykorezystywany przy innych bibliotekcha ponieważ, Scikit-Learn przydaje się do transformacji i tym podobnych działań, a „mięso” już jest mielone przez inne moduły. Jest więc podstawą w wielu miejscach i całkiem sensowną pomocą w innych.

**PRZYKŁAD**
Celem programu jest skwantyzowanie zdjęcie które zostanie pobrane z internetu przy podaniu URL zdjęcia.


Nasz input:


![image](https://user-images.githubusercontent.com/80325475/151675509-d7120274-0884-4cbb-a0e5-6f2920bdf286.png)



Po skorzystaniu z Scikit-learn i skwantyzowaniu
otrzymujemy to:


![image](https://user-images.githubusercontent.com/80325475/151675564-34a8a17e-0377-45ff-a402-7a54ffd05209.png)


Kod z którego otrzymałem ten efekt jest dostępny w pliku Scikit-learn.ipynb wraz z opisami kroków wykonwywanych przez algorytm

Źródło: https://scikit-learn.org/stable/auto_examples/cluster/plot_color_quantization.html#sphx-glr-auto-examples-cluster-plot-color-quantization-py

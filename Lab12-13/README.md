Program korzystając z systemów neuronowych (NTS) nakłada na obraz styl drugiego obrazu. Najlepsze efekty otrzymujemy jeśli obrazy w podobnym rozmiarze lub takim samym.

Źródło kodu: https://keras.io/examples/generative/neural_style_transfer/

W moim przykładzie na zdjęcie: 

![image](https://user-images.githubusercontent.com/80325475/150857031-959cf7ca-2820-44d5-8088-2cac17a44f70.png)

Będę chciał nałożyć styl tego zdjęcia: 

![image](https://user-images.githubusercontent.com/80325475/150857070-23d2ae7b-6c76-49e3-9003-88f2691b4344.png)

Takie wyniki otrzymałem przy:

200 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857226-2be64814-493b-492c-8652-9eb3b58d8039.png)

600 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857261-ce40dc1d-56ff-4cf4-ba4b-a8abcd8ad678.png)


1000 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857328-7d8aa91c-f8fc-413c-9c60-ecf3665a3e11.png)

1400 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857353-798cebca-782d-4219-92e3-1372d5de7f4b.png)

2000 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857376-63bbffe2-321d-4521-9301-28aa3bc73622.png)

2600 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857418-8b679e40-a67b-43b7-bac4-99140706e84b.png)

3000 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857459-a69a4c9f-4fd2-4462-8921-644aad283673.png)

4000 iteracji

![image](https://user-images.githubusercontent.com/80325475/150857532-2ad97979-cdd6-4e84-83ee-3f7577fd7c2e.png)

A tak wyglądaja czasy w każdym z wyżej wymienionych wyników.

![image](https://user-images.githubusercontent.com/80325475/150858117-0b81ef63-e05a-4fa0-a489-5fe488e6b928.png)

![image](https://user-images.githubusercontent.com/80325475/150858773-9c143734-d2b5-4c6d-955c-50253a5444c5.png)

Przerobiłem troche kod i teraz przy uruchomieniu programu algorytm zacznie od 200 iteracji, w ciągu pracy algorytmu będziemy dostawać kompunikaty o ilości iteracji oraz jakie straty przy nich mieliśmy. Na koniec iteracaji program wypisze nam ile trwała operacja, dla ilu iteracji, jak nazywa się plik z obrazem wynikowym oraz pokaże nam ten obraz. Następnie pętla zwiększy ilośc iteracji o 200 i powtórzy cały proces i tak będzie się działo aż do 4000 iteracji ale trzeba pamiętać że przy korzystaniu z google colab i GPU ukończenie całej tej pętli trwa 1 godzinę i 21 minut. Mój zmienony kod można znaleźć w pliku Lab12_13_SeriaWynikow.ipynb (Uwaga! Plik potrafi długo się ładować ok.20-30sekund)

**Warstwy sieci VGG-19**

Spróbuje zmienić warstwy VGG19 wybierając jedną z warstw:

>Model: "vgg19"
>_________________________________________________________________
> Layer (type)                Output Shape              Param #   
>=================================================================
>input_4 (InputLayer)        [(None, None, None, 3)]   0                                                                          
>block1_conv1 (Conv2D)       (None, None, None, 64)    1792                                                                    
>block1_conv2 (Conv2D)       (None, None, None, 64)    36928                                                                   
>block1_pool (MaxPooling2D)  (None, None, None, 64)    0                                                                        
>block2_conv1 (Conv2D)       (None, None, None, 128)   73856                                                                     
>block2_conv2 (Conv2D)       (None, None, None, 128)   147584                                                                    
>block2_pool (MaxPooling2D)  (None, None, None, 128)   0                                                                         
>block3_conv1 (Conv2D)       (None, None, None, 256)   295168                                                                  
>block3_conv2 (Conv2D)       (None, None, None, 256)   590080                                                                   
>block3_conv3 (Conv2D)       (None, None, None, 256)   590080                                                                    
>block3_conv4 (Conv2D)       (None, None, None, 256)   590080                                                                   
>block3_pool (MaxPooling2D)  (None, None, None, 256)   0                                                                        
>block4_conv1 (Conv2D)       (None, None, None, 512)   1180160                                                                   
>block4_conv2 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block4_conv3 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block4_conv4 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block4_pool (MaxPooling2D)  (None, None, None, 512)   0                                                                         
>block5_conv1 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block5_conv2 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block5_conv3 (Conv2D)       (None, None, None, 512)   2359808                                                                  
>block5_conv4 (Conv2D)       (None, None, None, 512)   2359808                                                                   
>block5_pool (MaxPooling2D)  (None, None, None, 512)   0  

Wszystkie przykłady będą testowane dla 1000 iteracji

**Przykład 1**

```
style_layer_names = [
    "block1_conv1",
    "block2_conv2",
    "block3_conv3",
    "block4_conv4",
    "block5_conv4",
]
```

<p align="left">Początkowe warstwy</p><p align="right">Warstwy w Przykład1</p>

![image](https://user-images.githubusercontent.com/80325475/150857328-7d8aa91c-f8fc-413c-9c60-ecf3665a3e11.png)<p align="right">![image](https://user-images.githubusercontent.com/80325475/150869316-3c21c8fc-b858-429f-960e-df7e4a8f0dcc.png)</p>

**Przykład 2**
```
style_layer_names = [
    "block1_conv1",
    "block2_conv1",
]
```
<p align="left">Początkowe warstwy</p><p align="right">Warstwy w Przykład1</p>

![image](https://user-images.githubusercontent.com/80325475/150870941-67ec5914-e0d8-4947-9ee2-9319f38e046b.png)<p align="right">![image](https://user-images.githubusercontent.com/80325475/150869316-3c21c8fc-b858-429f-960e-df7e4a8f0dcc.png)</p>





Program ma za zadanie przy pomocy wzoru Leibniz-a policzyć w przybliżeniu liczbe pi.

Najpierw można zauważyć funkcje Leibniz która liczy liczbe pi korzystając ze wzoru

![image](https://user-images.githubusercontent.com/80325475/144889069-c2728746-57cc-49ba-ab9b-e8628c0bf9cd.png)

![image](https://user-images.githubusercontent.com/80325475/144889111-054c2e4d-7de3-425d-a804-a14f83e7f5a0.png)

W main użytkownik jest proszony o podanie p czyli ilości procesów. Następnie w pętli dla każdego procesu sprawdzany jest fork czy jest równy 0. Następnie jest wywoływana funkcja leibniz oraz wypisywany PID procesu potomnego.

![image](https://user-images.githubusercontent.com/80325475/144890078-9e2f1a38-64b5-45d8-aa20-5185e63d4ae7.png)


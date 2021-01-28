# Zadanie Testowe - Jacek Cieślak

## Plik wejściowy
Plik wejściowy powinien być plikiem csv zawierającym kolejne wymagane od programu operacje w kolejnych liniach. Pierwszym elementem w każdej linii powinna być nazwa operacji, która ma zostać przeprowadzona. Wszystkie kolejne kolumny pliku powinny zawierać kolejne argumenty dla operacji.

Aktualnie dostępne operacje:
  -  Arithmetic Addition: proste dodawanie wszystkich argumentów
  -  Arithmetic Multiplication: proste mnożenie wszystkich argumentów
  -  Matrix Addition: dodawanie macieżowe

W przypadku macierzy przyjęto notację rozdzielającą poszczególne wiersze średnikami.
Poniżej przedstawiono przykładowy zapis macierzy.
```
[ a b c ]
[ d e f ]   = a b c; d e f; g h i
[ g h i ]
```

## Plik wyjściowy
Plik wyjściowy przyjmuje formę pliku csv, w którym poszczególne wiersze opisują kolejne działania. Struktura każdego wiersza przedstawiono poniżej:
```
NazwaOperacji, PASS/FAIL (informacja o sukcesie bądź błędzie przetwarzania), wynik operacji/komunikat błędu, argumenty przyjmowane przez operację
```
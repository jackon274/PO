# Kalkulator
Projekt prostego kalkulatora ze wsparciem dla podstawowych operacji matematycznych: dodawanie, odejmowanie, mnożenie, dzielenie, pierwiastek kwadratowy. Zapewnia również obsługę podstawowych błędów dzielenia przez zero oraz pierwiastka z liczby ujemnej.

## Klasy

Projekt posiada dwie podstawowe klasy zapewniające całą funkcjonalność logiki: Kalkulator oraz Memory. Klasa Kalkulator zapewnia obsługę działań arytmetycznych przez odpowiednie metody. Obsługa strumienia wejściowego odbywa się w metodzie handleStream(), która na podstawie danych w strumieniu decyduje o wyborze operacji. Klasa memory zapewnia pamięć kalkulatora. Obecnie jest tylko jedna pamięć, przechowująca informację o ostatniej operacij, jednak rozdzielenie na dwie osobne klasy umożliwia łatwe rozbudowanie o pamięć globalną. Metody przy braku wskaźnikla na daną pamięć przyjmują pamięć domyślną, jednak jest możliwe stworzenie nowej, np. globalnej i użycie tych samych metod z innym miejscem zapisu docelowego.

## Operacje niedozwolone

Kalkulator zapewnia obsługę błędów pierwiastka z liczb ujemnych (działania dozwolone są tylko na zbiorze liczb rzeczywistych) oraz dzielenia przez zero, w przypadku wystąpienia takiego zdarzenia wyświetlony zostaje komunikat systemowy oraz zostaje wyczyszczony strumień danych.

## Obsługa wpisywania danych

Kalkulator zbudowany jest w oparciu o std::stringstream, co umożliwia bardzo łatwą rozbudowę o kolejne operacje matematyczne. Przyciski wywołują metodę dopisującą dane do strumienia, obsługiwane są operacje [liczba] [znak] [liczba] oraz [liczba] [operacja], obecnie nie jest możliwe łączenie operacji w ciągi, przykładowo wpisanie 2+3*4 spowoduje wykonanie pierwszej operacji, tj. 2+3. Po każdym wywołaniu metody obsługującej strumień, jest on czyszczony, tzn. kolejne operacje w ciągu zostaną usunięte. 

## Konwersja systemów liczbowych

Kalkulator umożliwia przeliczanie systemów liczbowych o dowolnych podstawach w zakresie 2-10 oraz system szesnastkowy. Nie obsługuje liczb zmiennoprzecinowych ani ujemnych.


## License

Copyright (c) 2025 Jacek Konderak.
Wykonano na potrzeby projektu z programowania obiektowego, wykorzystanie możliwe tylko do celów związanych z zajęciami uczelnianymi.

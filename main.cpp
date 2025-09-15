// Biblioteka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"
#include "Bibliotekarz.hpp"

int main() {
	Uzytkownicy* wskaznik = nullptr;
	Bibliotekarz biblio;
	while (true) {

		std::cout << "Hello World!\n";
		std::cout << "Pierwsze Menu\n";
		std::cout << "--------------------------------\n";
		std::cout << "1. Wprowadz ksiazke\n";
		std::cout << "2. Wyswietl ksiazki\n";
		std::cout << "3. Zaloguj\n";
		std::cout << "4. Wyjdz\n";
		int wybor;
		std::cin >> wybor;
		if (wybor == 1) {
			Ksiazka ksiazka;
			ksiazka.zapiszKsiazke();
		}
		else if (wybor == 2) {
			Ksiazka ksiazka;
			ksiazka.wyswietlKsiazki();
		}
		else if (wybor == 3) {
			wczytajUzytkownikow();
			if (wczytajUzytkownikow() == "Bibliotekarz") {
				wskaznik = &biblio;
				wskaznik->menu();
			}
		}
		else if (wybor == 4) {
			std::cout << "Koniec programu\n";
			return 0;
		}
		else {
			std::cout << "Nie ma takiej opcji, sprobuj ponownie\n";
		}
	} return 0;
}
	

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

// Biblioteka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"
#include "Bibliotekarz.hpp"
#include "Czytelnik.hpp"
#include "Administrator.hpp"

int main() {
	Uzytkownicy* wskaznik = nullptr;
	Bibliotekarz biblio;
	Administrator admin;
	while (true) {

		std::cout << "Biblioteka - Panel logowania\n";
		std::cout << "\n";
		std::cout << "1. Zaloguj\n";
		std::cout << "2. Wyjdz\n";
		int wybor;
		std::cout << "Wybor: ";
		std::cin >> wybor;
		if (wybor == 1) {
			std::pair<std::string, std::string> dane = wczytajUzytkownikow();
			if (dane.first == "Bibliotekarz") {
				wskaznik = &biblio;
				wskaznik->menu();

			}
			else if (dane.first == "Czytelnik") {
				Czytelnik czytacz("", "", dane.second, "", "");
				wskaznik = &czytacz;
				wskaznik->menu();
			}
			else if (dane.first == "Administrator") {
				wskaznik = &admin;
				wskaznik->menu();
			}
			else std::cerr << "Błedny login lub haslo" << std::endl;
		}
		else if (wybor == 2) {
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
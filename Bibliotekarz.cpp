#include <iostream>
#include "Bibliotekarz.hpp"
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"


Bibliotekarz::Bibliotekarz(std::string i, std::string n, std::string l, std::string h, std::string r)
	: Uzytkownicy(i, n, l, h, r) {}

Bibliotekarz::Bibliotekarz() : Uzytkownicy("", "", "", "", "") {}

void Bibliotekarz::menu() {
	std::cout << "Udalo sie! Wyswietlam menu dla Bibliotekarza" << std::endl;
	while (true) {
		std::string wybor;
		Ksiazka ksiazka;
		std::cout << "Wybierz opcje:" << std::endl;
		std::cout << "1. Wyswietl ksiazki" << std::endl;
		std::cout << "2. Dodaj ksiazke" << std::endl;
		std::cout << "3. Usun ksiazke" << std::endl;
		std::cout << "4. Wyswietl Czytelnikow" << std::endl;
		std::cout << "5. Cofnij" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> wybor;

		if (wybor == "1") {
			ksiazka.wyswietlKsiazki();
		}
		else if (wybor == "2") {
			ksiazka.zapiszKsiazke();
		}
		else if (wybor == "3") {
			std::cout << "Przyszla funkcja odpowiedzialna za usuwanie ksiazek";
		} 
		else if (wybor == "4") {
			std::cout << "Przyszla funkcja odpowiedzialna Wyswietlanie czytelnikow";
		}
		else if (wybor == "5") {
			break;
		}
		else {
			std::cout << "Nie ma takie opcji!";
		}
	}
}
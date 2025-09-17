#include <iostream>
#include "Czytelnik.hpp"
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"


Czytelnik::Czytelnik(std::string i, std::string n, std::string l, std::string h, std::string r)
	: Uzytkownicy(i, n, l, h, r) {}

Czytelnik::Czytelnik() : Uzytkownicy("", "", "", "", "") {}

void Czytelnik::menu() {
	std::cout << "Udalo sie! Wyswietlam menu Czytelnika!" << std::endl;
	while (true) {
		std::string wybor;
		Ksiazka ksiazka;
		//Czytelnik czytacz;
		std::cout << "Wybierz opcje:" << std::endl;
		std::cout << "1. Wyswietl ksiazki" << std::endl;
		std::cout << "2. Wypozycz ksiazke" << std::endl;
		std::cout << "3. Sprawdz wypozyczone ksiazki" << std::endl;
		std::cout << "4. Oddaj ksiazke" << std::endl;
		std::cout << "5. Cofnij" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> wybor;

		if (wybor == "1") {
			ksiazka.wyswietlKsiazki();
		}
		else if (wybor == "2") {
			ksiazka.wypozyczKsiazke(this->login);//wskaznik na biezacy obiekt, przekazuje login do funkcji
		}
		else if (wybor == "3") {
			ksiazka.sprawdzWypozyczone(this->login);
		}
		else if (wybor == "4") {
			std::cout << "Przyszla funkcja odpowiedzialna za oddawanie ksiazek";
		}
		else if (wybor == "5") {
			break;
		}
		else {
			std::cout << "Nie ma takie opcji!";
		}
	}
}
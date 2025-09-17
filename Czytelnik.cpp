#include <iostream>
#include "Czytelnik.hpp"
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku


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
			wyswietlKsiazki();
		}
		else if (wybor == "2") {
			ksiazka.wypozyczKsiazke(this->login);//wskaznik na biezacy obiekt, przekazuje login do funkcji
		}
		else if (wybor == "3") {
			ksiazka.sprawdzWypozyczone(this->login);
		}
		else if (wybor == "4") {
			ksiazka.zwrocKsiazke(this->login);
		}
		else if (wybor == "5") {
			break;
		}
		else {
			std::cout << "Nie ma takie opcji!";
		}
	}
}

void Czytelnik::wyswietlKsiazki() {
	std::ifstream plik("ksiazki.txt", std::ios::in);
	std::string linia;
	std::cout << "\n";
	if (plik.good() == false)
	{
		std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
		exit(0);
	}
	else {
		std::cout << "Lista ksiazek w bibliotece: " << std::endl;
		while (std::getline(plik, linia)) {
			std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, stan;

			std::istringstream iss(linia);
			std::getline(iss, tytul, ';');
			std::getline(iss, autor_imie, ';');
			std::getline(iss, autor_nazwisko, ';');
			std::getline(iss, gatunek, ';');
			std::getline(iss, opis, ';');
			std::getline(iss, s_rok, ';');
			std::getline(iss, stan, ';');

			int rok_wydania = std::stoi(s_rok);

			std::cout << "Tytul: " << tytul << std::endl;
			std::cout << "Autor: " << autor_imie << " " << autor_nazwisko << std::endl;
			std::cout << "Gatunek: " << gatunek << std::endl;
			std::cout << "Opis: " << opis << std::endl;
			std::cout << "Rok wydania: " << rok_wydania << std::endl;
			if (stan == "wolna") {
				std::cout << "Stan: Dostepna" << std::endl;
			}
			else {
				std::cout << "Stan: Wypozyczona" << std::endl;
				std::cout << "--------------------------------" << std::endl;
			}
		}
	}
}

void Czytelnik::dodajUzytkownika() {
	std::cout << "Funkcja dodajUzytkownika jeszcze nie zaimplementowana" << std::endl;
}

void Czytelnik::wyswietlUzytkownikow() {

}
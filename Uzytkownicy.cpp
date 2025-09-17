#include <iostream>
#include "Uzytkownicy.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku

Uzytkownicy::Uzytkownicy(std::string i = "imie_test", std::string n = "nazwisko_test", std::string l = "login_test", std::string h = "haslo_test", std::string r = "rodzaj_test") {
	imie = i;
	nazwisko = n;
	login = l;
	haslo = h;
	rodzaj = r;
}

std::pair<std::string, std::string> wczytajUzytkownikow() {
	std::string linia;
	std::string try_login, try_haslo;
	std::ifstream plik_u("uzytkownicy.txt", std::ios::in);
	std::cout << "\n";
	std::cout << "Podaj login: ";
	std::cin >> try_login;
	std::cout << "Podaj haslo: ";
	std::cin >> try_haslo;




	if (plik_u.good() == false) {
		std::cerr << "Blad odczytu pliku uzytkownicy.txt";
	}
	else {
		bool znaleziono = false;   // flaga
		while (std::getline(plik_u, linia)) {
			std::string imie, nazwisko, login, haslo, typ;

			std::istringstream iss(linia);
			std::getline(iss, imie, ';');
			std::getline(iss, nazwisko, ';');
			std::getline(iss, login, ';');
			std::getline(iss, haslo, ';');
			std::getline(iss, typ, ';');

			if (try_login == login && try_haslo == haslo) {
				std::cout << "Zalogowano jako " << imie << " " << nazwisko << std::endl;
				std::cout << "\n";
				znaleziono = true;
				return { typ, login };
			}


		}
		if (!znaleziono) {
			std::cout << "Bledny login lub haslo.\n";
			
		}

	}
}

void Uzytkownicy::wyswietlUzytkownikow() {
	std::string linia;
	std::ifstream plik_u("uzytkownicy.txt", std::ios::app);
	std::cout << "\n";
	std::cout << "Lista Czytelnikow: " << std::endl;
	std::cout << "\n";

	if (plik_u.good() == false) {
		std::cout << "Nie udalo sie wczytac pliku uzytkownicy.txt" << std::endl;
	}
	else {
		bool znaleziono = false;   // flaga
		while (std::getline(plik_u, linia)) {
			std::string imie, nazwisko, login, haslo, typ;

			std::istringstream iss(linia);
			std::getline(iss, imie, ';');
			std::getline(iss, nazwisko, ';');
			std::getline(iss, login, ';');
			std::getline(iss, haslo, ';');
			std::getline(iss, typ, ';');

			if (typ == "Czytelnik") {
				std::cout << "Uzytkownik: " << login << std::endl;
				std::cout << "imie i nazwisko: " << imie << " " << nazwisko << std::endl;
				std::cout << "\n";
			}
			else continue;


		}

	}
}
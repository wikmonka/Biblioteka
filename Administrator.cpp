#include <iostream>
#include "Administrator.hpp"
#include "Uzytkownicy.hpp"
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku


Administrator::Administrator() : Uzytkownicy("", "", "", "", "") {}

void Administrator::menu() {
	std::string wybor;
	while (true) {
		std::cout << "Menu Administratora: " << std::endl;
		std::cout << "1. Dodaj Uzytkownika" << std::endl;
		std::cout << "2. Usun Uzytkownika" << std::endl;
		std::cout << "3. Wyswietl wszystkich uzytkownikow biblioteki" << std::endl;
		std::cout << "4. Cofnij" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> wybor;
		if (wybor == "1") {
			Administrator::dodajUzytkownika();
		}
		else if (wybor == "2") {
			usunUzytkownika();
		}
		else if (wybor == "3") {
			wyswietlUzytkownikow();
		}
		else if (wybor == "4") {
			break;
		}
		else {
			std::cout << "Wybierz dostepna opcje!" << std::endl;
		}
	}
}

void Administrator::wyswietlKsiazki() {
	std::cout << "wyswietlam ksiazki dla admina";
}

void Administrator::dodajUzytkownika() {
	std::cout << "\n";
	std::cout << "Podaj imie nowego uzytkownika: ";
	std::getline(std::cin >> std::ws, imie); //czysci pierwsza linie przed getline
	std::cout << "Podaj nazwisko nowego uzytkownika: ";
	std::getline(std::cin, nazwisko);
	std::cout << "Podaj login nowego uzytkownika: ";
	std::getline(std::cin, login);
	std::cout << "Podaj haslo nowego uzytkownika: ";
	std::getline(std::cin, haslo);
	std::cout << "Podaj rodzaj nowego uzytkownika (Czytelnik/Bibliotekarz/Administrator): " << std::endl;
	std::getline(std::cin, rodzaj);

	if (rodzaj == "Czytelnik" || rodzaj == "Bibliotekarz" || rodzaj == "Administrator") {


		std::ofstream plik("uzytkownicy.txt", std::ios::app);
		if (!plik) {
			std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
			exit(0);
		}
		else {
			plik << imie << ";" << nazwisko << ";" << login << ";" << haslo << ";" << rodzaj << std::endl;
			plik.close();
		}
	}
	else {
		std::cout << "Dozwolone jedynie: Administrator/Bibliotekarz/Czytelnik" << std::endl;
	}

}

void Administrator::usunUzytkownika() {
	std::string login_do_usuniecia;
	std::cout << "Podaj login uzytkownika do usuniecia: ";
	std::getline(std::cin >> std::ws, login_do_usuniecia);

	std::ifstream plik_wejscie("uzytkownicy.txt");
	if (!plik_wejscie) {
		std::cerr << "Nie mozna otworzyc pliku uzytkownicy.txt!" << std::endl;
		return;
	}

	std::ofstream plik_wyjscie("temp2.txt");
	if (!plik_wyjscie) {
		std::cerr << "Nie mozna utworzyc pliku tymczasowego!" << std::endl;
		plik_wejscie.close();
		return;
	}

	bool znaleziono = false;
	std::string linia;
	while (std::getline(plik_wejscie, linia)) {
		std::istringstream iss(linia);
		std::string imie, nazwisko, login, haslo, rodzaj;

		std::getline(iss, imie, ';');
		std::getline(iss, nazwisko, ';');
		std::getline(iss, login, ';');
		std::getline(iss, haslo, ';');
		std::getline(iss, rodzaj, ';');

		if (login == login_do_usuniecia) {
			if (rodzaj == "Administrator") {
				std::cout << "Nie mozna usunac administratora!" << std::endl;
				plik_wyjscie << linia << std::endl;
			}
			else {
				znaleziono = true;
				std::cout << "Usunieto Uzytkownika: " << login << std::endl;
			}
		}
		else {
			plik_wyjscie << linia << std::endl;
		}
	}

	plik_wejscie.close();
	plik_wyjscie.close();

	if (!znaleziono) {
		std::cout << "Nie znaleziono uzytkownika o podanym loginie." << std::endl;
		std::remove("temp2.txt");
	}
	else {
		std::remove("uzytkownicy.txt");
		if (std::rename("temp2.txt", "uzytkownicy.txt") != 0) {
			std::cerr << "Blad podczas zmiany nazwy pliku!" << std::endl;
		};

	}
}

void Administrator::wyswietlUzytkownikow() {
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

			std::cout << "Uzytkownik: " << login << std::endl;
			std::cout << "imie i nazwisko: " << imie << " " << nazwisko << std::endl;
			std::cout << "haslo: " << haslo << std::endl;
			std::cout << "typ: " << typ << std::endl;
			std::cout << "\n";
			


		}

	}
}
#include <iostream>
#include "Administrator.hpp"
#include "Uzytkownicy.hpp"
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku

Administrator::Administrator(std::string i, std::string n, std::string l, std::string h, std::string r)
	: Uzytkownicy(i, n, l, h, r) {}

Administrator::Administrator() : Uzytkownicy("", "", "", "", "") {}

void Administrator::menu() {
	std::string wybor;
	while (true) {
		std::cout << "Wyswietlam menu Administratora: " << std::endl;
		std::cout << "1. Dodaj Uzytkownika" << std::endl;
		std::cout << "2. Usun Uzytkownika" << std::endl;
		std::cout << "3. Cofnij" << std::endl;
		std::cout << "Wybor: " << std::endl;
		std::cin >> wybor;
		if (wybor == "1") {
			Administrator::dodajUzytkownika();
		}
		else if (wybor == "2") {
			std::cout << "Przyszla funckja usuwnia" << std::endl;
		}
		else if (wybor == "3") {
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
	std::cout << "Podaj imie nowego uzytkownika: " << std::endl;
	std::getline(std::cin >> std::ws, imie); //czysci pierwsza linie przed getline
	std::cout << "Podaj nazwisko nowego uzytkownika: " << std::endl;
	std::getline(std::cin, nazwisko);
	std::cout << "Podaj login nowego uzytkownika: " << std::endl;
	std::getline(std::cin, login);
	std::cout << "Podaj haslo nowego uzytkownika: " << std::endl;
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
		exit (0);
	}

}

void Administrator::usunUzytkownika() {
	std::cout << "przyszla funckja do usuwania" << std::endl;
}
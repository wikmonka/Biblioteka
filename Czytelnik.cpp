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
    


void Czytelnik::menu() {
	std::cout << "Menu Czytelnika!" << std::endl;
	while (true) {
		std::string wybor;
		Ksiazka ksiazka;
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
    std::string linia, wybor, szukany_autor, szukany_nosnik, szukany_gatunek;

    std::cout << "\n";
    std::cout << "Wybierz typ filtra" << std::endl;
    std::cout << "1. Wszystko" << std::endl;
    std::cout << "2. Dostepne" << std::endl;
    std::cout << "3. Po nazwisku Autora" << std::endl;
    std::cout << "4. Po gatunku" << std::endl;
    std::cout << "5. Po nosniku" << std::endl;
    std::cout << "Wybor: ";
    std::cin >> wybor;
    std::cout << "\n";

    if (wybor == "3") {
        std::cout << "Podaj nazwisko autora: ";
        std::cin >> szukany_autor;
    }
    else if (wybor == "4") {
        std::cout << "Dostepne gatunki: Horror/Dramat/Komedia/Sci-Fi/Beletrystyka/Dokument/Biografia/Kryminal/Thriller/Romans. " << std::endl;
        std::cout << "Podaj gatunek: ";
        std::cin >> szukany_gatunek;
    }
    else if (wybor == "5") {
        std::cout << "Podaj nosnik (ksiazka/e-book/audiobook): ";
        std::cin >> szukany_nosnik;
    }


    if (plik.good() == false)
    {
        std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
        exit(0);
    }
    else {
        std::cout << "Lista ksiazek w bibliotece: " << std::endl;
        std::cout << "\n";
        bool found = false;
        while (std::getline(plik, linia)) {
            std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, nosnik, stan;

            std::istringstream iss(linia);
            std::getline(iss, tytul, ';');
            std::getline(iss, autor_imie, ';');
            std::getline(iss, autor_nazwisko, ';');
            std::getline(iss, gatunek, ';');
            std::getline(iss, opis, ';');
            std::getline(iss, s_rok, ';');
            std::getline(iss, nosnik, ';');
            std::getline(iss, stan, ';');

            int rok_wydania = std::stoi(s_rok);
            bool match = false;

            if (wybor == "1") {
                match = true;
            }
            else if (wybor == "2") {
                if (stan == "wolna") {
                    match = true;
                }
            }
            else if (wybor == "3") {
                if (autor_nazwisko == szukany_autor) {
                    match = true;
                }
            }
            else if (wybor == "4") {
                if (gatunek == szukany_gatunek) {
                    match = true;
                }
            }
            else if (wybor == "5") {
                if (nosnik == szukany_nosnik) {
                    match = true;
                }
            }
            else {
                std::cout << "Wybierz dostepna opcje!" << std::endl;
                std::cout << "\n";
                break;
            }

            if (match) {
                std::cout << "Tytul: " << tytul << std::endl;
                std::cout << "Autor: " << autor_imie << " " << autor_nazwisko << std::endl;
                std::cout << "Gatunek: " << gatunek << std::endl;
                std::cout << "Opis: " << opis << std::endl;
                std::cout << "Rok wydania: " << rok_wydania << std::endl;
                std::cout << "Nosnik: " << nosnik << std::endl;
                if (stan == "wolna") {
                    std::cout << "Stan: Dostepna" << std::endl;
                }
                else {
                    std::cout << "Stan: Wypozyczona" << std::endl;
                }
                std::cout << "--------------------------------" << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "Nie znaleziono pasujacych ksiazek." << std::endl;
        }
    }
    plik.close();
    std::cout << "\n";
}

void Czytelnik::dodajUzytkownika() {
}

void Czytelnik::wyswietlUzytkownikow() {

}
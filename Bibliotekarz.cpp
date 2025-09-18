#include <iostream>
#include "Bibliotekarz.hpp"
#include "Uzytkownicy.hpp"
#include "Ksiazka.hpp"
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku


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
		std::cout << "5. Dodaj Czytelnika" << std::endl;
		std::cout << "6. Cofnij" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> wybor;

		if (wybor == "1") {
			wyswietlKsiazki();
		}
		else if (wybor == "2") {
			ksiazka.zapiszKsiazke();
		}
		else if (wybor == "3") {
			ksiazka.usunKsiazke();
		} 
		else if (wybor == "4") {
			wyswietlUzytkownikow();
		}
		else if (wybor == "5") {
			Bibliotekarz::dodajUzytkownika();
		}
		else if (wybor == "6") {
			break;
		}
		else {
			std::cout << "Nie ma takie opcji!";
		}
	}
}

void Bibliotekarz::wyswietlKsiazki() {
    std::ifstream plik("ksiazki.txt", std::ios::in);
    std::string linia, wybor, szukany_autor, szukany_nosnik, szukany_gatunek, szukany_czytelnik;

    std::cout << "\n";
    std::cout << "Wybierz typ filtra" << std::endl;
    std::cout << "1. Wszystko" << std::endl;
    std::cout << "2. Dostepne" << std::endl;
    std::cout << "3. Po nazwisku Autora" << std::endl;
    std::cout << "4. Po gatunku" << std::endl;
    std::cout << "5. Po nosniku" << std::endl;
    std::cout << "6. Wypozyczone przez konkretnego Czytelnika" << std::endl;
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
    else if (wybor == "6") {
        std::cout << "Podaj login Czytelnika:  ";
        std::cin >> szukany_czytelnik;
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
            else if (wybor == "6") {
                if (stan == szukany_czytelnik) {
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
                    std::cout << "Stan: Wypozyczona przez - " << stan << std::endl;
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




void Bibliotekarz::dodajUzytkownika() {
	std::cout << "\n";
	std::cout << "Podaj imie nowego czytelnika: " << std::endl;
	std::getline(std::cin >> std::ws, imie); //czysci pierwsza linie przed getline
	std::cout << "Podaj nazwisko nowego czytelnika: " << std::endl;
	std::getline(std::cin, nazwisko);
	std::cout << "Podaj login nowego czytelnika: " << std::endl;
	std::getline(std::cin, login);
	std::cout << "Podaj haslo nowego czytelnika: " << std::endl;
	std::getline(std::cin, haslo);



	std::ofstream plik("uzytkownicy.txt", std::ios::app);
	if (!plik) {
		std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
		exit(0);
	}
	else {
		plik << imie << ";" << nazwisko << ";" << login << ";" << haslo << ";" << "Czytelnik" << std::endl;
		std::cout << "Dodano nowego czytelnika: " << login << std::endl;
		plik.close();
	}
}


void Bibliotekarz::wyswietlUzytkownikow() {
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
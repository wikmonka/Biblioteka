#include "Ksiazka.hpp"
#include "Uzytkownicy.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku



Ksiazka::Ksiazka(/*int id, */std::string t, std::string a_i, std::string a_n, std::string g, std::string o, int r_w, std::string n, std::string s) {
	//id_ksiazki = id;
	tytul = t;
	autor_imie = a_i;
	autor_nazwisko = a_n;
	gatunek = g;
	opis = o;
	rok_wydania = r_w;
	nosnik = n;
	stan = s;

}

void Ksiazka::zapiszKsiazke() {

	//id_ksiazki++;
	std::cout << "\n";
	std::cout << "Podaj tytul ksiazki: ";
	std::getline(std::cin >> std::ws,tytul); //czysci pierwsza linie przed getline
	std::cout << "Podaj imie autora: ";
	std::getline(std::cin, autor_imie);
	std::cout << "Podaj nazwisko autora: ";
	std::getline(std::cin, autor_nazwisko);
	std::cout << "Dostepne gatunki: Horror/Dramat/Komedia/Sci-Fi/Beletrystyka/Dokument/Biografia/Kryminal/Thriller/Romans. " << std::endl;
	std::cout << "Wybor: ";
	std::getline(std::cin, gatunek);
	std::cout << "Podaj opis: ";
	std::getline(std::cin, opis);
	std::cout << "Podaj rok wydania: ";
	std::cin >> rok_wydania;
	std::cout << "nosnik (ksiazka/e-book/audiobook): ";
	std::cin >> nosnik;

	std::ofstream plik("ksiazki.txt", std::ios::app);
	if (nosnik == "ksiazka" || nosnik == "e-book" || nosnik == "audiobook") {
		if (gatunek == "Horror" || gatunek == "Dramat" || gatunek == "Komedia" || gatunek == "Sci-Fi" || gatunek == "Beletrystyka" || gatunek == "Dokument" || gatunek == "Biografia" || gatunek == "Kryminal" || gatunek == "Thriller" || gatunek == "Romans") {
			if (!plik) {
				std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
				return;
			}
			else {
				plik /* << id_ksiazki << ";"*/ << tytul << ";" << autor_imie << ";" << autor_nazwisko << ";" << gatunek << ";" << opis << ";" << rok_wydania << ";" << nosnik << ";" << "wolna" << std::endl;
				plik.close();
				std::cout << "Pomyslnie dodano nowy/a " << nosnik << ": " << tytul << std::endl;
			}
		}
		else {
			std::cout << "Podaj odpowieni gatunek!" << std::endl;
			std::cout << "\n";
			return;
		}
	}
	else {
		std::cout << "Podaj odpowieni Nosnik!" << std::endl;
		std::cout << "\n";
		return;
	}
	

	

	
}

void Ksiazka::usunKsiazke() {
	std::string tytul_do_usuniecia;
	std::cout << "Podaj tytul ksiazki do wypozyczenia: ";
	std::getline(std::cin >> std::ws, tytul_do_usuniecia);

	std::ifstream plik_wejscie("ksiazki.txt");
	if (!plik_wejscie) {
		std::cerr << "Nie mozna otworzyc pliku ksiazki.txt!" << std::endl;
		return;
	}

	std::ofstream plik_wyjscie("temp.txt");
	if (!plik_wyjscie) {
		std::cerr << "Nie mozna utworzyc pliku tymczasowego!" << std::endl;
		plik_wejscie.close();
		return;
	}

	bool znaleziono = false;
	std::string linia;
	while (std::getline(plik_wejscie, linia)) {
		std::istringstream iss(linia);
		std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, nosnik, stan;

		std::getline(iss, tytul, ';');
		std::getline(iss, autor_imie, ';');
		std::getline(iss, autor_nazwisko, ';');
		std::getline(iss, gatunek, ';');
		std::getline(iss, opis, ';');
		std::getline(iss, s_rok, ';');
		std::getline(iss, nosnik, ';');
		std::getline(iss, stan, ';');

		if (tytul == tytul_do_usuniecia) {
			znaleziono = true;
			std::cout << "Usunieto ksiazke: " << tytul << std::endl;
		}
		else {
			plik_wyjscie << linia << std::endl;
		}
	}

	plik_wejscie.close();
	plik_wyjscie.close();

	if (!znaleziono) {
		std::cout << "Nie znaleziono ksiazki o podanym tytule." << std::endl;
		std::remove("temp.txt");
	}
	else {
		std::remove("ksiazki.txt");
		if (std::rename("temp.txt", "ksiazki.txt") != 0) {
			std::cerr << "Blad podczas zmiany nazwy pliku!" << std::endl;
		};

	}
}


void Ksiazka::wypozyczKsiazke(std::string uzytkownik_login) {
	std::string tytul_do_wypozyczenia;
	std::cout << "Podaj tytul ksiazki do wypozyczenia: ";
	std::getline(std::cin >> std::ws, tytul_do_wypozyczenia);

	std::ifstream plik_wejscie("ksiazki.txt");
	if (!plik_wejscie) {
		std::cerr << "Nie mozna otworzyc pliku ksiazki.txt!" << std::endl;
		return;
	}

	std::ofstream plik_wyjscie("temp.txt");
	if (!plik_wyjscie) {
		std::cerr << "Nie mozna utworzyc pliku tymczasowego!" << std::endl;
		plik_wejscie.close();
		return;
	}

	bool znaleziono = false;
	std::string linia;
	while (std::getline(plik_wejscie, linia)) {
		std::istringstream iss(linia);
		std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, nosnik, stan;
		std::getline(iss, tytul, ';');
		std::getline(iss, autor_imie, ';');
		std::getline(iss, autor_nazwisko, ';');
		std::getline(iss, gatunek, ';');
		std::getline(iss, opis, ';');
		std::getline(iss, s_rok, ';');
		std::getline(iss, nosnik, ';');
		std::getline(iss, stan, ';');

		if (tytul == tytul_do_wypozyczenia) {
			znaleziono = true;
			if (stan == "wolna") {
				plik_wyjscie << tytul << ";" << autor_imie << ";" << autor_nazwisko << ";" << gatunek << ";" << opis << ";" << s_rok << ";" << nosnik << ";" << uzytkownik_login << std::endl;
				std::cout << "Pomyslnie wypozyczono ksiazke: " << tytul << std::endl;
			}
			else {
				plik_wyjscie << linia << std::endl;
				std::cout << tytul <<"Ta ksiazka jest obecnie wypozyczona " << std::endl;
			}
		}
		else {
			plik_wyjscie << linia << std::endl;
		}
	}

	plik_wejscie.close();
	plik_wyjscie.close();

	if (!znaleziono) {
		std::cout << "Nie znaleziono ksiazki o podanym tytule." << std::endl;
		std::remove("temp.txt");
	}
	else {
		std::remove("ksiazki.txt");
		if (std::rename("temp.txt", "ksiazki.txt") != 0) {
			std::cerr << "Blad podczas zmiany nazwy pliku!" << std::endl;
		};
		
	}
}


void Ksiazka::sprawdzWypozyczone(std::string uzytkownik_login) {
	std::ifstream plik("ksiazki.txt", std::ios::in);
	std::string linia;
	std::cout << "\n";
	if (plik.good() == false)
	{
		std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
		exit(0);
	}
	else {
		std::cout << "Twoje wypozyczone ksiazki " << std::endl;
		std::cout << "\n";
		while (std::getline(plik, linia)) {
			std::string /*s_id,*/ tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, nosnik, stan;

			std::istringstream iss(linia);
			//std::getline(iss, s_id, ';');
			std::getline(iss, tytul, ';');
			std::getline(iss, autor_imie, ';');
			std::getline(iss, autor_nazwisko, ';');
			std::getline(iss, gatunek, ';');
			std::getline(iss, opis, ';');
			std::getline(iss, s_rok, ';');
			std::getline(iss, nosnik, ';');
			std::getline(iss, stan, ';');

			//int id_ksiazki = std::stoi(s_id);
			int rok_wydania = std::stoi(s_rok);

			if (stan == uzytkownik_login) {

				std::cout << "Tytul: " << tytul << std::endl;
				std::cout << "Autor: " << autor_imie << " " << autor_nazwisko << std::endl;
				std::cout << "Gatunek: " << gatunek << std::endl;
				std::cout << "Opis: " << opis << std::endl;
				std::cout << "Rok wydania: " << rok_wydania << std::endl;
				std::cout << "Nosnik: " << nosnik << std::endl;
				std::cout << "Stan: " << stan << std::endl;
				std::cout << "--------------------------------" << std::endl;
			}
			else {
				continue;
			}
		}
	}
}

void Ksiazka::zwrocKsiazke(std::string uzytkownik_login) {
	std::string tytul_do_zwrotu;
	std::cout << "Podaj tytul ksiazki do zwrotu: ";
	std::getline(std::cin >> std::ws, tytul_do_zwrotu);

	std::ifstream plik_wejscie("ksiazki.txt");
	if (!plik_wejscie) {
		std::cerr << "Nie mozna otworzyc pliku ksiazki.txt!" << std::endl;
		return;
	}

	std::ofstream plik_wyjscie("temp.txt");
	if (!plik_wyjscie) {
		std::cerr << "Nie mozna utworzyc pliku tymczasowego!" << std::endl;
		plik_wejscie.close();
		return;
	}

	bool znaleziono = false;
	std::string linia;
	while (std::getline(plik_wejscie, linia)) {
		std::istringstream iss(linia);
		std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok, nosnik, stan;

		std::getline(iss, tytul, ';');
		std::getline(iss, autor_imie, ';');
		std::getline(iss, autor_nazwisko, ';');
		std::getline(iss, gatunek, ';');
		std::getline(iss, opis, ';');
		std::getline(iss, s_rok, ';');
		std::getline(iss, nosnik, ';');
		std::getline(iss, stan, ';');

		if (tytul == tytul_do_zwrotu) {
			znaleziono = true;
			if (stan == uzytkownik_login) {
				plik_wyjscie << tytul << ";" << autor_imie << ";" << autor_nazwisko << ";" << gatunek << ";" << opis << ";" << s_rok << ";" << nosnik << ';' << "wolna" << std::endl;
				std::cout << "Oddano ksiazke: " << tytul << std::endl;
			}
			else {
				plik_wyjscie << linia << std::endl;
				std::cout << tytul << " - Ta ksiazka nie jest przez Ciebie wypozyczona" << std::endl;
			}
		}
		else {
			plik_wyjscie << linia << std::endl;
		}
	}

	plik_wejscie.close();
	plik_wyjscie.close();

	if (!znaleziono) {
		std::cout << "Nie znaleziono ksiazki o podanym tytule." << std::endl;
		std::remove("temp.txt");
	}
	else {
		std::remove("ksiazki.txt");
		if (std::rename("temp.txt", "ksiazki.txt") != 0) {
    std::cerr << "Blad podczas zmiany nazwy pliku!" << std::endl;
}
	}
}
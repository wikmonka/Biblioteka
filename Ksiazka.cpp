#include "Ksiazka.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits> //czyszczenie linii przed getline
#include <cstdlib>//exit przy sprawdzaniu odczytu pliku



Ksiazka::Ksiazka(/*int id, */std::string t, std::string a_i, std::string a_n, std::string g, std::string o, int r_w) {
	//id_ksiazki = id;
	tytul = t;
	autor_imie = a_i;
	autor_nazwisko = a_n;
	gatunek = g;
	opis = o;
	rok_wydania = r_w;

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
	std::cout << "Podaj gatunek: ";
	std::getline(std::cin, gatunek);
	std::cout << "Podaj opis: ";
	std::getline(std::cin, opis);
	std::cout << "Podaj rok wydania: ";
	std::cin >> rok_wydania;


	std::ofstream plik("ksiazki.txt", std::ios::app);

	if (!plik) {
		std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
		exit(0);
	}
	else {
		plik /* << id_ksiazki << ";"*/ << tytul << ";" << autor_imie << ";" << autor_nazwisko << ";" << gatunek << ";" << opis << ";" << rok_wydania << std::endl;
		plik.close();
	}
}

void Ksiazka::wyswietlKsiazki() {
	std::ifstream plik("ksiazki.txt", std::ios::in);
	std::string linia;
	std::cout << "\n";
	if (plik.good() == false)
	{
		std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
		exit(0);
	} else{
		std::cout << "Lista ksiazek w bibliotece: " << std::endl;
		while (std::getline(plik, linia)) {
			std::string /*s_id,*/ tytul, autor_imie, autor_nazwisko, gatunek, opis, s_rok;
			
			std::istringstream iss(linia);
			//std::getline(iss, s_id, ';');
			std::getline(iss, tytul, ';');
			std::getline(iss, autor_imie, ';');
			std::getline(iss, autor_nazwisko, ';');
			std::getline(iss, gatunek, ';');
			std::getline(iss, opis, ';');
			std::getline(iss, s_rok, ';');

			//int id_ksiazki = std::stoi(s_id);
			int rok_wydania = std::stoi(s_rok);

			//std::cout << "ID ksiazki: " << id_ksiazki << std::endl;
			std::cout << "Tytul: " << tytul << std::endl;
			std::cout << "Autor: " << autor_imie << " " << autor_nazwisko << std::endl;
			std::cout << "Gatunek: " << gatunek << std::endl;
			std::cout << "Opis: " << opis << std::endl;
			std::cout << "Rok wydania: " << rok_wydania << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}
	}
	

	
	

}



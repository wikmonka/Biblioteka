#pragma once	
#include <iostream>
#include <string>
#include <fstream>


class Ksiazka {
public:
	std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, stan;
	int /*id_ksiazki, */rok_wydania;

	Ksiazka(/*int = 0,*/ std::string = "tytul_test", std::string = "autor_imie_test", std::string = "autor_nazwisko_test", std::string = "gatunek_test", std::string = "opis_test", int = 0, std::string = "");

	~Ksiazka() {}
	void wyswietlKsiazki();

	void zapiszKsiazke();

	void wypozyczKsiazke();

	
};


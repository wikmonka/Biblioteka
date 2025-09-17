#pragma once	
#include <iostream>
#include <string>
#include <fstream>


class Ksiazka {
public:
	std::string tytul, autor_imie, autor_nazwisko, gatunek, opis, nosnik, stan;
	int /*id_ksiazki, */rok_wydania;

	Ksiazka(std::string = "tytul_test", std::string = "autor_imie_test", std::string = "autor_nazwisko_test", std::string = "gatunek_test", std::string = "opis_test", int = 0, std::string = "", std::string = "");

	~Ksiazka() {}
	

	void zapiszKsiazke();

	void usunKsiazke();

	void wypozyczKsiazke(std::string uzytkownik_login);

	void sprawdzWypozyczone(std::string uzytkownik_login);

	void zwrocKsiazke(std::string uzytkownik_login);
	
};


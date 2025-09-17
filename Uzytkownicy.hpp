#pragma once	
#include <iostream>
#include <string>

class Uzytkownicy {
public:
	std::string imie, nazwisko, login, haslo, rodzaj;

	Uzytkownicy(std::string i, std::string n, std::string l, std::string h, std::string r);

	~Uzytkownicy() {}

	virtual void menu() = 0;

	
};
std::pair<std::string, std::string> wczytajUzytkownikow();
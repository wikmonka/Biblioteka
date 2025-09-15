#include <iostream>
#include "Bibliotekarz.hpp"
#include "Uzytkownicy.hpp"


Bibliotekarz::Bibliotekarz(std::string i, std::string n, std::string l, std::string h, std::string r)
	: Uzytkownicy(i, n, l, h, r) {}

Bibliotekarz::Bibliotekarz() : Uzytkownicy("", "", "", "", "") {}

void Bibliotekarz::menu() {
	std::cout << "Udalo sie! Wyswietlam menu dla Bibliotekarza" << std::endl;
}
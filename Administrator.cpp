#include <iostream>
#include "Administrator.hpp"
#include "Uzytkownicy.hpp"

Administrator::Administrator(std::string i, std::string n, std::string l, std::string h, std::string r)
	: Uzytkownicy(i, n, l, h, r) {}

Administrator::Administrator() : Uzytkownicy("", "", "", "", "") {}

void Administrator::menu() {
	std::cout << "Udalo sie! Wyswietlam menu Administratora!" << std::endl;
}
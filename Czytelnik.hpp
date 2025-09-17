#pragma once	
#include <iostream>
#include <string>
#include "Uzytkownicy.hpp"


class Czytelnik : public Uzytkownicy {
public:
	Czytelnik();
	void menu();
	Czytelnik(std::string i, std::string n, std::string l, std::string h, std::string r);

};
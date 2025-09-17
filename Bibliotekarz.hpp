#pragma once	
#include <iostream>
#include <string>
#include "Uzytkownicy.hpp"

class Bibliotekarz : public Uzytkownicy {
public:
	Bibliotekarz();
	void menu();
	Bibliotekarz(std::string i, std::string n, std::string l, std::string h, std::string r);

};
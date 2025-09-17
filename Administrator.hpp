#pragma once
#include <iostream>
#include <string>
#include "Uzytkownicy.hpp"


class Administrator : public Uzytkownicy {
public:
	Administrator();
	void menu();
	Administrator(std::string i, std::string n, std::string l, std::string h, std::string r);

};
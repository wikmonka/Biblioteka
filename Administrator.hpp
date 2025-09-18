#pragma once
#include <iostream>
#include <string>
#include "Uzytkownicy.hpp"


class Administrator : public Uzytkownicy {
public:
	Administrator();
	void menu();
	void wyswietlKsiazki();
	void dodajUzytkownika();
	void usunUzytkownika();
	void wyswietlUzytkownikow();
};
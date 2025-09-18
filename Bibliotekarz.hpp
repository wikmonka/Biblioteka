#pragma once	
#include <iostream>
#include <string>
#include "Uzytkownicy.hpp"

class Bibliotekarz : public Uzytkownicy {
public:
	Bibliotekarz();
	void menu();
	
	void wyswietlKsiazki();
	void dodajUzytkownika();
	void wyswietlUzytkownikow();

};
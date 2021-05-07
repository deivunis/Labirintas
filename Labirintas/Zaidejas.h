#pragma once

#include <iostream>
#include "Labirintas.h"

using namespace std;

class Zaidejas : public Labirintas
{
public:
	void Vardas();
	string get_Vardas();
	int get_Gyvybes();
	void virsu(int& x, int& y);
	void apacia(int& posx, int& posy);
	void kaire(int& x, int& y);
	void desine(int& x, int& y);
};
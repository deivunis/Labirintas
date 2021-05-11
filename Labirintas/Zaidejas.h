#pragma once

#include <iostream>
#include "Labirintas.h"

using namespace std;

class Zaidejas : public Labirintas
{
public:
	int gyvybes;
	int dmg;
	int pinigai;
	bool ar_nukove;
public:
	Zaidejas()
	{
		gyvybes = 100;
		dmg = 30;
		pinigai = 0;
		ar_nukove = false;
	}
	~Zaidejas() {};
public:
	void Vardas();
	string get_Vardas();
	int get_Gyvybes();
	int get_Pinigai();
	void virsu(int& posx, int& posy);
	void apacia(int& posx, int& posy);
	void kaire(int& posx, int& posy);
	void desine(int& posx, int& posy);
	void Kova(bool& ar_nukove);
};
#pragma once

#include <iostream>
#include "Labirintas.h"
#include "Inventorius.h"

using namespace std;

class Zaidejas : public Labirintas
{
public:
	vector<inventorius> kuprine;
	
public:
	int gyvybes;
	int energija;
	int dmg;
	int pinigai;
	bool ar_nukove;
	bool ar_rado;
	int kiekis;
	int zingsniai;
public:
	Zaidejas()
	{
		gyvybes = 100;
		energija = 100;
		dmg = 0;
		pinigai = 0;
		ar_nukove = false;
		ar_rado = false;
		kiekis = 0;
		zingsniai = 0;
	}
	~Zaidejas() {};
public:
	void operator ++();
	string get_Vardas();
	int get_Gyvybes();
	int get_Energija();
	int get_Pinigai();
	void virsu(int& posx, int& posy);
	void apacia(int& posx, int& posy);
	void kaire(int& posx, int& posy);
	void desine(int& posx, int& posy);
	void Kova(bool& ar_nukove, int& posx, int& posy);
	void Rasti(bool& ar_rado, int& posx, int& posy);
	int operator +(Zaidejas x);
};
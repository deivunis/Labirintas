#pragma once

#include <iostream>

using namespace std;
class Zemelapis;
class Zaidejas
{
public:
	string slapyvardis;
	int gyvybes = 100;
	int width, height;
	int x = 0;
	int y = 0;
	int posx = 1;
	int posy = 1;
	char judeti;
	bool ar_laimejo = false;
	/*Zemelapis* lengvas_lygis[10][20];
	Zaidejas(Zemelapis* lengvas_lygis[10][20])
	{
		_mapp[10][20] = lengvas_lygis[10][20];
	}*/

public:
	class Zemelapis;
	void Vardas();
	string get_Vardas();
	int get_Gyvybes();
	void virsu(int& x, int& y);
	void apacia(int& x, int& y);
	void kaire(int& x, int& y);
	void desine(int& x, int& y);
};
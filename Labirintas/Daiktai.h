#pragma once
#include "Labirintas.h"
#include "Zemelapiai.h"

class Items : public Labirintas
{
public:
	//lengvas lygis
	int amx, amy;
	int gex, gey;
	int eex, eey;
	//vidutinis lygis
	int amx2, amy2, amx3, amy3;
	int gex2, gey2, gex3, gey3;
	int eex2, eey2, eex3, eey3;
	//bendri
	char aukso_maisas;
	char gyvybiu_eleksyras;
	char energijos_eleksyras;
public:
	Items()
	{
		//lengvas lygis
		amx = 3, amy = 12;
		gex = 3, gey = 5;
		eex = 2, eey = 18;
		//vidutinis lygis
		amx2 = 13, amy2 = 25;
		amx3 = 16, amy3 = 1;
		gex2 = 11, gey2 = 13;
		gex3 = 7, gey3 = 7;
		eex2 = 29, eey2 = 27;
		eex3 = 23, eey3 = 4;
		//bendri
		aukso_maisas = (36);
		gyvybiu_eleksyras = { 3 };
		energijos_eleksyras = (175);
	}
	~Items() {};
public:
	int Random();
	string Maisas();
	string Hp();
	string Energy();
};

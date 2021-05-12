#pragma once
#include "Labirintas.h"
#include "Zemelapiai.h"

class Items : public Labirintas
{
public:
	int amx, amy;
	int gex, gey;
	int eex, eey;
	char aukso_maisas;
	char gyvybiu_eleksyras;
	char energijos_eleksyras;
public:
	Items()
	{
		amx = 3, amy = 12;
		gex = 3, gey = 5;
		eex = 2, eey = 18;
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

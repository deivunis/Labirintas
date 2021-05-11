#pragma once
#include "Labirintas.h"
#include "Zaidejas.h"
#include "Zemelapiai.h"


class Priesas : public Labirintas
{
public:
	int gx, gy;
	int vx, vy;
	char goblinas;
	char vilkolakis;
public:
	Priesas()
	{
		gx = 7;
		gy = 1;
		vx = 4;
		vy = 9;
		goblinas = { 4 };
		vilkolakis = { 6 };
	}
	~Priesas() {};
public:
	//virtual void Monstras() = 0;
	virtual int Damage() = 0;
};
class Goblinas : public Priesas
{
public:
	//void Monstras();
	int Damage();
	int goblino_Pinigai();
};
class Vilkolakis : public Priesas
{
public:
	int Damage();
	int vilkolakio_Eleksyras();
};

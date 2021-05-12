#pragma once
#include "Labirintas.h"
#include "Zaidejas.h"
#include "Zemelapiai.h"


class Priesas : public Labirintas
{
public:
	//lengvas lygis
	int gx, gy;
	int vx, vy;
	int sx, sy;
	//vidutinis lygis
	int gx2, gy2;
	int vx2, vy2;
	int sx2, sy2;
	//bendri
	char goblinas;
	char vilkolakis;
	char skeletonas;
public:
	Priesas()
	{
		//lengvas lygis
		gx = 7, gy = 1;
		vx = 4, vy = 9;
		sx = 3, sy = 1;
		//vidutinis lygis
		gx2 = 10, gy2 = 25;
		vx2 = 13, vy2 = 19;
		sx2 = 5, sy2 = 13;
		//bendri
		goblinas = { 4 };
		vilkolakis = { 6 };
		skeletonas = { 5 };
	}
	virtual ~Priesas() {};
public:
	//virtual void Monstras() = 0;
	virtual int Damage() = 0;
	virtual int Exhaustion() = 0;
};
class Goblinas : public Priesas
{
public:
	//void Monstras();
	int Damage();
	int Exhaustion();
	int goblino_Pinigai();
	virtual ~Goblinas() {};
};
class Vilkolakis : public Priesas
{
public:
	int Damage();
	int Exhaustion();
	int vilkolakio_Eleksyras();
	virtual ~Vilkolakis() {};
};
class Skeletonas : public Priesas
{
public:
	int Damage();
	int Exhaustion();
	int skeletono_Eleksyras();
	virtual ~Skeletonas() {};
};

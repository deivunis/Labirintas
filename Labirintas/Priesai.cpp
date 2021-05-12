#include "Priesai.h"

using namespace std;

/*/void Goblinas::Monstras()
{
	mx = 7;
	my = 1;
	monstras = { 4 };
}*/
int Goblinas::Damage()
{
	srand((unsigned)time(0));
	int dmg = 1 + (rand() % 30);
	return dmg;
}
int Goblinas::Exhaustion()
{
	srand((unsigned)time(0));
	int exh = 1 + (rand() % 30);
	return exh;
}
int Goblinas::goblino_Pinigai()
{
	srand((unsigned)time(0));
	int money = 1 + (rand() % 100);
	return money;
}
int Vilkolakis::Damage()
{
	srand((unsigned)time(0));
	int dmg = 1 + (rand() % 50);
	return dmg;
}
int Vilkolakis::Exhaustion()
{
	srand((unsigned)time(0));
	int exh = 1 + (rand() % 15);
	return exh;
}
int Vilkolakis::vilkolakio_Eleksyras()
{
	srand((unsigned)time(0));
	int hp = 1 + (rand() % 20);
	return hp;
}
int Skeletonas::Damage()
{
	srand((unsigned)time(0));
	int dmg = 1 + (rand() % 25);
	return dmg;
}
int Skeletonas::Exhaustion()
{
	srand((unsigned)time(0));
	int exh = 1 + (rand() % 50);
	return exh;
}
int Skeletonas::skeletono_Eleksyras()
{
	srand((unsigned)time(0));
	int pwr = 1 + (rand() % 20);
	return pwr;
}

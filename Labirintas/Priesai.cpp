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
int Goblinas::goblino_Pinigai()
{
	return 18;
}
int Vilkolakis::Damage()
{
	srand((unsigned)time(0));
	int dmg = 1 + (rand() % 50);
	return dmg;
}
int Vilkolakis::vilkolakio_Eleksyras()
{
	return 10;
}

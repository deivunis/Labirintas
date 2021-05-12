#include "Daiktai.h"

using namespace std;

int Items::Random()
{
	srand((unsigned)time(0));
	int skaicius = 1 + (rand() % 100);
	return skaicius;
}
string Items::Maisas()
{
	string auksas = "Aukso Maisas";
	return auksas;
}
string Items::Hp()
{
	string hp = "Gyvybiu eleksyras";
	return hp;
}
string Items::Energy()
{
	string energy = "Energijos eleksyras";
	return energy;
}


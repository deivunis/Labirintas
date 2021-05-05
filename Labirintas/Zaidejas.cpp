#include "Zaidejas.h"
#include "Zemelapiai.h"

using namespace std;

void Zaidejas::Vardas()
{
	cin >> slapyvardis;
}

string Zaidejas::get_Vardas()
{
	return slapyvardis;
}

int Zaidejas::get_Gyvybes()
{
	return gyvybes;
}

void Zaidejas::virsu(int& x, int& y)
{
    if (Zemelapis::lengvas_lygis[x][y - 1] == ' ')
    {
    }
}
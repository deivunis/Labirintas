#include "Labirintas.h"
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
void Zaidejas::virsu(int& posx, int& posy)
{
    if (lengvas_lygis[posx - 1][posy] == ' ')
    {
        pposx = posx;
        pposy = posy;
        posx--;
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::apacia(int& posx, int& posy)
{
    if (lengvas_lygis[posx + 1][posy] == ' ')
    {
        pposx = posx;
        pposy = posy;
        posx++;
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::kaire(int& posx, int& posy)
{
    if (lengvas_lygis[posx][posy - 1] == ' ')
    {
        pposx = posx;
        pposy = posy;
        posy--;
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::desine(int& posx, int& posy)
{
    if (lengvas_lygis[posx][posy + 1] == ' ')
    {
        pposx = posx;
        pposy = posy;
        posy++;
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
#include "Zaidejas.h"
#include "Zemelapiai.h"

using namespace std;
Zemelapis zemelapis;
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
    char v_laikinas[100][100];
    if (zemelapis.lengvas_lygis[x][y - 1] == ' ') 
    {
        zemelapis.lengvas_lygis[x][y - 1] = zemelapis.lengvas_lygis[x][y];
        zemelapis.lengvas_lygis[x][y] = { 'X' };

    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::apacia(int& x, int& y)
{
    char a_laikinas[100][100];
    if (zemelapis.lengvas_lygis[x][y + 1] == ' ')
    {
        zemelapis.lengvas_lygis[x][y + 1] = zemelapis.lengvas_lygis[x][y];
        zemelapis.lengvas_lygis[x][y] = { 'X' };
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::kaire(int& x, int& y)
{
    char k_laikinas[100][100];
    if (zemelapis.lengvas_lygis[x - 1][y] == ' ')
    {
        zemelapis.lengvas_lygis[x - 1][y] = zemelapis.lengvas_lygis[x][y];
        zemelapis.lengvas_lygis[x][y] = { 'X' };
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
void Zaidejas::desine(int& x, int& y)
{
    char d_laikinas[100][100];
    if (zemelapis.lengvas_lygis[x + 1][y] == ' ')
    {
        zemelapis.lengvas_lygis[x + 1][y] = zemelapis.lengvas_lygis[x][y];
        zemelapis.lengvas_lygis[x][y] = { 'X' };
    }
    else
    {
        cout << "Atsitrenkei i siena!" << endl;
    }
}
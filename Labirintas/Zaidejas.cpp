#include "Labirintas.h"
#include "Zaidejas.h"
#include "Zemelapiai.h"
#include "Priesai.h"

using namespace std;

Priesas* pG2 = new Goblinas();
Goblinas* pGD2 = dynamic_cast<Goblinas*>(pG2);
Priesas* pV2 = new Vilkolakis();
Vilkolakis* pVD2 = dynamic_cast<Vilkolakis*>(pV2);

void Zaidejas::Vardas()
{
	cin >> slapyvardis;
}

string Zaidejas::get_Vardas()
{
	return slapyvardis;
}

int Zaidejas::get_Pinigai()
{
    return pinigai;
}

void Zaidejas::virsu(int& posx, int& posy)
{
    if (levelis == 1)
    {
        if (lengvas_lygis[posx - 1][posy] == ' ')
        {
            pposx = posx;
            pposy = posy;
            posx--;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
    if (levelis == 2)
    {
        if (vidutinis_lygis[posx - 1][posy] == ' ')
        {
            pposx2 = posx;
            pposy2 = posy;
            posx--;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
}

void Zaidejas::apacia(int& posx, int& posy)
{
    if (levelis == 1)
    {
        if (lengvas_lygis[posx + 1][posy] == ' ')
        {
            pposx = posx;
            pposy = posy;
            posx++;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
    if (levelis == 2)
    {
        if (vidutinis_lygis[posx + 1][posy] == ' ')
        {
            pposx2 = posx;
            pposy2 = posy;
            posx++;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
}

void Zaidejas::kaire(int& posx, int& posy)
{
    if (levelis == 1)
    {
        if (lengvas_lygis[posx][posy - 1] == ' ')
        {
            pposx = posx;
            pposy = posy;
            posy--;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
    if (levelis == 2)
    {
        if (vidutinis_lygis[posx][posy - 1] == ' ')
        {
            pposx2 = posx;
            pposy2 = posy;
            posy--;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
}

void Zaidejas::desine(int& posx, int& posy)
{
    if (levelis == 1)
    {
        if (lengvas_lygis[posx][posy + 1] == ' ')
        {
            pposx = posx;
            pposy = posy;
            posy++;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
    if (levelis == 2)
    {
        if (vidutinis_lygis[posx][posy + 1] == ' ')
        {
            pposx2 = posx;
            pposy2 = posy;
            posy++;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
}

void Zaidejas::Kova(bool& ar_nukove)
{
    //pG2->Monstras();
    if (pG2->gx == posx && pG2->gy == posy && gyvybes > 30)
    {
        gyvybes = gyvybes - pGD2->Damage();
        pinigai = pinigai + pGD2->goblino_Pinigai();
        cout << "Uzklupai goblina ir nugalejai!" << endl;
        cout << "Kovodamas praradai 30 gyvybiu, taciau radai 8 monetas pas goblina!" << endl;
        pG2->gx = 0;
        pG2->gy = 0;
        ar_nukove = true;
    }
    else if(pG2->gx == posx && pG2->gy == posy && gyvybes <= 30)
    {
        gyvybes = 0;
        cout << "Uzklupai goblina, taciau jis tave iveike!" << endl;
        ar_nukove = false;
    }
    if (pV2->vx == posx && pV2->vy == posy && gyvybes > 30)
    {
        gyvybes = gyvybes - pVD2->Damage();
        cout << "Uzklupai vilkolaki ir nugalejai! " << endl;
        cout << "Kovodamas praradai 40 gyvybiu, taciau vilkolakis turejo eleksyra, kuris atstate 10 tavo gyvybiu!" << endl;
        gyvybes = gyvybes + pVD2->vilkolakio_Eleksyras();
        pV2->vx = 0;
        pV2->vy = 0;
        ar_nukove = true;
    }
    else if (pV2->vx == posx && pV2->vy == posy && gyvybes <= 30)
    {
        gyvybes = 0;
        cout << "Uzklupai vilkolaki, taciau jis tave iveike!" << endl;
        ar_nukove = false;
    }
}

int Zaidejas::get_Gyvybes()
{
    return gyvybes;
}
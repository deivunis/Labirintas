#include "Labirintas.h"
#include "Zaidejas.h"
#include "Zemelapiai.h"
#include "Priesai.h"
#include "Daiktai.h"

using namespace std;

Priesas* pG2 = new Goblinas();
Goblinas* pGD2 = dynamic_cast<Goblinas*>(pG2);
Priesas* pV2 = new Vilkolakis();
Vilkolakis* pVD2 = dynamic_cast<Vilkolakis*>(pV2);
Items i2;

void Zaidejas::Vardas()
{
    string slap;
	cin >> slap;
    for (char const& c : slap)
    {
        if (isdigit(c)) throw "Klaida: varde negali buti skaiciu!\nPrograma baige darba.";
        else slapyvardis = slap;
    }
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
    if (pG2->gx == posx && pG2->gy == posy && gyvybes > pGD2->Damage())
    {
        gyvybes = gyvybes - pGD2->Damage();
        pinigai = pinigai + pGD2->goblino_Pinigai();
        cout << "Uzklupai goblina ir nugalejai!" << endl;
        cout << "Kovodamas praradai " << pGD2->Damage() << " gyvybiu, taciau radai 18 monetu pas goblina!" << endl;
        pG2->gx = 0;
        pG2->gy = 0;
        ar_nukove = true;
    }
    else if(pG2->gx == posx && pG2->gy == posy && gyvybes <= pGD2->Damage())
    {
        gyvybes = 0;
        cout << "Uzklupai goblina, taciau jis tave iveike!" << endl;
        ar_nukove = false;
    }
    if (pV2->vx == posx && pV2->vy == posy && gyvybes > pVD2->Damage())
    {
        gyvybes = gyvybes - pVD2->Damage();
        cout << "Uzklupai vilkolaki ir nugalejai! " << endl;
        cout << "Kovodamas praradai " << pVD2->Damage() 
             << " gyvybiu, taciau vilkolakis turejo eleksyra, kuris atstate 10 tavo gyvybiu!" << endl;
        gyvybes = gyvybes + pVD2->vilkolakio_Eleksyras();
        pV2->vx = 0;
        pV2->vy = 0;
        ar_nukove = true;
    }
    else if (pV2->vx == posx && pV2->vy == posy && gyvybes <= pVD2->Damage())
    {
        gyvybes = 0;
        cout << "Uzklupai vilkolaki, taciau jis tave iveike!" << endl;
        ar_nukove = false;
    }
}
void Zaidejas::Rasti(bool& ar_rado)
{
    if (i2.amx == posx && i2.amy == posy)
    {
        cout << "Sveikiname, radai aukso maisa! " << endl;
        kuprine.push_back({ i2.Maisas(), i2.Random() });
        i2.amx = 0;
        i2.amy = 0;
        ar_rado = true;
    }
    if (i2.gex == posx && i2.gey == posy)
    {
        cout << "Sveikiname, radai gyvybiu eleksyra! " << endl;
        kuprine.push_back({ i2.Hp(), i2.Random() });
        i2.gex = 0;
        i2.gey = 0;
        ar_rado = true;
    }
    if (i2.eex == posx && i2.eey == posy)
    {
        cout << "Sveikiname, radai energijos eleksyra! " << endl;
        kuprine.push_back({ i2.Energy(), i2.Random() });
        i2.eex = 0;
        i2.eey = 0;
        ar_rado = true;
    }

}

int Zaidejas::get_Gyvybes()
{
    return gyvybes;
}
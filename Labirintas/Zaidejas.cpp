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
Priesas* pS2 = new Skeletonas();
Skeletonas* pSD2 = dynamic_cast<Skeletonas*>(pS2);
Items i2;

void Zaidejas::operator++()
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
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
            zingsniai++;
        }
        else cout << "Atsitrenkei i siena!" << endl;
    }
}

void Zaidejas::Kova(bool& ar_nukove, int& posx, int& posy)
{
    //pG2->Monstras();
    if (levelis == 1)
    {
        if (pG2->gx == posx && pG2->gy == posy && gyvybes > pGD2->Damage() && energija > pGD2->Exhaustion())
        {
            gyvybes = gyvybes - pGD2->Damage();
            energija = energija - pGD2->Exhaustion();
            pinigai = pinigai + pGD2->goblino_Pinigai();
            cout << "Uzklupai goblina ir nugalejai!" << endl;
            cout << "Kovodamas praradai:\n"
                << pGD2->Damage() << " gyvybiu\n"
                << pGD2->Exhaustion() << " energijos.\nTaciau radai "
                << pGD2->goblino_Pinigai() << " monetu pas goblina!" << endl;

            pG2->gx = 0;
            pG2->gy = 0;
            ar_nukove = true;
        }
        else if (pG2->gx == posx && pG2->gy == posy && gyvybes <= pGD2->Damage())
        {
            gyvybes = 0;
            cout << "Uzklupai goblina, taciau jis tave iveike!" << endl;
            ar_nukove = false;
        }
        else if (pG2->gx == posx && pG2->gy == posy && energija <= pGD2->Exhaustion() && gyvybes > pGD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
        if (pV2->vx == posx && pV2->vy == posy && gyvybes > pVD2->Damage())
        {
            gyvybes = gyvybes - pVD2->Damage();
            energija = energija - pVD2->Exhaustion();
            cout << "Uzklupai vilkolaki ir nugalejai! " << endl;
            cout << "Kovodamas praradai:\n"
                << pVD2->Damage() << " gyvybiu\n"
                << pVD2->Exhaustion() << " energijos.\nTaciau radai gyvybiu eleksyra, kuris atstate "
                << pVD2->vilkolakio_Eleksyras() << " tavo gyvybiu!" << endl;
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
        else if (pV2->vx == posx && pV2->vy == posy && energija <= pVD2->Exhaustion() && gyvybes > pVD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
        if (pS2->sx == posx && pS2->sy == posy && gyvybes > pSD2->Damage())
        {
            gyvybes = gyvybes - pSD2->Damage();
            energija = energija - pSD2->Exhaustion();
            cout << "Uzklupai skeletona ir nugalejai! " << endl;
            cout << "Kovodamas praradai:\n"
                << pSD2->Damage() << " gyvybiu\n"
                << pSD2->Exhaustion() << " energijos.\nTaciau radai energijos eleksyra, kuris atstate "
                << pSD2->skeletono_Eleksyras() << " tavo energijos!" << endl;
            energija = energija + pSD2->skeletono_Eleksyras();
            pS2->sx = 0;
            pS2->sy = 0;
            ar_nukove = true;
        }
        else if (pS2->sx == posx && pS2->sy == posy && gyvybes <= pSD2->Damage())
        {
            gyvybes = 0;
            cout << "Uzklupai skeletona, taciau jis tave iveike!" << endl;
            ar_nukove = false;
        }
        else if (pS2->sx == posx && pS2->sy == posy && energija <= pSD2->Exhaustion() && gyvybes > pSD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
    }
    if (levelis == 2)
    {
        if (pG2->gx2 == posx && pG2->gy2 == posy && gyvybes > pGD2->Damage() && energija > pGD2->Exhaustion())
        {
            gyvybes = gyvybes - pGD2->Damage();
            energija = energija - pGD2->Exhaustion();
            pinigai = pinigai + pGD2->goblino_Pinigai();
            cout << "Uzklupai goblina ir nugalejai!" << endl;
            cout << "Kovodamas praradai:\n"
                << pGD2->Damage() << " gyvybiu\n"
                << pGD2->Exhaustion() << " energijos.\nTaciau radai "
                << pGD2->goblino_Pinigai() << " monetu pas goblina!" << endl;

            pG2->gx2 = 0;
            pG2->gy2 = 0;
            ar_nukove = true;
        }
        else if (pG2->gx2 == posx && pG2->gy2 == posy && gyvybes <= pGD2->Damage())
        {
            gyvybes = 0;
            cout << "Uzklupai goblina, taciau jis tave iveike!" << endl;
            ar_nukove = false;
        }
        else if (pG2->gx2 == posx && pG2->gy2 == posy && energija <= pGD2->Exhaustion() && gyvybes > pGD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
        if (pV2->vx2 == posx && pV2->vy2 == posy && gyvybes > pVD2->Damage())
        {
            gyvybes = gyvybes - pVD2->Damage();
            energija = energija - pVD2->Exhaustion();
            cout << "Uzklupai vilkolaki ir nugalejai! " << endl;
            cout << "Kovodamas praradai:\n"
                << pVD2->Damage() << " gyvybiu\n"
                << pVD2->Exhaustion() << " energijos.\nTaciau radai gyvybiu eleksyra, kuris atstate "
                << pVD2->vilkolakio_Eleksyras() << " tavo gyvybiu!" << endl;
            gyvybes = gyvybes + pVD2->vilkolakio_Eleksyras();
            pV2->vx2 = 0;
            pV2->vy2 = 0;
            ar_nukove = true;
        }
        else if (pV2->vx2 == posx && pV2->vy2 == posy && gyvybes <= pVD2->Damage())
        {
            gyvybes = 0;
            cout << "Uzklupai vilkolaki, taciau jis tave iveike!" << endl;
            ar_nukove = false;
        }
        else if (pV2->vx2 == posx && pV2->vy2 == posy && energija <= pVD2->Exhaustion() && gyvybes > pVD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
        if (pS2->sx2 == posx && pS2->sy2 == posy && gyvybes > pSD2->Damage())
        {
            gyvybes = gyvybes - pSD2->Damage();
            energija = energija - pSD2->Exhaustion();
            cout << "Uzklupai skeletona ir nugalejai! " << endl;
            cout << "Kovodamas praradai:\n"
                << pSD2->Damage() << " gyvybiu\n"
                << pSD2->Exhaustion() << " energijos.\nTaciau radai energijos eleksyra, kuris atstate "
                << pSD2->skeletono_Eleksyras() << " tavo energijos!" << endl;
            energija = energija + pSD2->skeletono_Eleksyras();
            pS2->sx2 = 0;
            pS2->sy2 = 0;
            ar_nukove = true;
        }
        else if (pS2->sx2 == posx && pS2->sy2 == posy && gyvybes <= pSD2->Damage())
        {
            gyvybes = 0;
            cout << "Uzklupai skeletona, taciau jis tave iveike!" << endl;
            ar_nukove = false;
        }
        else if (pS2->sx2 == posx && pS2->sy2 == posy && energija <= pSD2->Exhaustion() && gyvybes > pSD2->Damage())
        {
            energija = 0;
            cout << "Kovodamas issekai, todel 30 sekundziu negali judeti, kol siek tiek pailsesi!" << endl;
            Sleep(30000);
            energija = 30;
            cout << "Pailsejai" << endl;
            ar_nukove = false;
        }
    }
}
void Zaidejas::Rasti(bool& ar_rado, int& posx, int& posy)
{
    if (levelis == 1)
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
    if (levelis == 2)
    {
        if (i2.amx2 == posx && i2.amy2 == posy)
        {
            cout << "Sveikiname, radai aukso maisa! " << endl;
            kuprine.push_back({ i2.Maisas(), i2.Random() });
            i2.amx2 = 0;
            i2.amy2 = 0;
            ar_rado = true;
        }
        if (i2.amx3 == posx && i2.amy3 == posy)
        {
            cout << "Sveikiname, radai aukso maisa! " << endl;
            kuprine.push_back({ i2.Maisas(), i2.Random() });
            i2.amx3 = 0;
            i2.amy3 = 0;
            ar_rado = true;
        }
        if (i2.gex2 == posx && i2.gey2 == posy)
        {
            cout << "Sveikiname, radai gyvybiu eleksyra! " << endl;
            kuprine.push_back({ i2.Hp(), i2.Random() });
            i2.gex2 = 0;
            i2.gey2 = 0;
            ar_rado = true;
        }
        if (i2.gex3 == posx && i2.gey3 == posy)
        {
            cout << "Sveikiname, radai gyvybiu eleksyra! " << endl;
            kuprine.push_back({ i2.Hp(), i2.Random() });
            i2.gex3 = 0;
            i2.gey3 = 0;
            ar_rado = true;
        }
        if (i2.eex2 == posx && i2.eey2 == posy)
        {
            cout << "Sveikiname, radai energijos eleksyra! " << endl;
            kuprine.push_back({ i2.Energy(), i2.Random() });
            i2.eex2 = 0;
            i2.eey2 = 0;
            ar_rado = true;
        }
        if (i2.eex3 == posx && i2.eey3 == posy)
        {
            cout << "Sveikiname, radai energijos eleksyra! " << endl;
            kuprine.push_back({ i2.Energy(), i2.Random() });
            i2.eex3 = 0;
            i2.eey3 = 0;
            ar_rado = true;
        }
    }

}
int Zaidejas::get_Energija()
{
    return energija;
}
int Zaidejas::get_Gyvybes()
{
    return gyvybes;
}
int Zaidejas::operator+(Zaidejas x)
{
    if (zingsniai == 1)
    {
        zingsniai = zingsniai + x.zingsniai;
    }
    return zingsniai;
}
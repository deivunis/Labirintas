#include <iostream>
#include "Zemelapiai.h"
#include "Zaidejas.h"
#include <Windows.h>
#include "Priesai.h"

using namespace std;

Priesas* pG = new Goblinas();
Goblinas* pGD = dynamic_cast<Goblinas*>(pG);
Priesas* pV = new Vilkolakis();
Vilkolakis* pVD = dynamic_cast<Vilkolakis*>(pV);

void Zemelapis::lengvas_Spausdinti(int& posx, int& posy, int& pposx, int& pposy, bool& ar_nukove)
{
    lengvas_lygis[pposx][pposy] = tarpas;
    lengvas_lygis[posx][posy] = zaidejas;
    lengvas_lygis[outx][outy] = isejimas;
    if(ar_nukove == false) lengvas_lygis[pGD->gx][pGD->gy] = pGD->goblinas;
    if (ar_nukove == false) lengvas_lygis[pVD->vx][pVD->vy] = pVD->vilkolakis;

    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        for (int j = 0; j < 20; j++)
        {
            cout << lengvas_lygis[i][j];
        }
    }
    cout << endl;
}
void Zemelapis::vidutinis_Spausdinti(int& posx2, int& posy2, int& pposx2, int& pposy2)
{
    vidutinis_lygis[pposx2][pposy2] = tarpas;
    vidutinis_lygis[posx2][posy2] = zaidejas;
    vidutinis_lygis[outx2][outy2] = isejimas;
    for (int i = 0; i < 31; i++)
    {
        cout << endl;
        for (int j = 0; j < 31; j++)
        {
            cout << vidutinis_lygis[i][j];
        }
    }
}

#include "Zemelapiai.h"

using namespace std;

Priesas* pG = new Goblinas();
Goblinas* pGD = dynamic_cast<Goblinas*>(pG);
Priesas* pV = new Vilkolakis();
Vilkolakis* pVD = dynamic_cast<Vilkolakis*>(pV);
Priesas* pS = new Skeletonas();
Skeletonas* pSD = dynamic_cast<Skeletonas*>(pS);
Items i;

void Zemelapis::lengvas_Spausdinti(int& posx, int& posy, int& pposx, int& pposy, bool& ar_nukove, bool& ar_rado)
{
    lengvas_lygis[pposx][pposy] = tarpas;
    lengvas_lygis[posx][posy] = zaidejas;
    lengvas_lygis[outx][outy] = isejimas;

    if (ar_nukove == false) lengvas_lygis[pGD->gx][pGD->gy] = pGD->goblinas;
    if (ar_nukove == false) lengvas_lygis[pVD->vx][pVD->vy] = pVD->vilkolakis;
    if (ar_nukove == false) lengvas_lygis[pSD->sx][pSD->sy] = pSD->skeletonas;
    if (ar_rado == false) lengvas_lygis[i.amx][i.amy] = i.aukso_maisas;
    if (ar_rado == false) lengvas_lygis[i.gex][i.gey] = i.gyvybiu_eleksyras;
    if (ar_rado == false) lengvas_lygis[i.eex][i.eey] = i.energijos_eleksyras;

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
void Zemelapis::vidutinis_Spausdinti(int& posx2, int& posy2, int& pposx2, int& pposy2, bool& ar_nukove, bool& ar_rado)
{
    vidutinis_lygis[pposx2][pposy2] = tarpas;
    vidutinis_lygis[posx2][posy2] = zaidejas;
    vidutinis_lygis[outx2][outy2] = isejimas;

    if (ar_nukove == false) vidutinis_lygis[pGD->gx2][pGD->gy2] = pGD->goblinas;
    if (ar_nukove == false) vidutinis_lygis[pVD->vx2][pVD->vy2] = pVD->vilkolakis;
    if (ar_nukove == false) vidutinis_lygis[pSD->sx2][pSD->sy2] = pSD->skeletonas;
    if (ar_rado == false) vidutinis_lygis[i.amx2][i.amy2] = i.aukso_maisas;
    if (ar_rado == false) vidutinis_lygis[i.amx3][i.amy3] = i.aukso_maisas;
    if (ar_rado == false) vidutinis_lygis[i.gex2][i.gey2] = i.gyvybiu_eleksyras;
    if (ar_rado == false) vidutinis_lygis[i.gex3][i.gey3] = i.gyvybiu_eleksyras;
    if (ar_rado == false) vidutinis_lygis[i.eex2][i.eey2] = i.energijos_eleksyras;
    if (ar_rado == false) vidutinis_lygis[i.eex3][i.eey3] = i.energijos_eleksyras;

    for (int i = 0; i < 31; i++)
    {
        cout << endl;
        for (int j = 0; j < 31; j++)
        {
            cout << vidutinis_lygis[i][j];
        }
    }
    cout << endl;
}

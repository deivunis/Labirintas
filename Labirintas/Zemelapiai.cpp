#include <iostream>
#include "Zemelapiai.h"
#include "Zaidejas.h"
#include <Windows.h>

using namespace std;

void Zemelapis::Spausdinti(int& posx, int& posy, int& pposx, int& pposy)
{
    lengvas_lygis[pposx][pposy] = tarpas;
    lengvas_lygis[posx][posy] = zaidejas;
    lengvas_lygis[outx][outy] = isejimas;
    for (int i = 0; i < 10; i++)
    {
        cout << endl;
        for (int j = 0; j < 20; j++)
        {
            cout << lengvas_lygis[i][j];
        }
    }
}

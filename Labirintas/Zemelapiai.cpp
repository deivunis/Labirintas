#include <iostream>
#include "Zemelapiai.h"

using namespace std;

void Zemelapis::Spausdinti()
{
    for (int y = 0; y < 10; y++)
    {
        cout << endl;
        for (int x = 0; x < 20; x++)
        {
            cout << lengvas_lygis[y][x];
        }
    }
}

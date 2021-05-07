#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Zaidejas.h"
#include "Zemelapiai.h"

using namespace std;

int main()
{
	int pasirinkimas;
	char taipne;

	Zaidejas x;
	Zemelapis z;

	cout << "Sveiki atvyke i zaidima - Labirintas!" << endl;
	cout << "Norint pradeti zaisti iveskite savo varda: " << endl;
	x.Vardas();
	system("cls");

	do
	{
		cout << x.get_Vardas() << " iveskite pasirinkima ir spauskite ENTER!" << endl;
		cout << "	1 - Zaidimo informacija ir taisykles." << endl;
		cout << "	2 - Pradeti zaidima." << endl;
		cout << "	3 - Zaidejo informacija." << endl;
		cout << "	4 - Palikti zaidima.\n" << endl;

		cin >> pasirinkimas;
		system("cls");

		switch (pasirinkimas)
		{
		case 1:
			cout << "Zaidimo informacija: " << endl;
			cout << "	Zaidimo tikslas - kovoti arba isvengti priesu ir saugiai pereiti labirinta." << endl;
			cout << "	Zaidimo valdymas - W A S D mygtukai.\n" << endl;
			//papildyti
			break;
		case 2:
			//þaidimo pradëjimas
			z.Spausdinti();
			while (x.ar_laimejo == false)
			{
				cin >> x.judeti;
				if (x.judeti == 'W')
				{
					x.virsu(x.posx, x.posy);
					z.Spausdinti();
				}
				if (x.judeti == 'S')
				{
					x.apacia(x.posx, x.posy);
					z.Spausdinti();
				}
				if (x.judeti == 'A')
				{
					x.kaire(x.posx, x.posy);
					z.Spausdinti();
				}
				if (x.judeti == 'D')
				{
					x.desine(x.posx, x.posy);
					z.Spausdinti();
				}
			}




			break;
		case 3:
			cout << "Zaidëjo informacija: " << endl;
			cout << "	Gyvybes: " << x.get_Gyvybes() << "\n" << endl;
			break;
		case 4:
			cout << x.get_Vardas() << " Ar tikrai norite palikti zaidima? T/N" << endl;
			cin >> taipne;
			if (taipne == 'T')
			{
				cout << "Iki pasimatymo " << x.get_Vardas() << "!" << endl;
				pasirinkimas = 5;
			}
			else
			{
				break;
			}
		/*default:
			cout << "Neteisingai ivestas pasirinkimas!" << endl;
			cout << "Iveskite skaiciu (1-4) is naujo!" << endl;
			break;*/
		}

	} while (pasirinkimas != 5);

	return 0;
}
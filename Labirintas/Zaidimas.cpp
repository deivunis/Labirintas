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
			while (x.ar_laimejo == false)
			{
				z.Spausdinti(x.posx, x.posy, x.pposx, x.pposy);
				cin >> x.judeti;
				if (x.judeti == 'W')
				{
					system("cls");
					x.virsu(x.posx, x.posy);
				}
				if (x.judeti == 'S')
				{
					system("cls");
					x.apacia(x.posx, x.posy);
				}
				if (x.judeti == 'A')
				{
					system("cls");
					x.kaire(x.posx, x.posy);
				}
				if (x.judeti == 'D')
				{
					system("cls");
					x.desine(x.posx, x.posy);
				}
				if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D')
				{
					system("cls");
					cout << "Bloga ivedimo komanda! (Didziosios WASD raides)" << endl;
				}
				if (x.posx == 4 && x.posy == 19)
				{
					x.ar_laimejo = true;
					system("cls");
					cout << "Sveikiname, perejote labirinta!" << endl;
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
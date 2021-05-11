#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include "Zaidejas.h"
#include "Zemelapiai.h"
#include "Priesai.h"

using namespace std;

int main()
{
	int meniu_pasirinkimas;
	char pabaigos_pasirinkimas;
	char lygio_pasirinkimas = 'N';

	Zaidejas* pZaidejas = new Zaidejas();
	Zemelapis* pZemalapis = new Zemelapis();

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

		cin >> meniu_pasirinkimas;
		system("cls");

		switch (meniu_pasirinkimas)
		{
		case 1:
			cout << "Zaidimo informacija: " << endl;
			cout << "	Zaidimo tikslas - kovoti arba isvengti priesu ir saugiai pereiti labirinta." << endl;
			cout << "	Zaidimo valdymas - W A S D mygtukai." << endl;
			cout << "	Norint iseiti spauskite - Q\n" << endl;
			//papildyti
			break;
		case 2:
			//þaidimo pradëjimas
			if (x.levelis == 1)
			{
				while (x.ar_laimejo == false && x.ar_iseiti == false)
				{
					z.lengvas_Spausdinti(x.posx, x.posy, x.pposx, x.pposy, x.ar_nukove);
					x.Kova(x.ar_nukove);
					if(x.gyvybes <= 0) x.ar_iseiti = true;

					cout << "Zaidejo gyvybes " << x.get_Gyvybes() << endl;
					cout << "Zaidejo pinigai " << x.get_Pinigai() << endl;
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
					if (x.judeti == 'Q')
					{
						system("cls");
						x.ar_iseiti = true;
						cout << "Baigete zaidima!" << endl;
					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q')
					{
						system("cls");
						cout << "Bloga ivedimo komanda! (Judeti - didziosios WASD raides. Baigti zaisti - Q)" << endl;
					}
					if (x.posx == 4 && x.posy == 19)
					{
						x.ar_laimejo = true;
						x.levelis = 2;
						system("cls");
						cout << "Sveikiname, perejote labirinta!" << endl;
						cout << "Ar norite pradeti 2 lygi? T/N" << endl;
						cin >> lygio_pasirinkimas;
						system("cls");
					}
				}
			}
			if (lygio_pasirinkimas == 'T' && x.levelis == 2)
			{
				x.ar_laimejo = false;
				while (x.ar_laimejo == false && x.ar_iseiti == false)
				{
					z.vidutinis_Spausdinti(x.posx2, x.posy2, x.pposx2, x.pposy2);
					cin >> x.judeti;
					if (x.judeti == 'W')
					{
						system("cls");
						x.virsu(x.posx2, x.posy2);
					}
					if (x.judeti == 'S')
					{
						system("cls");
						x.apacia(x.posx2, x.posy2);
					}
					if (x.judeti == 'A')
					{
						system("cls");
						x.kaire(x.posx2, x.posy2);
					}
					if (x.judeti == 'D')
					{
						system("cls");
						x.desine(x.posx2, x.posy2);
					}
					if (x.judeti == 'Q')
					{
						system("cls");
						x.ar_iseiti = true;
						cout << "Baigete zaidima!" << endl;
					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q')
					{
						system("cls");
						cout << "Bloga ivedimo komanda! (Judeti - didziosios WASD raides. Baigti zaisti - Q)" << endl;
					}
					if (x.posx2 == 29 && x.posy2 == 30)
					{
						x.ar_laimejo = true;
						x.levelis = 3;
						system("cls");
						cout << "Sveikiname, perejote labirinta!" << endl;
					}
				}
			}
			break;
		case 3:
			cout << "Zaidëjo informacija: " << endl;
			cout << "	Gyvybes: " << x.get_Gyvybes() << "\n" << endl;
			break;
		case 4:
			cout << x.get_Vardas() << " Ar tikrai norite palikti zaidima? T/N" << endl;
			cin >> pabaigos_pasirinkimas;
			if (pabaigos_pasirinkimas == 'T')
			{
				cout << "Iki pasimatymo " << x.get_Vardas() << "!" << endl;
				meniu_pasirinkimas = 5;
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

	} while (meniu_pasirinkimas != 5);

	return 0;
}
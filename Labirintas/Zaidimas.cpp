#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include "Zaidejas.h"
#include "Zemelapiai.h"
#include "Priesai.h"
#include "Daiktai.h"

using namespace std;

int main()
{
	int meniu_pasirinkimas;
	char pabaigos_pasirinkimas;
	char lygio_pasirinkimas = 'N';

	Zaidejas* pZaidejas = new Zaidejas();
	Zemelapis* pZemalapis = new Zemelapis();
	Items* pItem = new Items();

	Zaidejas x;
	Zemelapis z;
	//Items i;

	cout << "Sveiki atvyke i zaidima - Labirintas!" << endl;
	cout << "Norint pradeti zaisti iveskite savo varda: " << endl;
	try
	{
		x.Vardas();
		system("cls");
	}
	catch (const char* szMessage)
	{
		cout << szMessage << endl;
		return 0;
	}

	do
	{
		cout << x.get_Vardas() << " iveskite pasirinkima ir spauskite ENTER!" << endl;
		cout << "	1 - Zaidimo informacija ir taisykles." << endl;
		cout << "	2 - Pradeti zaidima." << endl;
		cout << "	3 - Zaidejo inventorius." << endl;
		cout << "	4 - Palikti zaidima.\n" << endl;

		cin >> meniu_pasirinkimas;
		system("cls");

		switch (meniu_pasirinkimas)
		{
		case 1:
			cout << "Zaidimo informacija: " << endl;
			cout << "	->Zaidimo tikslas - kovoti arba isvengti priesu ir saugiai pereiti labirinta." << endl;
			cout << "	->Zaidimo valdymas:\n"
				 << "	   Judeti - W A S D mygtukai.\n	   Inventorius - I\n	   Baigti zaisti - Q" << endl;
			cout << endl;
			//papildyti
			break;
		case 2:
			//þaidimo pradëjimas
			if (x.levelis == 1)
			{
				while (x.ar_laimejo == false && x.ar_iseiti == false)
				{
					z.lengvas_Spausdinti(x.posx, x.posy, x.pposx, x.pposy, x.ar_nukove, x.ar_rado);
					x.Kova(x.ar_nukove);
					x.Rasti(x.ar_rado);
					if(x.gyvybes <= 0) x.ar_iseiti = true;

					cout << "Zaidejo gyvybes " << x.get_Gyvybes() << endl;
					cout << "Zaidejo pinigai " << x.get_Pinigai() << endl;
					cout << "Zaidejo energija " << x.get_Energija() << endl;

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
					if (x.judeti == 'I')
					{
						system("cls");
						sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
							{
								return a.kiekis > b.kiekis;
							});
						cout << "Zaidejo inventorius: " << endl;
						for (int i = 0; i < x.kuprine.size(); i++)
						{
							cout << "	" << x.kuprine[i].pavadinimas << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						cout << endl;

					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q' && x.judeti != 'I')
					{
						system("cls");
						cout << "Bloga ivedimo komanda!\n"
							 << "Judeti - didziosios WASD raides.\nInventorius - I\nBaigti zaisti - Q" << endl;
					}
					if (x.posx == 4 && x.posy == 19)
					{
						x.ar_laimejo = true;
						x.ar_nukove = false;
						x.ar_rado = false;
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
					z.vidutinis_Spausdinti(x.posx2, x.posy2, x.pposx2, x.pposy2, x.ar_nukove, x.ar_rado);
					x.Kova(x.ar_nukove);
					x.Rasti(x.ar_rado);
					if (x.gyvybes <= 0) x.ar_iseiti = true;

					cout << "Zaidejo gyvybes " << x.get_Gyvybes() << endl;
					cout << "Zaidejo pinigai " << x.get_Pinigai() << endl;
					cout << "Zaidejo energija " << x.get_Energija() << endl;

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
					if (x.judeti == 'I')
					{
						system("cls");
						sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
							{
								return a.kiekis > b.kiekis;
							});
						cout << "Zaidejo inventorius: " << endl;
						for (int i = 0; i < x.kuprine.size(); i++)
						{
							cout << "	" << x.kuprine[i].pavadinimas << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						cout << endl;

					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q' && x.judeti != 'I')
					{
						system("cls");
						cout << "Bloga ivedimo komanda!\n"
							<< "Judeti - didziosios WASD raides.\nInventorius - I\nBaigti zaisti - Q" << endl;
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
			sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
				{
					return a.kiekis > b.kiekis;
				});

			cout << "Zaidejo inventorius: " << endl;
			for (int i = 0; i < x.kuprine.size(); i++)
			{
				cout << "	" << x.kuprine[i].pavadinimas << " " << x.kuprine[i].kiekis << "% talpos." << endl;
			}
			cout << endl;
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
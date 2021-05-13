#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include "Zaidejas.h"
#include "Zemelapiai.h"
#include "Priesai.h"
#include "Daiktai.h"

using namespace std;

int main()
{
	int meniu_pasirinkimas;
	int eiles_numeris;
	char pabaigos_pasirinkimas;
	char lygio_pasirinkimas = 'N';
	char inv_pasirinkimas = 'N';
	int hp_kiekis = 0, pwr_kiekis = 0, money_kiekis = 0;
	int score;

	Zaidejas* pZaidejas = new Zaidejas();
	Zemelapis* pZemalapis = new Zemelapis();
	Items* pItem = new Items();

	Zaidejas x, x2;
	Zemelapis z;
	//Items i;

	cout << "Sveiki atvyke i zaidima - Labirintas!" << endl;
	cout << "Norint pradeti zaisti iveskite savo varda: " << endl;
	try
	{
		++x;
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
					x.Kova(x.ar_nukove, x.posx, x.posy);
					x.Rasti(x.ar_rado, x.posx, x.posy);
					score = x + x2;
					if(x.gyvybes <= 0) x.ar_iseiti = true;

					cout << "Zaidejo gyvybes " << x.get_Gyvybes() + hp_kiekis << endl;
					cout << "Zaidejo pinigai " << x.get_Pinigai() + money_kiekis << endl;
					cout << "Zaidejo energija " << x.get_Energija() + pwr_kiekis << endl;
					cout << "Zaidejo zingsniai " << score << endl;

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
							cout << "	" << i+1 << " " << x.kuprine[i].pavadinimas << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						cout << "?" << " Ar norite ka nors panaudoti? T/N " << endl;
						cin >> inv_pasirinkimas;
						if (inv_pasirinkimas == 'T')
						{
							
							cout << "Iveskite norimo daikto eiles numeri: " << endl;
							cin >> eiles_numeris;
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Gyvybiu eleksyras")
							{
								hp_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Gyvybes() + hp_kiekis > 100)
								{
									hp_kiekis = hp_kiekis - ((x.get_Gyvybes() + hp_kiekis) - 100);
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Energijos eleksyras")
							{
								pwr_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Energija() + hp_kiekis > 100)
								{
									pwr_kiekis = pwr_kiekis - ((x.get_Energija() + pwr_kiekis) - 100);
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Aukso Maisas")
							{
								money_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								
							}
							x.kuprine.erase(x.kuprine.begin() + (eiles_numeris - 1));
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
						hp_kiekis = 0;
						pwr_kiekis = 0;
						money_kiekis = 0;
						score = 0;
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
					x.Kova(x.ar_nukove, x.posx2, x.posy2);
					x.Rasti(x.ar_rado, x.posx2, x.posy2);
					score = x + x2;
					if (x.gyvybes <= 0) x.ar_iseiti = true;

					cout << "Zaidejo gyvybes " << x.get_Gyvybes() + hp_kiekis << endl;
					cout << "Zaidejo pinigai " << x.get_Pinigai() + money_kiekis << endl;
					cout << "Zaidejo energija " << x.get_Energija() + pwr_kiekis << endl;
					cout << "Zaidejo zingsniai " << score << endl;
				

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
							cout << "	" << i + 1 << " " << x.kuprine[i].pavadinimas << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						cout << "?" << " Ar norite ka nors panaudoti? T/N " << endl;
						cin >> inv_pasirinkimas;
						if (inv_pasirinkimas == 'T')
						{

							cout << "Iveskite norimo daikto eiles numeri: " << endl;
							cin >> eiles_numeris;
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Gyvybiu eleksyras")
							{
								hp_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Gyvybes() + hp_kiekis > 100)
								{
									hp_kiekis = hp_kiekis - ((x.get_Gyvybes() + hp_kiekis) - 100);
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Energijos eleksyras")
							{
								pwr_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Energija() + hp_kiekis > 100)
								{
									pwr_kiekis = pwr_kiekis - ((x.get_Energija() + pwr_kiekis) - 100);
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Aukso Maisas")
							{
								money_kiekis = x.kuprine[eiles_numeris - 1].kiekis;

							}
							x.kuprine.erase(x.kuprine.begin() + (eiles_numeris - 1));
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
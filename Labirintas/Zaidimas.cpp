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
#include "../include/color.hpp" //spalvos (https://github.com/imfl/color-console)

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
	std::cout << "Sveiki atvyke i zaidima -" << dye::aqua(" Labirintas!") << endl;
	std::cout << "Norint pradeti zaisti iveskite savo" << dye::aqua(" varda: ") << endl;
	try
	{
		++x;
		system("cls");
	}
	catch (const char* szMessage)
	{
		std::cout << dye::red(szMessage) << endl;
		return 0;
	}

	do
	{
		std::cout << dye::aqua(x.get_Vardas()) << " iveskite pasirinkima ir spauskite" << dye::aqua(" ENTER!") << endl;
		std::cout << dye::red("	1") << " - Zaidimo informacija ir taisykles." << endl;
		std::cout << dye::red("	2") << " - Pradeti zaidima." << endl;
		std::cout << dye::red("	3") << " - Zaidejo inventorius." << endl;
		std::cout << dye::red("	4") << " - Palikti zaidima.\n" << endl;

		std::cin >> meniu_pasirinkimas;
		system("cls");

		switch (meniu_pasirinkimas)
		{
		case 1:
			std::cout << dye::aqua("Zaidimo informacija: ") << endl;
			std::cout << dye::red("	->") << dye::aqua("Zaidimo tikslas") << " - kovoti arba isvengti priesu ir saugiai pereiti labirinta." << endl;
			std::cout << dye::red("	->") << dye::aqua("Zaidimo valdymas") << ":\n"
				 << "	   Judeti - " << dye::red("W A S D") << " mygtukai.\n"
				 << "	   Inventorius - " << dye::red("I\n")
				 << "	   Grizti i meniu - " << dye::red("Q") << endl;
			std::cout << dye::red("	->") << dye::aqua("Zaidimo lygiai") << " - siuo metu zaidime yra 2 lygiai." << endl;
			std::cout << endl;
			//papildyti
			break;
		case 2:
			//þaidimo pradëjimas
			if (x.levelis == 1)
			{
				while (x.ar_laimejo == false && x.ar_iseiti == false)
				{
					z.lengvas_Spausdinti(x.posx, x.posy, x.pposx, x.pposy, x.ar_nukove, x.ar_rado);
					score = x + x2;
					if(x.gyvybes <= 0) x.ar_iseiti = true;

					std::cout << "Zaidejo gyvybes: " << dye::black_on_red(x.get_Gyvybes() + hp_kiekis) << endl;
					std::cout << "Zaidejo energija: " << dye::black_on_blue(x.get_Energija() + pwr_kiekis) << endl;
					std::cout << "Zaidejo pinigai: " << dye::black_on_green(x.get_Pinigai() + money_kiekis) << endl;
					std::cout << "Zaidejo zingsniai: " << dye::black_on_yellow(score) << endl;
					std::cout << endl;
					x.Kova(x.ar_nukove, x.posx, x.posy);
					x.Rasti(x.ar_rado, x.posx, x.posy);

					std::cin >> x.judeti;
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
						//x.ar_iseiti = true;
						std::cout << dye::green("Grizote i pagrindini meniu!") << endl;
						break;
					}
					if (x.judeti == 'I')
					{
						system("cls");
						sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
							{
								return a.kiekis > b.kiekis;
							});
						std::cout << "Zaidejo inventorius: " << endl;
						for (int i = 0; i < x.kuprine.size(); i++)
						{
							std::cout << "	" << dye::red(i+1) << " " << dye::aqua(x.kuprine[i].pavadinimas) << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						std::cout << endl;
						std::cout << dye::red("?") << " Ar norite ka nors panaudoti? " << dye::aqua("T/N ") << endl;
						std::cin >> inv_pasirinkimas;
						if (inv_pasirinkimas == 'T')
						{
							
							std::cout << "Iveskite norimo daikto eiles numeri: " << endl;
							std::cin >> eiles_numeris;
							system("cls");
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Gyvybiu eleksyras")
							{
								hp_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Gyvybes() + hp_kiekis > 100)
								{
									hp_kiekis = hp_kiekis - ((x.get_Gyvybes() + hp_kiekis) - 100);
									std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Energijos eleksyras")
							{
								pwr_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Energija() + pwr_kiekis > 100)
								{
									pwr_kiekis = pwr_kiekis - ((x.get_Energija() + pwr_kiekis) - 100);
									std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Aukso Maisas")
							{
								money_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
							}
							x.kuprine.erase(x.kuprine.begin() + (eiles_numeris - 1));
						}
						//std::cout << endl;
						//system("cls");

					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q' && x.judeti != 'I')
					{
						system("cls");
						std::cout << dye::red("Bloga ivedimo komanda!\n")
							 << dye::red("  ->Judeti - didziosios WASD raides.\n  ->Inventorius - I\n  ->Grizti i meniu - Q") << endl;
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
						std::cout << dye::green("Sveikiname, perejote labirinta!") << endl;
						std::cout << dye::green("Ar norite pradeti 2 lygi? T/N") << endl;
						std::cin >> lygio_pasirinkimas;
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
					score = x + x2;
					if (x.gyvybes <= 0) x.ar_iseiti = true;

					std::cout << "Zaidejo gyvybes: " << dye::black_on_red(x.get_Gyvybes() + hp_kiekis) << endl;
					std::cout << "Zaidejo energija: " << dye::black_on_blue(x.get_Energija() + pwr_kiekis) << endl;
					std::cout << "Zaidejo pinigai: " << dye::black_on_green(x.get_Pinigai() + money_kiekis) << endl;
					std::cout << "Zaidejo zingsniai: " << dye::black_on_yellow(score) << endl;
					std::cout << endl;

					x.Kova(x.ar_nukove, x.posx2, x.posy2);
					x.Rasti(x.ar_rado, x.posx2, x.posy2);

					std::cin >> x.judeti;
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
						//x.ar_iseiti = true;
						std::cout << dye::green("Grizote i pagrindini meniu!") << endl;
						break;
					}
					if (x.judeti == 'I')
					{
						system("cls");
						sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
							{
								return a.kiekis > b.kiekis;
							});
						std::cout << "Zaidejo inventorius: " << endl;
						for (int i = 0; i < x.kuprine.size(); i++)
						{
							std::cout << "	" << dye::red(i + 1) << " " << dye::aqua(x.kuprine[i].pavadinimas) << " " << x.kuprine[i].kiekis << "% talpos." << endl;
						}
						std::cout << endl;
						std::cout << dye::red("?") << " Ar norite ka nors panaudoti? " << dye::aqua("T/N ") << endl;
						std::cin >> inv_pasirinkimas;
						if (inv_pasirinkimas == 'T')
						{

							std::cout << "Iveskite norimo daikto eiles numeri: " << endl;
							std::cin >> eiles_numeris;
							system("cls");
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Gyvybiu eleksyras")
							{
								hp_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Gyvybes() + hp_kiekis > 100)
								{
									hp_kiekis = hp_kiekis - ((x.get_Gyvybes() + hp_kiekis) - 100);
									std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Energijos eleksyras")
							{
								pwr_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								if (x.get_Energija() + pwr_kiekis > 100)
								{
									pwr_kiekis = pwr_kiekis - ((x.get_Energija() + pwr_kiekis) - 100);
									std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
								}
							}
							if (x.kuprine[eiles_numeris - 1].pavadinimas == "Aukso Maisas")
							{
								money_kiekis = x.kuprine[eiles_numeris - 1].kiekis;
								std::cout << dye::green("Panaudojote: ") << dye::green(x.kuprine[eiles_numeris - 1].pavadinimas) << endl;
							}
							x.kuprine.erase(x.kuprine.begin() + (eiles_numeris - 1));
						}
						//std::cout << endl;
						//system("cls");

					}
					if (x.judeti != 'W' && x.judeti != 'S' && x.judeti != 'A' && x.judeti != 'D' && x.judeti != 'Q' && x.judeti != 'I')
					{
						system("cls");
						std::cout << dye::red("Bloga ivedimo komanda!\n")
							<< dye::red("  ->Judeti - didziosios WASD raides.\n  ->Inventorius - I\n  ->Grizti i meniu - Q") << endl;
					}
					if (x.posx2 == 29 && x.posy2 == 30)
					{
						x.ar_laimejo = true;
						x.levelis = 3;
						system("cls");
						std::cout << dye::green("Sveikiname, perejote labirinta!") << endl;
					}
				}
			}
			break;
		case 3:
			sort(x.kuprine.begin(), x.kuprine.end(), [](inventorius a, inventorius b)
				{
					return a.kiekis > b.kiekis;
				});

			std::cout << "Zaidejo inventorius: " << endl;
			for (int i = 0; i < x.kuprine.size(); i++)
			{
				std::cout << "	" << dye::red(i + 1) << " " << dye::aqua(x.kuprine[i].pavadinimas) << " " << x.kuprine[i].kiekis << "% talpos." << endl;
			}
			std::cout << endl;
			break;
		case 4:
			std::cout << dye::aqua(x.get_Vardas()) << ", ar tikrai norite palikti zaidima? T/N" << endl;
			std::cin >> pabaigos_pasirinkimas;
			//system("cls");
			if (pabaigos_pasirinkimas == 'T')
			{
				std::cout << "Iki pasimatymo, " << dye::aqua(x.get_Vardas()) << "!" << endl;
				meniu_pasirinkimas = 96784315; // toks skaicius, kad zaidejas netycia nepataikytu ant uzdarymo skaiciaus
			}
			else
			{
				break;
			}
		default:
			if (meniu_pasirinkimas != 96784315)
			{
				std::cout << dye::red("Neteisingai ivestas pasirinkimas!") << endl;
				std::cout << dye::red("Iveskite skaiciu (1-4) is naujo!") << endl;
				std::cout << endl;
				break;
			}
		}

	} while (meniu_pasirinkimas != 96784315);

	delete pZaidejas;
	delete pZemalapis;

	return 0;
}
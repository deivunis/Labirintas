#pragma once

#include <iostream>

using namespace std;

class Zaidejas
{
public:
	string slapyvardis;
	int gyvybes = 100;

public:
	void Vardas();
	string get_Vardas();
	int get_Gyvybes();
	void virsu(int& x, int& y);
	void apacia(int& x, int& y);
	void kaire(int& x, int& y);
	void desine(int& x, int& y);
};
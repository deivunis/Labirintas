#pragma once
#include "Labirintas.h"
#include "Zaidejas.h"
#include "Priesai.h"
#include "Daiktai.h"

class Zemelapis : public Labirintas
{
public:
    char sunkus_lygis[40][40];
public:
    void lengvas_Spausdinti(int& posx, int& posy, int& pposx, int& pposy, bool& ar_nukove, bool& ar_rado);
    void vidutinis_Spausdinti(int& posx2, int& posy2, int& pposx2, int& pposy2, bool& ar_nukove, bool& ar_rado);
};
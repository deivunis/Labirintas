#pragma once
#include "Labirintas.h"

class Zemelapis : public Labirintas
{
public:
    char sunkus_lygis[40][40];
public:
    void lengvas_Spausdinti(int& posx, int& posy, int& pposx, int& pposy);
    void vidutinis_Spausdinti(int& posx2, int& posy2, int& pposx2, int& pposy2);
};
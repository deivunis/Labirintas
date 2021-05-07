#pragma once
#include "Labirintas.h"

class Zemelapis : public Labirintas
{
public:
    char vidutinis_lygis[20][30];
    char sunkus_lygis[30][40];
public:
    void Spausdinti(int& posx, int& posy, int& pposx, int& pposy);
};
#pragma once
#include "cMonstruo.h"
class cElite :
    public cMonstruo
{
    int inteligencia;
    int fuerza;
    int ProbGolpe;//de 0 a 100
public:
    cElite(int poderAtaque, string Nombre, int fuerza,int inteligencia);
    ~cElite() { };
    void Atacar(cPersona* persona);
    void setProbGolpe();
};


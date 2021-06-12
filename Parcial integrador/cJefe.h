#pragma once
#include "cMonstruo.h"
class cJefe :
    public cMonstruo
{
    int inteligencia;
    int fuerza;
    int probCritico;
public:
    cJefe(int poderAtaque, string Nombre, int fuerza, int inteligencia);
    ~cJefe() { };
    void Atacar(cPersona* persona);
    void setProbCritico() { probCritico++; };
};


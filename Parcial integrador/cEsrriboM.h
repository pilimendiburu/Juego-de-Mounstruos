#pragma once
#include "cMonstruo.h"
class cEsrriboM :
    public cMonstruo
{
    int inteligencia;
public:
    cEsrriboM(int poderAtaque, string Nombre, int inteligencia);
    ~cEsrriboM() { };
    void Atacar(cPersona* persona);
};


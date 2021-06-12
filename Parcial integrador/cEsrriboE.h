#pragma once
#include "cMonstruo.h"
class cEsrriboE :
    public cMonstruo
{
    int fuerza;
public:
    cEsrriboE(int poderAtaque, string Nombre, int fuerza);
    ~cEsrriboE() { };
    void Atacar(cPersona* persona);
};


#include "cEsrriboE.h"


cEsrriboE::cEsrriboE(int poderAtaque, string Nombre, int fuerza):cMonstruo(poderAtaque, Nombre) {
    this->fuerza = fuerza;
}

void cEsrriboE::Atacar(cPersona* persona)
{
    int da�o_a_dar = 0;
    if (!persona->getEstado())
        throw new exception("\nLa persona esta muerta :(");
    da�o_a_dar = poderAtaque+ fuerza / 10;//suponemos que el da�o base es el poder de ataque
    persona->RecibirDa�o(da�o_a_dar, *this);
}

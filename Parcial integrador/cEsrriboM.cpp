#include "cEsrriboM.h"


cEsrriboM::cEsrriboM(int poderAtaque, string Nombre, int inteligencia):cMonstruo(poderAtaque, Nombre) {
    this->inteligencia = inteligencia;
}

void cEsrriboM::Atacar(cPersona* persona)
{
    int da�o_a_dar = 0;
    if (!persona->getEstado())
        throw new exception("\nLa persona esta muerta :(");
    da�o_a_dar = poderAtaque+ 50 * (1 - exp(-inteligencia / 100));//suponemos que el da�o base es el poder de ataque
    persona->RecibirDa�o(da�o_a_dar, *this);
}

#include "cJefe.h"
cJefe::cJefe(int poderAtaque, string Nombre, int fuerza, int inteligencia) :cMonstruo(poderAtaque, Nombre)
{
    this->fuerza = fuerza;
    this->inteligencia = inteligencia;
    probCritico = 0;
}

void cJefe::Atacar(cPersona* persona)
{
    int da�o_a_dar = 0;
    if (!persona->getEstado())
        throw new exception("\nLa persona esta muerta :(");
    da�o_a_dar = poderAtaque + fuerza / 5 + inteligencia / 5;//suponemos que el da�o base es el poder de ataque
    if (probCritico == 25)
        da�o_a_dar = 2 * da�o_a_dar;
    persona->RecibirDa�o(da�o_a_dar, *this);
}

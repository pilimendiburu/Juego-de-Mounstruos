#include "cElite.h"


cElite::cElite(int poderAtaque, string Nombre, int fuerza, int inteligencia):cMonstruo(poderAtaque, Nombre)
{
    this->fuerza = fuerza;
    this->inteligencia = inteligencia;
    ProbGolpe = 0;
}

void cElite::Atacar(cPersona* persona)
{
    int daño_a_dar = 0;
    if (!persona->getEstado())
        throw new exception("\nLa persona esta muerta :(");
    setProbGolpe();
    if (ProbGolpe == 0)
        daño_a_dar = 0;
    else {
        daño_a_dar = poderAtaque + 100 * (1 - exp(-(inteligencia + fuerza) / 100));//suponemos que el daño base es el poder de ataque
    }
    persona->RecibirDaño(daño_a_dar, *this);
}


void cElite::setProbGolpe()
{
    int prob = rand() % 101;//random de 0 a 100
    ProbGolpe = prob;
}

#include "cPersona.h"
#include "cEsrriboM.h"
#include "cEsrriboE.h"
#include "cElite.h"
#include "cJefe.h"

cPersona::cPersona(int fuerza, int inteligencia, int Armadura, int poderAtaque) :vidaMax(NMAX)
{
    this->fuerza = fuerza;
    this->inteligencia = inteligencia;
    this->Armadura = Armadura;
    this->poderAtaque = poderAtaque;
    estado = true;
    vida = vidaMax;
}
/*#include "cEsrriboM.h"
#include "cEsrriboE.h"
#include "cElite.h"
#include "cJefe.h"*/
void cPersona::Atacar(cMonstruo* ene)
{
    if (!(ene->getEstado()))
        throw new exception("EL enemigo esta muerto :)");
    int daño_a_hacer = poderAtaque + fuerza + inteligencia;
    ene->RecibirDaño(daño_a_hacer);
}

void cPersona::RecibirDaño(int daño, cMonstruo& ene)
{
    int daño_a_recibir = 0;
    cEsrriboE* case1 = dynamic_cast<cEsrriboE*>(&ene);
    cEsrriboM* case2 = dynamic_cast<cEsrriboM*>(&ene);
    cElite* case3 = dynamic_cast<cElite*>(&ene);
    cJefe* case4 = dynamic_cast<cJefe*>(&ene);
    if (case2 != NULL)
        daño_a_recibir = daño - inteligencia / 2;
    if (case1 != NULL || case3 != NULL)
        daño_a_recibir = daño - Armadura;
    if (case4 != NULL) {
        daño_a_recibir = daño - Armadura / 4 - inteligencia / 4;
        case4->setProbCritico();
    }
    cPersona* p = this;
    try {
        *p - daño_a_recibir;
    }
    catch (exception* e) {
        throw e;
    }
}

ostream& operator<<(ostream& out, const cPersona& o)
{
    out << "\nFuerza: " << o.fuerza << "\nInteligencia: " << o.inteligencia << "\nVida actual: " << o.vida << "\nArmadura: "
        << o.Armadura << "\nPoder Ataque: " << o.poderAtaque << endl;
    return out;
}

void operator-(cPersona& p, int daño)
{
    p.vida = p.vida - daño;
    if (p.vida <= 0)
        throw new exception("\nHas muerto.");
}

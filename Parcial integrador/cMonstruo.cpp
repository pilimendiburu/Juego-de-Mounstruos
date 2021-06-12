#include "cMonstruo.h"


void cMonstruo::RecibirDaño(int daño)
{
    vida = vida - daño;
    if (vida <= 0) {
        estado = false;
        vida = 0;
    }
}
int cMonstruo::CM = 0;
cMonstruo::cMonstruo(int poderAtaque, string Nombre):vidaMax(4000)
{
    vida = vidaMax;
    this->poderAtaque = poderAtaque;
    this->Nombre = Nombre;
    estado = true;//vivo
    CM++;
}


int cMonstruo::getStaticCounte()
{
    return CM;
}

bool cMonstruo::getEstado()
{
    return estado;
}

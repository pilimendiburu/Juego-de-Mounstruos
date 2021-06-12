#include "cMonstruo.h"


void cMonstruo::RecibirDa�o(int da�o)
{
    vida = vida - da�o;
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

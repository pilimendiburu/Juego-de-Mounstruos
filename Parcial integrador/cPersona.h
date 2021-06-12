#pragma once
#include "librerias.h"
/*class cEsrriboM;
class cEsrriboE;
class cElite;*/
class cMonstruo;
class cPersona
{
	friend ostream& operator<<(ostream& out, const cPersona& o);
	friend void operator-(cPersona& p, int daño);
	friend class cEsrriboM;
	friend class cEsrriboE;
	friend class cElite;
	friend class cJefe;

	int fuerza;
	int inteligencia;
	int vida;
	const int vidaMax;
	int Armadura;
	int poderAtaque;
	bool estado;
public:
	cPersona(int fuerza, int inteligencia,
		int Armadura, int poderAtaque);
	~cPersona() { };
	void Atacar(cMonstruo* ene);
	bool getEstado() { return estado; };
protected:
	void RecibirDaño(int daño, cMonstruo& ene);
};
ostream& operator<<(ostream& out, const cPersona& o);
void operator-(cPersona& p,int daño);

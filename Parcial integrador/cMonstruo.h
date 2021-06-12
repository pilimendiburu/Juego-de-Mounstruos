#pragma once
#include "librerias.h"
#include "cPersona.h"
class cPersona;
class cMonstruo
{
protected:
	friend class cPersona;
	//agragar friend
	int vida;
	const int vidaMax;
	int poderAtaque;
	bool estado;
	string Nombre;
	static int CM;
	void RecibirDa�o(int da�o);
public:
	cMonstruo(int poderAtaque,string Nombre);
	string getNombre() { return Nombre; };
	~cMonstruo() { /*no descuento el contador pq dice creados, no vivos*/};
	virtual void Atacar(cPersona* persona) = 0;
	static int getStaticCounte();
	bool getEstado();
};


#include "librerias.h"
#include "cPersona.h"
#include "cEsrriboM.h"
#include "cEsrriboE.h"
#include "cElite.h"
#include "cJefe.h"

int main()
{
	srand(time(NULL));
	cPersona* p1 = new cPersona(1000, 900, 444, 200);
	cMonstruo* m1 = new cJefe(5000,"Willy", 1000,800);
	cMonstruo* m2 = new cElite(4000, "Juanjo", 800, 500);
	cMonstruo* m3 = new cEsrriboE(2000, "Milo", 200);
	cMonstruo* m4 = new cEsrriboM(900, "Pedro", 400);
	cout << "\nJugador: " << endl;
	cout << *p1;
	do
	{
		try
		{
			p1->Atacar(m4);
		}
		catch (exception* e)
		{
			cout << e->what() << endl;//si alguno esta muerto
			break;
		}
		try
		{
			m4->Atacar(p1);
		}
		catch (exception* e)
		{
			cout << e->what() << endl;
			break;//si alguno esta muerto
		}
	} while (m4->getEstado() == true && p1->getEstado() == true);
	if (m4->getEstado()) {
		cout << "\nHa ganado: " << m1->getNombre() << endl;
		cout << *p1;
		delete p1;
		cPersona* p2 = new cPersona(900, 950, 744, 1000);
		do
		{
			try
			{
				p2->Atacar(m3);
			}
			catch (exception* e)
			{
				cout << e->what() << endl;//si alguno esta muerto
				break;
			}
			try
			{
				m3->Atacar(p2);
			}
			catch (exception* e)
			{
				cout << e->what() << endl;//si alguno esta muerto
				break;
			}
		} while (m3->getEstado() == true && p2->getEstado() == true);
		if (p2->getEstado()) {
			cout << "\nHa ganado el siguiente jugador." << endl;
			cout<<* p2;
		}
		else {
			cout << "\nHa perdido el siguiente jugador" << endl;
		}
		delete p2;
	}
	else {
		cout << "\nHas ganado, Siguiente monstruo: " << m2->getNombre() << endl;
		cout << *p1;
		do
		{
			try
			{
				p1->Atacar(m2);
			}
			catch (exception* e)
			{
				cout << e->what() << endl;//si alguno esta muerto
				break;//si alguno esta muerto
			}
			try
			{
				m2->Atacar(p1);
			}
			catch (exception* e)
			{
				cout << e->what() << endl;//si alguno esta muerto
				break;//si alguno esta muerto
			}
		} while (m2->getEstado() == true && p1->getEstado() == true);
		if (!m2->getEstado())
			cout << "\nHas ganado!" << endl;
		else {
			cout << "\nHa ganado el monstruo: " << m2->getNombre();
			delete p1;
			cPersona* p2 = new cPersona(900, 950, 744, 1000);
			do
			{
				try
				{
					p2->Atacar(m1);
				}
				catch (exception* e)
				{
					cout << e->what() << endl;//si alguno esta muerto
					break;//si alguno esta muerto
				}
				try
				{
					m1->Atacar(p2);
				}
				catch (exception* e)
				{
					cout << e->what() << endl;//si alguno esta muerto
					break;//si alguno esta muerto
				}
			} while (m1->getEstado() == true && p2->getEstado() == true);
			if (p2->getEstado())
				cout << "\nHa ganado el siguiente jugador." << endl;
			else {
				cout << "\nHa perdido el siguiente jugador" << endl;
			}
			delete p2;
		}
	}
	cout << cMonstruo::getStaticCounte()<<endl;
	system("pause");
	delete m1;
	delete m2;
	delete m3;
	delete m4;

}
#include "Control.h"
Control::Control(){}
void Control::opciones() {
	Interfaz *interfaz = new Interfaz;
	ListaFichas *bolsaFichas = new ListaFichas;
	Jugador *jugador = new Jugador("Ian");
	cout << jugador->toString() << endl;

}
Control::~Control(){}
